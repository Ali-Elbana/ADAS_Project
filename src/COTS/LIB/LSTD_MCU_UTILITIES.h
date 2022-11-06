/**
 * @file LSTD_MCU_UTILITIES.h
 * @author Ali El Bana
 * @brief This file contains the MCU utility macro-functions
 * @version 1.0
 * @date 10/29/2022
 */

#ifndef COTS_LIB_LSTD_MCU_UTILITIES_H_
#define COTS_LIB_LSTD_MCU_UTILITIES_H_
/**
 * @defgroup utilities Utilities macros
 *
 * @{
 */

/**
 * @def MY_MS_DELAY(T)
 * Declare a delay with a `T` microseconds with a NOP delay
 *
 */

#define MY_MS_DELAY(T)   do{ u32 Timer = (T * 500); while (Timer--) { asm ("nop"); } } while(0);

/** @} */

#endif /* COTS_LIB_LSTD_MCU_UTILITIES_H_ */
