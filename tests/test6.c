/**
 * File name: tests/test6.c
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

/* Testing eca_rev_bit() */

int main()
{
	srand((unsigned)time(NULL));
	int wolfram_code, i, j;			//counter
	int len = 80;
	char *msg = "Testing eca_rev_bit()";
	char *failed = "[FAIL]";
	char *passed = "[PASS]";
	int dots = len - strlen(msg) - 6;	/* 6 is the length of pass/fail string */
	printf("%s", msg);
	for (i = 0; i < dots; i++)
		printf(".");

	struct bitmatrix *output = NULL;
	struct bitfield *input = NULL;
	struct bitfield *check = NULL;
	unsigned long *check_long = NULL;
//printf("\n");
	for (i = 0; i < 256; i++) {
//printf("Wolfram code %i\n", i);
		int bit = rand() % 2;
//printf("Input %i\n", bit);
		output = eca_rev_bit(bit, i);
		int nr_parents = bmrows(output);
//printf("Output %i parents\n", nr_parents);
		int nr_bits = __builtin_popcount(i);
		if ((bit == 1 && nr_parents != nr_bits) || (bit == 0 && nr_parents != 8 - nr_bits)) {
			printf("%s\n", failed);
			return 1;
		}
		/* testing parents */
		for (j = 0; j < nr_parents; j++) {
			input = long2bf(output->matrix[j], 3);
/**
bfprint_lsb(input);
printf("\n");
*/
			check = eca_string(input, i);
			check_long = bf2long(check);
			if (check_long[0] != bit) {
				printf("%s\n", failed);
				return 1;
			}
			bfdel(input);
			bfdel(check);
			free(check_long);
		}
		bmdel(output);
	}
	printf("%s\n", passed);
	return 0;
}
