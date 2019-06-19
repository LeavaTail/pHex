#ifndef PRINT_H
#define PRINT_H

#define ASCIIFROM 0x21
#define ASCIITO   0x7e

#define BUFSIZE 16
#define LINESIZE 6
#define HEXSIZE 4
#define HEXCOUNT 8
#define COUNTSIZE 8

#define COUNTLINE (COUNTSIZE+1)
#define HEXLINE   (HEXSIZE * HEXCOUNT + HEXCOUNT)
#define DUMPLINE  (BUFSIZE+1)
#define MSGLINE   (COUNTLINE + HEXLINE + DUMPLINE + 1)

static int count;
extern int printmsg(unsigned char *data, int len);
#endif
