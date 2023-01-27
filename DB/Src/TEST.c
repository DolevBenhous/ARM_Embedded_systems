/*
 * RTG.c
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

#include "DB_SERVER.h"
#include "TEST.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
  * @brief In this method we will select on the relevant test.
  * We insert to the chosen one all the data that we received from client.
  * @param  uint8_t protocol to check.
  * @param  uint8_t iteration counter.
  * @param  uint8_t length of string received from client.
  * @param  char* string that client sent to use in protocol test.
  * @retval uint8_t status check.
  */
uint8_t test(uint8_t main_iter, uint8_t per_to_check, uint8_t length, char * string_to_check)
{
	uint8_t status = 0;
	if(!(per_to_check == TIMER || per_to_check == UART || per_to_check == SPI || per_to_check == I2C
							   || per_to_check == ADC33||per_to_check == WRONG_PACK_SIZE))
	{
		printf("WRONG PERIPHERIAL\r\n");
		return FAILURE;
	}
	if(main_iter > 255)
	{
		main_iter %= 255;
	}
	switch(per_to_check)
	{
		case TIMER:
			status = DB_TIME(main_iter);
			break;
		case UART:
			status = DB_UART(main_iter, length, string_to_check);
			break;
		case SPI:
			status = DB_SPI(main_iter, length, string_to_check);
			break;
		case I2C:
			status = DB_I2C(main_iter, length, string_to_check);
			break;
		case ADC33:
			status = DB_ADC(main_iter);
			break;
		case WRONG_PACK_SIZE:
			status = FAILURE;
		default:
			printf ("chose different per\r\n");
	}
	return status;
}

