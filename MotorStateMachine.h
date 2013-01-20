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
  /* has the motor been turned on */
	bool running;

public:
  /* constructor */
	MotorStateMachine();
	/* deconstructor */
	~MotorStateMachine();
  /* see MotorInterface.h for details on the methods below */	
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
  /* the current motor state */
	MotorState *curState;
	/* the queue for signals being sent to the motor */
	std::list<StateSignal> motorQueue;
	/* internal timer used to record the dorrs location */
	int timer;
	/* reference to the controller to send it signals */
	ControllerStateMachine* csm;
};

#endif /* MOTORSTATEMACHINE_H_ */
