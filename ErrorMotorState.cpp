/*
 * ErrorMotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "ErrorMotorState.h"
#include "LoweringMotorState.h"
#include "RaisingMotorState.h"

#include <iostream>

using namespace std;

ErrorMotorState::ErrorMotorState(MotorStateMachine *machine)
	: MotorState(machine){

	msm = machine;
}

MotorState* ErrorMotorState::acceptEvent(StateSignal s){
	if (s == motor_up_inactive){
		return new LoweringMotorState(msm);
	} else if (s == motor_down_inactive){
		return new RaisingMotorState(msm);
	}
	return this;
}

bool ErrorMotorState::onEntry(){
	cout << "Motor error" << endl;
	return true;
}

bool ErrorMotorState::onExit(){
	//cout << "Motor is no longer errored" << endl;
	return true;
}
