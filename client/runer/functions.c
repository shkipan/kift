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
	free(code);
	pthread_exit(0);
}

void *open_weather() {
	const char
		*code = {"osascript -e 'open location \"https://weather.com/\"'"};
	system(code);
	pthread_exit(0);
}

/* If you don't have music in iTunes - it's your problem:) */
void *play_music() {
	const char *code = {"osascript -e 'tell application \"iTunes\" to play'"};
	system(code);
	pthread_exit(0);
}

void *web_search(void *data) {
	const char *term = (char *)data;
	char       *code = sstring(
		"osascript -e 'open location \"https://www.google.com/search?q=%s\"'",
		term);
	system(code);
	free(code);
	pthread_exit(0);
}

void *set_brightness(void *data) {
	/* 1 - max, 0 - min */
	int key_code = 0;
	if ((int)data == 1) {
		key_code = 113;
	}
	else {
		key_code = 107;
	}
	char *code = sstring("osascript -e 'tell application \"System Events\"\n"
						 "    repeat 16 times\n"
						 "        key code %i\n"
						 "    end repeat\n"
						 "end tell'", key_code);
	system(code);
	free(code);
	pthread_exit(0);
}

void *lock_screen() {
	const char *code =
				   "/System/Library/CoreServices/Menu\\ Extras/User.menu/Contents/Resources/CGSession -suspend";
	system(code);
	pthread_exit(0);
}

void *new_email() {
	const char *code = "osascript -e 'tell application \"Mail\"\n"
					   "\tset newMessage to make new outgoing message with properties {subject:\"\", content:\"\" & return & return}\n"
					   "\ttell newMessage\n"
					   "\t\tset visible to true\n"
					   "\t\tmake new to recipient at end of to recipients with properties {name:\"\", address:\"\"}\n"
					   "\tend tell\n"
					   "\tactivate\n"
					   "end tell'";
	system(code);
	pthread_exit(0);
}

void *today_events() {
	const char *code = "osascript -e 'tell application \"Calendar\"\n"
					   "\tswitch view to day view\n"
					   "\tview calendar at current date\n"
					   "end tell'";
	system(code);
	pthread_exit(0);
}

void *month_events() {
	const char *code = "osascript -e 'tell application \"Calendar\"\n"
					   "\tswitch view to month view"
					   "\tview calendar at current date\n"
					   "end tell'";
	system(code);
	pthread_exit(0);
}

void *show_traffic() {
	const char *code =
				   "osascript -e 'open location \"https://infoportal.ua/uk/zatori-kiyeva-onlayn/\"'";
	system(code);
	pthread_exit(0);
}

void *make_screenshot(void *data) {
	/* 1 - interactive mode , 0 - fullscreen screenshot*/
	char *code;

	if ((int)data == 1)
		code = "screencapture ~/Desktop/$(date +%Y%m%d%H%M%S).png";
	else
		code = "screencapture -i ~/Desktop/$(date +%Y%m%d%H%M%S).png";
	system(code);
	pthread_exit(0);
}

void *change_volume(void *data) {
	/* 1 - volume+ ,0 - volume- */
	char *code;
	if ((int)data == 1)
		code = "osascript -e 'set volume output volume ((output volume of (get volume settings)) + 10)'";
	else
		code = "osascript -e 'set volume output volume ((output volume of (get volume settings)) - 10)'";
	system(code);
	pthread_exit(0);
}

void *open_app(void *data) {
	char *code = sstring("osascript -e 'tell application \"%s\"\n"
						 "\treopen\n"  //reopen app
					  "\tactivate\n"
						 "end tell'", (char*)data);
	system(code);
	free(code);
	pthread_exit(0);
}

void *myip() {
	const char *code =
				   "osascript -e 'open location \"https://2ip.ua/ua/\"'";
	system(code);
	pthread_exit(0);
}