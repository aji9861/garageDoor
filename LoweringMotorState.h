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
	LoweringMotorState(MotorStateMachine *machine);
	MotorState* acceptEvent(StateSignal s);
	bool onEntry();
	bool onExit();
};

#endif /* LOWERINGMOTORSTATE_H_ */
