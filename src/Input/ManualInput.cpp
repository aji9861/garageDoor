/*
 * ManualInput.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: adam
 */

#include "ManualInput.h"
#include "../Signal.h"

#include <iostream>
#include <pthread.h>
using namespace std;

ManualInput::ManualInput(ControllerStateMachine *machine){
	csm = machine;
}


void* getInput(void* csm){
	char in;
	while(!cin.eof()){
		cin.get(in);
		if (in == 'r'){
			((ControllerStateMachine *) csm)->addListenerEvent(btn_push);
		}
		else if (in == 'm'){
			((ControllerStateMachine *) csm)->addListenerEvent(motor_overcurrent);
		}
		else if (in == 'i'){
			((ControllerStateMachine *) csm)->addListenerEvent(beam_interupt);
		}
	}

}


void ManualInput::readInput(){
	pthread_t input_t;

	int buttonThread = pthread_create(&input_t, NULL,
			getInput, csm);

	pthread_join(input_t, NULL);

}
