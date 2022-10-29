/*
 * LSTD_MCU_UTILITIES.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Abo3a
 */

#ifndef COTS_LIB_LSTD_MCU_UTILITIES_H_
#define COTS_LIB_LSTD_MCU_UTILITIES_H_


#define My_ms_Delay(T)   do{ u32 Timer = (T * 500); while (Timer--) { asm ("nop"); } } while(0);


#endif /* COTS_LIB_LSTD_MCU_UTILITIES_H_ */
