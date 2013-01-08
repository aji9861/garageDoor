/*
 * MotorState.h
 *
 *  Created on: Jan 7, 2012
 *      Author: wkb6223
 */

#ifndef MOTORSTATE_H_
#define MOTORSTATE_H_

#include "../Signal.h"
#include "MotorStateMachine.h"

class MotorStateMachine;

class MotorState {
protected:
	MotorStateMachine *msm;
public:
	MotorState(MotorStateMachine *machine);
	virtual ~MotorState();
	virtual MotorState* acceptEvent(Signal s);
	virtual bool onEntry();
	virtual bool onExit();
};

#endif /* MOTORSTATE_H_ */
