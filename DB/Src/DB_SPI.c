/*
 * DB_SPI.c
 *
 *  Created on: Nov 22, 2022
 *      Author: dolev
 */

/****************************************
 *
 * SPI1 (MASTER)
 * PA5 	SCK   (CN7)  - Brown
 * PA6 	MISO  (CN7)  - Green
 * PB5 	MOSI  (CN7)  - Red
 *
 * SPI4 (SLAVE):
 * PE2 	SCK   (CN10) - Brown
 * PE5  MISO  (CN9)  - Green
 * PE6  MOSI  (CN9)  - Red
 *
 **********************************************/

#include "DB_SERVER.h"
#include "TEST.h"
#include "DB_SPI.h"

ITStatus flag_spi;
uint8_t SPI_SLAVE_BUFF[MAX_SIZE_OF_STRING]  = {0};
uint8_t SPI_MASTER_BUFF[MAX_SIZE_OF_STRING] = {0};
/**
  * @brief In this method we will check SPI protocol.
  * We use SPI_1 and SPI_4 ports to test this action.
  * @param  uint8_t iteration counter.
  * @param  uint8_t length of string received from client.
  * @param  char* string that client sent to use in protocol test.
  * @retval uint8_t status check.
  */
uint8_t DB_SPI(uint8_t main_iter, uint8_t length, char * string_to_check)
{
	printf("Start test of SPI protocol:\r\n");
	while (main_iter --)
	{
		flag_spi = RESET;
		// SLAVE is ready to get data to SLAVE_BUFF and transmit SLAVE_BUFF to MASTER.
		if (HAL_SPI_TransmitReceive_DMA(SPI_SLAVE, SPI_SLAVE_BUFF, SPI_SLAVE_BUFF, length) != HAL_OK)
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		// MASTER transmit the string from client to SLAVE_BUFF and receive empty SLAVE_BUFF to MASTER_BUFF.
		if (HAL_SPI_TransmitReceive_DMA(SPI_MASTER, (uint8_t *)string_to_check, SPI_MASTER_BUFF,  length) != HAL_OK)
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		while(flag_spi != SET){;}
		flag_spi = RESET;

		// SLAVE transmit his buffer to MASTER_BUFF and ready to receive MASTER_BUFF to SLAVE_BUFF.
		if (HAL_SPI_TransmitReceive_DMA(SPI_SLAVE, SPI_SLAVE_BUFF, SPI_SLAVE_BUFF, length) != HAL_OK)
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		// MASTER receive SLAVE_BUFF to MASTER_BUFF and transmit empty MASTER_BUFF to SLAVE_BUFF.
		if (HAL_SPI_TransmitReceive_DMA(SPI_MASTER, SPI_MASTER_BUFF, SPI_MASTER_BUFF,  length) != HAL_OK)
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		while(flag_spi != SET){;}

		if(memcmp(string_to_check, SPI_MASTER_BUFF,length)!= 0)
		// check that string at the end of 'SPI' is the same as the string at the beginning.
		{
			return FAILURE;
		}
	}
	printf("SPI_WORKS_GOOD\r\n");
    printf("---------------------\r\n");
	return SUCCESS;
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if(hspi == SPI_MASTER)
	{
		flag_spi = SET;
	}
}
