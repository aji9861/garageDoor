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

MotorState* ErrorMotorState::acceptEvent(Signal s){
	if (s == motor_up_inactive){
		return new LoweringMotorState;
	} else if (s == motor_down_inactive){
		return new RaisingMotorState;
	}
	return this;
}

bool ErrorMotorState::onEntry(){
	cout << "Motor error" << endl;
	return true;
}

bool ErrorMotorState::onExit(){
	cout << "Motor is no longer errored" << endl;
	return true;
}
