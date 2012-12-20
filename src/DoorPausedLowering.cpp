/*
 * DoorPausedLowering.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorPausedLowering.h"
#include "DoorRaising.h"

State* DoorPausedLowering::acceptEvent(Signal s){
	if (s == btn_push){
		return new DoorRaising();
	}
	return this;
}

