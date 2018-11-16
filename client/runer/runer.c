//
// Created by Robert on 16.11.18.
//

#include <runer.h>

void run_script(int number, void *data) {

	pthread_t pthread;
	pthread_attr_t pthread_attr;

	pthread_attr_init(&pthread_attr);

	switch (number) {
		case 1 : pthread_create(&pthread, &pthread_attr, set_alarm, data);
			break;
		case 2 :
			pthread_create(&pthread,
						   &pthread_attr,
						   close_all_finder_windows,
						   data);
			break;
		case 3: pthread_create(&pthread,
							   &pthread_attr,
							   mute_audio_output,
							   data);
			break;
		case 4: pthread_create(&pthread, &pthread_attr, open_weather, data);
			usleep(50);
			break;
		case 5: pthread_create(&pthread, &pthread_attr, play_music, data);
			usleep(50);
			break;
		default:break;
	}

	pthread_detach(pthread);
}