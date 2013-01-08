/*
 * ControllerStateMachine.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "ControllerStateMachine.h"
#include "DoorClosed.h"
#include <pthread.h>
#include <unistd.h>

ControllerStateMachine::ControllerStateMachine() {
	motor = new MotorStateMachine;
	running = true;
	curState = new DoorClosed;
	curState->onEntry();
	motor->setController(this);
	startController();
}

ControllerStateMachine::~ControllerStateMachine() {
	delete(curState);
	delete(motor);
}

void ControllerStateMachine::addListenerEvent(StateSignal s){
	listenerQueue.push_back(s);
}

bool ControllerStateMachine::isRunning(){
	return running;
}

void* runController(void* controller){
	while (((ControllerStateMachine*)controller)->isRunning()){
		((ControllerStateMachine*)controller)->checkController();
		sleep(1);
	}
	return NULL;
}

void ControllerStateMachine::checkController(){
	if(!listenerQueue.empty()){
		State *newState = curState->acceptEvent(listenerQueue.front());
		if (newState != curState){
			addMotorEvent(curState->onExit());
			curState = newState;
			addMotorEvent(curState->onEntry());
		}
		listenerQueue.pop_front();
	}
}

void ControllerStateMachine::startController(){
	pthread_t controller_t;

	pthread_create(&controller_t, NULL, runController, this);
}



void ControllerStateMachine::addMotorEvent(StateSignal s){
	motor->addListenerEvent(s);
}
