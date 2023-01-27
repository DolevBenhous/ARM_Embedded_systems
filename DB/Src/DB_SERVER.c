/*
 * DB_LWIP.c
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

#include "DB_SERVER.h"
#include "DB_MAIN.h"
#include "TEST.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lwip/pbuf.h"
#include "lwip/tcp.h"
#include "lwip/udp.h"

ip_addr_t client_addr;
u16_t client_port;

void udp_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
	client_addr = *addr; 	// holds client's address.
	client_port = port;		// holds client's port.e
	flag_packet = 1;		// notice than packet is received
	proccess_manage(p);		//load local packet with payload
	pbuf_free(p);			// free the allocation
}

void udpServer_init(void)
{
   upcb = udp_new(); 										//1. Create a new UDP control block.

   err_t err = udp_bind(upcb, IP_ADDR_ANY, SERVER_PORT);	//2. Bind the upcb to the local port.

   if (err == ERR_OK)										//3. Set a receive callback for the upcb.
   {
	   udp_recv(upcb, udp_receive_callback, NULL);
   }
   else
   {
	   udp_remove(upcb);
   }
}
