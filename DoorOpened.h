/*
 * DoorOpened.h
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#ifndef DOOROPENED_H_
#define DOOROPENED_H_

#include "State.h"

class DoorOpened: public State {
public:
	State *acceptEvent(StateSignal s);
	StateSignal onEntry();
	StateSignal onExit();
};

#endif /* DOOROPENED_H_ */
