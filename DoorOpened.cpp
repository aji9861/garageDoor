/*
 * DoorOpened.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorOpened.h"
#include "DoorLowering.h"

#include <iostream>

using namespace std;

State* DoorOpened::acceptEvent(StateSignal s){
	if (s == btn_push){
		return new DoorLowering;
	}

	return this;
}

StateSignal DoorOpened::onEntry(){
	cout << "Enter door opened" << endl;
	return no_signal;
}

StateSignal DoorOpened::onExit(){
	//cout << "Exit door opened" << endl;
	return no_signal;
}
