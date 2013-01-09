/*
 * DoorPausedLowering.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorPausedLowering.h"	//used for inheritance
#include "DoorRaising.h"		//used for state changes
#include <iostream>				//used for output to terminal
using namespace std;			//same

State* DoorPausedLowering::acceptEvent(StateSignal s){
	/* method called to receive signals,
	 * returns:
	 * signal == btn_push: DoorRaising state
	 * signal == anything else: self
	 */
	if (s == btn_push){
		return new DoorRaising();
	}
	return this;
}

StateSignal DoorPausedLowering::onEntry(){
	/* method called on entry to the state, declares that the state has been
	 * entered.  return should not adjust state of the motor
	 */
	cout << "Enter door paused" << endl;
	return no_signal;
}

StateSignal DoorPausedLowering::onExit(){
	/* method called on exit to the state.  return should not adjust state of
	 * the motor
	 */
	return no_signal;
}
