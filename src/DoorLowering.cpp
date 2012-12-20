/*
 * DoorLowering.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorLowering.h"
#include "DoorPausedLowering.h"

State* DoorLowering::acceptEvent(Signal s){
	if (s == btn_push){
		return new DoorPausedLowering();
	}
	return this;
}
