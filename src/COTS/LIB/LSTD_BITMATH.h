/*
 * LSTD_BITMATH.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Abo3a
 */

#ifndef COTS_LIB_LSTD_BITMATH_H_
#define COTS_LIB_LSTD_BITMATH_H_


#define SET_BIT(Reg, bitnum)		(Reg) |= (1<<(bitnum))
#define CLR_BIT(Reg, bitnum)		(Reg) &= ~(1<<(bitnum))
#define TOGGLE_BIT(Reg, bitnum)		(Reg) ^= (1<<(bitnum))
#define GET_BIT(Reg, bitnum)		(((Reg)>>(bitnum)) & 1)


#define SET_BITs(Reg, bits, bitnum, factor) 		(Reg) |= ((bits) << (bitnum * factor))
#define CLR_BITs(Reg, bits, bitnum, factor)     	(Reg) &= ~((bits) << (bitnum * factor))
#define TOGGLE_BITs(Reg, bits, bitnum, factor)		(Reg) ^= ((bits) << (bitnum * factor))
#define GET_BITs(Reg, bits, bitnum, factor)			(((Reg) >> (bitnum * factor)) & (bits))

#endif /* COTS_LIB_LSTD_BITMATH_H_ */
