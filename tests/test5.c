/**
 * File name: tests/test5.c
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

/* Testing bmnew(), bmaddrow(), bmdelrow() and bmdel() */

int main()
{
	srand((unsigned)time(NULL));
	int wolfram_code, i;			//counter
	int len = 80;
	char *msg = "Testing bmnew(), bmaddrow(), bmdelrow() and bmdel()";
	char *failed = "[FAIL]";
	char *passed = "[PASS]";
	int dots = len - strlen(msg) - 6;	/* 6 is the length of pass/fail string */
	printf("%s", msg);
	for (i = 0; i < dots; i++)
		printf(".");

	struct bitmatrix *input = bmnew(len, len / 2);
	if (!input) {
		printf("%s\n", failed);
		return 1;
	}
	/** randomly append and remove bitfields */
	struct bitfield *tmp = NULL;
	struct bitfield *tmp2 = NULL;
	int size;
	for (i = 0; i < len; i++) {
		int create;
		switch (bmrows(input)) {
			case 0:
				create = 1;
				break;
			case 80:
				create = 0;
				break;
			default:
				create = rand() % 2;
				break;
		}
		size = bmrows(input);
		if (create) {
			/** try to append a null bitfield to a real set -- should not work **/
			bmaddrow(input, tmp2);
			if (bmrows(input) != size) {
				printf("%s\n", failed);
				return 1;
			}

			tmp = bfnew(len);
			bmaddrow(input, tmp);
			if (bmrows(input) != size + 1) {
				printf("%s\n", failed);
				return 1;
			}
			bfdel(tmp);
		}
		else {
			bmdelrow(input, rand() % size);
			if (bmrows(input) != size - 1) {
				printf("%s\n", failed);
				return 1;
			}
		}
	}
	bmdel(input);
	printf("%s\n", passed);
	return 0;
}
