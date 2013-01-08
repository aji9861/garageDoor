/*
 * LoweringMotorState.h
 *
 *  Created on: Jan 8, 2013
 *      Author: wkb6223
 */

#ifndef LOWERINGMOTORSTATE_H_
#define LOWERINGMOTORSTATE_H_

#include "MotorState.h"

class LoweringMotorState: public MotorState {
public:
	MotorState* acceptEvent(Signal s);
	bool onEntry();
	bool onExit();
};

#endif /* LOWERINGMOTORSTATE_H_ */
