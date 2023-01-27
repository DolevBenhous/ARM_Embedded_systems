/*
 * DB_SPI.h
 *
 *  Created on: Nov 22, 2022
 *      Author: dolev
 */

#ifndef INC_DB_SPI_H_
#define INC_DB_SPI_H_

#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern UART_HandleTypeDef huart3;
extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi4;

#define UART_DEBUG &huart3
#define SPI_1 &hspi1
#define SPI_4 &hspi4

#define SPI_MASTER &hspi1
#define SPI_SLAVE &hspi4

uint8_t DB_SPI(uint8_t mainIter, uint8_t length, char * stringToCheck);

#endif /* INC_DB_SPI_H_ */
