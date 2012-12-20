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

State* State::acceptEvent(Signal s){
	return this;
}

bool State::onExit(){
	return true;
}

bool State::onEntry(){
	return true;
}

