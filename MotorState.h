/*
 * MotorState.h
 *
 *  Created on: Jan 7, 2012
 *      Author: wkb6223
 */

#ifndef MOTORSTATE_H_
#define MOTORSTATE_H_

#include "StateSignal.h"
#include "MotorStateMachine.h"

class MotorStateMachine;

class MotorState {
protected:
  /* reference to the motorStateMachine */
	MotorStateMachine *msm;
public:
  /* constructor */
	MotorState(MotorStateMachine *machine);
	/* deconstructor */
	virtual ~MotorState();
	/* accept signals to see if a state change is needed */
	virtual MotorState* acceptEvent(StateSignal s);
	/* method called when the state is entered */
	virtual bool onEntry();
	/*method called when the state is left */
	virtual bool onExit();
};

#endif /* MOTORSTATE_H_ */
