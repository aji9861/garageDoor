/*
 * ErrorMotorState.h
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#ifndef ERRORMOTORSTATE_H_
#define ERRORMOTORSTATE_H_

#include "MotorState.h"

class ErrorMotorState: public MotorState {
public:
	ErrorMotorState(MotorStateMachine *machine);
	MotorState* acceptEvent(StateSignal s);
	bool onEntry();
	bool onExit();
};
#endif /* ERRORMOTORSTATE_H_ */
