#ifndef _PRINT_H
#define _PRINT_H

/**
 * Program Name, version, author.
 * displayed when 'usage' and 'version'
 */
#define PROGRAM_NAME	"phex"
#define PROGRAM_VERSION	"0.1"
#define PROGRAM_AUTHOR	"LeavaTail"
#define COPYRIGHT_YEAR	"2019"
/**
 * Debug code
 */
#ifdef PHEX_DEBUG
#define phex_debug(fmt, ...)						\
	do {								\
		fprintf( stderr, "(%s: %u): %s:" fmt, \
				__FILE__, __LINE__, __func__, ##__VA_ARGS__); \
	} while (0)
#else
#define phex_debug(fmt, ...)	do { } while (0)
#endif

/**
 * ERROR STATUS CODE
 *  1: invalid command-line option
 */
enum
{
	CMDLINE_FAILURE = 1
};

/**
 * ASCII information
 */
#define ASCIIBYTES 2
#define ASCIIFROM 0x21
#define ASCIITO   0x7e

/**
 * Output area (buffer size)
 */
#define BUFSIZE 16
#define LINESIZE 6
#define HEXSIZE 4
#define HEXCOUNT 8
#define COUNTSIZE 8

#define COUNTLINE (COUNTSIZE + 1)
#define HEXLINE   (HEXSIZE * HEXCOUNT + HEXCOUNT)
#define DUMPLINE  (BUFSIZE + 1)
#define MSGLINE   (COUNTLINE + HEXLINE + DUMPLINE + 1)

#define DELIMCHAR ' '

/* print.c */
extern int printmsg(char *, size_t);
/* hex.c */
extern int atoh(const char *, char *, size_t, size_t);
/* string.c */
extern int zpadding(char *, size_t);
extern int delimiter(char *, size_t, const char);

#endif /*_PRINT_H */
