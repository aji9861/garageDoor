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
#include "MotorInterface.h"
#include <pthread.h>

class MotorInterface;

class ControllerStateMachine {
public:
	ControllerStateMachine(bool simualted);
	~ControllerStateMachine();
	void addListenerEvent(StateSignal s);
	bool isRunning();
	void checkController();

private:
	State *curState;
	MotorInterface *motor;
	bool running;
	std::list<StateSignal> listenerQueue;
	pthread_mutex_t queueMutex;

	void addMotorEvent(StateSignal s);
	void startController();
};

#endif /* CONTROLLERSTATEMACHINE_H_ */
