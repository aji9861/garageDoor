/*
 * ControllerStateMachine.h
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#ifndef CONTROLLERSTATEMACHINE_H_
#define CONTROLLERSTATEMACHINE_H_

#include <list>
#include "Signal.h"
#include "State.h"
#include "Motor/MotorStateMachine.h"

class MotorStateMachine;

class ControllerStateMachine {
public:
	ControllerStateMachine();
	~ControllerStateMachine();
	void addListenerEvent(Signal s);

private:
	State *curState;
	MotorStateMachine *motor;
	std::list<Signal> listenerQueue;
	std::list<Signal> motorQueue;

	void addMotorEvent(Signal s);
};

#endif /* CONTROLLERSTATEMACHINE_H_ */
