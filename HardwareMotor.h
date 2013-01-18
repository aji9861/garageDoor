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

#include <stdint.h>
#include <sys/mman.h>
#include <sys/neutrino.h>


class HardwareMotor: public MotorInterface {
	ControllerStateMachine *csm;
	uintptr_t ctrlHandle;
public:
	HardwareMotor();
	virtual ~HardwareMotor();
	void addListenerEvent(StateSignal s);
	void setController(ControllerStateMachine *controller);
	void sendControlSignal(StateSignal s);
};

#endif /* HARDWAREMOTOR_H_ */
