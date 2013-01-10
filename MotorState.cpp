/*
 * MotorState.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#include "MotorState.h"		//used for inheritance

MotorState::MotorState(MotorStateMachine *machine){
	/* constructor 
	 */
	msm = machine;
}

MotorState::~MotorState() {
	//delete(this);
}

MotorState* MotorState::acceptEvent(StateSignal s){
	/* called to add a signal to the queue 
	 */
	return this;
}

bool MotorState::onExit(){
	/* called when a state exits 
	 */
	return true;
}

bool MotorState::onEntry(){
	/* called when the state enters 
	 */
	return true;
}
