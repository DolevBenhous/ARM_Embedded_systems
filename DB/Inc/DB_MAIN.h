/*
 * DB_MAIN.h
 *
 *  Created on: Nov 21, 2022
 *      Author: dolev
 */

#ifndef INC_DB_MAIN_H_
#define INC_DB_MAIN_H_

#include "TEST.h"

extern struct udp_pcb *upcb;
extern uint8_t flag_packet;
extern ip_addr_t client_addr;
extern u16_t client_port;

void proccess_manage(struct pbuf *global_payload);
void package_back();

#endif /* INC_DB_MAIN_H_ */
