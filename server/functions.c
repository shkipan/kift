//
// Created by Robert on 22.11.18.
//
#include <server.h>
#include <smart_string.h>

void *close_all_finder_windows() {
	return ("osascript -e \'tell application \"Finder\" to close every window\'");
}

void *set_alarm(void *minustes) {
	char *code = sstring(
		"sleep %u && afplay /Users/rkoval/CLionProjects/kiftv1/client/audio/ring.aiff",
		(unsigned int)minustes);
	return (code);
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
	
}

void *open_weather() {
	const char
		*code = {"osascript -e 'open location \"https://weather.com/\"'"};
	system(code);

}

/* If you don't have music in iTunes - it's your problem:) */
void *play_music() {
	const char *code = {"osascript -e 'tell application \"iTunes\" to play'"};
	system(code);

}

void *web_search(void *data) {
	const char *term = (char *)data;
	char       *code = sstring(
		"osascript -e 'open location \"https://www.google.com/search?q=%s\"'",
		term);
	system(code);
	free(code);

}

void *set_brightness(void *data) {
	/* 1 - max, 0 - min */
	int key_code = 0;
	if ((int)data == 1) {
		key_code = 144;
	}
	else {
		key_code = 145;
	}
	char *code = sstring("osascript -e 'tell application \"System Events\"\n"
						 "    repeat 16 times\n"
						 "        key code %i\n"
						 "    end repeat\n"
						 "end tell'", key_code);
	system(code);
	free(code);

}

void *lock_screen() {
	const char *code =
				   "/System/Library/CoreServices/Menu\\ Extras/User.menu/Contents/Resources/CGSession -suspend";
	system(code);

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
	
}

void *today_events() {
	const char *code = "osascript -e 'tell application \"Calendar\"\n"
					   "\tswitch view to day view\n"
					   "\tview calendar at current date\n"
					   "end tell'";
	system(code);
	
}

void *month_events() {
	const char *code = "osascript -e 'tell application \"Calendar\"\n"
					   "\tswitch view to month view"
					   "\tview calendar at current date\n"
					   "end tell'";
	system(code);
	
}

void *show_traffic() {
	const char *code =
				   "osascript -e 'open location \"https://infoportal.ua/uk/zatori-kiyeva-onlayn/\"'";
	system(code);
	
}

void *make_screenshot(void *data) {
	/* 1 - interactive mode , 0 - fullscreen screenshot*/
	char *code;

	if ((int)data == 1)
		code = "screencapture ~/Desktop/$(date +%Y%m%d%H%M%S).png";
	else
		code = "screencapture -i ~/Desktop/$(date +%Y%m%d%H%M%S).png";
	system(code);
}

void *change_volume(void *data) {
	/* 1 - volume+ ,0 - volume- */
	char *code;
	if ((int)data == 1)
		code = "osascript -e 'set volume output volume ((output volume of (get volume settings)) + 10)'";
	else
		code = "osascript -e 'set volume output volume ((output volume of (get volume settings)) - 10)'";
	system(code);
}

void *open_app(void *data) {
	char *code = sstring("osascript -e 'tell application \"%s\"\n"
						 "\treopen\n"  //reopen app
						 "\tactivate\n"
						 "end tell'", (char*)data);
	system(code);
	free(code);
}

void *my_ip() {
	const char *code =
				   "osascript -e 'open location \"https://2ip.ua/ua/\"'";
	system(code);
}

void *my_location() {
	const char *code =
				   "osascript -e 'open location \"https://www.google.com/maps/\"'";
	system(code);
}

//TODO
/*
 * Get Log of executed commands; - client only
 *
 * */
//and what ??? how to return this ??
void *get_hostname() {
	size_t len = 30;
	char hostname[len];

	gethostname(hostname, len);
}
