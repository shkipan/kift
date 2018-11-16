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
#define PORT 3490


char 	*init_server_info(void);

#endif
