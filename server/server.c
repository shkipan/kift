//
// Created by Robert on 16.11.18.
//

#include <server.h>
#include <pthread.h>
#include <sys/fcntl.h>

#define FD_SETSIZE 512

char *init_server_info(void) {
	static char    hostname[128] = {0};
	char           *host_ip;
	struct hostent *host_info;
	struct in_addr *adress_list;

	gethostname(hostname, 128);
	host_info   = gethostbyname(hostname);
	adress_list = (struct in_addr *)host_info->h_addr_list;
	host_ip     = inet_ntoa(adress_list[4]);
	printf("\t\t\t\e[1m\e[95mWelcome to KIFT VUI!\e[0m\n");
	printf("Server domain: \e[32m\e[1m%s\e[0m\n", hostname);
	printf("Server IP: \e[32m\e[1m%s:%d\e[0m\n", host_ip, PORT);
	printf("Max clients: \e[32m\e[1m%d\e[0m\n\n", MAX_CLIENTS);
	return (host_ip);
}

void *run_http(void *socket) {

	FILE *html_data;
	html_data = fopen("index.html", "r");

	char response_data[1024];
	fgets(response_data, 1024, html_data);

	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	strcat(http_header, response_data);
	printf("%s", http_header);
	send((int)socket, http_header, sizeof(http_header), 0);
	//stop_server((int)socket);
	fclose(html_data);
	pthread_exit(0);
}

int stop_server(int socket) {
	shutdown(socket, 2);
}

int run_server() {
	const char server_msg[25] = "Welocme to server!";

	pthread_t      pthread;
	pthread_attr_t pthread_attr;
	pthread_attr_init(&pthread_attr);

	server_t server;
	server.sip                      = init_server_info();
	server.ssocket                  = socket(AF_INET, SOCK_STREAM, 0);
	server.saddress.sin_family      = AF_INET;
	server.saddress.sin_port        = htons(PORT);
	//inet_aton(server.sip, &server.saddress.sin_addr);
	server.saddress.sin_addr.s_addr = INADDR_ANY;

	/* reserv port */
	int binder = bind(server.ssocket,
					  (struct sockaddr *)&server.saddress,
					  sizeof(server.saddress));

	int listener                           =
			listen(server.ssocket, 50);

	int                client;
	struct sockaddr_in client_address; // info about client
	socklen_t          client_address_size = sizeof(client_address);

	while (1) {
		client = accept(server.ssocket,
						(struct sockaddr *)&client_address,
						&client_address_size);
		if (client < 0) {
			printf("ERROR");
		}
		//fcntl(client, O_NONBLOCK | O_ASYNC);
		printf("client - %d\n", client);
		//pthread_create(&pthread, &pthread_attr, run_http, client);

		//pthread_detach(pthread);
	}

	//run_http(client);

	//send(client, server_msg, sizeof(server_msg),0);
}
