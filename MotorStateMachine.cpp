/*
 * MotorStateMachine.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "MotorStateMachine.h"	//used for inheritance
#include "IdleMotorState.h"		//used for state change
#include <pthread.h>			//used for pthreads
#include <unistd.h>				//used for sleep
using namespace std;			//used for output

MotorStateMachine::MotorStateMachine() {
	/* constructor, initializes variables and sets the starting state to a
	 * closed door as well as launches the pthread to watch the signal queue
	 */
	running = true;
	timer = 0;
	curState = new IdleMotorState(this);
	curState->onEntry();
	startMotor();
}

MotorStateMachine::~MotorStateMachine() {
	/* deconstructor
	 */
	delete(curState);
}

bool MotorStateMachine::isRunning(){
	/* returns if the controller is turned on.
	 */
	return running;
}

void MotorStateMachine::addListenerEvent(StateSignal s){
	/* Adds a signal to the motorQueue
	 */
	motorQueue.push_back(s);
}

void* runMotor(void* motor){
	/* method to be run in a separate pthread. while the controller is running
	 * it will call checkController every second. */
	while (((MotorStateMachine *) motor)->isRunning()){
		((MotorStateMachine *) motor)->checkMotor();
		sleep(1);
	}
	return NULL;
}

void MotorStateMachine::startMotor(){
	/* launches pthread to monitor the signal queue 
	 */
	pthread_t motor_t;
	pthread_create(&motor_t, NULL, runMotor, this);
}

void MotorStateMachine::checkMotor(){
	/* method that is called from the spawned pthread, continually checks for
	 * any signal that have been added to the queue and updates the state based
	 * on them
	 */
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


void MotorStateMachine::setController(ControllerStateMachine* controller){
	/* sets the controller so that signals can be sent to it
	 */
	csm = controller;
}

void MotorStateMachine::sendControlSignal(StateSignal s){
	/* sends a signal to the controller
	 */
	csm->addListenerEvent(s);
}

void MotorStateMachine::incTimer(){
	/* increments the timer for how high the door is
	 */
	timer++;
}

void MotorStateMachine::decTimer(){
	/* decrincrements the timer for how high the door is
	 */
	timer--;
}

int MotorStateMachine::getTimer(){
	/* gets the timer for how high the door is
	 */
	return timer;
}
