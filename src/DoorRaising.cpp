/*
 * DoorRaising.cpp
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#include "DoorRaising.h"
#include "DoorPausedRaising.h"


State* DoorRaising::acceptEvent(Signal s){
	if (s == btn_push){
		return new DoorPausedRaising();
	}
	else if (s == motor_overcurrent){
		return new DoorPausedRaising();
	}

	return this;
}

