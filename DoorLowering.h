/*
 * DoorLowering.h
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#ifndef DOORLOWERING_H_
#define DOORLOWERING_H_

#include "State.h"

class DoorLowering: public State {
public:
  /* see State.h for details on the methods below */
	State* acceptEvent(StateSignal s);
	StateSignal onEntry();
	StateSignal onExit();
};

#endif /* DOORLOWERING_H_ */
