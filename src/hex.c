#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"
/*
 * atoh: convert ascii char to Hexadecimal char
 *
 */
int atoh(char *nptr, char *dist, size_t len, size_t dist_len)
{
	int i;
	char ascii[2+1] = "\0";
	size_t num = 0;

	/* Initialize dist buffer */
	dist[0] = '\0';

	for(i = 0; i < len && i < dist_len; i++, num+=2) {
		sprintf(ascii, "%02x", nptr[i]);
		strcat(dist, ascii);
	}
	return num;
}
