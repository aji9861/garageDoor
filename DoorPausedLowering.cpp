/*
 * DoorPausedLowering.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorPausedLowering.h"
#include "DoorRaising.h"

#include <iostream>

using namespace std;

State* DoorPausedLowering::acceptEvent(StateSignal s){
	if (s == btn_push){
		return new DoorRaising();
	}
	return this;
}

StateSignal DoorPausedLowering::onEntry(){
	cout << "Enter door paused lowering" << endl;
	return no_signal;
}

StateSignal DoorPausedLowering::onExit(){
	cout << "Exit door paused lowering" << endl;
	return no_signal;
}
