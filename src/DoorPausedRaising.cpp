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

State* DoorPausedRaising::acceptEvent(Signal s){
	if (s == btn_push){
		return new DoorLowering;
	}
	return this;
}

bool DoorPausedRaising::onEntry(){
	cout << "Enter door paused raising" << endl;
	return true;
}

bool DoorPausedRaising::onExit(){
	cout << "Exit door paused raising" << endl;
	return true;
}
