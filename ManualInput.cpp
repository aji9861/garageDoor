/*
 * ManualInput.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: adam
 */

#include "ManualInput.h"
#include "StateSignal.h"

#include <iostream>
#include <pthread.h>
using namespace std;

ManualInput::ManualInput(ControllerStateMachine *machine){
	csm = machine;
}


void* getKeyInput(void* csm){
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

	return NULL;
}


void ManualInput::readInput(){
	pthread_t input_t;

	pthread_create(&input_t, NULL, getKeyInput, csm);

	pthread_join(input_t, NULL);

}
