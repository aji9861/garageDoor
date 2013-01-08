/*
 * RaisingMotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */


#include "RaisingMotorState.h"
#include "IdleMotorState.h"
#include "ErrorMotorState.h"

#include <iostream>

using namespace std;

MotorState* RaisingMotorState::acceptEvent(Signal s){
	if (s == motor_up_inactive){
		return new IdleMotorState;
	} else if (s == motor_down_active){
		return new ErrorMotorState;
	}
	return this;
}

bool RaisingMotorState::onEntry(){
	cout << "Motor raising" << endl;
	return true;
}

bool RaisingMotorState::onExit(){
	cout << "Motor is no longer raising" << endl;
	return true;
}
