/**
 * @file MRCC_interface.h
 * @author Ali El Bana & Mo Alaa
 * @brief This file contains the interfacing information for the RCC module
 * @version 2.0
 * @date 11/9/2022
 */

/* Header file guard */
#ifndef MCAL_RCC_MRCC_INTERFACE_H_
#define MCAL_RCC_MRCC_INTERFACE_H_

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief Initialize the RCC with a certain configurations.
 */
void MRCC_vInit(void);

/**
 * @brief Enabling the CLK on a specific Peripheral.
 * @param[in] A_u32BusID Bus ID.
 * @param[in] A_u32PeriphralID Peripheral ID.
 */
void MRCC_vEnablePeriphralCLK(u32_t A_u32BusID, u32_t A_u32PeriphralID);

/**
 * @brief Disabling the CLK on a specific Peripheral.
 * @param[in] A_u32BusID Bus ID.
 * @param[in] A_u32PeriphralID Peripheral ID.
 */
void MRCC_vDisablePeriphralCLK(u32_t A_u32BusID, u32_t A_u32PeriphralID);

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @defgroup Bus ID options
 *
 * @{
 */

/**
 * @def RCC_AHB1
 * @brief AHB1 Bus
 *
 */
#define RCC_AHB1 1

/**
 * @def RCC_AHB2
 * @brief AHB2 Bus
 *
 */
#define RCC_AHB2 2

/**
 * @def RCC_APB1
 * @brief APB1 Bus
 *
 */
#define RCC_APB1 3

/**
 * @def RCC_APB2
 * @brief APB2 Bus
 *
 */
#define RCC_APB2 4

/**
 * @def RCC_AHB1LPENR
 * @brief peripheral clock enable in low power mode register
 *
 */
#define RCC_AHB1LPENR 5

/** @} */

/**
 * @defgroup Peripheral ID options
 *
 * @{
 */

/**
 * @def AHB1ENR_DMA2EN
 * @brief Enable CLK on DMA2 peripheral
 *
 */
#define AHB1ENR_DMA2EN 22

/**
 * @def AHB1ENR_DMA1EN
 * @brief Enable CLK on DMA1 peripheral
 *
 */
#define AHB1ENR_DMA1EN 21

/**
 * @def AHB1ENR_CRCEN
 * @brief Enable CLK on CRC peripheral
 *
 */
#define AHB1ENR_CRCEN 12

/**
 * @def AHB1ENR_GPIOHEN
 * @brief Enable CLK on GPIOH peripheral
 *
 */
#define AHB1ENR_GPIOHEN 7

/**
 * @def AHB1ENR_GPIOEEN
 * @brief Enable CLK on GPIOE peripheral
 *
 */
#define AHB1ENR_GPIOEEN 4

/**
 * @def AHB1ENR_GPIODEN
 * @brief Enable CLK on GPIOD peripheral
 *
 */
#define AHB1ENR_GPIODEN 3

/**
 * @def AHB1ENR_GPIOCEN
 * @brief Enable CLK on GPIOC peripheral
 *
 */
#define AHB1ENR_GPIOCEN 2

/**
 * @def AHB1ENR_GPIOBEN
 * @brief Enable CLK on GPIOB peripheral
 *
 */
#define AHB1ENR_GPIOBEN 1

/**
 * @def AHB1ENR_GPIOAEN
 * @brief Enable CLK on GPIOA peripheral
 *
 */
#define AHB1ENR_GPIOAEN 0

/**
 * @def AHB2ENR_OTGFSEN
 * @brief Enable CLK on OTGFS peripheral
 *
 */
#define AHB2ENR_OTGFSEN 7

/**
 * @def APB1ENR_PWREN
 * @brief Enable CLK on PWR peripheral
 *
 */
#define APB1ENR_PWREN 28

/**
 * @def APB1ENR_I2C3EN
 * @brief Enable CLK on I2C3 peripheral
 *
 */
#define APB1ENR_I2C3EN 23

/**
 * @def APB1ENR_I2C2EN
 * @brief Enable CLK on I2C2 peripheral
 *
 */
#define APB1ENR_I2C2EN 22

/**
 * @def APB1ENR_I2C1EN
 * @brief Enable CLK on I2C1 peripheral
 *
 */
#define APB1ENR_I2C1EN 21

/**
 * @def APB1ENR_USART2EN
 * @brief Enable CLK on USART2 peripheral
 *
 */
#define APB1ENR_USART2EN 17

/**
 * @def APB1ENR_SPI3EN
 * @brief Enable CLK on SPI3 peripheral
 *
 */
#define APB1ENR_SPI3EN 15

/**
 * @def APB1ENR_SPI2EN
 * @brief Enable CLK on SPI2 peripheral
 *
 */
#define APB1ENR_SPI2EN 14

/**
 * @def APB1ENR_WWDGEN
 * @brief Enable CLK on WWD peripheral
 *
 */
#define APB1ENR_WWDGEN 11

/**
 * @def APB1ENR_TIM5EN
 * @brief Enable CLK on TIM5 peripheral
 *
 */
#define APB1ENR_TIM5EN 3

/**
 * @def APB1ENR_TIM4EN
 * @brief Enable CLK on TIM4 peripheral
 *
 */
#define APB1ENR_TIM4EN 2

/**
 * @def APB1ENR_TIM3EN
 * @brief Enable CLK on TIM3 peripheral
 *
 */
#define APB1ENR_TIM3EN 1

/**
 * @def APB1ENR_TIM2EN
 * @brief Enable CLK on TIM2 peripheral
 *
 */
#define APB1ENR_TIM2EN 0

/**
 * @def APB2ENR_TIM11EN
 * @brief Enable CLK on TIM11 peripheral
 *
 */
#define APB2ENR_TIM11EN 18

/**
 * @def APB2ENR_TIM10EN
 * @brief Enable CLK on TIM10 peripheral
 *
 */
#define APB2ENR_TIM10EN 17

/**
 * @def APB2ENR_TIM9EN
 * @brief Enable CLK on TIM9 peripheral
 *
 */
#define APB2ENR_TIM9EN 16

/**
 * @def APB2ENR_SYSCFGEN
 * @brief Enable CLK on SYSCFG peripheral
 *
 */
#define APB2ENR_SYSCFGEN 14

/**
 * @def APB2ENR_SPI4EN
 * @brief Enable CLK on SPI4 peripheral
 *
 */
#define APB2ENR_SPI4EN 13

/**
 * @def APB2ENR_SPI1EN
 * @brief Enable CLK on SPI1 peripheral
 *
 */
#define APB2ENR_SPI1EN 12

/**
 * @def APB2ENR_SDIOEN
 * @brief Enable CLK on SDIO peripheral
 *
 */
#define APB2ENR_SDIOEN 11

/**
 * @def APB2ENR_ADC1EN
 * @brief Enable CLK on ADC1 peripheral
 *
 */
#define APB2ENR_ADC1EN 8

/**
 * @def APB2ENR_USART6EN
 * @brief Enable CLK on USART6 peripheral
 *
 */
#define APB2ENR_USART6EN 5

/**
 * @def APB2ENR_USART1EN
 * @brief Enable CLK on USART1 peripheral
 *
 */
#define APB2ENR_USART1EN 4

/**
 * @def APB2ENR_TIM1EN
 * @brief Enable CLK on TIM1 peripheral
 *
 */
#define APB2ENR_TIM1EN 0

/**
 * @def AHB1LPENR_FLITFLPEN
 * @brief Enable CLK on FLITFLP peripheral
 *
 */
#define AHB1LPENR_FLITFLPEN 15

/** @} */

#endif /* MCAL_RCC_MRCC_INTERFACE_H_ */
