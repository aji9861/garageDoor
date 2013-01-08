/*
 * MotorStateMachine.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "MotorStateMachine.h"
#include "IdleMotorState.h"
#include <pthread.h>
#include <unistd.h>

using namespace std;

MotorStateMachine::MotorStateMachine() {
	time = 0;
	running = true;
	curState = new IdleMotorState;
	curState->onEntry();
}

MotorStateMachine::~MotorStateMachine() {
	delete(curState);
}

bool MotorStateMachine::isRunning(){
	return running;
}

void MotorStateMachine::addListenerEvent(Signal s){
	motorQueue.push_back(s);
}

void* runMotor(void* motor){
	while (((MotorStateMachine *) motor)->isRunning()){
		((MotorStateMachine *) motor)->checkMotor();
		sleep(1);
	}
	return NULL;
}

void MotorStateMachine::startMotor(){
	pthread_t motor_t;

	pthread_create(&motor_t, NULL, runMotor, this);

	pthread_join(motor_t, NULL);
}

void MotorStateMachine::checkMotor(){
	if (!motorQueue.empty()){
		MotorState *newState = curState->acceptEvent(motorQueue.front());
		if (newState != curState){
			curState->onExit();
			curState = newState;
			curState->onEntry();
		}
		motorQueue.pop_front();
	}
}


