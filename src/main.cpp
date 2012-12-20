/*
 * main.cpp
 *
 *  Created on: Dec 20, 2012
 *      Author: adam
 */

#include <iostream>
#include "State.h"
#include "DoorClosed.h"

using namespace std;

int main(){
	State *s = new DoorClosed;
	delete(s);
	cout << "Hello" << endl;

	return 1;
}
