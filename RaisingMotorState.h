/*
 * RaisingMotorState.h
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#ifndef RAISINGMOTORSTATE_H_
#define RAISINGMOTORSTATE_H_

#include "MotorState.h"
#include <pthread.h>

class RaisingMotorState: public MotorState {
/* timer used to determine the hight of the motor */
pthread_t timer_t;
public:
  /* constructor */
	RaisingMotorState(MotorStateMachine *machine);
	/* see MotorState.h for details on the following */
	MotorState* acceptEvent(StateSignal s);
	bool onEntry();
	bool onExit();
};
#endif /* RAISINGMOTORSTATE_H_ */
