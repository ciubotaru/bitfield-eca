/**
 * File name: tests/test3.c
 * Project name: bitfield-eca, an implementation of elementary cellular
 * automata written in C.
 * URL: https://github.com/ciubotaru/bitfield-eca
 * Author: Vitalie Ciubotaru <vitalie at ciubotaru dot tk>
 * License: General Public License, version 3 or later
 * Date: January 7, 2017
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eca.h"

/* Testing eca_ring() */

int main()
{
	int i, j;			//counter
	int len = 80;
	char *msg = "Testing eca_ring()";
	char *failed = "[FAIL]";
	char *passed = "[PASS]";
	int dots = len - strlen(msg) - 6;	/* 6 is the length of pass/fail string */
	printf("%s", msg);
	for (i = 0; i < dots; i++)
		printf(".");
	for (i = 0; i < 256; i++) {
		for (j = 0; j < 8; j++) {
			struct bitfield *input = int2bf( &j, 3);
			struct bitfield *output = eca_ring(input, i);
			unsigned char *output_char = bf2char(output);
			if (((output_char[0] >> 1) & 1) != (( i >> j) & 1)) {
				printf("%s\n", failed);
				printf("Failed algorythm was: eca_%i\n", i);
				bfdel(input);
				bfdel(output);
				return 1;
			}
			bfdel(input);
			bfdel(output);
			free(output_char);
		}
	}
	printf("%s\n", passed);
	return 0;
}
