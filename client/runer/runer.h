//
// Created by Robert on 16.11.18.
//

#ifndef RUNER_H
#define RUNER_H

#include <stdlib.h>
#include <pthread.h>
#include <smart_string.h>
#include <stdbool.h>
#include <unistd.h>
void run_script(int number, void *data);
		/* Scripts */

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
void *myip();

/* Tools */
void *make_screenshot(void *data);
void *close_all_finder_windows();
void *set_brightness(void *data); // change_br
void *lock_screen();
void *open_app(void *data);
#endif
