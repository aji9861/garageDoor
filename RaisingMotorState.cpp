/*
 * RaisingMotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */


#include "RaisingMotorState.h"	//used for inheritance
#include "IdleMotorState.h"		//used for state change
#include "ErrorMotorState.h"	//same
#include <unistd.h>				//used for sleep
#include <iostream>				//used for output
using namespace std;			//same

RaisingMotorState::RaisingMotorState(MotorStateMachine *machine)
	: MotorState(machine){
		/* constructor
		 */
	msm = machine;
}

void* raiseMotor(void* motorMachine){
	/* method for counting down while the door lowers 
	 */
	MotorStateMachine* motor = (MotorStateMachine *) motorMachine;
	while(motor->getTimer() < 10){
		sleep(1);
		motor->incTimer();
		cout << "Motor Timer: " << motor->getTimer() << endl;
	}
	motor->sendControlSignal(door_open);
	return NULL;
}

MotorState* RaisingMotorState::acceptEvent(StateSignal s){
	/* method called to receive signals,
	 * returns:
	 * signal == motor_up_inactive: IdleMotorState state
	 * signal == motor_down_active: ErrorMotorState state
	 * signal == anything else: self
	 */
	if (s == motor_up_inactive){
		return new IdleMotorState(msm);
	} else if (s == motor_down_active){
		return new ErrorMotorState(msm);
	}
	return this;
}

bool RaisingMotorState::onEntry(){
	/* method called on entry to the state, declares that the state has been
	 * entered.  return should not adjust state of the motor
	 */
	cout << "Motor raising" << endl;
	pthread_create(&timer_t, NULL, raiseMotor, msm);
	return true;
}

bool RaisingMotorState::onExit(){
	/* method called on exit to the state.  return should not adjust state of
	 * the motor
	 */
	pthread_cancel(timer_t);
	return true;
}
