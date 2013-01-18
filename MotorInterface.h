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
	MotorInterface();
	virtual ~MotorInterface();
	virtual void addListenerEvent(StateSignal s);
	virtual void startMotor();
	virtual bool isRunning();
	virtual void checkMotor();
	virtual void incTimer();
	virtual void decTimer();
	virtual int getTimer();
	virtual void setController(ControllerStateMachine* controller);
	virtual void sendControlSignal(StateSignal s);
};

#endif /* MOTORINTERFACE_H_ */
