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
	u32_t IMR;
	u32_t EMR;
	u32_t RTSR;
	u32_t FTSR;
	u32_t SWIER;
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
 * @defgroup exti_registers EXTI Registers
 *
 * @{
 */

/**
 * @def ENABLE
 * EXTI register
 * @todo Document this macro
 *
 */
#define ENABLE (1)
/**
 * @def DISABLE
 * EXTI register
 * @todo Document this macro
 *
 */
#define DISABLE (2)
/** @} */

/**
 * @defgroup exti_registers EXTI Registers
 *
 * @{
 */

/**
 * @def EXTI_IRQs
 * @todo Document this macro
 * EXTI register
 *
 */
#define EXTI_IRQs (23)
/** @} */

#endif //_EXTI_private_H
