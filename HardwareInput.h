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

class HardwareInput: public InputInterface {
	ControllerStateMachine *csm;
public:
	HardwareInput(ControllerStateMachine *machine);
	void readInput();
};

#endif /* HARDWAREINPUT_H_ */
