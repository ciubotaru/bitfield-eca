/**
 * File name: examples/rule30.c
 * Project name: bitfield-eca, an implementation of elementary cellular
 * automata written in C.
 * URL: https://github.com/ciubotaru/bitfield-eca
 * Author: Vitalie Ciubotaru <vitalie at ciubotaru dot tk>
 * License: General Public License, version 3 or later
 * Date: January 7, 2017
**/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <eca.h>

int main()
{
	printf("Wolfram's Rule30 cellular automaton...\n");
	srand(time(NULL));
	int size = 80;
	int i;
	/* create an array of parent generation cells with 2 extra cells */
	struct bitfield *input = bfnew(size);
	/* randomly assign "dead" (0) or "alive" (1) status to parent generation */
	for (i = 0; i < bfsize(input); i++)
		if (rand() % 2 == 1)
			bfsetbit(input, i);
	/* show it */
	bfprint_lsb(input);
	printf("\n");

	struct bitfield *output = eca_string(input, 30);

	/* show it */
	printf(" ");
	bfprint_lsb(output);
	printf("\n");
	printf("---\n");
	return 0;
}
