/*
 * IdleMotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "IdleMotorState.h"
#include "RaisingMotorState.h"
#include "LoweringMotorState.h"

#include <iostream>

using namespace std;

MotorState* IdleMotorState::acceptEvent(Signal s){
	if (s == motor_up_active){
		return new RaisingMotorState;
	} else if (s == motor_down_active){
		return new LoweringMotorState;
	}
	return this;
}

bool IdleMotorState::onEntry(){
	cout << "Motor idle" << endl;
	return true;
}

bool IdleMotorState::onExit(){
	cout << "Motor is no longer idle" << endl;
	return true;
}
