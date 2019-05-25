/**
 * File name: tests/test8.c
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

/* Testing eca_rev_string() */

int main()
{
	srand((unsigned)time(NULL));
	int wolfram_code, i, j;			//counter
	int len = 80;
	char *msg = "Testing eca_rev_string()";
	char *failed = "[FAIL]";
	char *passed = "[PASS]";
	int dots = len - strlen(msg) - 6;	/* 6 is the length of pass/fail string */
	printf("%s", msg);
	for (i = 0; i < dots; i++)
		printf(".");

	struct bitfield *input = bfnew(len);
	for (i = 0; i < len; i++) {
		if (rand() % 2) bfsetbit(input, i);
	}

	struct bitmatrix *output = NULL;
	struct bitfield *output_bf = NULL;
	struct bitfield *check = NULL;
	unsigned long *check_long = NULL;
/*
printf("\n");
printf("Input:\n");
bfprint_lsb(input);
printf("\n");
*/
	for (i = 0; i < 256; i++) {
//printf("Wolfram code %i\n", i);
		output = eca_rev_string(input, i);
		int nr_parents = bmrows(output);
//printf("Output %i parents\n", nr_parents);
		for (j = 0; j < nr_parents; j++) {
			output_bf = bmgetrow(output, j);
			check = eca_string(output_bf, i);
			if (bfcmp(input, output_bf, NULL) != 0) {
				printf("%s\n", failed);
				return 1;
			}
			bfdel(output_bf);
			bfdel(check);
		}
		bmdel(output);
	}
	printf("%s\n", passed);
	return 0;
}
