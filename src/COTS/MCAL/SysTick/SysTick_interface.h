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
 */
void MSysTick_vSetBusyWait(u32_t A_u32Ticks);

/**
 * @brief Synchronous delay function
 * @param[in] A_u32Ticks Number of ticks to delay for
 * @param[in] A_u32TickType Type of the delay
 */
void MSysTick_vDelay(u32_t A_u32Ticks, u32_t A_u32TickType);

/**
 * @brief Synchronous delay function
 * @param[in] A_u32Ticks Number of ticks to delay in micro seconds for
 */
void MSysTick_vDelayMicroSec(u32_t A_u32Ticks);

/**
 * @brief Synchronous delay function
 * @param[in] A_u32Ticks Number of ticks to delay in milli seconds for
 */
void MSysTick_vDelayMilliSec(u32_t A_u32Ticks);

/**
 * @brief Synchronous delay function
 * @param[in] A_u32Ticks Number of ticks to delay in seconds for
 */
void MSysTick_vDelaySec(u32_t A_u32Ticks);

/**
 * @brief Asynchronous 1-cycle delay function
 * @details This function counts down the ticks number, and when it reaches 0, it stops, unlike `MSysTick_vSetPeriodicInterval`
 * @param[in] A_u32Ticks Number of ticks to delay for
 * @param[in] A_Fptr Callback function to call when the countdown has finished
 */
void MSysTick_vSetSingleInterval(u32_t A_u32Ticks, void (*A_Fptr)(void));

/**
 * @brief Asynchronous repetitive delay function
 * @details This function counts down the ticks number, and when it reaches 0, it starts the countdown again
 * @param[in] A_u32Ticks Number of ticks to delay for
 * @param[in] A_Fptr Callback function to call when the countdown has finished
 * @see MSysTick_vSetSingleInterval for a 1-cycle delay function
 * @see MSysTick_vSetBusyWait for a synchronous delay function
 * @see MSysTick_vStopInterval to stop the interval delay function
 */
void MSysTick_vSetPeriodicInterval(u32_t A_u32Ticks, void (*A_Fptr)(void));

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

/**
 * @brief Enable the Systick Exception
 */
void MSysTick_vEnableException(void) ;

/**
 * @brief Disable the Systick Exception
 */
void MSysTick_vDisableException(void) ;

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @def BUSY_TICK_TIME
 * @brief Set the time you want to count when using the busy wait function
 */
#define BUSY_TICK_TIME (1000)

/**
 * @def SINGLE_INTERVAL_TICK_TIME
 * @brief Set the time you want to count when using the single interval function
 */
#define SINGLE_INTERVAL_TICK_TIME (1000)

/**
 * @def PERIODIC_INTERVAL_TICK_TIME
 * @brief @brief Set the time you want to count when using the periodic interval function
 */
#define PERIODIC_INTERVAL_TICK_TIME (1000)

/**
 * @defgroup delay_units Delay Units
 *
 * @{
 */

/**
 * @def MILLI_SEC
 * @brief Delay in milli seconds
 */
#define MILLI_SEC (1)

/**
 * @def MICRO_SEC
 * @brief Delay in micro seconds
 */
#define MICRO_SEC (2)

/**
 * @def SEC
 * @brief Delay in seconds
 */
#define SEC (3)
/** @} */

#endif //_SysTick_interface_H
