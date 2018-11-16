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

/* Scripts */
void *close_all_finder_windows();
void *set_alarm(void *minustes);
void *mute_audio_output(void *mute);
void *open_weather();
void *play_music();
#endif
