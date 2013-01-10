/*
 * ManualInput.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: adam
 */

#include "ManualInput.h"	//used for input
#include "StateSignal.h"	//used to pass signals
#include <iostream>			//used for output
#include <pthread.h>		//used for pthreads
using namespace std;		//used for output

ManualInput::ManualInput(ControllerStateMachine *machine){
	/* contructor
	 */
	csm = machine;
}

void* getInput(void* csm){
	/* used to get input
	 */
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
	/* starts up pthreads
	 */
	pthread_t input_t;

	pthread_create(&input_t, NULL, getInput, csm);

	pthread_join(input_t, NULL);

}
