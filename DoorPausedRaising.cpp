/*
 * DoorPausedRaising.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorPausedRaising.h"	//used for inheritance
#include "DoorLowering.h"		//used for state change
#include <iostream>				//used to output to terminal
using namespace std;			//same

State* DoorPausedRaising::acceptEvent(StateSignal s){
	/* method called to receive signals,
	 * returns:
	 * signal == btn_push: DoorLowering state
	 * signal == anything else: self
	 */
	if (s == btn_push){
		return new DoorLowering;
	}
	return this;
}

StateSignal DoorPausedRaising::onEntry(){
	/* method called on entry to the state, declares that the state has been
	 * entered.  return should not adjust state of the motor
	 */
	cout << "Enter door paused" << endl;
	return no_signal;
}

StateSignal DoorPausedRaising::onExit(){
	/* method called on exit to the state.  return should not adjust state of
	 * the motor
	 */
	return no_signal;
}
