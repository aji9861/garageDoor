/*
 * DoorRaising.cpp
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#include "DoorRaising.h"		//used for inheritance
#include "DoorPausedRaising.h"	//used for state change
#include "DoorOpened.h"			//same
#include <iostream>				//used to output to terminal
using namespace std;			//same

State* DoorRaising::acceptEvent(StateSignal s){
	/* method called to receive signals,
	 * returns:
	 * signal == btn_push: DoorPausedRaising state
	 * signal == motor_overcurrent: DoorPausedRaising state
	 * signal == door_open: DoorOpened state
	 * signal == anything else: self
	 */
	if (s == btn_push){
		return new DoorPausedRaising;
	}
	else if (s == motor_overcurrent){
		return new DoorPausedRaising;
	}
	else if (s == door_open){
		return new DoorOpened;
	}

	return this;
}

StateSignal DoorRaising::onEntry(){
	/* method called on entry to the state, declares that the state has been
	 * entered.  return should make the door start raising
	 */
	cout << "Enter door raising" << endl;
	return motor_up_active;
}

StateSignal DoorRaising::onExit(){
	/* method called on exit to the state.  return should make the motor stop
	 * raising.
	 */
	return motor_up_inactive;
}
