/**
 * @file GPIO_private.h
 * @author Ali El Bana
 * @brief This file contains the registers information and addresses for the GPIO module
 * @version 1.0
 * @date 08/22/2022
 */

/* Header file guard */
#ifndef _GPIO_private_H
#define _GPIO_private_H

/**
 * @brief MDIO Configuration structure for a speific PIN initialization
 * @struct GPIOx_MemoryMapType
 *
 */
typedef struct
{
	/**
	 * @brief Control PIN mode whether **INPUT** or **OUTPUT**
	 */
	VAR(u32_t) MODERx;

	/**
	 * @brief Select the output type between push-pull or open-drain
	 */
	VAR(u32_t) OTYPERx;
	
	/**
	 * @brief Configure the speed that the PIN is connected to
	 */
	VAR(u32_t) OSPEEDRx;
	
	/**
	 * @brief Control the pull-up or pull-down of the pin, despite its directon
	 */
	VAR(u32_t) PUPDRx;
	
	/**
	 * @brief Read the input data
	 */
	VAR(u32_t) IDRx;
	
	/**
	 * @brief Write the output data
	 */
	VAR(u32_t) ODRx;
	
	/**
	 * @brief (Re)set each bit in the output data register
	 */
	VAR(u32_t) BSRRx;
	
	/**
	 * @brief Lock the GPIO control registers
	 */
	VAR(u32_t) LCKRx;
	
	/**
	 * @brief Control alternate function **LOW** register
	 */
	VAR(u32_t) AFRLx;
	
	/**
	 * @brief Control alternate function **HIGH** register
	 */
	VAR(u32_t) AFRHx;
} GPIOx_MemoryMapType;

/**
 * @defgroup gpio_addresses GPIO Addresses
 *
 * @{
 */

/**
 * @def GPIO_BASE_ADDRESS_A
 * Port A Base address
 *
 */
#define GPIO_BASE_ADDRESS_A (0x40020000)

/**
 * @def GPIO_BASE_ADDRESS_B
 * Port B Base address
 *
 */
#define GPIO_BASE_ADDRESS_B (0x40020400)

/**
 * @def GPIO_BASE_ADDRESS_C
 * Port C Base address
 *
 */
#define GPIO_BASE_ADDRESS_C (0x40020800)

/** @} */

/**
 * @defgroup gpio_registers GPIO Registers
 *
 * @{
 */

/**
 * @def GPIOA
 * GPIO register for port A
 *
 */
#define GPIOA ((volatile P2VAR(GPIOx_MemoryMapType))	(GPIO_BASE_ADDRESS_A))

/**
 * @def GPIOB
 * GPIO register for port B
 *
 */
#define GPIOB ((volatile P2VAR(GPIOx_MemoryMapType))	(GPIO_BASE_ADDRESS_B))

/**
 * @def GPIOC
 * GPIO register for port C
 *
 */
#define GPIOC ((volatile P2VAR(GPIOx_MemoryMapType))	(GPIO_BASE_ADDRESS_C))

/** @} */

#endif //_GPIO_private_H
