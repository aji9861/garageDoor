/*
 * DoorClosed.cpp
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#include "DoorClosed.h"
#include "DoorRaising.h"

DoorClosed::DoorClosed(){ }

DoorClosed::~DoorClosed(){ }

State* DoorClosed::acceptEvent(Signal s){
	if (s == btn_push){
		return new DoorRaising();
	}
	return this;
}

bool DoorClosed::onEntry(){
	return true;
}

bool DoorClosed::onExit(){
	return true;
}
