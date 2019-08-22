#ifndef _PRINT_H
#define _PRINT_H

#define ASCIIBYTES 2
#define ASCIIFROM 0x21
#define ASCIITO   0x7e

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
