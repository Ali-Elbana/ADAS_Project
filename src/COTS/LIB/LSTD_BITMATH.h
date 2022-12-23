/**
 * @file LSTD_BITMATH.h
 * @author Ali El Bana
 * @brief This file contains the bit math manipulation macro-functions
 * @version 1.0
 * @date 10/29/2022
 */

#ifndef COTS_LIB_LSTD_BITMATH_H_
#define COTS_LIB_LSTD_BITMATH_H_

/**
 * @defgroup bitmath Bit Manipulation Math Macros 
 * 
 * @{
 */

/**
 * @def SET_BIT(Reg, bitnum)
 * Sets a certain bit's value
 *
 */
#define SET_BIT(Reg, bitnum) (Reg) |= (1 << (bitnum))

/**
 * @def CLR_BIT(Reg, bitnum)
 * Clears a certain bit's value to
 *
 */
#define CLR_BIT(Reg, bitnum) (Reg) &= ~(1 << (bitnum))

/**
 * @def TOGGLE_BIT(Reg, bitnum)
 * Toggle a bit to `0` if it's `1`, `1` otherwise
 *
 */
#define TOGGLE_BIT(Reg, bitnum) (Reg) ^= (1 << (bitnum))

/**
 * @def GET_BIT(Reg, bitnum)
 * Returns the value of the bit whether it's `1` or `0`
 *
 */
#define GET_BIT(Reg, bitnum)	(((Reg)>>(bitnum)) & 1)

/** @} */

/**
 * @defgroup bitmathgroup Bit Group Manipulation Math Macros
 *
 * @{
 */

/**
 * @def SET_BITs(Reg, bits, bitnum, factor)
 * Sets the values of a group of bits
 *
 */
#define SET_BITs(Reg, bits, bitnum, factor) (Reg) |= ((bits) << (bitnum * factor))

/**
 * @def CLR_BITs(Reg, bits, bitnum, factor)
 * Clears the value of a group of bits
 *
 */
#define CLR_BITs(Reg, bits, bitnum, factor) (Reg) &= ~((bits) << (bitnum * factor))

/**
 * @def TOGGLE_BITs(Reg, bits, bitnum, factor)
 * Toggles the value of a group of bits
 *
 */
#define TOGGLE_BITs(Reg, bits, bitnum, factor) (Reg) ^= ((bits) << (bitnum * factor))

/**
 * @def GET_BITs(Reg, bits, bitnum, factor)
 * Returns the value of a group of bits
 *
 */
#define GET_BITs(Reg, bits, bitnum, factor) (((Reg) >> (bitnum * factor)) & (bits))

/** @} */

#endif /* COTS_LIB_LSTD_BITMATH_H_ */
