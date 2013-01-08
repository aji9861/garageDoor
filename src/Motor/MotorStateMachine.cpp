/*
 * MotorStateMachine.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "MotorStateMachine.h"
#include "IdleMotorState.h"

MotorStateMachine::MotorStateMachine() {
	timer = 0;
	curState = new IdleMotorState(this);
	curState->onEntry();
}

MotorStateMachine::~MotorStateMachine() {
	delete(curState);
}

void MotorStateMachine::addListenerEvent(Signal s){
	motorQueue.push_back(s);

	MotorState *newState = curState->acceptEvent(s);
	if (newState != curState){
		curState->onExit();
		curState = newState;
		curState->onEntry();
	}
}

void MotorStateMachine::setController(ControllerStateMachine* controller){
	csm = controller;
}

void MotorStateMachine::sendControlSignal(Signal s){
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
