/*
 * HardwareMotor.cpp
 *
 *  Created on: Jan 16, 2013
 *      Author: aji9861
 */

#include "HardwareMotor.h"

#include <iostream>
#include <hw/inout.h>
#include <pthread.h>
#include "Constants.h"
#include <unistd.h>

using namespace std;

HardwareMotor::HardwareMotor() {
	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
		perror("Failed to get I/O access permission");
	}

	ctrlHandle = mmap_device_io(IO_PORT_SIZE, CTRL_ADDRESS);
	if(ctrlHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}

	out8((ctrlHandle + DIO_A), 0x00);
	usleep(100000);
	out8((ctrlHandle + DIO_A), 0x08);
}

HardwareMotor::~HardwareMotor() {
	// TODO Auto-generated destructor stub
}
void HardwareMotor::setController(ControllerStateMachine* controller){
	csm = controller;
}

void HardwareMotor::addListenerEvent(StateSignal s){
	uint8_t current;
	if(s == motor_up_active){
		current = in8((ctrlHandle + DIO_A));
		out8((ctrlHandle + DIO_A), (current | 0x01));
	}else if(s == motor_up_inactive){
		current = in8((ctrlHandle + DIO_A));
		out8((ctrlHandle + DIO_A), (current & 0xFE));
	}else if(s == motor_down_active){
		/* Turn on beam and lower motor */
		//current = in8((ctrlHandle + DIO_A));
		//out8((ctrlHandle + DIO_A), (current | 0x06));

		/* turn on beam */
		current = in8((ctrlHandle + DIO_A));
		out8((ctrlHandle + DIO_A), (current | 0x04));
		usleep(50);
		/* lower motor */
		current = in8((ctrlHandle + DIO_A));
		out8((ctrlHandle + DIO_A), (current | 0x02));
	}else if(s == motor_down_inactive){
		/* Stop motor and turn off beam */
		//current = in8((ctrlHandle + DIO_A));
		//out8((ctrlHandle + DIO_A), (current & 0xF9));

		/* stop motor */
		current = in8((ctrlHandle + DIO_A));
		out8((ctrlHandle + DIO_A), (current & 0xFD));
		usleep(50);
		/* turn off beam */
		current = in8((ctrlHandle + DIO_A));
		out8((ctrlHandle + DIO_A), (current & 0xFB));
	}
	printf("Current: %X\n", current);


}

void HardwareMotor::sendControlSignal(StateSignal s){
	csm->addListenerEvent(s);
}
