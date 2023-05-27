/* FILENAME: Testing_LDR_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 12/22/2022
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../COTS/LIB/LSTD_COMPILER.h"
#include "../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"

#include "../../../COTS/HAL/LDR/LDR_interface.h"

#include "Testing_LDR_interface.h"
#include "Testing_LDR_private.h"
#include "Testing_LDR_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TMLDR_vLightLEDsWithLevels(void)
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;

	MGPIOx_vLockedPins() ;

	MGPIOx_ConfigType LED1 =
	{

		.Port 		= GPIO_PORTB, .Pin = GPIOx_PIN5, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType LED2 =
	{

		.Port 		= GPIO_PORTB, .Pin = GPIOx_PIN6, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType LED3 =
	{

		.Port 		= GPIO_PORTB, .Pin = GPIOx_PIN7, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType LED4 =
	{

		.Port 		= GPIO_PORTB, .Pin = GPIOx_PIN8, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType LED5 =
	{

		.Port 		= GPIO_PORTB, .Pin = GPIOx_PIN9, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType LED6 =
	{

		.Port 		= GPIO_PORTB, .Pin = GPIOx_PIN10, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType LED7 =
	{

		.Port 		= GPIO_PORTB, .Pin = GPIOx_PIN12, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType LED8 =
	{

		.Port 		= GPIO_PORTB, .Pin = GPIOx_PIN13, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_vInit( &LED1 ) ;
	MGPIOx_vInit( &LED2 ) ;
	MGPIOx_vInit( &LED3 ) ;
	MGPIOx_vInit( &LED4 ) ;
	MGPIOx_vInit( &LED5 ) ;
	MGPIOx_vInit( &LED6 ) ;
	MGPIOx_vInit( &LED7 ) ;
	MGPIOx_vInit( &LED8 ) ;

	HLDR_vInit( ) ;

	u16_t L_u16BrightnessLevel = INITIAL_ZERO ;

	while( TRUE )
	{

		L_u16BrightnessLevel = HLDR_u16DigitalOutputValue( ) ;

		if( L_u16BrightnessLevel < DARK )
		{
			MGPIOx_vSetPinValue( LED1.Port, LED1.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED2.Port, LED2.Pin, GPIOx_LOW ) ;
			MGPIOx_vSetPinValue( LED3.Port, LED3.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED4.Port, LED4.Pin, GPIOx_LOW ) ;
			MGPIOx_vSetPinValue( LED5.Port, LED5.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED6.Port, LED6.Pin, GPIOx_LOW ) ;
			MGPIOx_vSetPinValue( LED7.Port, LED7.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED8.Port, LED8.Pin, GPIOx_LOW ) ;
		}

		else if( (L_u16BrightnessLevel > DARK) && (L_u16BrightnessLevel < VERY_DIM) )
		{
			MGPIOx_vSetPinValue( LED1.Port, LED1.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED2.Port, LED2.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetPinValue( LED3.Port, LED3.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED4.Port, LED4.Pin, GPIOx_LOW ) ;
			MGPIOx_vSetPinValue( LED5.Port, LED5.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED6.Port, LED6.Pin, GPIOx_LOW ) ;
			MGPIOx_vSetPinValue( LED7.Port, LED7.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED8.Port, LED8.Pin, GPIOx_LOW ) ;
		}

		else if( (L_u16BrightnessLevel > VERY_DIM) && (L_u16BrightnessLevel < MODERATE) )
		{
			MGPIOx_vSetPinValue( LED1.Port, LED1.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED2.Port, LED2.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetPinValue( LED3.Port, LED3.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED4.Port, LED4.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetPinValue( LED5.Port, LED5.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED6.Port, LED6.Pin, GPIOx_LOW ) ;
			MGPIOx_vSetPinValue( LED7.Port, LED7.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED8.Port, LED8.Pin, GPIOx_LOW ) ;
		}

		else if( (L_u16BrightnessLevel > MODERATE) && (L_u16BrightnessLevel < OVERCAST) )
		{
			MGPIOx_vSetPinValue( LED1.Port, LED1.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED2.Port, LED2.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetPinValue( LED3.Port, LED3.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED4.Port, LED4.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetPinValue( LED5.Port, LED5.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED6.Port, LED6.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetPinValue( LED7.Port, LED7.Pin, GPIOx_LOW ) ; MGPIOx_vSetPinValue( LED8.Port, LED8.Pin, GPIOx_LOW ) ;
		}

		else if( L_u16BrightnessLevel > OVERCAST )
		{
			MGPIOx_vSetPinValue( LED1.Port, LED1.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED2.Port, LED2.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetPinValue( LED3.Port, LED3.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED4.Port, LED4.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetPinValue( LED5.Port, LED5.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED6.Port, LED6.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetPinValue( LED7.Port, LED7.Pin, GPIOx_HIGH ) ; MGPIOx_vSetPinValue( LED8.Port, LED8.Pin, GPIOx_HIGH ) ;
		}

	}

}

/**************************************************************************************/
/**************************************************************************************/





