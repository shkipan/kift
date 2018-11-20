//
// Created by Robert on 16.11.18.
//

#include <runer.h>

#define TIMER 500000  //try remove after

void run_script(int number, void *data) {

	pthread_t pthread;
	pthread_attr_t pthread_attr;

	pthread_attr_init(&pthread_attr);

	switch (number) {
		case 1 : pthread_create(&pthread, &pthread_attr, set_alarm, data);
			usleep(TIMER);
			break;
		case 2 :
			pthread_create(&pthread,
						   &pthread_attr,
						   close_all_finder_windows,
						   NULL);
			usleep(TIMER);
			break;
		case 3: pthread_create(&pthread,
							   &pthread_attr,
							   mute_audio_output,
							   data);
			usleep(TIMER);
			break;
		case 4: pthread_create(&pthread, &pthread_attr, open_weather, NULL);
			usleep(TIMER);
			break;
		case 5: pthread_create(&pthread, &pthread_attr, play_music, NULL);
			usleep(TIMER);
			break;
		case 6: pthread_create(&pthread, &pthread_attr, web_search, data);
			usleep(TIMER);
			break;
		case 7: pthread_create(&pthread, &pthread_attr, set_brightness, data);
			usleep(TIMER);
			break;
		case 8: pthread_create(&pthread, &pthread_attr, lock_screen, NULL);
			usleep(TIMER);
			break;
		case 9: pthread_create(&pthread, &pthread_attr, new_email, NULL);
			usleep(TIMER);
			break;
		case 10: pthread_create(&pthread, &pthread_attr, today_events, NULL);
			usleep(TIMER);
			break;
		case 11: pthread_create(&pthread, &pthread_attr, month_events, NULL);
			usleep(TIMER);
			break;
		case 12: pthread_create(&pthread, &pthread_attr, show_traffic, NULL);
			usleep(TIMER);
			break;
		case 13: pthread_create(&pthread, &pthread_attr, make_screenshot, data);
			usleep(TIMER);
			break;
		case 14: pthread_create(&pthread, &pthread_attr, change_volume, data);
			usleep(TIMER);
			break;
		case 15: pthread_create(&pthread, &pthread_attr, open_app, data);
			usleep(TIMER);
			break;
		case 16: pthread_create(&pthread, &pthread_attr, myip, NULL);
			usleep(TIMER);
			break;
		default:break;
	}
	pthread_detach(pthread);
}