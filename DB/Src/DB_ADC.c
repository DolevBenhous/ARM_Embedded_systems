/*
 * DB_ADC.c
 *
 *  Created on: Nov 23, 2022
 *      Author: dolev
 */

/****************************************
 *
 * Connect 3.3V to ADC
 * 3.3V -- CN8     - White
 * ADC PA0 -- CN10 - White
 *
 **********************************************/

#include "DB_SERVER.h"
#include "TEST.h"
#include "DB_ADC.h"

int flag_adc = 0; 			//flag for ADC Interrupt
double currentVoltage = 0;
uint32_t currentValue = 0;

/**
  * @brief In this method we will check the voltage in 3.3V port.
  * We use "ADC1" port to test this action.
  * @param  uint8_t iteration counter.
  * @retval uint8_t status check.
  */
uint8_t DB_ADC(uint8_t main_iter){
	printf("Start test of ADC:\r\n");
	while (main_iter)
	{
		if(HAL_ADC_Start_IT(ADC_1)!= HAL_OK)				// start interrupt for ADC1 , jump to callback
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		if (flag_adc)
		{
			currentValue =  HAL_ADC_GetValue(ADC_1);								// get value from 3.3V port.
			currentVoltage = ((double)currentValue/ADC_TO_VOLT_FACTOR);				// convert value to VOLTAGE
			if (!(BOTTOM_BOUND < currentVoltage && currentVoltage < TOP_BOUND))		// check if the range of Voltage is okay.
			{
				return FAILURE;
			}
			main_iter --;
			flag_adc = RESET;															// reset ADC flag interrupt
		}
	}
	printf("ADC_WORKS_GOOD\r\n");
    printf("---------------------\r\n");
	return SUCCESS;
}

// ADC interrupt Callback (notify that data conversion is finished)
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	flag_adc = SET;		// go through the loop.
}

