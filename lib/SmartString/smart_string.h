//
// Created by Robert on 15.11.18.
//

#ifndef SMART_LINE_H
#define SMART_LINE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define INIT_SIZE 512
#define sstring smart_string

typedef struct smart_line {
	char         *buff;
	unsigned int buff_count;
	unsigned int buff_size;
}sline_t;

char *smart_string(const char *base, ...);

#endif
