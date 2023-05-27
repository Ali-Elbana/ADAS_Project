/**
 * @file EXTI_private.h
 * @author Ali El Bana
 * @brief This file contains the private information related to the EXTI module
 * @version 1.0
 * @date 09/02/2022
 */

/* Header file guard */
#ifndef _EXTI_private_H
#define _EXTI_private_H

/**
 * @brief EXTI Configuration structure for interrupt initialization process
 * @struct EXTI_Type
 *
 */
typedef struct
{
	/**
	 * @brief Interrupt mask register
	 */
	u32_t IMR;
	/**
	 * @brief Event mask register
	 */
	u32_t EMR;
	/**
	 * @brief Rising trigger status register
	 */
	u32_t RTSR;
	/**
	 * @brief Falling trigger status register
	 */
	u32_t FTSR;
	/**
	 * @brief Software interrupt event register
	 */
	u32_t SWIER;
	/**
	 * @brief Pending regiser
	 */
	u32_t PR;
} EXTI_Type;

/**
 * @defgroup exti_memory_addresses EXTI Memory Addresses
 *
 * @{
 */

/**
 * @def EXTI_BASE_ADDRESS
 * EXTI base address
 *
 */
#define EXTI_BASE_ADDRESS (0x40013C00)
/** @} */

/**
 * @defgroup exti_registers EXTI Registers
 *
 * @{
 */

/**
 * @def MEXTI
 * EXTI register
 *
 */
#define MEXTI ((volatile P2VAR(EXTI_Type))(EXTI_BASE_ADDRESS))
/** @} */

/**
 * @defgroup exti_line_status EXTI Lines Status
 *
 * @{
 */

/**
 * @def ENABLE
 * Enable a certain line ID from the config
 *
 */
#define ENABLE (1)
/**
 * @def DISABLE
 * Disable a certain line ID from the config
 *
 */
#define DISABLE (2)
/** @} */

/**
 * @defgroup exti_line_settings EXTI Line Settings
 *
 * @{
 */

/**
 * @def EXTI_MAX_EXTI_NUM
 * Maximum number of available interrupt lines
 *
 */
#define EXTI_MAX_EXTI_NUM (22)
/** @} */

/**
 * @def EXTI_IRQs
 * Number of available interrupt IRQs
 */
#define EXTI_IRQs 23


#endif //_EXTI_private_H
