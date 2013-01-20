/*
 * StateSignal.h
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#ifndef STATESIGNAL_H_
#define STATESIGNAL_H_

/*
 * The signal used in both the state machine and the motor.
 * Previous name changed from Signal.h due to name space conflicts 
 */
enum StateSignal {
	btn_push,
	motor_overcurrent,
	beam_interupt,
	door_open,
	door_closed,
	motor_up_active,
	motor_up_inactive,
	motor_down_active,
	motor_down_inactive,
	no_signal,
};

#endif /* STATESIGNAL_H_ */
