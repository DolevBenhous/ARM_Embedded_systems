/*
 * DB_LWIP.h
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

#ifndef INC_DB_SERVER_H_
#define INC_DB_SERVER_H_

#include "TEST.h"
#include "usart.h"
#include "arch.h"

#define SERVER_PORT 		7
#define MAX_SIZE_OF_STRING 	255
#define MAX_SIZE_OF_PACKET 	263

extern struct netif gnetif;
extern struct udp_pcb *upcb;
extern uint8_t flag_packet;
extern struct pbuf *global_payload;

extern uint8_t    iter;
extern uint8_t    per;
extern uint8_t    length;
extern uint8_t    result;
extern uint8_t    test_result;
extern char       test_check[MAX_SIZE_OF_STRING];

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

extern UART_HandleTypeDef huart3;
#define UART_DEBUG &huart3

void udpServer_init(void);
extern char buf[100];

typedef struct send
{
    uint32_t testId;
    uint8_t perToTest;
    uint8_t iter;
    uint8_t bitPatternLength;
    char *bitPattern;

} client_sent_t;

typedef struct test_result
{
    uint32_t testId;
    uint8_t result;
} test_res_t;


#endif /* INC_DB_SERVER_H_ */
