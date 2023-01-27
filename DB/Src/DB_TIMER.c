/*
 * DB_TIMER.c
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

#include "DB_SERVER.h"
#include "TEST.h"
#include "DB_TIMER.h"
uint16_t timer_val;
ITStatus flag_timer;

uint8_t DB_TIME(uint8_t main_iter)
{
	 // Start timer
	flag_timer = RESET;
	HAL_TIM_Base_Start_IT(TIM_3);				// TIMER 3 starts count
	while (main_iter)
	{
		while (!flag_timer){}
		main_iter --;
		flag_timer = RESET;
	}
	HAL_TIM_Base_Stop_IT(TIM_3);				//// TIMER 3 stop at the end of test
	return SUCCESS;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
// Check which version of the timer triggered this callback and toggle LED
	if (htim == TIM_3)
		{
		  HAL_GPIO_TogglePin(GPIO_PER_1, GPIO_LED_1);
		  HAL_GPIO_TogglePin(GPIO_PER_2, GPIO_LED_2);
		  HAL_GPIO_TogglePin(GPIO_PER_3, GPIO_LED_3);
		  flag_timer = SET;
		}
}
