/**
 * @file GPIO_config.h
 * @author Ali El Bana & Mo Alaa
 * @brief This file contains the GPIO configurations
 * @version 2.0
 * @date 08/22/2022
 */

#ifndef _GPIO_config_H
#define _GPIO_config_H

/**********************************************************************************/
// GPIOx configurations //
/**********************************************************************************/

/**
 * @def GPIOA_PIN_POS
 * @brief lock PA13, PA14 and PA15
 *
 */
#define GPIOA_PIN_POS (0b1110000000000000) // I want to lock PA13,14,15.

/**
 * @def GPIOB_PIN_POS
 * @brief lock PB2, PB3 and PB4
 *
 */
#define GPIOB_PIN_POS (0b0000100000011100) // I want to lock PB2,3,4,11.

/**
 * @def LCKK_BIT_POS
 * @brief Position of LCKK bit
 *
 */
#define LCKK_BIT_POS (16U) // Position of LCKK bit.

/**
 * @def PORTA_BIT_MANIPULATION
 * @brief Port A data output manipulation mask
 */
#define PORTA_BIT_MANIPULATION 0xE000

/**
 * @def PORTB_BIT_MANIPULATION
 * @brief Port B data output manipulation mask
 */
#define PORTB_BIT_MANIPULATION 0x001C

#endif //_GPIO_config_H
