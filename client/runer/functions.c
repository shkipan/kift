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
		"sleep %u && afplay /Users/rkoval/CLionProjects/kiftv1/client/audio/ring.aiff",
		(unsigned int)minustes);

	int ret = system(code);
	if (ret == -1) {
		fprintf(stderr, "Set alarm system call error!");
	}
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
	char *code = {"osascript -e 'open location \"https://weather.com/\"'"};
	system(code);
	pthread_exit(0);
}

/* If you don't have music in iTunes - it's your problem:) */
void *play_music() {
	printf("azaz");
	char *code = {"osascript -e 'tell application \"iTunes\" to play'"};
	system(code);
	pthread_exit(0);
}

void *web_search(void *data) {
	char *term = (char *)data;

	char *code = sstring(
		"osascript -e 'open location \"https://www.google.com/search?q=%s\"'",
		term);
	system(code);
	free(code);
	pthread_exit(0);
}

void *set_brightness(void *data)
{
	/* 1 - max, 0 - min */
	int key_code = 0;
	if ((int)data == 1)
		key_code = 113;
	else
		key_code = 107;
	char *code = sstring("osascript -e 'tell application \"System Events\"\n"
						 "    repeat 16 times\n"
						 "        key code %i\n"
						 "    end repeat\n"
						 "end tell'", key_code);
	system(code);
	free(code);
	pthread_exit(0);
}