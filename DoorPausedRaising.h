/*
 * DoorPausedRaising.h
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#ifndef DOORPAUSEDRAISING_H_
#define DOORPAUSEDRAISING_H_

#include "State.h"

class DoorPausedRaising: public State {
public:
	State* acceptEvent(StateSignal s);
	StateSignal onEntry();
	StateSignal onExit();
};

#endif /* DOORPAUSEDRAISING_H_ */
