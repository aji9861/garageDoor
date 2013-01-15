/*
 * RaisingMotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */


#include "RaisingMotorState.h"
#include "IdleMotorState.h"
#include "ErrorMotorState.h"
#include <unistd.h>

#include <iostream>

using namespace std;

RaisingMotorState::RaisingMotorState(MotorStateMachine *machine)
	: MotorState(machine){
	msm = machine;
}

void* raiseMotor(void* motorMachine){
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
	if (s == motor_up_inactive){
		return new IdleMotorState(msm);
	} else if (s == motor_down_active){
		return new ErrorMotorState(msm);
	}
	return this;
}

bool RaisingMotorState::onEntry(){
	cout << "Motor raising" << endl;
	pthread_create(&timer_t, NULL, raiseMotor, msm);
	return true;
}

bool RaisingMotorState::onExit(){
	//cout << "Motor is no longer raising" << endl;
	pthread_cancel(timer_t);
	return true;
}
