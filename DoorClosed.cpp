/*
 * DoorClosed.cpp
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#include "DoorClosed.h"
#include "DoorRaising.h"
#include <iostream>

using namespace std;

State* DoorClosed::acceptEvent(StateSignal s){
	if (s == btn_push){
		return new DoorRaising;
	}
	return this;
}

StateSignal DoorClosed::onEntry(){
	cout << "Enter door closed" << endl;
	return no_signal;
}

StateSignal DoorClosed::onExit(){
	//cout << "Exit door closed" << endl;
	return no_signal;
}
