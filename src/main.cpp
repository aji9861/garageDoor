/*
 * main.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include <iostream>
#include "ControllerStateMachine.h"

using namespace std;

int main(){
	ControllerStateMachine *csm = new ControllerStateMachine;
	csm->addListenerEvent(btn_push);
	//cout << csm->curState << endl;

	cout << "Hello" << endl;

	return 0;
}
