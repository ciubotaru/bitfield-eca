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

unsigned int eca_string_ip(struct bitfield *instance, const unsigned int wolfram_code);	/* transforms an array of bits as an elementary cellular automaton given by Wolfram's code "in-place" */

struct bitfield *eca_string(const struct bitfield *input, const unsigned int wolfram_code);	/* transforms an array of bits as an elementary cellular automaton given by Wolfram's code */

unsigned int eca_ring_ip(struct bitfield *instance, const unsigned int wolfram_code);	/* treats the input array of bits as a ring and transforms it as an elementary cellular automaton given by Wolfram's code "in-place" */

struct bitfield *eca_ring(const struct bitfield *input, const unsigned int wolfram_code);	/* treats the input array of bits as a ring and transforms it as an elementary cellular automaton given by Wolfram's code */

#endif
