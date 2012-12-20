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
	State *acceptEvent(Signal s);
	bool onEntry();
	bool onExit();
};

#endif /* DOOROPENED_H_ */
