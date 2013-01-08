/*
 * MotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "MotorState.h"

MotorState::MotorState(MotorStateMachine *machine){
	msm = machine;
}

MotorState::~MotorState() {
	//delete(this);
}

MotorState* MotorState::acceptEvent(StateSignal s){
	return this;
}

bool MotorState::onExit(){
	return true;
}

bool MotorState::onEntry(){
	return true;
}
