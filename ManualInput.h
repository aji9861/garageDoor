/*
 * ManualInput.h
 *
 *  Created on: Jan 6, 2013
 *      Author: adam
 */

#ifndef MANUALINPUT_H_
#define MANUALINPUT_H_

#include "InputInterface.h"
#include "ControllerStateMachine.h"

class ManualInput: public InputInterface {
	ControllerStateMachine *csm;
public:
	ManualInput(ControllerStateMachine *csm);
	void readInput();
private:


};

#endif /* MANUALINPUT_H_ */
