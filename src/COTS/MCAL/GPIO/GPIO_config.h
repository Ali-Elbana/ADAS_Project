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

#define GPIOA_PIN_POS (0b1110000000000000)  //I want to lock PA13,14,15.
#define GPIOB_PIN_POS (0b0000000000011100)  //I want to lock PB2,3,4.
#define LCKK_BIT_POS (16U)   			    //Position of LCKK bit.


#endif //_GPIO_config_H
