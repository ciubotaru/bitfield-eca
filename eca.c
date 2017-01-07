/**
 * File name: eca.c
 * Project name: bitfield-eca, an implementation of elementary cellular
 * automata written in C.
 * URL: https://github.com/ciubotaru/bitfield-eca
 * Author: Vitalie Ciubotaru <vitalie at ciubotaru dot tk>
 * License: General Public License, version 3 or later
 * Copyright 2017
**/

#include "eca.h"

inline static struct bitfield *eca_0(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	int input_size = bfsize(left);
	struct bitfield *output = bfnew(input_size);
	return output;
}

inline static struct bitfield *eca_1(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_2(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfand(right, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_3(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *output = bfnot(tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_4(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfand(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_5(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *output = bfnot(tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_6(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *output = bfand(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_7(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(center, right);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_8(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfand(tmp1, center);
	struct bitfield *output = bfand(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_9(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfxor(center, right);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_10(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *output = bfand(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_11(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *output = bfxor(left, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_12(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *output = bfxor(tmp1, center);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_13(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfor(center, tmp1);
	struct bitfield *tmp3 = bfor(left, tmp2);
	struct bitfield *output = bfxor(left, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_14(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_15(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *output = bfnot(left);
	return output;
}

inline static struct bitfield *eca_16(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_17(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *output = bfnot(tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_18(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfnot(center);
	struct bitfield *output = bfand(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_19(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_20(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *output = bfand(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_21(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_22(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfxor(left, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_23(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *tmp3 = bfxor(center, right);
	struct bitfield *tmp4 = bfor(tmp2, tmp3);
	struct bitfield *output = bfxor(left, tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_24(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *output = bfand(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_25(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_26(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_27(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *output = bfxor(left, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_28(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_29(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *tmp3 = bfor(tmp2, center);
	struct bitfield *output = bfxor(left, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_30(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *output = bfxor(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_31(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_32(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfand(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_33(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfor(center, tmp1);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_34(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *output = bfand(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_35(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *output = bfxor(tmp3, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_36(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *output = bfand(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_37(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(center, right);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_38(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_39(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *output = bfxor(tmp3, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_40(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *output = bfand(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_41(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfxor(left, center);
	struct bitfield *tmp3 = bfxor(tmp2, right);
	struct bitfield *tmp4 = bfor(tmp1, tmp3);
	struct bitfield *output = bfnot(tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_42(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_43(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfnot(center);
	struct bitfield *tmp3 = bfxor(left, tmp2);
	struct bitfield *tmp4 = bfor(tmp1, tmp3);
	struct bitfield *output = bfxor(left, tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_44(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_45(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfor(center, tmp1);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_46(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(center, right);
	struct bitfield *output = bfxor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_47(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfnot(center);
	struct bitfield *tmp3 = bfand(tmp2, right);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_48(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *output = bfand(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_49(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfor(left, center);
	struct bitfield *tmp3 = bfor(tmp2, tmp1);
	struct bitfield *output = bfxor(tmp3, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_50(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_51(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *output = bfnot(center);
	return output;
}

inline static struct bitfield *eca_52(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfand(center, right);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_53(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfxor(center, tmp1);
	struct bitfield *tmp3 = bfor(left, tmp2);
	struct bitfield *output = bfxor(tmp3, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_54(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *output = bfxor(tmp1, center);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_55(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfand(tmp1, center);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_56(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfand(tmp1, center);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_57(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_58(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfxor(center, right);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_59(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *tmp3 = bfnot(center);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_60(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	struct bitfield *output = bfxor(left, center);
	return output;
}

inline static struct bitfield *eca_61(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 OR 3)) OR (1 XOR 2) */
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *tmp3 = bfxor(left, center);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_62(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) XOR (1 OR 2 OR 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(left, center);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *output = bfxor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_63(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT (1 AND 2) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *output = bfnot(tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_64(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND 2 AND (NOT 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *output = bfand(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_65(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 XOR 2) OR 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_66(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 3) AND (2 XOR 3) */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *output = bfand(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_67(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 AND 3) OR (1 XOR 2)) */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfxor(left, center);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_68(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 2 AND (NOT 3) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *output = bfand(center, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_69(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) OR 2 OR 3) XOR 3 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_70(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((1 AND 3) OR 2) XOR 3 */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_71(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR (NOT 3) OR 2) XOR 3 */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *tmp3 = bfor(tmp2, center);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_72(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 2 AND (1 XOR 3) */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *output = bfand(center, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_73(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 AND 3) OR (1 XOR 2 XOR 3)) */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfxor(left, center);
	struct bitfield *tmp3 = bfxor(tmp2, right);
	struct bitfield *tmp4 = bfor(tmp1, tmp3);
	struct bitfield *output = bfnot(tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_74(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND (2 OR 3)) XOR 3 */
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_75(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((NOT 2) OR 3 */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_76(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2 AND 3) XOR 2 */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_77(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((1 XOR 2) OR (1 XOR (NOT 3))) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *tmp3 = bfxor(left, tmp2);
	struct bitfield *tmp4 = bfor(tmp1, tmp3);
	struct bitfield *output = bfxor(left, tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_78(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((1 XOR 2) OR 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_79(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT 1) OR (2 AND (NOT 3)) */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *tmp3 = bfand(center, tmp2);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_80(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND (NOT 3) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *output = bfand(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_81(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR (NOT 2) OR 3) XOR 3 */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_82(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR (2 AND 3)) XOR 3 */
	struct bitfield *tmp1 = bfand(center, right);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_83(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR (2 XOR (NOT 3))) XOR 3 */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfxor(center, tmp1);
	struct bitfield *tmp3 = bfor(left, tmp2);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_84(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR 2 OR 3) XOR 3 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_85(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT 3 */
	struct bitfield *output = bfnot(right);
	return output;
}

inline static struct bitfield *eca_86(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR 2) XOR 3 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *output = bfxor(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_87(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 OR 2) AND 3) */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_88(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((1 OR 2) AND 3) */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_89(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR (NOT 2)) XOR 3 */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_90(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR 3 */
	struct bitfield *output = bfxor(left, right);
	return output;
}

inline static struct bitfield *eca_91(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR (NOT (2 OR 3))) XOR 3 */
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *tmp3 = bfor(left, tmp2);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_92(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR (2 XOR 3)) XOR 3 */
	struct bitfield *tmp1 = bfxor(center, right);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_93(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 OR (NOT 2)) AND 3) */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *tmp3 = bfand(tmp2, right);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_94(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT (1 AND 3) XOR (1 OR 2 OR 3) */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfor(left, center);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *output = bfxor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_95(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT (1 AND 3) */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *output = bfnot(tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_96(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND (2 XOR 3) */
	struct bitfield *tmp1 = bfxor(center, right);
	struct bitfield *output = bfand(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_97(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 XOR 2 XOR 3) OR (2 AND 3) */
	struct bitfield *tmp1 = bfxor(left,center);
	struct bitfield *tmp2 = bfxor(tmp1, right);
	struct bitfield *tmp3 = bfand(center, right);
	struct bitfield *tmp4 = bfor(tmp2, tmp3);
	struct bitfield *output = bfnot(tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_98(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((1 OR  3) AND 2) XOR 3 */
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfand(tmp1, center);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_99(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) OR 3) XOR 2 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_100(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((1 OR 2) AND 3) XOR 2 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_101(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) OR 2) XOR 3 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_102(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 2 XOR 3 */
	struct bitfield *output = bfxor(center, right);
	return output;
}

inline static struct bitfield *eca_103(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 OR 3)) OR (2 XOR 3) */
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *tmp3 = bfxor(center, right);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_104(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) XOR ((1 OR 2) AND 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(left, center);
	struct bitfield *tmp3 = bfand(tmp2, right);
	struct bitfield *output = bfxor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_105(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR 2 XOR (NOT 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *output = bfxor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_106(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) XOR 3 */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *output = bfxor(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_107(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) XOR ((NOT (1 OR 2)) OR 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(left, center);
	struct bitfield *tmp3 = bfnot(tmp2);
	struct bitfield *tmp4 = bfor(tmp3, right);
	struct bitfield *output = bfxor(tmp1, tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_108(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 3) XOR 2 */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *output = bfxor(tmp1, center);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_109(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT ((1 XOR 2)) AND (1 OR 3)) XOR 3 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfor(left, right);
	struct bitfield *tmp3 = bfand(tmp1, tmp2);
	struct bitfield *tmp4 = bfnot(tmp3);
	struct bitfield *output = bfxor(tmp4, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_110(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) AND 3) OR (2 XOR 3) */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *tmp3 = bfxor(center, right);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_111(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT 1) OR (2 XOR 3) */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_112(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (1 AND 2 AND 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_113(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (NOT ((1 XOR 2) OR (1 XOR 3))) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *tmp4 = bfnot(tmp3);
	struct bitfield *output = bfxor(left, tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_114(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((1 XOR 2) OR 3) XOR 2 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_115(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND (NOT 3)) OR (NOT 2) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *tmp3 = bfnot(center);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_116(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR 2) XOR (2 AND 3) */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfand(center, right);
	struct bitfield *output = bfxor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_117(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND (NOT 2)) OR (NOT 3) */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *tmp3 = bfnot(right);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_118(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR 2 OR 3) XOR (2 AND 3) */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *tmp3 = bfand(center, right);
	struct bitfield *output = bfxor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_119(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT (2 AND 3) */
	struct bitfield *tmp1 = bfand(center, right);
	struct bitfield *output = bfnot(tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_120(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (2 AND 3) */
	struct bitfield *tmp1 = bfand(center, right);
	struct bitfield *output = bfxor(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_121(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT ((1 XOR 2) AND (2 OR 3))) XOR 3 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfor(center, right);
	struct bitfield *tmp3 = bfand(tmp1, tmp2);
	struct bitfield *tmp4 = bfnot(tmp3);
	struct bitfield *output = bfxor(tmp4, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_122(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 3) OR ((NOT 2) AND 3) */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfnot(center);
	struct bitfield *tmp3 = bfand(tmp2, right);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_123(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT 2) OR (1 XOR 3) */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_124(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 2) OR (2 AND (NOT 3)) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *tmp3 = bfand(center, tmp2);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_125(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 2) OR (NOT 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_126(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 2) OR (1 XOR 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_127(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT (1 AND 2 AND 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_128(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND 2 AND 3 */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *output = bfand(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_129(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 XOR 2) OR (1 XOR 3)) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_130(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 2 XOR 3) AND 3 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(tmp1, right);
	struct bitfield *output = bfand(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_131(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 XOR 2)) AND ((NOT 1) OR 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *tmp3 = bfnot(left);
	struct bitfield *tmp4 = bfor(tmp3, right);
	struct bitfield *output = bfand(tmp2, tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_132(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 2 XOR 3) AND 2 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(tmp1, right);
	struct bitfield *output = bfand(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_133(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) OR 2) AND (NOT (1 XOR 3)) */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *tmp3 = bfxor(left, right);
	struct bitfield *tmp4 = bfnot(tmp3);
	struct bitfield *output = bfand(tmp2, tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_134(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND (2 OR 3)) XOR 2 XOR 3 */
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *tmp3 = bfxor(tmp2, center);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_135(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT 1) XOR (2 AND 3) */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfand(center, right);
	struct bitfield *output = bfxor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_136(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (2 AND 3) */
	struct bitfield *output = bfand(center, right);
	return output;
}

inline static struct bitfield *eca_137(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) OR 2 OR 3) XOR 2 XOR 3 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *tmp4 = bfxor(tmp3, center);
	struct bitfield *output = bfxor(tmp4, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_138(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) OR 2) AND 3 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *output = bfand(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_139(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 OR 2) XOR (2 AND 3)) */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfand(center, right);
	struct bitfield *tmp3 = bfxor(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_140(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) OR 3) AND 2 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfand(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_141(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((1 XOR 2) OR (NOT 3)) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfxor(left, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_142(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((1 XOR 2) OR (1 XOR 3)) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfxor(left, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_143(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT 1) OR (2 AND 3) */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfand(center, right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_144(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND (1 XOR 2 XOR 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(tmp1, right);
	struct bitfield *output = bfand(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_145(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT (((NOT 1) AND 3) OR (2 XOR 3)) */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *tmp3 = bfxor(center, right);
	struct bitfield *tmp4 = bfor(tmp2, tmp3);
	struct bitfield *output = bfnot(tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_146(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((1 OR 3) AND 2) XOR 3 */
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfand(tmp1, center);
	struct bitfield *tmp3 = bfxor(left, tmp2);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_147(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 3) XOR (NOT 2) */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfnot(center);
	struct bitfield *output = bfxor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_148(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((1 OR 2) AND 3) XOR 2 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *tmp3 = bfxor(left, tmp2);
	struct bitfield *output = bfxor(tmp3, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_149(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) XOR (NOT 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *output = bfxor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_150(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR 2 XOR 3 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *output = bfxor(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_151(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) XOR (NOT ((1 OR 2) AND 3)) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(left, center);
	struct bitfield *tmp3 = bfand(tmp2, right);
	struct bitfield *tmp4 = bfnot(tmp3);
	struct bitfield *output = bfxor(tmp1, tmp4);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_152(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR 2 OR 3) XOR 2 XOR 3 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *tmp3 = bfxor(tmp2, center);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_153(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 2 XOR (NOT 3) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *output = bfxor(center, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_154(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (1 AND 2) XOR 3 */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_155(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 OR 2) AND (2 XOR 3)) */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *tmp3 = bfand(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_156(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (1 AND 3) XOR 2 */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_157(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 OR 3) AND (2 XOR 3)) */
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *tmp3 = bfand(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_158(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 2 XOR 3) OR (2 AND 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(tmp1, right);
	struct bitfield *tmp3 = bfand(center, right);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_159(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT (1 AND (2 XOR 3)) */
	struct bitfield *tmp1 = bfxor(center, right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_160(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND 3 */
	struct bitfield *output = bfand(left, right);
	return output;
}

inline static struct bitfield *eca_161(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (1 OR (NOT 2) OR 3) XOR 3 */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *tmp3 = bfor(tmp2, right);
	struct bitfield *tmp4 = bfxor(left, tmp3);
	struct bitfield *output = bfxor(tmp4, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_162(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR (NOT 2)) AND 3 */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfand(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_163(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) OR (2 XOR 3)) XOR 2 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfxor(tmp3, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_164(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (1 OR 2 OR 3) XOR 3 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *tmp3 = bfxor(left, tmp2);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_165(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (NOT 3) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *output = bfxor(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_166(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) XOR 2 XOR 3 */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfxor(tmp1, center);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_167(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 OR 2) AND (1 XOR 3)) */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *tmp3 = bfand(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_168(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR 2) AND 3 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *output = bfand(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_169(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 OR 2)) XOR 3 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_170(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 3 */
	struct bitfield *output = bfclone(right);
	return output;
}

inline static struct bitfield *eca_171(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 OR 2)) OR 3 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_172(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND (2 XOR 3)) XOR 2 */
	struct bitfield *tmp1 = bfxor(center, right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_173(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR (NOT 3)) OR (2 AND 3) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *tmp3 = bfand(center, right);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_174(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((1 AND 2) XOR 2) OR 3 */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfxor(tmp1, center);
	struct bitfield *output = bfor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_175(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT 1) OR 3 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *output = bfor(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_176(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND ((NOT 2) OR 3) */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *output = bfand(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_177(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (NOT ((1 XOR 2) OR 3)) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *tmp3 = bfnot(tmp2);
	struct bitfield *output = bfxor(left, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_178(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((1 XOR 2) OR (1 XOR 3)) XOR 2 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfxor(tmp3, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_179(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND  3) OR (NOT 2) */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfnot(center);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_180(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR 2 XOR (2 AND 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfand(center, right);
	struct bitfield *output = bfxor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_181(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 XOR 3) AND (2 OR 3)) */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfor(center, right);
	struct bitfield *tmp3 = bfand(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_182(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 3) OR (1 XOR 2 XOR 3) */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfxor(left, center);
	struct bitfield *tmp3 = bfxor(tmp2, right);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_183(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 XOR 3) AND 2) */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfand(tmp1, center);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_184(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((1 XOR 3) AND 2) */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfand(tmp1, center);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_185(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 3) OR (2 XOR (NOT 3)) */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *tmp3 = bfxor(center, tmp2);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_186(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND (NOT 2)) OR 3 */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_187(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT 2) OR 3 */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *output = bfor(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_188(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 2) OR (2 AND 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfand(center, right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_189(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 2) OR (2 XOR (NOT 3)) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *tmp3 = bfxor(center, tmp2);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_190(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 2) OR 3 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *output = bfor(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_191(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 AND 2)) OR 3 */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_192(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND 2 */
	struct bitfield *output = bfand(left, center);
	return output;
}

inline static struct bitfield *eca_193(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (1 OR 2 OR (NOT 3)) XOR 2 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *tmp4 = bfxor(left, tmp3);
	struct bitfield *output = bfxor(tmp4, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_194(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (1 OR 2 OR 3) XOR 2 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfor(tmp1, right);
	struct bitfield *tmp3 = bfxor(left, tmp2);
	struct bitfield *output = bfxor(tmp3, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_195(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (NOT 2) */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *output = bfxor(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_196(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR (NOT 3)) AND 2 */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfand(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_197(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 OR (2 XOR 3))) XOR 2 */
	struct bitfield *tmp1 = bfxor(center, right);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *tmp3 = bfnot(tmp2);
	struct bitfield *output = bfxor(tmp3, center);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_198(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 3) XOR 2 XOR 3 */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfxor(tmp1, center);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_199(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 XOR 2) AND (1 OR 3)) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfor(left, right);
	struct bitfield *tmp3 = bfand(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_200(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 OR 3) AND 2 */
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *output = bfand(tmp1, center);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_201(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 OR 3)) XOR 2 */
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_202(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND (2 XOR 3)) XOR 3 */
	struct bitfield *tmp1 = bfxor(center, right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_203(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR (NOT 2)) OR (2 AND 3) */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *tmp3 = bfand(center, right);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_204(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 2 */
	struct bitfield *output = bfclone(center);
	return output;
}

inline static struct bitfield *eca_205(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 OR 3)) OR 2 */
	struct bitfield *tmp1 = bfor(left, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_206(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((NOT 1) AND 3) OR 2 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_207(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT 1) OR 2 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *output = bfor(tmp1, center);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_208(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND (2 OR (NOT 3)) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfor(center, tmp1);
	struct bitfield *output = bfand(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_209(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 AND 2) XOR (2 OR 3)) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(center, right);
	struct bitfield *tmp3 = bfxor(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_210(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (2 AND 3) XOR 3 */
	struct bitfield *tmp1 = bfand(center, right);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_211(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 XOR 2) AND (2 OR 3)) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfor(center, right);
	struct bitfield *tmp3 = bfand(tmp1, tmp2);
	struct bitfield *output = bfnot(tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_212(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((1 XOR 2) OR (1 XOR 3)) XOR 3 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfxor(left, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *output = bfxor(tmp3, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_213(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) OR (NOT 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_214(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) OR (1 XOR 2 XOR 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfxor(left, center);
	struct bitfield *tmp3 = bfxor(tmp2, right);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_215(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* NOT ((1 XOR 2) AND 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfnot(tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_216(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR ((1 XOR 2) AND 3) */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_217(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) OR (2 XOR (NOT 3)) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *tmp3 = bfxor(center, tmp2);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_218(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 3) OR (2 AND 3) */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfand(center, right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_219(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR 3) OR (1 XOR (NOT 2)) */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfnot(center);
	struct bitfield *tmp3 = bfxor(left, tmp2);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_220(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND (NOT 3)) OR 2 */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfand(left, tmp1);
	struct bitfield *output = bfor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_221(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 2 OR (NOT 3) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *output = bfor(center, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_222(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 2 OR (1 XOR 3) */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *output = bfor(center, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_223(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT (1 AND 3)) OR 2 */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_224(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 AND (2 OR 3) */
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *output = bfand(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_225(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 XOR (NOT (2 OR 3)) */
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfxor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_226(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((1 XOR 3) AND 2) XOR 3 */
	struct bitfield *tmp1 = bfxor(left, right);
	struct bitfield *tmp2 = bfand(tmp1, center);
	struct bitfield *output = bfxor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_227(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 3) OR (1 XOR (NOT 2)) */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *tmp2 = bfnot(center);
	struct bitfield *tmp3 = bfxor(left, tmp2);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_228(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* ((1 XOR 2) AND 3) XOR 2 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfxor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_229(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) OR (1 XOR (NOT 3)) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *tmp3 = bfxor(left, tmp2);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_230(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) OR (2 XOR 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfxor(center, right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_231(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR (NOT 2)) OR (2 XOR 3) */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *tmp3 = bfxor(center, right);
	struct bitfield *output = bfor(tmp2, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_232(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) OR ((1 OR 2) AND 3) */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *tmp2 = bfor(left, center);
	struct bitfield *tmp3 = bfand(tmp2, right);
	struct bitfield *output = bfor(tmp1, tmp3);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	return output;
}

inline static struct bitfield *eca_233(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT ((1 XOR 2) OR (2 AND 3))) XOR 3 */
	struct bitfield *tmp1 = bfxor(left, center);
	struct bitfield *tmp2 = bfand(center, right);
	struct bitfield *tmp3 = bfor(tmp1, tmp2);
	struct bitfield *tmp4 = bfnot(tmp3);
	struct bitfield *output = bfxor(tmp4, right);
	bfdel(tmp1);
	bfdel(tmp2);
	bfdel(tmp3);
	bfdel(tmp4);
	return output;
}

inline static struct bitfield *eca_234(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 2) OR 3 */
	struct bitfield *tmp1 = bfand(left, center);
	struct bitfield *output = bfor(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_235(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR (NOT 2)) OR 3 */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *output = bfor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_236(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 AND 3) OR 2 */
	struct bitfield *tmp1 = bfand(left, right);
	struct bitfield *output = bfor(tmp1, center);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_237(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (1 XOR (NOT 3)) OR 2 */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfxor(left, tmp1);
	struct bitfield *output = bfor(tmp2, center);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_238(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 2 OR 3 */
	struct bitfield *output = bfor(center, right);
	return output;
}

inline static struct bitfield *eca_239(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* (NOT 1) OR 2 OR 3 */
	struct bitfield *tmp1 = bfnot(left);
	struct bitfield *tmp2 = bfor(tmp1, center);
	struct bitfield *output = bfor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_240(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 */
	struct bitfield *output = bfclone(left);
	return output;
}

inline static struct bitfield *eca_241(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR (NOT (2 OR 3)) */
	struct bitfield *tmp1 = bfor(center, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_242(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR ((NOT 2) AND 3) */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfand(tmp1, right);
	struct bitfield *output = bfor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_243(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR (NOT 2) */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *output = bfor(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_244(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR (2 AND (NOT 3)) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfand(center, tmp1);
	struct bitfield *output = bfor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_245(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR (NOT 3) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *output = bfor(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_246(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR (2 XOR 3) */
	struct bitfield *tmp1 = bfxor(center, right);
	struct bitfield *output = bfor(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_247(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR (NOT (2 AND 3)) */
	struct bitfield *tmp1 = bfand(center, right);
	struct bitfield *tmp2 = bfnot(tmp1);
	struct bitfield *output = bfor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_248(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR (2 AND 3) */
	struct bitfield *tmp1 = bfand(center, right);
	struct bitfield *output = bfor(left, tmp1);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_249(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR (2 XOR (NOT 3)) */
	struct bitfield *tmp1 = bfnot(right);
	struct bitfield *tmp2 = bfxor(center, tmp1);
	struct bitfield *output = bfor(left, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_250(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR 3 */
	struct bitfield *output = bfor(left, right);
	return output;
}

inline static struct bitfield *eca_251(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR (NOT 2) OR 3 */
	struct bitfield *tmp1 = bfnot(center);
	struct bitfield *tmp2 = bfor(left, tmp1);
	struct bitfield *output = bfor(tmp2, right);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_252(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR 2 */
	struct bitfield *output = bfor(left, center);
	return output;
}

inline static struct bitfield *eca_253(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR 2 OR (NOT 3) */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *tmp2 = bfnot(right);
	struct bitfield *output = bfor(tmp1, tmp2);
	bfdel(tmp1);
	bfdel(tmp2);
	return output;
}

inline static struct bitfield *eca_254(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* 1 OR 2 OR 3 */
	struct bitfield *tmp1 = bfor(left, center);
	struct bitfield *output = bfor(tmp1, right);
	bfdel(tmp1);
	return output;
}

inline static struct bitfield *eca_255(const struct bitfield *left, const struct bitfield *center, const struct bitfield *right)
{
	/* a unit */
	int input_size = bfsize(left);
	struct bitfield *output = bfnew_ones(input_size);
	return output;
}

static struct bitfield * (*eca[256])() = {
	&eca_0,
	&eca_1,
	&eca_2,
	&eca_3,
	&eca_4,
	&eca_5,
	&eca_6,
	&eca_7,
	&eca_8,
	&eca_9,
	&eca_10,
	&eca_11,
	&eca_12,
	&eca_13,
	&eca_14,
	&eca_15,
	&eca_16,
	&eca_17,
	&eca_18,
	&eca_19,
	&eca_20,
	&eca_21,
	&eca_22,
	&eca_23,
	&eca_24,
	&eca_25,
	&eca_26,
	&eca_27,
	&eca_28,
	&eca_29,
	&eca_30,
	&eca_31,
	&eca_32,
	&eca_33,
	&eca_34,
	&eca_35,
	&eca_36,
	&eca_37,
	&eca_38,
	&eca_39,
	&eca_40,
	&eca_41,
	&eca_42,
	&eca_43,
	&eca_44,
	&eca_45,
	&eca_46,
	&eca_47,
	&eca_48,
	&eca_49,
	&eca_50,
	&eca_51,
	&eca_52,
	&eca_53,
	&eca_54,
	&eca_55,
	&eca_56,
	&eca_57,
	&eca_58,
	&eca_59,
	&eca_60,
	&eca_61,
	&eca_62,
	&eca_63,
	&eca_64,
	&eca_65,
	&eca_66,
	&eca_67,
	&eca_68,
	&eca_69,
	&eca_70,
	&eca_71,
	&eca_72,
	&eca_73,
	&eca_74,
	&eca_75,
	&eca_76,
	&eca_77,
	&eca_78,
	&eca_79,
	&eca_80,
	&eca_81,
	&eca_82,
	&eca_83,
	&eca_84,
	&eca_85,
	&eca_86,
	&eca_87,
	&eca_88,
	&eca_89,
	&eca_90,
	&eca_91,
	&eca_92,
	&eca_93,
	&eca_94,
	&eca_95,
	&eca_96,
	&eca_97,
	&eca_98,
	&eca_99,
	&eca_100,
	&eca_101,
	&eca_102,
	&eca_103,
	&eca_104,
	&eca_105,
	&eca_106,
	&eca_107,
	&eca_108,
	&eca_109,
	&eca_110,
	&eca_111,
	&eca_112,
	&eca_113,
	&eca_114,
	&eca_115,
	&eca_116,
	&eca_117,
	&eca_118,
	&eca_119,
	&eca_120,
	&eca_121,
	&eca_122,
	&eca_123,
	&eca_124,
	&eca_125,
	&eca_126,
	&eca_127,
	&eca_128,
	&eca_129,
	&eca_130,
	&eca_131,
	&eca_132,
	&eca_133,
	&eca_134,
	&eca_135,
	&eca_136,
	&eca_137,
	&eca_138,
	&eca_139,
	&eca_140,
	&eca_141,
	&eca_142,
	&eca_143,
	&eca_144,
	&eca_145,
	&eca_146,
	&eca_147,
	&eca_148,
	&eca_149,
	&eca_150,
	&eca_151,
	&eca_152,
	&eca_153,
	&eca_154,
	&eca_155,
	&eca_156,
	&eca_157,
	&eca_158,
	&eca_159,
	&eca_160,
	&eca_161,
	&eca_162,
	&eca_163,
	&eca_164,
	&eca_165,
	&eca_166,
	&eca_167,
	&eca_168,
	&eca_169,
	&eca_170,
	&eca_171,
	&eca_172,
	&eca_173,
	&eca_174,
	&eca_175,
	&eca_176,
	&eca_177,
	&eca_178,
	&eca_179,
	&eca_180,
	&eca_181,
	&eca_182,
	&eca_183,
	&eca_184,
	&eca_185,
	&eca_186,
	&eca_187,
	&eca_188,
	&eca_189,
	&eca_190,
	&eca_191,
	&eca_192,
	&eca_193,
	&eca_194,
	&eca_195,
	&eca_196,
	&eca_197,
	&eca_198,
	&eca_199,
	&eca_200,
	&eca_201,
	&eca_202,
	&eca_203,
	&eca_204,
	&eca_205,
	&eca_206,
	&eca_207,
	&eca_208,
	&eca_209,
	&eca_210,
	&eca_211,
	&eca_212,
	&eca_213,
	&eca_214,
	&eca_215,
	&eca_216,
	&eca_217,
	&eca_218,
	&eca_219,
	&eca_220,
	&eca_221,
	&eca_222,
	&eca_223,
	&eca_224,
	&eca_225,
	&eca_226,
	&eca_227,
	&eca_228,
	&eca_229,
	&eca_230,
	&eca_231,
	&eca_232,
	&eca_233,
	&eca_234,
	&eca_235,
	&eca_236,
	&eca_237,
	&eca_238,
	&eca_239,
	&eca_240,
	&eca_241,
	&eca_242,
	&eca_243,
	&eca_244,
	&eca_245,
	&eca_246,
	&eca_247,
	&eca_248,
	&eca_249,
	&eca_250,
	&eca_251,
	&eca_252,
	&eca_253,
	&eca_254,
	&eca_255
};

void eca_string_ip(struct bitfield *instance, const unsigned int wolfram_code)
{
	int size = bfsize(instance);
	struct bitfield *left = bfsub(instance, 2, size);
	struct bitfield *center = bfsub(instance, 1, size - 1);
	struct bitfield *right = bfsub(instance, 0, size - 2);
	bfresize(instance, size - 2);
	struct bitfield *output = eca[wolfram_code](left, center, right);
	bfcpy(output, instance);
	bfdel(left);
	bfdel(center);
	bfdel(right);
	bfdel(output);
}

struct bitfield *eca_string(const struct bitfield *input, const unsigned int wolfram_code)
{
	int input_size = bfsize(input);
	struct bitfield *left = bfsub(input, 2, input_size);
	struct bitfield *center = bfsub(input, 1, input_size - 1);
	struct bitfield *right = bfsub(input, 0, input_size - 2);
	struct bitfield *output = eca[wolfram_code](left, center, right);
	bfdel(left);
	bfdel(center);
	bfdel(right);
	return output;
}

void eca_ring_ip(struct bitfield *instance, const unsigned int wolfram_code)
{
	struct bitfield *left = bfshift(instance, -1);
	struct bitfield *right = bfshift(instance, 1);
	struct bitfield *output = eca[wolfram_code](left, instance, right);
	bfcpy(output, instance);
	bfdel(left);
	bfdel(right);
	bfdel(output);
}

struct bitfield *eca_ring(const struct bitfield *input, const unsigned int wolfram_code)
{
	struct bitfield *left = bfshift(input, -1);
	struct bitfield *right = bfshift(input, 1);
	struct bitfield *output = eca[wolfram_code](left, input, right);
	bfdel(left);
	bfdel(right);
	return output;
}
