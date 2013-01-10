/*
 * IdleMotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "IdleMotorState.h"		//used for inheritance
#include "RaisingMotorState.h"	//used for state change
#include "LoweringMotorState.h"	//same
#include <iostream>				//used for output
using namespace std;			//same

IdleMotorState::IdleMotorState(MotorStateMachine *machine)
	: MotorState(machine){
		/* contructor
		 */
		msm = machine;
}

MotorState* IdleMotorState::acceptEvent(StateSignal s){
	/* method called to receive signals,
	 * returns:
	 * signal == motor_up_active: RaisingMotorState state
	 * signal == motor_down_active: LoweringMotorState state
	 * signal == anything else: self
	 */
	if (s == motor_up_active){
		return new RaisingMotorState(msm);
	} else if (s == motor_down_active){
		return new LoweringMotorState(msm);
	}
	return this;
}

bool IdleMotorState::onEntry(){
	/* method called on entry to the state, declares that the state has been
	 * entered.  return should not adjust state of the motor
	 */
	cout << "Motor idle" << endl;
	return true;
}

bool IdleMotorState::onExit(){
	/* method called on exit to the state.  return should not adjust state of
	 * the motor
	 */
	return true;
}
