/*
 * DB_TIMER.h
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

#ifndef INC_DB_TIMER_H_
#define INC_DB_TIMER_H_

#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim3;

#define UART_DEBUG &huart3
#define TIM_3 &htim3

#define GPIO_PER_1 GPIOB
#define GPIO_PER_2 GPIOB
#define GPIO_PER_3 GPIOB
#define GPIO_LED_1 LD1_Pin
#define GPIO_LED_2 LD2_Pin
#define GPIO_LED_3 LD3_Pin

uint8_t DB_TIME(uint8_t mainIter);

#endif /* INC_DB_TIMER_H_ */
