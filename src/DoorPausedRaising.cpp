/*
 * DoorPausedRaising.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "DoorPausedRaising.h"
#include "DoorLowering.h"

State* DoorPausedRaising::acceptEvent(Signal s){
	if (s == btn_push){
		return new DoorLowering();
	}
	return this;
}
