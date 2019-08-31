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
#include <config.h>
#include <getopt.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "print.h"

/**
 * PRINT MODE
 * command mode(stdin mode, file input mode, dump save mode)
 */
static enum
{
	/* no argument("phex"). STDIN as input. */
	PHEX_STDINMODE,
	/* one argument("phex FILE"). FILE as input */
	PHEX_FILEMODE,
	/* two argument("phex FILE1 FILE2") FILE1'dump store FILE2 */
	PHEX_DUMPMODE
} phex_mode;


/**
 * Special Option(no short option)
 */
enum
{
	GETOPT_HELP_CHAR = (CHAR_MIN - 2),
	GETOPT_VERSION_CHAR = (CHAR_MIN - 3)
};

/* option data {"long name", needs argument, flags, "short name"} */
static struct option const longopts[] =
{
	{"help",no_argument, NULL, GETOPT_HELP_CHAR},
	{"version",no_argument, NULL, GETOPT_VERSION_CHAR},
	{0,0,0,0}
};

/**
 * usage - print out usage.
 * @status: Status code
 */
void usage(int status)
{
	FILE *out;
	switch (status) {
	case CMDLINE_FAILURE:
		out = stderr;
		break;
	default:
		out = stdout;
	}
	fprintf(out, "Usage: %s [OPTION]... [FILE]\n",
										PROGRAM_NAME);

	exit(status);
}

/**
 * version - print out program version.
 * @command_name: command name
 * @version:      program version
 * @author:       program authoer
 */
void version(const char *command_name, const char *version,
			const char *author)
{
	FILE *out = stdout;

	fprintf(out, "%s %s\n", command_name, version);
	fprintf(out, "Written by %s.\n", author);
}

/**
 * read_stdin - read stdin to output Hexadecimal.
 *
 * Return: 0 - success
 *         otherwise - error(show ERROR STATUS CODE)
 */
int read_stdin(void)
{
	FILE *in = stdin;
	FILE *f2;

	return 0;
}

/**
 * read_file - read file to output Hexadecimal.
 *
 * Return: 0 - success
 *         otherwise - error(show ERROR STATUS CODE)
 */
int read_file(const char *path)
{
	int err;
	char *inbuf;
	FILE *fin;
	FILE *fout;
	struct stat st;
	size_t outsize;
	size_t insize;

	if(stat(path, &st)) {
		perror("file doesn't get status.");
		err = EXIT_FAILURE;
		goto out;
	}
	insize = st.st_size;

	if ((fin = fopen(path, "rb")) == NULL) {
		perror("file open error");
		err = EXIT_FAILURE;
		goto out;
	}

	if(fstat(STDOUT_FILENO, &st)) {
		perror("file doesn't get status.");
		err = EXIT_FAILURE;
		goto fin_end;
	}
	outsize = st.st_size;

	if ((fin = fopen(path, "rb")) == NULL) {
		perror("file open error");
		err = EXIT_FAILURE;
		goto fin_end;
	}
fout_end:
	fclose(fout);
fin_end:
	fclose(fin);
out:
	return err;
}

/**
 * dump_file - read file to output another file.
 *
 * Return: 0 - success
 *         otherwise - error(show ERROR STATUS CODE)
 */
int dump_file(const char *inpath, const char *outpath)
{
	return 0;
}

/**
 * main - make a hexdump or do the reverse
 * @argc: count of arguments
 * @argv: command line argument vector
 */
int main(int argc, char *argv[])
{
	int opt;
	int longindex;
	int n_files;
	bool infile = false;
	int fd = 0;
	size_t len;
	char data[BUFSIZE + 1];

	/**
	 * Initialize Phase.
	 * parse option, argument. set flags.
	 */
	while ((opt = getopt_long(argc, argv,
		"abc:g:iEpul:s:r",
		longopts, &longindex)) != -1) {
		switch (opt) {
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
		case GETOPT_HELP_CHAR:
			usage(EXIT_SUCCESS);
			break;
		case GETOPT_VERSION_CHAR:
			version(PROGRAM_NAME, PROGRAM_VERSION, PROGRAM_AUTHOR);
			exit(EXIT_SUCCESS);
			break;
		default:
			usage(CMDLINE_FAILURE);
		}
	}

	n_files = argc - optind;
	switch (n_files) {
	case 0:
		phex_mode = PHEX_STDINMODE;
		read_stdin();
		break;
	case 1:
		phex_mode = PHEX_FILEMODE;
		read_file(argv[optind]);
		break;
	case 2:
		phex_mode = PHEX_DUMPMODE;
		dump_file(argv[optind], argv[optind + 1]);
		break;
	default:
		usage(CMDLINE_FAILURE);
	}

	if (argc > optind) {
		infile = true;
		if ((fd = open(argv[optind], O_RDONLY)) == -1) {
			perror("file open error");
			exit(EXIT_FAILURE);
		}
	}

	/**
	 * Main Phase.
	 * read input file(or stdio), output data.
	 */
	while ((len = read(fd, data, BUFSIZE)) > 0) {
		data[len] = '\0';
		printmsg(data, len);
	}

	/**
	 * Terminate Phase
	 */
	if (infile)
		close(fd);
	return 0;
}
