/*
 * MotorStateMachine.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "MotorStateMachine.h"
#include "IdleMotorState.h"

MotorStateMachine::MotorStateMachine() {
	curState = new IdleMotorState;
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
