/*
 * IdleMotorState.h
 *
 *  Created on: Jan 7, 2013
 *      Author: wkb6223
 */

#ifndef IDLEMOTORSTATE_H_
#define IDLEMOTORSTATE_H_

#include "MotorState.h"

class IdleMotorState: public MotorState {
public:
	IdleMotorState(MotorStateMachine *machine);
	MotorState* acceptEvent(StateSignal s);
	bool onEntry();
	bool onExit();
};
#endif /* IDLEMOTORSTATE_H_ */
