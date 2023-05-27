/**
 * @file SysTick_config.h
 * @brief Configuration file for SysTick driver
 * @details This file contains configurations for SysTick driver
 * @date 9/4/2021
 * @version 1.0
 * @author Ali El Bana
*/

#ifndef _SysTick_config_H
#define _SysTick_config_H

/**
 * @defgroup systick_configuration Systick Configuration
 *
 * @{
 */

/**
 * @def CLK_SOURCE
 * Clock source for SysTick
 * @note Accepted values: AHB_DividedBy8, AHB
 */
#define CLK_SOURCE AHB_DividedBy8

/**********************************************************************************/

/**
 * @def Exception_Request
 * Exception request for SysTick
 * @note Accepted values: Dont_AssertRequest, AssertRequest
 */
#define Exception_Request Dont_AssertRequest

/**********************************************************************************/

/**
 * @def SINGLE_INTERVAL_MODE
 * Single interval mode
 */
#define SINGLE_INTERVAL_MODE (1)

/**
 * @def PERIODIC_INTERVAL_MODE
 * Periodic interval mode
 */
#define PERIODIC_INTERVAL_MODE (2)

/**
 * @def MAX_TICKS
 * Maximum number of ticks
 */
#define MAX_TICKS (16777216)

/** @} */

#endif //_SysTick_config_H
