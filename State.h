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
	State();
	virtual ~State();
	virtual State* acceptEvent(StateSignal s);
	virtual StateSignal onEntry();
	virtual StateSignal onExit();
};

#endif /* STATE_H_ */
