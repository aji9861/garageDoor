/*
 * State.h
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#ifndef STATE_H_
#define STATE_H_

#include "StateSignal.h"

class State {
public:
  /* constructor */
	State();
	/* deconstructor */
	virtual ~State();
	/* accept statesignals to see if a state change is needed */
	virtual State* acceptEvent(StateSignal s);
	/* method called once the state is entered */
	virtual StateSignal onEntry();
	/* method called once the state is exited */
	virtual StateSignal onExit();
};

#endif /* STATE_H_ */
