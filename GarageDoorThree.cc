/*
 * main.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <sys/neutrino.h>


#include "ControllerStateMachine.h"
#include "InputInterface.h"
#include "ManualInput.h"
#include "HardwareInput.h"


#define SIMULATED false

using namespace std;

ManualInput* runSimulated(ControllerStateMachine *machine){
	return new ManualInput(machine);
}

HardwareInput* runHardware(ControllerStateMachine *machine){
	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
		perror("Failed to get I/O access permission");
		return NULL;
	}

	return new HardwareInput(machine);

}


int main(int argc, char *argv[]) {

	bool simulated = SIMULATED;
	ControllerStateMachine *csm = new ControllerStateMachine;
	InputInterface *input;
	if (simulated){
		input = runSimulated(csm);
	} else{
		input = runHardware(csm);
	}
	if (input == NULL){
		return 1;
	}
	input->readInput();

	cout << "End simulation" << endl;

	return EXIT_SUCCESS;
}


