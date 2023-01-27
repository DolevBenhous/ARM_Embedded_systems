/*
 * DB_UART.h
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

#ifndef INC_DB_UART_H_
#define INC_DB_UART_H_

#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>

extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart6;

#define UART_DEBUG &huart3
#define SLAVE_UART_6 &huart6
#define MASTER_UART_4 &huart4

uint8_t DB_UART(uint8_t mainIter, uint8_t length, char * stringToCheck);

#endif /* INC_DB_UART_H_ */
