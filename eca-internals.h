#ifndef CHAR_BIT
#include <limits.h>
#endif
//#ifndef SHORT_BIT
//#define SHORT_BIT (unsigned int) (sizeof(unsigned short) * CHAR_BIT)
//#endif
//#ifndef INT_BIT
//#define INT_BIT (unsigned int) (sizeof(unsigned int) * CHAR_BIT)
//#endif
#ifndef LONG_BIT
#define LONG_BIT (unsigned int) (sizeof(unsigned long) * CHAR_BIT)
#endif
//#ifndef LONG_LONG_BIT
//#define LONG_LONG_BIT (unsigned int) (sizeof(unsigned long long) * CHAR_BIT)
//#endif
//#define BITMASK(b) (1UL << ((b) % LONG_BIT))
//#define BITSLOT(bit_nr) ((bit_nr) / LONG_BIT)
//#define BITGET(bitmatrix_name, row_nr, bit_nr) (((bitmatrix_name)->matrix[row_nr][BITSLOT(bit_nr)] >> ((bit_nr) % LONG_BIT))  & 1UL)
//#define BITSET(bitmatrix_name, row_nr, bit_nr) ((bitmatrix_name)->matrix[row_nr][BITSLOT(bit_nr)] |= BITMASK(bit_nr))
//#define BITCLEAR(bitmatrix_name, row_nr, bit_nr) ((bitmatrix_name)->matrix[row_nr][BITSLOT(bit_nr)] &= ~BITMASK(bit_nr))
//#define BITTEST(bitmatrix_name, row_nr, bit_nr) ((bitmatrix_name)->matrix[row_nr][BITSLOT(bit_nr)] & BITMASK(bit_nr))
//#define BITTOGGLE(bitmatrix_name, row_nr, bit_nr) ((bitmatrix_name)->matrix[row_nr][BITSLOT(bit_nr)] ^= BITMASK(bit_nr))
#define BITNSLOTS(bitfield_size) (((bitfield_size) + LONG_BIT - 1) / LONG_BIT)

struct bitmatrix {
	unsigned long **matrix;
	unsigned int rows;
	unsigned int cols;
};
