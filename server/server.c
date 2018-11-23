//
// Created by Robert on 16.11.18.
//

#include <server.h>


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

int stop_server(int socket) {
	shutdown(socket, 2);
}

int run_server() {
	server_t app;
	app.serv_ip               = init_server_info();
	app.ssocket               = socket(AF_INET, SOCK_STREAM, 0);
	app.saddr.sin_family      = AF_INET;
	app.saddr.sin_port        = htons(PORT);
	//inet_aton(app.serv_ip, &app.saddr.sin_addr);
	app.saddr.sin_addr.s_addr = INADDR_ANY;


	/* thread */
	pthread_t      pthread;
	pthread_attr_t pthread_attr;
	pthread_attr_init(&pthread_attr);

	/* reserv port */
	int binder =
			bind(app.ssocket, (struct sockaddr *)&app.saddr, sizeof(app.saddr));
	if (binder == -1) {
		fprintf(stderr, "Can't assign address to socket (bind)\n");
	}

	int listener = listen(app.ssocket, 50);
	if (listener == -1) {
		fprintf(stderr, "Can't set socket as passive\n");
	}

	struct timeval tv;
	tv.tv_sec = 30;
	tv.tv_usec = 0;

	struct sockaddr_in client_addr;
	while (1) {
		int client = accept(app.ssocket, NULL, NULL);
		if (client < 0) {
			fprintf(stderr, "Socket accept Error\n");
		}
		else {
			printf("Client %d connected\n", client);
			pthread_create(&pthread, &pthread_attr, worker, (void *)client);
			//pthread_join(pthread, NULL);
			//
			pthread_detach(pthread);
		}

	}
}
