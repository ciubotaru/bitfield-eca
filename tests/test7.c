/**
 * File name: tests/test7.c
 * Project name: bitfield-eca, an implementation of elementary cellular
 * automata written in C.
 * URL: https://github.com/ciubotaru/bitfield-eca
 * Author: Vitalie Ciubotaru <vitalie at ciubotaru dot tk>
 * License: General Public License, version 3 or later
 * Date: May 18, 2019
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "eca.h"
#include "eca-internals.h"

/* Testing bmgetrow() */

int main()
{
	srand((unsigned)time(NULL));
	int wolfram_code, i, j;			//counter
	int len = 80;
	char *msg = "Testing bmgetrow()";
	char *failed = "[FAIL]";
	char *passed = "[PASS]";
	int dots = len - strlen(msg) - 6;	/* 6 is the length of pass/fail string */
	printf("%s", msg);
	for (i = 0; i < dots; i++)
		printf(".");

	struct bitfield *input_bf = bfnew(len);
	for (i = 0; i < len; i++) {
		if (rand() % 2) bfsetbit(input_bf, i);
	}
	struct bitmatrix *input_bm = bmnew(len, len);
	bmaddrow(input_bm, input_bf);

	/* try to retrieve bitfield from a null bitmatrix, shoul fsil */
	struct bitfield *output = bmgetrow(NULL, 0);
	if (output != NULL) {
		printf("%s\n", failed);
		return 1;
	}
	/* try to retriev bitfield beyond bitmatrix size, should fail */
	output = bmgetrow(input_bm, bmrows(input_bm));
	if (output != NULL) {
		printf("%s\n", failed);
		return 1;
	}
	/* try to retrieve actual bitfield, should work */
	output = bmgetrow(input_bm, bmrows(input_bm) - 1);
	if (!output) {
		printf("%s\n", failed);
		return 1;
	}
	/* compare with input data */
	if (bfcmp(input_bf, output, NULL) != 0) {
		printf("%s\n", failed);
		return 1;
	}
	printf("%s\n", passed);
	return 0;
}
