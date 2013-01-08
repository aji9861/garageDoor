/*
 * main.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include <cstdlib>
#include <iostream>
#include <pthread.h>

#include "ControllerStateMachine.h"
#include "InputInterface.h"
#include "ManualInput.h"


using namespace std;

int main(int argc, char *argv[]) {
	ControllerStateMachine *csm = new ControllerStateMachine;
	InputInterface *input = new ManualInput(csm);

	input->readInput();

	/*for (int i = 0; i < 10; i++){
		csm->addListenerEvent(btn_push);
		sleep(1);

	}*/
	cout << "End simulation" << endl;

	return EXIT_SUCCESS;
}
