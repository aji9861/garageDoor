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
	State* acceptEvent(Signal s);
	bool onEntry();
	bool onExit();
};

#endif /* DOORRAISING_H_ */
