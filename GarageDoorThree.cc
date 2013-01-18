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


int main(int argc, char *argv[]) {
	bool simulated = (argc > 1 && strcmp(argv[1], "-s") == 0);
	if (simulated){
		cout << "Running Simulated" << endl;
	}
	else{
		cout << "Running on hardware" << endl;
	}

	ControllerStateMachine *csm = new ControllerStateMachine(simulated);
	InputInterface *input;
	if (simulated){
		input = new ManualInput(csm);
	} else{
		input = new HardwareInput(csm);
	}
	if (input == NULL){
		return 1;
	}



	input->readInput();

//	sleep(5);

	cout << "End simulation" << endl;

	return EXIT_SUCCESS;
}


