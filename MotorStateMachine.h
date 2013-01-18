/*
 * MotorStateMachine.h
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#ifndef MOTORSTATEMACHINE_H_
#define MOTORSTATEMACHINE_H_

#include <list>
#include "StateSignal.h"
#include "MotorState.h"
#include "ControllerStateMachine.h"
#include "MotorInterface.h"

class MotorState;
class ControllerStateMachine;

class MotorStateMachine: public MotorInterface {
	bool running;

public:
	MotorStateMachine();
	~MotorStateMachine();
	void addListenerEvent(StateSignal s);
	void startMotor();
	bool isRunning();
	void checkMotor();
	void incTimer();
	void decTimer();
	int getTimer();
	void setController(ControllerStateMachine* controller);
	void sendControlSignal(StateSignal s);


private:
	MotorState *curState;
	std::list<StateSignal> motorQueue;
	int timer;
	ControllerStateMachine* csm;
};

#endif /* MOTORSTATEMACHINE_H_ */
