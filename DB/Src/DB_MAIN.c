/*
 * DB_MAIN.c
 *
 *  Created on: 3 Dec 2022
 *      Author: dolev
 */

#include "DB_MAIN.h"
#include "DB_SERVER.h"
#include "TEST.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usart.h"
#include "lwip.h"
#include "lwip/pbuf.h"
#include "lwip/tcp.h"
#include "lwip/udp.h"

test_res_t    status;
client_sent_t receive_pack;
struct pbuf *global_payload;

#define TEST_ID_OFFSET 				(global_payload->payload + 0)
#define PER_TO_TEST_OFFSET 			(global_payload->payload + 4)
#define ITER_OFFSET 				(global_payload->payload + 5)
#define BIT_PATTERN_LENGTH_OFFSET   (global_payload->payload + 6)
#define BIT_PATTERN_OFFSET   		(global_payload->payload + 7)
#define MIN_PACKET_SIZE				5
#define MAX_PACKET_SIZE				263

#define TEST_ID_REC_OFFSET 			(buf + 0)
#define RESULT_REC_OFFSET 			(buf + 4)
#define RECEIVE_PACK_SIZE			5



/**
  * @brief In this function get packet from client into local packet.
  * To manage packet data easily  contain ID test number and  his test's status
  * @param  struct pbuf *global_payload
  * @retval None
  */
void proccess_manage(struct pbuf *global_payload)
{
	//Get packet from client into packet for future test uses in SERVER -> (receivePack)
		receive_pack.testId            = *(uint32_t *)(TEST_ID_OFFSET);
		receive_pack.perToTest         = *(uint8_t *)(PER_TO_TEST_OFFSET);
		receive_pack.iter              = *(uint8_t *)(ITER_OFFSET) ;
		receive_pack.bitPatternLength  = *(uint8_t *)(BIT_PATTERN_LENGTH_OFFSET);
		memcpy(receive_pack.bitPattern, BIT_PATTERN_OFFSET, receive_pack.bitPatternLength);
		if (!(MIN_PACKET_SIZE <= global_payload->len && global_payload->len <= MAX_PACKET_SIZE))
		{
			printf("packet size not in range \r\n");
			receive_pack.perToTest = WRONG_PACK_SIZE;
		}

	// Save parameter to global variables in order to use in TEST function
		per     =  receive_pack.perToTest;			// parameter to know which protocol to test.
		iter    =  receive_pack.iter;				// parameter to know how many times test the protocol.
		length  =  receive_pack.bitPatternLength;	// parameter to know length of the string in protocol test.
		memcpy(test_check, receive_pack.bitPattern,receive_pack.bitPatternLength);
}

/**
  * @brief In this function we create packet that will sent back to client
  * In this we fill TEST function
  * At the end contain ID test number and  his test's status
  * @param  None
  * @retval None
  */
void package_back()
{
	flag_packet = 0;
	char buf[5];												//Initialize buffer
	status.result = test(iter, per, length, test_check); 	   	// get the result from the chosen test.
    *(uint32_t *)(TEST_ID_REC_OFFSET) = receive_pack.testId;	// fill the buffer with testID
    *(uint8_t *)(RESULT_REC_OFFSET) = status.result;			// fill the buffer with test's result

    struct pbuf *txBuf = pbuf_alloc(PBUF_TRANSPORT,RECEIVE_PACK_SIZE, PBUF_RAM); //Create buffer for transmit packet back to client.
	pbuf_take(txBuf, buf, RECEIVE_PACK_SIZE);

	udp_connect(upcb, &client_addr, client_port);								// Connect to the remote client

	udp_send(upcb, txBuf);			// Send a Reply to the Client

	udp_disconnect(upcb);			// free the UDP connection, so we can accept new clients

	pbuf_free(txBuf);				// Free the p_tx buffer
}

