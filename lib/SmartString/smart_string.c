//
// Created by Robert on 15.11.18.
//

#include <lib/SmartString/smart_string.h>

static size_t check_buff_size(sline_t *data, const char *str) {
	unsigned int new_size;

	size_t str_len = strlen(str);
	if (str_len > data->buff_size - data->buff_count) {
		new_size = 2 * data->buff_size;
		data->buff = realloc(data->buff, new_size);
		if (data->buff == NULL) {
			fprintf(stderr, "%s", "Can't allocate memory (2).\n");
			return 0;
		}
		data->buff_size = new_size;
	}
	return str_len;
}

char *smart_string(const char *base, ...) {
	va_list args;
	sline_t data    = {0, 0, INIT_SIZE};
	char    numbers[21];
	size_t  src_len = 0;
	char    *str    = NULL;

	if (!base || !*base) {
		return (NULL);
	}
	data.buff = malloc(data.buff_size * sizeof(char));
	memset(data.buff, 0, data.buff_size);
	va_start(args, base);
	/* main code */
	while (*base != '\0') {
		if (*base == '%') {
			/* string */
			if (*(base + 1) == 's') {
				str     = va_arg(args, char*);
				src_len = check_buff_size(&data, str);
				strncpy(data.buff + data.buff_count, str, src_len);
				data.buff_count += src_len;
				base += 2;
			}
				/* integer */
			else if (*(base + 1) == 'i') {
				memset(numbers, 0, 21);
				sprintf(numbers, "%i", va_arg(args,
					int));
				src_len = check_buff_size(&data, numbers);
				strncpy(data.buff + data.buff_count, numbers, src_len);
				data.buff_count += src_len;
				base += 2;

			}
				/* unsigned integer */
			else if (*(base + 1) == 'u') {
				memset(numbers, 0, 21);
				sprintf(numbers, "%u", va_arg(args,
					unsigned int));
				src_len = check_buff_size(&data, numbers);
				strncpy(data.buff + data.buff_count, numbers, src_len);
				data.buff_count += src_len;
				base += 2;
			}
		}
		if (*base != '\0') {
			strncpy(data.buff + data.buff_count, base, 1);
			data.buff_count++;
			if (data.buff_count + 1 > data.buff_size) {
				data.buff = realloc(data.buff, 2 * data.buff_size);
				if (data.buff == NULL) {
					fprintf(stderr, "%s", "Can't allocate memory (1).\n");
					return (NULL);
				}
				data.buff_size *= 2;
			}
			base++;
		}
	}
	va_end(args);
	return data.buff;
}
