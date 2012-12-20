/*
 * main.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include "ControllerStateMachine.h"

#include <iostream>
#include <pthread.h>

using namespace std;

int main(){
	ControllerStateMachine *csm = new ControllerStateMachine;
	for (int i = 0; i < 10; i++){
		csm->addListenerEvent(btn_push);
		sleep(1);

	}
	cout << "End simulation" << endl;

	return 0;
}
