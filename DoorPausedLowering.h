/*
 * DoorPausedLowering.h
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#ifndef DOORPAUSEDLOWERING_H_
#define DOORPAUSEDLOWERING_H_

#include "State.h"

class DoorPausedLowering: public State {
public:
	State* acceptEvent(StateSignal s);
	StateSignal onEntry();
	StateSignal onExit();
};

#endif /* DOORPAUSEDLOWERING_H_ */
