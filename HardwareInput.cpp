/*
 * HardwareInput.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: aji9861
 */

#include "HardwareInput.h"
#include "StateSignal.h"

#include <iostream>
#include <pthread.h>
#include <hw/inout.h>
#include "Constants.h"
#include <unistd.h>


using namespace std;

HardwareInput::HardwareInput(ControllerStateMachine *machine) {
	csm = machine;

	if ( ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
			perror("Failed to get I/O access permission");
	}

	ctrlHandle = mmap_device_io(IO_PORT_SIZE, CTRL_ADDRESS);
	if(ctrlHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}

	out8((ctrlHandle + DIGITAL_REG), INIT_CTRL_REG);
	curValues = in8((ctrlHandle + DIO_B));
}

void* getBoardInput(void *obj){
	HardwareInput *self = (HardwareInput* )obj;
	while(true){
		uint8_t curValues = self->getCurValues();
		uint8_t newValues = in8((self->getCtrlHandle() + DIO_B));
		uint8_t changed = curValues ^ newValues;

		if(changed)
			printf("Changed: %X\nNewValues:%X\n", changed);

		if (changed & 0x01 && newValues & 0x01){
			/* Door has reached full open */
			self->sendCsm(door_open);
			cout << "door open" << endl;
		}

		if (changed & 0x02 && newValues & 0x02){
			/* Door has reached full closed */
			self->sendCsm(door_closed);
			cout << "door closed" << endl;
		}

		if (changed & 0x04 && newValues & 0x04){
			/* IR Beam is now broken */
			self->sendCsm(beam_interupt);
			cout << "beam broken" << endl;
		}

		if (changed & 0x08 && newValues * 0x08){
			/* Overcurrent has occurred */
			self->sendCsm(motor_overcurrent);
			cout << "overcurrent" << endl;
		}

		if (changed & 0x10 && newValues & 0x10){
			/* Bit 4 has changed - Remote push button */
			self->sendCsm(btn_push);
			cout << "btn push" << endl;
		}
		self->setCurValues(newValues);
		usleep(10000);

	}

	return NULL;
}

void HardwareInput::readInput(){
	pthread_t input_t;

	pthread_create(&input_t, NULL, getBoardInput, this);

	pthread_join(input_t, NULL);
}

void HardwareInput::sendCsm(StateSignal s){
	csm->addListenerEvent(s);
}
uintptr_t HardwareInput::getCtrlHandle(){
	return ctrlHandle;
}
uint8_t HardwareInput::getCurValues(){
	return curValues;
}

void HardwareInput::setCurValues(uint8_t v){
	curValues = v;
}

