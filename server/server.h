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
#include <pthread.h>
#define MAX_CLIENTS 100
#define PORT 3490


typedef struct server_s {
	int                ssocket;
	char               *serv_ip;
	struct sockaddr_in saddr;

}server_t;

typedef struct cmd_rec_s {
	int cmd_number;
	char *cmd_text;
	char *cmd_answer;  //answer to SAM
	int argument;
	char *s_argument;
	size_t s_a_len;
} cmd_rec_t;

char *init_server_info(void);
int run_server();
void *worker(void *socket);
int stop_server(int socket);

/* Events */
void *set_alarm(void *minustes);
void *new_email();
void *today_events();
void *month_events();

/* Audio */
void *mute_audio_output(void *mute);
void *play_music();
void *change_volume(void *data);

/* Browser */
void *web_search(void *data);
void *show_traffic();
void *open_weather(); // show_weather ?
void *my_ip();
void *my_location();

/* Tools */
void *make_screenshot(void *data);
void *close_all_finder_windows();
void *set_brightness(void *data); // change_br
void *lock_screen();
void *open_app(void *data);

#endif
