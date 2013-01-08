/*
 * MotorStateMachine.h
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#ifndef MOTORSTATEMACHINE_H_
#define MOTORSTATEMACHINE_H_

#include <list>
#include "../Signal.h"
#include "MotorState.h"
#include "../ControllerStateMachine.h"

class MotorState;
class ControllerStateMachine;

class MotorStateMachine {

public:
	MotorStateMachine();
	~MotorStateMachine();
	void addListenerEvent(Signal s);
	void incTimer();
	void decTimer();
	int getTimer();
	void setController(ControllerStateMachine* controller);
	void sendControlSignal(Signal s);

private:
	MotorState *curState;
	std::list<Signal> motorQueue;
	int timer;
	ControllerStateMachine* csm;
};

#endif /* MOTORSTATEMACHINE_H_ */
