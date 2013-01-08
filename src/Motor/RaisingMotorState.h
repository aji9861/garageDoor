/*
 * RaisingMotorState.h
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#ifndef RAISINGMOTORSTATE_H_
#define RAISINGMOTORSTATE_H_

#include "MotorState.h"

class RaisingMotorState: public MotorState {
public:
	MotorState* acceptEvent(Signal s);
	bool onEntry();
	bool onExit();
};
#endif /* RAISINGMOTORSTATE_H_ */
