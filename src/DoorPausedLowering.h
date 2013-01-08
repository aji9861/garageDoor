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
	State* acceptEvent(Signal s);
	Signal onEntry();
	Signal onExit();
};

#endif /* DOORPAUSEDLOWERING_H_ */
