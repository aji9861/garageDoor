/*
 * HardwareMotor.cpp
 *
 *  Created on: Jan 16, 2013
 *      Author: aji9861
 */

#include "HardwareMotor.h"

#include <iostream>
#include <hw/inout.h>
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

	int result = pthread_mutex_init(&motorMutex, NULL);
	if (result != 0){
		printf("Mutex error: %d\n", result);
	}


	out8((ctrlHandle + DIO_A), 0x00);
	usleep(100000);
	out8((ctrlHandle + DIO_A), 0x08);

	startMotor();
}

HardwareMotor::~HardwareMotor() {
	pthread_mutex_destroy(&motorMutex);
}
void HardwareMotor::setController(ControllerStateMachine* controller){
	csm = controller;
}

void HardwareMotor::addListenerEvent(StateSignal s){
	if(s != no_signal){
		pthread_mutex_lock(&motorMutex);
		motorQueue.push_back(s);
		pthread_mutex_unlock(&motorMutex);
	}
}

void* runHardwareMotor(void* motor){
	while (true){
		((HardwareMotor *) motor)->checkMotor();
		usleep(50);
	}
	return NULL;

}

void HardwareMotor::startMotor(){
	pthread_t motor_t;
	pthread_create(&motor_t, NULL, runHardwareMotor, this);
}

void HardwareMotor::checkMotor(){
//	printf("Outside lock\n");
	pthread_mutex_lock(&motorMutex);
//	printf("inside lock\n");
	if(!motorQueue.empty()){
		StateSignal s = motorQueue.front();

		uint8_t current;
		if(s == motor_up_active){
			current = in8((ctrlHandle + DIO_A));
			out8((ctrlHandle + DIO_A), (current | 0x01));
		}else if(s == motor_up_inactive){
			current = in8((ctrlHandle + DIO_A));
			out8((ctrlHandle + DIO_A), (current & 0xFE));
		}else if(s == motor_down_active){
			/* Turn on beam and lower motor */
//			current = in8((ctrlHandle + DIO_A));
//			out8((ctrlHandle + DIO_A), (current | 0x06));

			/* turn on beam */
			current = in8((ctrlHandle + DIO_A));
			out8((ctrlHandle + DIO_A), (current | 0x04));
			usleep(50);
			/* lower motor */
			current = in8((ctrlHandle + DIO_A));
			out8((ctrlHandle + DIO_A), (current | 0x02));
		}else if(s == motor_down_inactive){
			/* Stop motor and turn off beam */
//			current = in8((ctrlHandle + DIO_A));
//			out8((ctrlHandle + DIO_A), (current & 0xF9));

			/* stop motor */
			current = in8((ctrlHandle + DIO_A));
			out8((ctrlHandle + DIO_A), (current & 0xFD));
			usleep(50);
			/* turn off beam */
			current = in8((ctrlHandle + DIO_A));
			out8((ctrlHandle + DIO_A), (current & 0xFB));
		}
//		printf("Current: %X\n", current);
		motorQueue.pop_front();
	}
	pthread_mutex_unlock(&motorMutex);
//	printf("lock released\n");


}

void HardwareMotor::sendControlSignal(StateSignal s){
	csm->addListenerEvent(s);
}
