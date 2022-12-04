/**
 * @file SysTick_interface.h
 * @author Ali El Bana
 * @brief This file contains the interfacing information for the Systick module
 * @version 1.0
 * @date 09/04/2022
 */

/* Header file guard */
#ifndef _SysTick_interface_H
#define _SysTick_interface_H

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief Initialize the Systick module
 */
void MSysTick_vInit(void);

/**
 * @brief Synchronous delay function
 * @param[in] A_u32Ticks Number of ticks to delay for
 * @see MSysTick_vSetPeriodicInterval for a interval asynchronous delay function
 * @see MSysTick_vSetSingleInterval for a 1-cycle asynchronous delay function
 */
void MSysTick_vSetBusyWait(VAR(u32_t) A_u32Ticks);

/**
 * @brief Asynchronous 1-cycle delay function
 * @details This function counts down the ticks number, and when it reaches 0, it stops, unlike `MSysTick_vSetPeriodicInterval`
 * @param[in] A_u32Ticks Number of ticks to delay for
 * @param[in] A_Fptr Callback function to call when the countdown has finished
 * @see MSysTick_vSetPeriodicInterval for a interval delay function
 * @see MSysTick_vSetBusyWait for a synchronous delay function
 */
void MSysTick_vSetSingleInterval(VAR(u32_t) A_u32Ticks, void (*A_Fptr)(void));

/**
 * @brief Asynchronous repetitive delay function
 * @details This function counts down the ticks number, and when it reaches 0, it starts the countdown again
 * @param[in] A_u32Ticks Number of ticks to delay for
 * @param[in] A_Fptr Callback function to call when the countdown has finished
 * @see MSysTick_vSetSingleInterval for a 1-cycle delay function
 * @see MSysTick_vSetBusyWait for a synchronous delay function
 * @see MSysTick_vStopInterval to stop the interval delay function
 */
void MSysTick_vSetPeriodicInterval(VAR(u32_t) A_u32Ticks, void (*A_Fptr)(void));

/**
 * @brief Stop the interval delay function
 * @see MSysTick_vSetPeriodicInterval for a interval delay function
 */
void MSysTick_vStopInterval(void);

/**
 * @brief Return the elapsed time since the start of the countdown
 * @return Return the elapsed time since the start of the countdown
 */
u32_t MSysTick_u32GetElapsedTime(void);

/**
 * @brief Return the remaining time in the systick register
 * @return The remaining time in the Systick register
 */
u32_t MSysTick_u32GetRemainingTime(void);

/**
 * @brief Enable the Systick timer
 */
void MSysTick_vEnable(void);

/**
 * @brief Disable the Systick timer
 */
void MSysTick_vDisable(void);

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @defgroup
 *
 * @{
 */

/**
 * @def TICK_TIME
 * @brief
 * @todo comment this macro
 */
#define TICK_TIME (3125)
/** @} */

#endif //_SysTick_interface_H
