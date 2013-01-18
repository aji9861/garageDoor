/*
 * DoorPausedRaising.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorPausedRaising.h"
#include "DoorLowering.h"

#include <iostream>

using namespace std;

State* DoorPausedRaising::acceptEvent(StateSignal s){
	if (s == btn_push){
		return new DoorLowering;
	}
	return this;
}

StateSignal DoorPausedRaising::onEntry(){
	cout << "Enter door paused raising" << endl;
	return no_signal;
}

StateSignal DoorPausedRaising::onExit(){
	//cout << "Exit door paused raising" << endl;
	return no_signal;
}
