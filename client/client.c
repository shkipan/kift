//
// Created by Robert on 18.11.18.
//
#include <client.h>

int connect_as() {

	int csocket;

	csocket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family      = AF_INET;
	server_address.sin_port        = htons(3490);
	server_address.sin_addr.s_addr = INADDR_ANY; //localhost ip /* inet_addr*/

	int con_status = connect(csocket,
							 (struct sockaddr *)&server_address,
							 sizeof(server_address));
	if (con_status == -1) {
		fprintf(stderr, "Connection Error!\n");
		exit(1);
	}

	char buff[2048];
	memset(buff,0,2048);


	/* While not activated - read from mic (while here) */
	/* If user say HELLO JARVIS then activator = 1 */
	int activator = 1;
	char *activation_phrase = "I AM HERE";
	char act[4];
	memset(act, 0,4);
	if (activator) {
		send(csocket, activation_phrase, strlen(activation_phrase), 0);
		recv(csocket, act, 4, 0);
		write(1, act, 4);
	}
	//send(csocket, "GOOD BYE", 8,0);
	if (strcmp(act, "OK") == 0)
	{
		while (1) {
			/* send voice */

			/* recieve command */
			//recv(csocket, buff,2048,0);
			if (buff[0] != '\0')
			{
				system(buff);
				printf("Works!");
			}
			memset(buff, 0, 2048);
		};
	}






//	char server_response[512];
//	recv(csocket,
//		 &server_response,
//		 sizeof(server_response),
//		 0); // use recvfrom instead

//	printf("%s\n", server_response);

	shutdown(csocket, 2);
}