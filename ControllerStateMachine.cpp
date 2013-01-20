/*
 * ControllerStateMachine.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "ControllerStateMachine.h"
#include "MotorStateMachine.h"
#include "DoorClosed.h"
#include "HardwareMotor.h"
#include <unistd.h>

#include <stdio.h>

using namespace std;

ControllerStateMachine::ControllerStateMachine(bool simulated) {
	if (simulated){
		motor = new MotorStateMachine;
	}
	else{
		motor = new HardwareMotor;
	}
	running = true;
	curState = new DoorClosed;
	curState->onEntry();
	motor->setController(this);
	startController();
	int result = pthread_mutex_init(&queueMutex, NULL);
	if (result != 0){
		printf("Mutex error: %d\n", result);
	}
}

ControllerStateMachine::~ControllerStateMachine() {
	delete(curState);
	delete(motor);
	pthread_mutex_destroy(&queueMutex);
}

void ControllerStateMachine::addListenerEvent(StateSignal s){
	pthread_mutex_lock(&queueMutex);
	listenerQueue.push_back(s);
	pthread_mutex_unlock(&queueMutex);
}

bool ControllerStateMachine::isRunning(){
	return running;
}

void* runController(void* controller){
	while (((ControllerStateMachine*)controller)->isRunning()){
		((ControllerStateMachine*)controller)->checkController();
		usleep(50);
	}
	return NULL;
}

void ControllerStateMachine::checkController(){
	pthread_mutex_lock(&queueMutex);
	if(!listenerQueue.empty()){
		State *newState = curState->acceptEvent(listenerQueue.front());
		listenerQueue.pop_front();
		if (newState != curState){
			addMotorEvent(curState->onExit());
			curState = newState;
			addMotorEvent(curState->onEntry());
		}
		listenerQueue.pop_front();
	}
	pthread_mutex_unlock(&queueMutex);
}

void ControllerStateMachine::startController(){
	pthread_t controller_t;

	pthread_create(&controller_t, NULL, runController, this);
}



void ControllerStateMachine::addMotorEvent(StateSignal s){
	motor->addListenerEvent(s);
}
