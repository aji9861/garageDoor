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

#include <stdint.h>
#include <sys/mman.h>
#include <sys/neutrino.h>

#define IO_PORT_SIZE 1
#define CTRL_ADDRESS 0x37A

#define MOTOR_UP_PORT in6
#define INIT_BIT 0x04


using namespace std;

HardwareInput::HardwareInput(ControllerStateMachine *machine) {
	csm = machine;

}

void HardwareInput::readInput(){
	uintptr_t ctrlHandle;

	ctrlHandle = mmap_device_io(IO_PORT_SIZE, CTRL_ADDRESS);
	if(ctrlHandle == MAP_DEVICE_FAILED){
		perror("Failed to map control register");
	}

	out8(ctrlHandle, INIT_BIT);

}
