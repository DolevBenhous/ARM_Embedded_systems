/*
 * DB_ADC.h
 *
 *  Created on: Nov 23, 2022
 *      Author: dolev
 *
 */

#ifndef INC_DB_ADC_H_
#define INC_DB_ADC_H_

#include "DB_SERVER.h"
#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern UART_HandleTypeDef huart3;
extern ADC_HandleTypeDef hadc1;

#define UART_DEBUG &huart3
#define ADC_1 &hadc1

#define TOP_BOUND 		   	3.5
#define BOTTOM_BOUND 	   	3.0
#define ADC_TO_VOLT_FACTOR 	1241.212

uint8_t DB_ADC(uint8_t mainIter);

#endif /* INC_DB_ADC_H_ */
