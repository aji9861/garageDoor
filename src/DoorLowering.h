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
	State* acceptEvent(Signal s);
	bool onEntry();
	bool onExit();
};

#endif /* DOORLOWERING_H_ */
