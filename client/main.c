//
// Created by Robert on 14.11.18.
//
#define MODELDIR "../lib/Sphinx/share/pocketsphinx/model"

#include <stdio.h>
#include <pocketsphinx.h>
#include <smart_string.c>
#include <stdbool.h>
#include <server/server.h>


#include <client/client.h>

/* to pthread */



int
main(int argc, char *argv[])
{
//	ps_decoder_t *ps = NULL;
//	cmd_ln_t *config = NULL;
//
//	config = cmd_ln_init(NULL, ps_args(), TRUE,
//						 "-hmm", MODELDIR "/en-us/en-us",
//		"-lm", MODELDIR "/en-us/en-us.lm.bin",
//		"-dict", MODELDIR "/en-us/cmudict-en-us.dict",
//		NULL);
//	ps = ps_init(config);


//	/* Say hello world*/
//	char *sam = "/Users/rkoval/CLionProjects/kiftv1/lib/SamBinary/sam";
//	char *text = "Hello world!";
//	char *code = sstring("%s %s", sam,text);
//	system(code);

unsigned int one = 1;

	run_script(7, (void*)1);


	//pthread_join(pthread, NULL);
	//printf("Hello!");
	//
	//init_server_info();
//	connect_as();
	return 0;
}

