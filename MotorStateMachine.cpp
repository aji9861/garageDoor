/*
 * MotorStateMachine.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "MotorStateMachine.h"
#include "IdleMotorState.h"
#include <pthread.h>
#include <unistd.h>

using namespace std;

MotorStateMachine::MotorStateMachine() {
	running = true;
	timer = 0;
	curState = new IdleMotorState(this);
	curState->onEntry();
	startMotor();
}

MotorStateMachine::~MotorStateMachine() {
	delete(curState);
}

bool MotorStateMachine::isRunning(){
	return running;
}

void MotorStateMachine::addListenerEvent(StateSignal s){
	motorQueue.push_back(s);
}

void* runMotor(void* motor){
	while (((MotorStateMachine *) motor)->isRunning()){
		((MotorStateMachine *) motor)->checkMotor();
		usleep(500000);
	}
	return NULL;
}

void MotorStateMachine::startMotor(){
	pthread_t motor_t;

	pthread_create(&motor_t, NULL, runMotor, this);
}

void MotorStateMachine::checkMotor(){
	if (!motorQueue.empty()){
		MotorState *newState = curState->acceptEvent(motorQueue.front());
		if (newState != curState){
			curState->onExit();
			curState = newState;
			curState->onEntry();
		}
		motorQueue.pop_front();
	}
}


void MotorStateMachine::setController(ControllerStateMachine* controller){
	csm = controller;
}

void MotorStateMachine::sendControlSignal(StateSignal s){
	csm->addListenerEvent(s);
}

void MotorStateMachine::incTimer(){
	timer++;
}

void MotorStateMachine::decTimer(){
	timer--;
}

int MotorStateMachine::getTimer(){
	return timer;
}
