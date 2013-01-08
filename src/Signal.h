/*
 * Signal.h
 *
 *  Created on: Dec 19, 2012
 *      Author: adam
 */

#ifndef SIGNAL_H_
#define SIGNAL_H_

enum Signal {
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

#endif /* SIGNAL_H_ */
