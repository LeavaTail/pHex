/*
 * hex.c
 *
 * control Hexadecimal characters.
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
 * atoh - convert ascii char to Hexadecimal char
 * @nptr: ASCII code characters (INPUT)
 * @dist: Hexadecimal characters (OUTPUT)
 * @len:  ASCII code characters length
 * @dist_len: Hexadecimal characters length
 *
 * Return - Count of Ascii characters
 */
int atoh(const char *nptr, char *dist, size_t len, size_t dist_len)
{
	int i;
	char ascii[ASCIIBYTES + 1] = "\0";
	size_t num = 0;

	/* Initialize dist buffer */
	dist[0] = '\0';

	for (i = 0; i < len && i < dist_len; i++, num+=ASCIIBYTES) {
		sprintf(ascii, "%02x", nptr[i]);
		strcat(dist, ascii);
	}
	return num;
}
