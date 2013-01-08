/*
 * ControllerStateMachine.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "ControllerStateMachine.h"
#include "DoorClosed.h"

ControllerStateMachine::ControllerStateMachine() {
	motor = new MotorStateMachine;
	curState = new DoorClosed;
	curState->onEntry();
}

ControllerStateMachine::~ControllerStateMachine() {
	delete(curState);
	motor->~MotorStateMachine();
}

void ControllerStateMachine::addListenerEvent(Signal s){
	listenerQueue.push_back(s);

	State *newState = curState->acceptEvent(s);
	if (newState != curState){
		addMotorEvent(curState->onExit());
		curState = newState;
		addMotorEvent(curState->onEntry());
	}
}

void ControllerStateMachine::addMotorEvent(Signal s){
	motor->addListenerEvent(s);
}
