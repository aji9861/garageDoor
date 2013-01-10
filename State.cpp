/*
 * State.cpp
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#include "State.h"	//used for inheritance

State::State(){
	//constructor
}

State::~State() {
	//delete(this);
}

State* State::acceptEvent(StateSignal s){
	/* method for accepting signals, may change state 
	 */
	return this;
}

StateSignal State::onExit(){
	/* called on exit from state
	 */
	return no_signal;
}

StateSignal State::onEntry(){
	/* called on entry to state
	 */
	return no_signal;
}

