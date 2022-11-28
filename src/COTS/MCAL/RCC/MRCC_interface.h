/**
 * @file MRCC_interface.h
 * @author Ali El Bana & Mo Alaa
 * @brief This file contains the interfacing information for the RCC module
 * @version 2.0
 * @date 11/9/2022
 */


#ifndef MCAL_RCC_MRCC_INTERFACE_H_
#define MCAL_RCC_MRCC_INTERFACE_H_



/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void MRCC_vInit( void ) ;

void MRCC_vEnablePeriphralCLK( u32_t A_u32BusID, u32_t A_u32PeriphralID ) ;

void MRCC_vDisablePeriphralCLK( u32_t A_u32BusID, u32_t A_u32PeriphralID ) ;


/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

// A_u32BusID options:
#define RCC_AHB1 		1
#define RCC_AHB2 		2
#define RCC_APB1 		3
#define RCC_APB2 		4
#define RCC_AHB1LPENR 	5

// A_u32PeriphralID options:
#define AHB1ENR_DMA2EN	  22
#define AHB1ENR_DMA1EN	  21
#define AHB1ENR_CRCEN	  12
#define AHB1ENR_GPIOHEN	  7
#define AHB1ENR_GPIOEEN	  4
#define AHB1ENR_GPIODEN	  3
#define AHB1ENR_GPIOCEN	  2
#define AHB1ENR_GPIOBEN	  1
#define AHB1ENR_GPIOAEN	  0

#define AHB2ENR_OTGFSEN	  7

#define APB1ENR_PWREN		28
#define APB1ENR_I2C3EN		23
#define APB1ENR_I2C2EN		22
#define APB1ENR_I2C1EN		21
#define APB1ENR_USART2EN	17
#define APB1ENR_SPI3EN		15
#define APB1ENR_SPI2EN		14
#define APB1ENR_WWDGEN		11
#define APB1ENR_TIM5EN		3
#define APB1ENR_TIM4EN		2
#define APB1ENR_TIM3EN		1
#define APB1ENR_TIM2EN		0

#define APB2ENR_TIM11EN		18
#define APB2ENR_TIM10EN		17
#define APB2ENR_TIM9EN		16
#define APB2ENR_SYSCFGEN	14
#define APB2ENR_SPI4EN		13
#define APB2ENR_SPI1EN		12
#define APB2ENR_SDIOEN		11
#define APB2ENR_ADC1EN		8
#define APB2ENR_USART6EN	5
#define APB2ENR_USART1EN	4
#define APB2ENR_TIM1EN		0



#define AHB1LPENR_FLITFLPEN 15




#endif /* MCAL_RCC_MRCC_INTERFACE_H_ */
