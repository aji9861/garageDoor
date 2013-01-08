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


LoweringMotorState::LoweringMotorState(MotorStateMachine *machine)
	: MotorState(machine){
	msm = machine;
}

void* lowerMotor(void* motorMachine){
	MotorStateMachine* motor = (MotorStateMachine *) motorMachine;
	while(motor->getTimer() > 0){
		sleep(1);
		motor->decTimer();
		cout << "Motor Timer: " << motor->getTimer() << endl;
	}
	motor->sendControlSignal(door_closed);
	return NULL;
}

MotorState* LoweringMotorState::acceptEvent(Signal s){
	if (s == motor_up_active){
		return new ErrorMotorState(msm);
	} else if (s == motor_down_inactive){
		return new IdleMotorState(msm);
	}
	return this;
}

bool LoweringMotorState::onEntry(){
	cout << "Motor lowering" << endl;
	pthread_create(&timer_t, NULL, lowerMotor, msm);
	return true;
}

bool LoweringMotorState::onExit(){
	cout << "Motor is no longer lowering" << endl;
	pthread_cancel(timer_t);
	return true;
}
