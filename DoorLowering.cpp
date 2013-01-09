/*
 * DoorLowering.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorLowering.h"
#include "DoorPausedLowering.h"
#include "DoorRaising.h"
#include "DoorClosed.h"

#include <iostream>

using namespace std;

State* DoorLowering::acceptEvent(StateSignal s){
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
	cout << "Enter door lowering" << endl;
	cout << "IR beam on" << endl;
	return motor_down_active;
}

StateSignal DoorLowering::onExit(){
	cout << "IR beam off" << endl;
	//cout << "Exit door lowering" << endl;
	return motor_down_inactive;
}
