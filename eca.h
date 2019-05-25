/**
 * File name: eca.h
 * Project name: bitfield-eca, an implementation of elementary cellular
 * automata written in C.
 * URL: https://github.com/ciubotaru/bitfield-eca
 * Author: Vitalie Ciubotaru <vitalie at ciubotaru dot tk>
 * License: General Public License, version 3 or later
 * Copyright 2017
**/

#ifndef BITFIELD_ECA_H
#define BITFIELD_ECA_H
#include <bitfield.h>

struct bitmatrix;

unsigned int eca_string_ip(struct bitfield *instance, const unsigned int wolfram_code);	/* transforms an array of bits as an elementary cellular automaton given by Wolfram's code "in-place" */

struct bitfield *eca_string(const struct bitfield *input, const unsigned int wolfram_code);	/* transforms an array of bits as an elementary cellular automaton given by Wolfram's code */

unsigned int eca_ring_ip(struct bitfield *instance, const unsigned int wolfram_code);	/* treats the input array of bits as a ring and transforms it as an elementary cellular automaton given by Wolfram's code "in-place" */

struct bitfield *eca_ring(const struct bitfield *input, const unsigned int wolfram_code);	/* treats the input array of bits as a ring and transforms it as an elementary cellular automaton given by Wolfram's code */

struct bitmatrix *bmnew(const unsigned int rows, const unsigned int cols); /* creates a bitmatrix structure, sets all its bits to false and returns a pointer to it */

int bmaddrow(struct bitmatrix *instance, struct bitfield *addition);

struct bitfield *bmgetrow(struct bitmatrix *instance, const unsigned int row_nr);

int bmdelrow(struct bitmatrix *instance, const unsigned int row_nr);

void bmdel(struct bitmatrix *instance); /* destroys a bitmatrix structure and frees memory */

unsigned int bmrows(const struct bitmatrix *instance);

unsigned int bmcols(const struct bitmatrix *instance);

struct bitmatrix *eca_rev_bit(const unsigned int bit, const unsigned int wolfram_code);

struct bitmatrix *eca_rev_string(const struct bitfield *input, const unsigned int wolfram_code);

#endif
