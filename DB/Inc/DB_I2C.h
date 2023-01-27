/*
 * DB_I2C.h
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

#ifndef INC_DB_I2C_H_
#define INC_DB_I2C_H_

#include "DB_SERVER.h"
#include "TEST.h"
#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern UART_HandleTypeDef huart3;
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

#define UART_DEBUG &huart3
#define I2C_MASTER &hi2c1
#define I2C_SLAVE &hi2c2
#define SLAVE_ADDRESS hi2c2.Init.OwnAddress1

uint8_t DB_I2C(uint8_t mainIter, uint8_t length, char * stringToCheck);

#endif /* INC_DB_I2C_H_ */
