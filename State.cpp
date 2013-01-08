/*
 * State.cpp
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#include "State.h"

State::State(){

}

State::~State() {
	//delete(this);
}

State* State::acceptEvent(StateSignal s){
	return this;
}

StateSignal State::onExit(){
	return no_signal;
}

StateSignal State::onEntry(){
	return no_signal;
}

