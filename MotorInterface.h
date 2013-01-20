/*
 * MotorInterface.h
 *
 *  Created on: Jan 16, 2013
 *      Author: aji9861
 */

#ifndef MOTORINTERFACE_H_
#define MOTORINTERFACE_H_

#include "StateSignal.h"
#include "ControllerStateMachine.h"

class ControllerStateMachine;

class MotorInterface {
public:
  /* constructor */
	MotorInterface();
	/* deconstructor */
	virtual ~MotorInterface();
	/* adding signals to the motor for possible state changes */
	virtual void addListenerEvent(StateSignal s);
	/* starts the thread watching the motor */
	virtual void startMotor();
	/* checks if the motor has started */
	virtual bool isRunning();
	/* check the queue for signals */
	virtual void checkMotor();
	/* timer ++ for door position */
	virtual void incTimer();
	/* timer -- for door position */
	virtual void decTimer();
	/* get the timer for the door position */
	virtual int getTimer();
	/* sets the controller to send signals */
	virtual void setController(ControllerStateMachine* controller);
	/* sends a signal to the controller ie. overcurrent */
	virtual void sendControlSignal(StateSignal s);
};

#endif /* MOTORINTERFACE_H_ */
