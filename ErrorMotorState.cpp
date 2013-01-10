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
		/* contructor 
		 */
		msm = machine;
}

MotorState* ErrorMotorState::acceptEvent(StateSignal s){
	/* method called to receive signals,
	 * returns:
	 * signal == motor_up_inactive: LoweringMotorState state
	 * signal == motor_down_inactive: RaisingMotorState state
	 * signal == anything else: self
	 */
	if (s == motor_up_inactive){
		return new LoweringMotorState(msm);
	} else if (s == motor_down_inactive){
		return new RaisingMotorState(msm);
	}
	return this;
}

bool ErrorMotorState::onEntry(){
	/* method called on entry to the state, declares that the state has been
	 * entered.  return should not adjust state of the motor
	 */
	cout << "Motor error" << endl;
	return true;
}

bool ErrorMotorState::onExit(){
	/* method called on exit to the state.  return should not adjust state of
	 * the motor
	 */
	cout << "Motor is no longer errored" << endl;
	return true;
}
