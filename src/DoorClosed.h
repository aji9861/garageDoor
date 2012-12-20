/*
 * DoorClosed.h
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#ifndef DOORCLOSED_H_
#define DOORCLOSED_H_

#include "State.h"


class DoorClosed: public State {
public:
	State* acceptEvent(Signal s);
	bool onEntry();
	bool onExit();
};

#endif /* DOORCLOSED_H_ */
