//
// Created by Robert on 22.11.18.
//
#include <server.h>

cmd_rec_t commands[22] = {
	{0,0,0,0,0,0},
	{1, "SET ALARM FOR <TIME> MINUTE(-S)", "I SET ALARM FOR <TIME> MINUTE(-S)", 2654, 0,0}, /// how about argument ?
	{2, "CLOSE FINDER", "I CLOSE ALL FINDER WINDOWS",0,0,0},
	{3, "MUTE SOUND", "YOU DON'T HEAR ME WAHAHAHAHA! ",1,0,0}, //arg 1
	{3, "UNMUTE SOUND", "NOW YOU HEAR ME, I'M HAPPY! ", 0,0,0},
	{4, "WHAT'S THE WEATHER", "LOOK OUT THE WINDOW",0,0,0},
	{5, "PLAY MUSIC", "DANCE! DANCE! ",0,0,0},
	{6, "FIND <TERM>", "HERE WHAT I FOUND", 0, "<TERM>", strlen("<TERM>")},
	{7, "SET BRIGHTNESS MORE", "MAY THE LIGHT BE WITH YOU", 1, 0, 0},
	{7, "SET BRIGHTNESS LESS", "feel power of the dark side!", 0, 0, 0},
	{8, "LOCK SCREEN", "OKAY", 0,0,0},
	{9, "WRITE NEW EMAIL", "BE CREATIVE! ", 0,0,0},
	{10, "OPEN AGENDA", "HERE IS YOUR TODAY EVENTS", 0,0,0},
	{11, "OPEN AGENDA FOR A MONTH", "HERE", 0,0,0}, //month
	{12, "SHOW ME TRAFFIC", "YOU HAVE A CAR? ",0,0,0},
	{13, "MAKE SCREENSHOT", "OKAY, BUT CLOSE PORNHUB FIRST", 1,0,0},
	{14, "VOLUME UP", "I INCREASE VOLUME", 1, 0,0},
	{14, "VOLUME DOWN", "I DECREASE VOLUME", 0,0,0},
	{15, "OPEN APP <NAME>", "I TRY OPEN APP", 0 , "<NAME>", strlen("<NAME>")},
	{16, "GET MY IP", "OKAY, HERE IS YOUR IP",0,0,0},
	{17, "WHERE AM I", "YOU ARE HERE",0,0,0},
	{0,0,0,0,0,0}
};

void *worker(void *socket) {
	char activator[32];
	while (1)
	{
		recv((int)socket, activator, 32, 0);
		if (strcmp(activator, "I AM HERE") == 0)
		{
			send((int)socket, "OK", 2, 0);
			memset(activator, 0, 32);






		} else if (strcmp(activator, "GOOD BYE") == 0)
			break;

	}
	write(1, "CLIENT DISCONNECT\n", 18);
	shutdown((int)socket, 2);
	pthread_exit(0);


//	char * a = close_all_finder_windows();
//	send((int)socket, a, strlen(a), 0);
//	printf("%s\n",a);
}