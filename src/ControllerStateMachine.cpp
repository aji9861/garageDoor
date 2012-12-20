/*
 * ControllerStateMachine.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "ControllerStateMachine.h"
#include "DoorClosed.h"

ControllerStateMachine::ControllerStateMachine() {
	curState = new DoorClosed;
	curState->onEntry();
}

ControllerStateMachine::~ControllerStateMachine() {
	delete(curState);
}

void ControllerStateMachine::addListenerEvent(Signal s){
	listenerQueue.push_back(s);

	State *newState = curState->acceptEvent(s);
	if (newState != curState){
		curState->onExit();
		curState = newState;
		curState->onEntry();
	}
}

void ControllerStateMachine::addMotorEvent(Signal s){
	motorQueue.push_back(s);
}
