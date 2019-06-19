#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"

char *__strncpy(char *dist, char *src, size_t n)
{
	strncpy(dist, src, n);
	dist[n] = '\0';
	return dist;
}

int zpadding(char *data, size_t len)
{
	if(len < BUFSIZE) {
		memset(data+len, '\0', BUFSIZE-len);
		data[BUFSIZE] = '\0';
	}
	return(BUFSIZE - len);
}

int delimiter(char *data, size_t len, char delim)
{
	int i;
	int j;
	char *tmp;

	if((tmp = (char*)calloc(len+1, sizeof(char)))== NULL) {
		perror("delimiter temporary space");
		exit(EXIT_FAILURE);
	}
	
	__strncpy(tmp, data, len);

	for(i = 0, j = 0; (i + j) < len; i+=HEXSIZE) {
		/* First step */
		if(i == 0 && j == 0) {
			__strncpy(data, tmp, HEXSIZE);
		} else {
		/* Later step */
			data[i+(j++)] = ' ';
			__strncpy(data+i+j, tmp+i, HEXSIZE);
		}
	}

	free(tmp);
	return 0;
}
