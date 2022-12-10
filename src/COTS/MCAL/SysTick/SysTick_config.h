/* FILENAME: SysTick_config
 *  Author:  Ali El Bana
 *  Version:  V1.0
 *  DATE:   Sun 09/04/2022
 */
#ifndef _SysTick_config_H
#define _SysTick_config_H

/**********************************************************************************/
// SysTick Configurations //
/**********************************************************************************/

/**
 * @defgroup gpio_addresses GPIO Addresses
 *
 * @{
 */

/**
 * @def GPIOA_BASE_ADDRESS
 * Port A Base address
 *
 */
/*options:
 *AHB_DividedBy8
 *AHB
 */
#define CLK_SOURCE AHB_DividedBy8
/** @} */

/**********************************************************************************/

/**
 * Options:
 * Dont_AssertRequest
 * AssertRequest
 */
#define Exception_Request AssertRequest

/**********************************************************************************/

/**
 * @defgroup interval_mode Systick Interval Mode Configuration
 *
 * @{
 */

/**
 * @def SINGLE_INTERVAL_MODE
 * @brief Single interval mode
 */
#define SINGLE_INTERVAL_MODE (1)
/**
 * @def PERIODIC_INTERVAL_MODE
 * @brief Periodic interval mode
 */
#define PERIODIC_INTERVAL_MODE (2)
/** @} */

#endif //_SysTick_config_H
