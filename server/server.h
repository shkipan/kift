//
// Created by Robert on 16.11.18.
//

#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <inttypes.h>
#include <string.h>

#define MAX_CLIENTS 100
#define PORT 3490

//rcv - receive
typedef enum rcv_data_type_e {
	RDT_UNDEFINED, RDT_VOICE, RDT_STRING
}rcv_data_type_t;

typedef struct rcv_data_s {

}rcv_data_t;

typedef struct server_s {
	int                ssocket;
	char               *sip;
	struct sockaddr_in saddress;

}server_t;

char *init_server_info(void);
int run_server();
int stop_server(int socket);

#endif
