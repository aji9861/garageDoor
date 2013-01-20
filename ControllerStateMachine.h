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
  /* constructor */
	ControllerStateMachine(bool simualted);
	/* deconstructor */
	~ControllerStateMachine();
	/* accepts signals for possible state changes */
	void addListenerEvent(StateSignal s);
	/* see if the controller has been turned on */
	bool isRunning();
	/* checks the signal queue if there are any signals */
	void checkController();

private:
  /* the current state */
	State *curState;
	/* reference to the motor to send it signals */
	MotorInterface *motor;
	/* has the controller been started */
	bool running;
	/* signal queue */
	std::list<StateSignal> listenerQueue;
	/* mutex to control access to the signal queue */
	pthread_mutex_t queueMutex;

  /* sends a signal to the motor */
	void addMotorEvent(StateSignal s);
	/* starts the thread watching the controller queue for anything being 
	 * added 
	 */
	void startController();
};

#endif /* CONTROLLERSTATEMACHINE_H_ */
