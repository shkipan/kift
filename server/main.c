//
// Created by Robert on 19.11.18.
//
#include <server.h>

int main ()
{
	int server = run_server();
//	run_http();

	stop_server(server);
	return 0;
}