/*
 * DoorLowering.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorLowering.h"		//used for inheritance
#include "DoorPausedLowering.h"	//used for state changes
#include "DoorRaising.h"		//same
#include "DoorClosed.h"			//same

#include <iostream> 			//used to output to terminal
using namespace std;			//same

State* DoorLowering::acceptEvent(StateSignal s){
	/* method called to receive signals,
	 * returns:
	 * signal == btn_push: DoorPausedLowering state
	 * signal == motor_overcurrent: DoorRaising state
	 * signal == beam_interupt: DoorRaising state
	 * signal == door_closed: DoorClosed state
	 * signal == anything else: self
	 */
	if (s == btn_push){
		return new DoorPausedLowering;
	}
	else if (s == motor_overcurrent){
		return new DoorRaising;
	}
	else if (s == beam_interupt){
		return new DoorRaising;
	}
	else if (s == door_closed){
		return new DoorClosed;
	}
	return this;
}

StateSignal DoorLowering::onEntry(){
	/* method called on entry to the state, declares that the state has been
	 * entered, and turns on the ir beam.  return should make the door start
	 * lowering
	 */
	cout << "Enter door lowering" << endl;
	cout << "IR beam on" << endl;
	return motor_down_active;
}

StateSignal DoorLowering::onExit(){
	/* method called on exit to the state.  ir beam is turned off.  return
	 * should make the motor stop lowering.
	 */
	cout << "IR beam off" << endl;
	return motor_down_inactive;
}
