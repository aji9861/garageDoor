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

State* DoorOpened::acceptEvent(Signal s){
	if (s == btn_push){
		return new DoorLowering;
	}

	return this;
}

Signal DoorOpened::onEntry(){
	cout << "Enter door opened" << endl;
	return no_signal;
}

Signal DoorOpened::onExit(){
	cout << "Exit door opened" << endl;
	return no_signal;
}
