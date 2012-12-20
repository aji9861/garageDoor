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

DoorClosed::DoorClosed(){ }

DoorClosed::~DoorClosed(){ }

State* DoorClosed::acceptEvent(Signal s){
	if (s == btn_push){
		return new DoorRaising();
	}
	return this;
}

bool DoorClosed::onEntry(){
	cout << "Enter door closed" << endl;
	return true;
}

bool DoorClosed::onExit(){
	cout << "Exit door closed" << endl;
	return true;
}
