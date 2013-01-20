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
  /* see State.h for details on teh methods below */
	State* acceptEvent(StateSignal s);
	StateSignal onEntry();
	StateSignal onExit();
};

#endif /* DOORPAUSEDLOWERING_H_ */
