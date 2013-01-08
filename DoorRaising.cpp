/*
 * DoorRaising.cpp
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#include "DoorRaising.h"
#include "DoorPausedRaising.h"
#include "DoorOpened.h"

#include <iostream>

using namespace std;

State* DoorRaising::acceptEvent(StateSignal s){
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
	cout << "Enter door raising" << endl;
	return motor_up_active;
}

StateSignal DoorRaising::onExit(){
	cout << "Exit door raising" << endl;
	return motor_up_inactive;
}
