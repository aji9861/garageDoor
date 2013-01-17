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
#include <unistd.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "ControllerStateMachine.h"
#include "InputInterface.h"
#include "ManualInput.h"
#include "HardwareInput.h"

using namespace std;

ManualInput* runSimulated(ControllerStateMachine *machine){
	return new ManualInput(machine);
}

HardwareInput* runHardware(ControllerStateMachine *machine){
	return new HardwareInput(machine);
}


int main(int argc, char *argv[]) {
	bool simulated = false;
	//bool simulated = (argc > 1 && argv[1] == "-s");// TODO: Make this flag check work
	if (simulated){
		cout << "Running Simulated" << endl;
	}
	else{
		cout << "Running on hardware" << endl;
	}

	ControllerStateMachine *csm = new ControllerStateMachine(simulated);
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

//	sleep(5);

	cout << "End simulation" << endl;

	return EXIT_SUCCESS;
}


