/**
 * @file SYSCFG_private.h
 * @author Ali El Bana
 * @brief This file contains the private information regarding the SYSCFG
 * @details This is needed to ensure that the clocked is enabled for the EXTI module
 * @version 1.0
 * @date 09/01/2022
 */

/* Header file guard */
#ifndef MCAL_EXTI_SYSCFG_PRV_H_
#define MCAL_EXTI_SYSCFG_PRV_H_

/**
 * @brief System configuration structure to initialize the SYSCFG module with
 * @struct MSYSCFG_MemMap_t
 *
 */
typedef struct
{
	/**
	 * @brief Memory remap register
	 * @details This register is used for speicifc configurations on memory map
	 */
	u32_t MEMRMP;
	/**
	 * @brief Peripheral mode configuration register
	 */
	u32_t PMC;
	/**
	 * @brief External interrupt configuration *1-4* registers
	 */
	u32_t EXTICR[4];
	/**
	 * @brief Compensation cell control register
	 */
	u32_t CMPCR;
} MSYSCFG_MemMap_t;

/**
 * @defgroup syscfg_memory_addresses SYSCFG Memory Addresses
 *
 * @{
 */

/**
 * @def SYSCFG_BASE_ADDR
 * SYSCFG base address
 *
 */
#define SYSCFG_BASE_ADDR (0x40013800)
/** @} */
/**
 * @defgroup syscfg_memory_registers SYSCFG Memory Registers
 *
 * @{
 */

/**
 * @def MSYSCFG
 * SYSCFG register
 *
 */
#define MSYSCFG ((volatile MSYSCFG_MemMap_t *)(SYSCFG_BASE_ADDR))
/** @} */

#endif /* MCAL_EXTI_SYSCFG_PRV_H_ */
