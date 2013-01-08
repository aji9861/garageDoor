/*
 * LoweringMotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "LoweringMotorState.h"
#include "ErrorMotorState.h"
#include "IdleMotorState.h"

#include <iostream>

using namespace std;

MotorState* LoweringMotorState::acceptEvent(Signal s){
	if (s == motor_up_active){
		return new ErrorMotorState;
	} else if (s == motor_down_inactive){
		return new IdleMotorState;
	}
	return this;
}

bool LoweringMotorState::onEntry(){
	cout << "Motor lowering" << endl;
	return true;
}

bool LoweringMotorState::onExit(){
	cout << "Motor is no longer lowering" << endl;
	return true;
}
