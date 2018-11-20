//
// Created by Robert on 18.11.18.
//
#include <client.h>

int connect_as() {

	int client_socket;

	client_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family      = AF_INET;
	server_address.sin_port        = htons(3490);
	server_address.sin_addr.s_addr = INADDR_ANY; //localhost ip /* inet_addr*/

	int connection_status = connect(client_socket,
									(struct sockaddr *)&server_address,
									sizeof(server_address));
	if (connection_status == -1)
		printf("Connection Error!");

	char server_response[512];
	recv(client_socket, &server_response, sizeof(server_response),0); // use recvfrom instead

	printf("%s\n", server_response);
	shutdown(client_socket, 2);
}