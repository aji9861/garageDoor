/*
 * HardwareMotor.h
 *
 *  Created on: Jan 16, 2013
 *      Author: aji9861
 */

#ifndef HARDWAREMOTOR_H_
#define HARDWAREMOTOR_H_

#include "MotorInterface.h"
#include "ControllerStateMachine.h"

#include <list>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <pthread.h>


class HardwareMotor: public MotorInterface {
  /* reference to the controller */
	ControllerStateMachine *csm;
	/* memory address of the purple box */
	uintptr_t ctrlHandle;
	/* queue of signals that need to be sent to the purplebox */
	std::list<StateSignal> motorQueue;
	/* mutex controlling access to the signal queue */
	pthread_mutex_t motorMutex;

public:
  /* constructor */
	HardwareMotor();
	/* deconstructor */
	virtual ~HardwareMotor();
	/* add signals to the motors queue */
	void addListenerEvent(StateSignal s);
	/* sets the reference for the controller */
	void setController(ControllerStateMachine *controller);
	/* send a signal to the controller */
	void sendControlSignal(StateSignal s); 
	/* start the motor */
	void startMotor();
	/* check the motors queue for signals */
	void checkMotor();
};

#endif /* HARDWAREMOTOR_H_ */
