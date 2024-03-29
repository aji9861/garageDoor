/*
 * DoorRaising.h
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#ifndef DOORRAISING_H_
#define DOORRAISING_H_

#include "State.h"

class DoorRaising: public State {
public:
  /* see State.h for details onon the methods below */
	State* acceptEvent(StateSignal s);
	StateSignal onEntry();
	StateSignal onExit();
};

#endif /* DOORRAISING_H_ */
