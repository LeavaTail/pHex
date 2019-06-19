/*
 * main.c
 *
 * Print data to Hexadecimal (like 'xxd').
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
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "print.h"

static int count = 0;

/*
 * main()
 * 
 * argc: 
 * argv:
 */
int main(int argc, char *argv[])
{
	int opt;
	bool infile = false;
	int fd = 0;
	int len;
	int i, j;
	unsigned char data[BUFSIZE+1];
	size_t count = 0;

	/*
	 * Initialize Phase.
	 * parse option, argument. set flags.
	 */
	while((opt = getopt(argc, argv, "abc:g:iEpul:s:r")) != -1) {
		switch(opt) {
			case 'a':
			case 'b':
			case 'c':
			case 'g':
			case 'i':
			case 'E':
			case 'p':
			case 'u':
			case 'l':
			case 's':
			case 'r':
			default:
				break;
		}
	}
	if(argc > optind) {
		infile = true;
		if ((fd = open(argv[optind], O_RDONLY)) == -1) {
			perror("file open error.");
			exit(EXIT_FAILURE);
		}
	}

	/*
	 * Main Phase.
	 * read input file(or stdio), output data.
	 */
	while ((len = read(fd, data, BUFSIZE)) != 0) {
		data[len] = '\0';
		printmsg(data, len);
	}

	/*
	 * Terminate Phase
	 *
	 */
	if(infile) {
		close(fd);
	}
	return 0;
}
