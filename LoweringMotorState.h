/*
 * LoweringMotorState.h
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#ifndef LOWERINGMOTORSTATE_H_
#define LOWERINGMOTORSTATE_H_

#include "MotorState.h"
#include <pthread.h>

class LoweringMotorState: public MotorState {
pthread_t timer_t;
public:
  /* constructor */
	LoweringMotorState(MotorStateMachine *machine);
	/* see MotorState.h for details on the methods below */
	MotorState* acceptEvent(StateSignal s);
	bool onEntry();
	bool onExit();
};

#endif /* LOWERINGMOTORSTATE_H_ */
