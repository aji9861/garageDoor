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

void HardwareInput::readInput(){
	uint8_t newValues = in8((ctrlHandle + DIO_B));


}
