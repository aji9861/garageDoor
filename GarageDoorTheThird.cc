/*
 * main.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include <cstdlib>					//used for input
#include <iostream>					//used for output
#include <pthread.h>				//used for pthreads

#include "ControllerStateMachine.h"	//used to launch the state machine
#include "InputInterface.h"			//used for input
#include "ManualInput.h"			//used for input

using namespace std;				//used for output

int main(int argc, char *argv[]) {
	/* main method */
	ControllerStateMachine *csm = new ControllerStateMachine;
	InputInterface *input = new ManualInput(csm);

	input->readInput();
	cout << "End simulation" << endl;

	return EXIT_SUCCESS;
}
