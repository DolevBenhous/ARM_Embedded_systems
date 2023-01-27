/*
 * DB_I2C.c
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

/****************************************
 *
 * I2C1 (Master):
 * 	I2C1_SCL PB6   (CN10) - Yellow
 * 	I2C1_SDA PB9   (CN10) - Blue

 * I2C2 (Slave):
 *  I2C2_SCL PB10  (CN10) - Yellow
 *  I2C2_SDA PB11  (CN10) - Blue
 *  Slave address: 154 (77)
 *
 **********************************************/

#include "DB_SERVER.h"
#include "TEST.h"
#include "DB_I2C.h"

ITStatus flag_i2c; 			//flag for I2C callback
uint8_t I2C_SLAVE_BUFF[MAX_SIZE_OF_STRING] = {0};
uint8_t I2C_MASTER_BUFF[MAX_SIZE_OF_STRING] = {0};

/**
  * @brief In this method we will check I2C protocol.
  * We use I2C_1 and I2C_2 ports to test this action.
  * @param  uint8_t iteration counter.
  * @param  uint8_t length of string received from client.
  * @param  char* string that client sent to use in protocol test.
  * @retval uint8_t status check.
  */
uint8_t DB_I2C(uint8_t main_iter, uint8_t length, char * string_to_check)
{
	printf("Start test of I2C protocol:\r\n");
	while (main_iter --)
	{
		flag_i2c = RESET;
		// I2C_SLAVE is ready to receive data from I2C_MASTER.
		if (HAL_I2C_Slave_Receive_DMA(I2C_SLAVE,I2C_SLAVE_BUFF, length) != HAL_OK)
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		// I2C_MASTER transmit data that he get from client.
		if (HAL_I2C_Master_Transmit_DMA(I2C_MASTER, SLAVE_ADDRESS, (uint8_t *)string_to_check, length) != HAL_OK)
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		while(flag_i2c != SET){;}
		flag_i2c = RESET;
		// I2C_SLAVE is ready to transmit data to I2C_MASTER.
		if (HAL_I2C_Slave_Transmit_DMA(I2C_SLAVE, I2C_SLAVE_BUFF, length) != HAL_OK)
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		// I2C_MASTER receive data from I2C_SLAVE.
		if (HAL_I2C_Master_Receive_DMA(I2C_MASTER, SLAVE_ADDRESS, I2C_MASTER_BUFF, length) != HAL_OK)
		{
			printf("TEST FAIL, (check hal_status)\r\n");
			return FAILURE;
		}
		while(flag_i2c != SET){;}
		if(memcmp(string_to_check,I2C_MASTER_BUFF,length)!= 0)
		// check that string at the end of 'I2C' is the same as the string at the beginning.
		{
			return FAILURE;
		}
	}
	printf("I2C_WORKS_GOOD\r\n");
    printf("---------------------\r\n");
	return SUCCESS;
}

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)	// check if MASTER complete transmission
{
	if(hi2c == I2C_MASTER)
	{
		flag_i2c = SET;
	}
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)	// check if MASTER complete receiving

{
	if(hi2c == I2C_MASTER)
	{
		flag_i2c = SET;
	}
}


