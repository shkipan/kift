//
// Created by Robert on 15.11.18.
//

#include <runer.h>

void *close_all_finder_windows() {
	system("osascript -e \'tell application \"Finder\" to close every window\'");
	printf("All Finder windows are closed.");
	pthread_exit(0);
}

void *set_alarm(void *minustes) {
	char *code = sstring(
		"sleep %u && afplay /Users/rkoval/CLionProjects/kiftv1/audio/ring.aiff",
		(unsigned int)minustes);
	system(code);
	free(code);
	printf("Alarm on.");
	pthread_exit(0);
}

void *mute_audio_output(void *mute) {
	char *status;

	if ((int)mute == 1) {
		status = "true";
	}
	else {
		status = "false";
	}

	char *code = sstring("osascript -e 'set volume output muted %s'", status);
	system(code);
	pthread_exit(0);
}

void *open_weather() {
	char *code = {"osascript -e 'tell application \"Safari\"\n"
				  "\topen location \"https://weather.com/\"\n"
				  "\tactivate\n"
				  "end tell'"};
	system(code);
	pthread_exit(0);
}