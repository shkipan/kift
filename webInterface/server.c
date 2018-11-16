//
// Created by Robert on 16.11.18.
//

#include <server.h>

#define MAX_CLIENTS 10
char 	*init_server_info(void)
{
	static char		hostname[128] = {0};
	char			*host_ip;
	struct hostent	*host_info;
	struct in_addr	*adress_list;

	gethostname(hostname, 128);
	host_info = gethostbyname(hostname);
	adress_list = (struct in_addr*)host_info->h_addr_list;
	host_ip = inet_ntoa(adress_list[4]);
	printf("\t\t\t\e[1m\e[95mWelcome to KIFT VUI!\e[0m\n");
	printf("Server domain: \e[32m\e[1m%s\e[0m\n", hostname);
	printf("Server IP: \e[32m\e[1m%s:%d\e[0m\n", host_ip, PORT);
	printf("Max clients: \e[32m\e[1m%d\e[0m\n\n", MAX_CLIENTS);
	return (host_ip);
}