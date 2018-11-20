//
// Created by Robert on 16.11.18.
//

#include <runer.h>

#define TIMER 5000  //try remove after

void run_script(int number, void *data) {

	pthread_t pthread;
	pthread_attr_t pthread_attr;

	pthread_attr_init(&pthread_attr);

	switch (number) {
		case 1 :
			pthread_create(&pthread, &pthread_attr, set_alarm, data);
			usleep(TIMER);
			break;
		case 2 :
			pthread_create(&pthread,
						   &pthread_attr,
						   close_all_finder_windows,
						   data);
			usleep(TIMER);
			break;
		case 3: pthread_create(&pthread,
							   &pthread_attr,
							   mute_audio_output,
							   data);
			usleep(TIMER);
			break;
		case 4: pthread_create(&pthread, &pthread_attr, open_weather, data);
			usleep(TIMER);
			break;
		case 5: pthread_create(&pthread, &pthread_attr, play_music, data);
			usleep(TIMER);
			break;
		case 6: pthread_create(&pthread, &pthread_attr, web_search, data);
			usleep(TIMER);
			break;
		case 7: pthread_create(&pthread, &pthread_attr, set_brightness, data);
			usleep(TIMER);
			break;
		default:break;
	}
	pthread_detach(pthread);
}