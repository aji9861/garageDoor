/*
 * State.h
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#ifndef STATE_H_
#define STATE_H_

#include "Signal.h"

class State {
public:
	State();
	virtual ~State();
	virtual State* acceptEvent(Signal s);
	virtual bool onEntry();
	virtual bool onExit();
};

#endif /* STATE_H_ */