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

class MotorStateMachine {
int time;
bool running;

public:
	MotorStateMachine();
	~MotorStateMachine();
	void addListenerEvent(Signal s);
	void startMotor();
	bool isRunning();
	void checkMotor();


private:
	MotorState *curState;
	std::list<Signal> motorQueue;
};

#endif /* MOTORSTATEMACHINE_H_ */
