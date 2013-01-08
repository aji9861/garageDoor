/*
 * MotorStateMachine.h
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#ifndef MOTORSTATEMACHINE_H_
#define MOTORSTATEMACHINE_H_

#include <list>
#include "Signal.h"
#include "MotorState.h"

class MotorStateMachine {
public:
	MotorStateMachine();
	~MotorStateMachine();
	void addListenerEvent(Signal s);

private:
	MotorState *curState;
	std::list<Signal> motorQueue;
};

#endif /* MOTORSTATEMACHINE_H_ */
