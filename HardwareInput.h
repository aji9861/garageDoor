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
  /* reference to the controller */
	ControllerStateMachine *csm;
	/* reference to purplebox memory */
	uintptr_t ctrlHandle;
	/* current vlaues of outputs from purplebox */
	uint8_t curValues;

public:
  /* constructor */
	HardwareInput(ControllerStateMachine *machine);
	/* see InputInterface */
	void readInput();
	/* sends a signal to the controller */
	void sendCsm(StateSignal s);
	/* set the memory location of the purplebox */
	uintptr_t getCtrlHandle();
	/* get the outputs from the purplebox */
	uint8_t getCurValues();
	/* set the input values to the purplebox */
	void setCurValues(uint8_t v);

};

#endif /* HARDWAREINPUT_H_ */
