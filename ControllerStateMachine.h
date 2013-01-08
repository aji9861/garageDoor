/*
 * ControllerStateMachine.h
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#ifndef CONTROLLERSTATEMACHINE_H_
#define CONTROLLERSTATEMACHINE_H_

#include <list>
#include "StateSignal.h"
#include "State.h"
#include "MotorStateMachine.h"

class MotorStateMachine;

class ControllerStateMachine {
public:
	ControllerStateMachine();
	~ControllerStateMachine();
	void addListenerEvent(StateSignal s);
	bool isRunning();
	void checkController();

private:
	State *curState;
	MotorStateMachine *motor;
	bool running;
	std::list<StateSignal> listenerQueue;
	std::list<StateSignal> motorQueue;

	void addMotorEvent(StateSignal s);
	void startController();
};

#endif /* CONTROLLERSTATEMACHINE_H_ */
