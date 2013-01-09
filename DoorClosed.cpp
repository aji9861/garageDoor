/*
 * DoorClosed.cpp
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#include "DoorClosed.h"		//used for inheritance
#include "DoorRaising.h"	//used in state changes
#include <iostream>			//used to output to terminal
using namespace std;		//same

State* DoorClosed::acceptEvent(StateSignal s){
	/* method called to receive signals,
	 * returns:
	 * signal == btn_push: doorRaising state
	 * signal == anything else: self
	 */
	if (s == btn_push){
		return new DoorRaising;
	}
	return this;
}

StateSignal DoorClosed::onEntry(){
	/* method called on entry to the state, declares that the state has been
	 * entered.  return should not adjust state of the motor
	 */
	cout << "Enter door closed" << endl;
	return no_signal;
}

StateSignal DoorClosed::onExit(){
	/* method called on exit to the state.  return should not adjust state of
	 * the motor
	 */
	return no_signal;
}
