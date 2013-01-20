/*
 * HardwareInput.h
 *
 *  Created on: Jan 14, 2013
 *      Author: aji9861
 */

#ifndef HARDWAREINPUT_H_
#define HARDWAREINPUT_H_

#include "InputInterface.h"
#include "ControllerStateMachine.h"

#include <stdint.h>
#include <sys/mman.h>
#include <sys/neutrino.h>


class HardwareInput: public InputInterface {
	ControllerStateMachine *csm;
	uintptr_t ctrlHandle;
	uint8_t curValues;

public:
	HardwareInput(ControllerStateMachine *machine);
	void readInput();
	void sendCsm(StateSignal s);
	uintptr_t getCtrlHandle();
	uint8_t getCurValues();
	void setCurValues(uint8_t v);

};

#endif /* HARDWAREINPUT_H_ */