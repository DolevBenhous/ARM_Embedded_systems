/*
 * DB_UART.c
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

/****************************************
 * UART4:
 * 	UART4_TX PC10 (CN8)  - Black
 * 	UART4_RX PC11 (CN8)  - Orange
 *
 * USART6:
 *  UART2_TX PG14 (CN10) - Orange
 *  UART2_RX PG9  (CN10) - Black
 *
 **********************************************/

#include "DB_SERVER.h"
#include "TEST.h"
#include "DB_UART.h"

ITStatus flag_uart;
uint8_t U6_SLAVE_BUFF[MAX_SIZE_OF_STRING] = {0};
uint8_t U4_MASTER_BUFF[MAX_SIZE_OF_STRING] = {0};
/**
  * @brief In this method we will check UART protocol.
  * We use UART4 and UART6 ports to test this action.
  * @param  uint8_t iteration counter.
  * @param  uint8_t length of string received from client.
  * @param  char* string that client sent to use in protocol test.
  * @retval uint8_t status check.
  */
uint8_t DB_UART(uint8_t main_iter, uint8_t length, char * string_to_check)
{
	printf("Start test of UART protocol:\r\n");
	while(main_iter --)
	{
		flag_uart = RESET;
		if(HAL_UART_Receive_DMA(SLAVE_UART_6, U6_SLAVE_BUFF , length) != HAL_OK)// UART6 ready to receive data from UART4.
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		if(HAL_UART_Transmit_DMA(MASTER_UART_4, (uint8_t *)string_to_check, length) != HAL_OK)// UART4 transmit the data from client to UART6.
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		while (flag_uart != SET){;}
		flag_uart = RESET;

		if(HAL_UART_Receive_DMA(MASTER_UART_4, U4_MASTER_BUFF , length) != HAL_OK)	// UART4 receive data from UART6.
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		if(HAL_UART_Transmit_DMA(SLAVE_UART_6, U6_SLAVE_BUFF, length) != HAL_OK)	// UART6 transmit back his buffer to UART4.
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		HAL_Delay(50);
		if(memcmp(string_to_check, U4_MASTER_BUFF,length)!= 0)
		// check that string at the end of 'UART' is the same as the string at the beginning.
		{
			return FAILURE;
		}
	}
	printf("UART_WORKS_GOOD\r\n");
    printf("---------------------\r\n");
	return SUCCESS;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) // check if SLAVE complete transmission
{
	if(huart == SLAVE_UART_6){
		flag_uart = SET;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)	// check if SLAVE complete receiving
{
	if(huart==SLAVE_UART_6){
		flag_uart = SET;
	}
}
