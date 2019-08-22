/*
 * string.c
 *
 * string utilities.
 *
 *
 * MIT License
 *
 * Copyright (c) 2019 LeavaTail
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"

/**
 * __strncpy - Copy string "src" to "dist" (buffer must terminate '\0')
 * @dist: Output buffer
 * @src:  Input buffer
 * @n:    Count of Copy bytes
 *
 * Return - Output buffer
 */
static char *__strncpy(char *dist, const char *src, size_t n)
{
	strncpy(dist, src, n);
	dist[n] = '\0';
	return dist;
}

/**
 * zpadding - Fill in the '\0' len bytes
 * @data:  Output buffer
 * @len:   Count of filled '\0'
 *
 * Return - Count of full actually bytes.
 */
int zpadding(char *data, size_t len)
{
	if (len < BUFSIZE) {
		memset(data+len, '\0', BUFSIZE - len);
		data[BUFSIZE] = '\0';
	}
	return (BUFSIZE - len);
}

/**
 * delimiter - Input buffer("data") separates specified character("delim")
 * @data:  separated buffer
 * @len:   buffer("data") length
 * @delim: Field delimiter
 *
 * Return - 0:         Success
 *        - OTHERWISE: ERROR
 */
int delimiter(char *data, size_t len, const char delim)
{
	int i;
	int j;
	char *tmp;

	if ((tmp = (char*)calloc(len + 1, sizeof(char))) == NULL) {
		perror("delimiter temporary space");
		exit(EXIT_FAILURE);
	}

	__strncpy(tmp, data, len);

	for (i = 0, j = 0; (i + j) < len; i += HEXSIZE) {
		if (i == 0 && j == 0) {
			__strncpy(data, tmp, HEXSIZE);
		} else {
			data[i + (j++)] = delim;
			__strncpy(data + i + j, tmp + i, HEXSIZE);
		}
	}

	free(tmp);
	return 0;
}
