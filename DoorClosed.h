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
  /* see State.h for details on the methods below */
	State* acceptEvent(StateSignal s);
	StateSignal onEntry();
	StateSignal onExit();
};

#endif /* DOORCLOSED_H_ */
