/*
 * print.c
 *
 * Print data.
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
#include <string.h>

#include "print.h"

/*
 * printmsg: print message
 *   data: printed data
 *   len:  data length
 */
int printmsg(unsigned char *data, int len)
{
	int i;
	unsigned char msg[MSGLINE+1]  = "\0";
	unsigned char hex[HEXLINE+1]  = "\0";
	unsigned char dump[DUMPLINE+1]= "\0";
	sprintf(msg, "%08x:", count);

	for(i = 0; (i < len) && data[i]; i++){
		/* Hexadecimal case */
		sprintf(hex, "%s%s%02x", 
				hex,
				i % 2 ? "" : " ",
				data[i]);

		/* ASCII case */
		if((data[i] < ASCIIFROM) || (data[i] > ASCIITO))
			data[i] = '.';
		sprintf(dump,"%s%c", dump,((char*)data)[i]);	
		
		count++;
	}
	/* Last line */
	if(len < BUFSIZE) {
		len = strlen(hex);
		memset(hex+len, ' ', HEXLINE-len);
		hex[HEXLINE] = '\0';
	}

	sprintf(msg,"%s %s  %s",msg, hex, dump);
	printf("%s\n",msg);
	return count;
}


