/*
 * RTG.h
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */
#ifndef INC_TEST_H_
#define INC_TEST_H_

#include "DB_SERVER.h"
#include "usart.h"
#include "lwip.h"
#include "DB_UART.h"
#include "DB_I2C.h"
#include "DB_ADC.h"
#include "DB_SPI.h"
#include "DB_TIMER.h"

#define FAILURE 255
#define SUCCESS 1
					//power of 2:
#define TIMER 1  	//0
#define UART  2   	//1
#define SPI   4    	//2
#define I2C   8    	//3
#define ADC33 16 	//4
#define WRONG_PACK_SIZE 66

uint8_t test(uint8_t mainIter, uint8_t per, uint8_t length, char * stringToCheck);

#endif /* INC_TEST_H_ */
