/**
 * @file SysTick_private.h
 * @author Ali El Bana
 * @brief This file contains the registers information and addresses for the Systick module
 * @version 1.0
 * @date 09/04/2022
 */

/* Header file guard */
#ifndef _SysTick_private_H
#define _SysTick_private_H

/**
 * @brief Systick memory map structure declaration for the Systick's registers
 * @struct SysTick_Type
 *
 */
typedef struct
{
	/**
	 * @brief Systick control and status register
	 * @details This register is responsible for enabling the systick features
	 */
	u32_t CTRL;
	/**
	 * @brief Systick reload value register
	 * @details This register is responsible for setting the countdown value
	 */
	u32_t LOAD;
	/**
	 * @brief Systick current value register
	 * @details This register holds the current value for the Systick counter
	 */
	u32_t VAL;
	/**
	 * @brief Systick calibration value register
	 * @details SysTick calibration value register
	 */
	u32_t CALIB;

} SysTick_Type;

/**
 * @defgroup systick_addresses Systick Addresses
 *
 * @{
 */

/**
 * @def SysTick_BASE_ADDRESS
 * Systick Base address
 *
 */

#define SysTick_BASE_ADDRESS (0xE000E010)

/** @} */

/**
 * @defgroup systick_registers Systick Registers
 *
 * @{
 */

/**
 * @def SysTick
 * Systick register
 *
 */
#define SysTick ((volatile P2VAR(SysTick_Type))(SysTick_BASE_ADDRESS))

/** @} */

/**
 * @defgroup systick_register_bits Systick Register Bits Positions
 *
 * @{
 */

/**
 * @def COUNTFLAG
 * This bit is responsible for keeping an eye on the timer whether it has counted to 0 or no, since the last time this was read
 * It returns 1 if the timer counted to 0, since last time this was read
 */
#define COUNTFLAG (16)

/**
 * @def CLKSOURCE
 * This bit is responsible for selecting the clock source for the Systick peripheral
 */
#define CLKSOURCE (2)

/**
 * @def TICKINT
 * This bit is responsible for controlling the exception request whether to enable or disable the request when reaching zero
 */
#define TICKINT (1)

/**
 * @def COUNTER_ENABLE
 * This bit is responsible for whether to enable the counter or no
 * When this is enabled, the counter loads the reload value from the load register and then starts countdowning.
 * On reaching 0, it sets the COUNTFLAG to 1 and optionally asserts the Systick depending on the value of TICKINT.
 * Then, it loads the reload value again and begins counting.
 * @see SysTick_Type::VAL
 * @see TICKINT
 */
#define COUNTER_ENABLE (0)
/** @} */

/**
 * @defgroup systick_clock_sources Systick Clock Sources
 * @{
 */

/**
 * @def AHB_DividedBy8
 * Set the clock source to divide the clock output of RCC by 8
 */
#define AHB_DividedBy8 (1)

/**
 * @def AHB
 * Set the clock source to the same as the clock output of RCC
 */
#define AHB (2)
/** @} */

/**
 * @defgroup systick_exception_request_enable Systick Exception (Interrupt) Status
 * @{
 */

/**
 * @def Dont_AssertRequest
 * Don't raise exception (interrupt) when the counter reaches 0
 */
#define Dont_AssertRequest (1)

/**
 * @def AssertRequest
 * Raise exception (interrupt) when the counter reaches 0
 */
#define AssertRequest (2)
/** @} */

#endif //_SysTick_private_H
