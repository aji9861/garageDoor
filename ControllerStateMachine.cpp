/*
 * ControllerStateMachine.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "ControllerStateMachine.h"	//used to send messages
#include "DoorClosed.h"				//to create starting state
#include <pthread.h>				//for pthread_create
#include <unistd.h>					//for sleep()

ControllerStateMachine::ControllerStateMachine() {
	/* constructor, initializes variables and sets the starting state to a
	 * closed door as well as launches the pthread to watch the signal queue
	 */
	motor = new MotorStateMachine;
	running = true;
	curState = new DoorClosed;
	curState->onEntry();
	motor->setController(this);
	startController();
}

ControllerStateMachine::~ControllerStateMachine() {
	/* deconstructor
	 */
	delete(curState);
	delete(motor);
}

void ControllerStateMachine::addListenerEvent(StateSignal s){
	/* Adds a signal to the listenerQueue
	 */
	listenerQueue.push_back(s);
}

bool ControllerStateMachine::isRunning(){
	/* returns if the controller is turned on.
	 */
	return running;
}

void* runController(void* controller){
	/* method to be run in a separate pthread. while the controller is running
	 * it will call checkController every second. */
	while (((ControllerStateMachine*)controller)->isRunning()){
		((ControllerStateMachine*)controller)->checkController();
		sleep(1);
	}
	return NULL;
}

void ControllerStateMachine::checkController(){
	/* method that is called from the spawned pthread, continually checks for
	 * any signal that have been added to the queue and updates the state based
	 * on them
	 */
	if(!listenerQueue.empty()){
		//only run if there is a signal in the queue
		State *newState = curState->acceptEvent(listenerQueue.front());
		if (newState != curState){
			//if there is a new state change curState to it.
			addMotorEvent(curState->onExit());
			curState = newState;
			addMotorEvent(curState->onEntry());
		}
		listenerQueue.pop_front();
	}
}

void ControllerStateMachine::startController(){
	/* launches pthread to monitor the signal queue*/
	pthread_t controller_t;
	pthread_create(&controller_t, NULL, runController, this);
}



void ControllerStateMachine::addMotorEvent(StateSignal s){
	/* sends a generated signal to the motor */
	motor->addListenerEvent(s);
}
