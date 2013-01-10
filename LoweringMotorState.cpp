/*
 * LoweringMotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "LoweringMotorState.h"	//used for inheritance
#include "ErrorMotorState.h"	//used for state change
#include "IdleMotorState.h"		//same
#include <unistd.h>				//used sleep
#include <iostream>				//used for output
using namespace std;			//same


LoweringMotorState::LoweringMotorState(MotorStateMachine *machine)
	: MotorState(machine){
		/* constructor
		 */
		msm = machine;
}

void* lowerMotor(void* motorMachine){
	/* method for counting down while the door lowers 
	 */
	MotorStateMachine* motor = (MotorStateMachine *) motorMachine;
	while(motor->getTimer() > 0){
		sleep(1);
		motor->decTimer();
		cout << "Motor Timer: " << motor->getTimer() << endl;
	}
	motor->sendControlSignal(door_closed);
	return NULL;
}

MotorState* LoweringMotorState::acceptEvent(StateSignal s){
	/* method called to receive signals,
	 * returns:
	 * signal == motor_up_active: ErrorMotorState state
	 * signal == motor_down_inactive: IdleMotorState state
	 * signal == anything else: self
	 */
	if (s == motor_up_active){
		return new ErrorMotorState(msm);
	} else if (s == motor_down_inactive){
		return new IdleMotorState(msm);
	}
	return this;
}

bool LoweringMotorState::onEntry(){
	/* method called on entry to the state, declares that the state has been
	 * entered.  return should not adjust state of the motor
	 */
	cout << "Motor lowering" << endl;
	pthread_create(&timer_t, NULL, lowerMotor, msm);
	return true;
}

bool LoweringMotorState::onExit(){
	/* method called on exit to the state.  return should not adjust state of
	 * the motor
	 */
	pthread_cancel(timer_t);
	return true;
}
