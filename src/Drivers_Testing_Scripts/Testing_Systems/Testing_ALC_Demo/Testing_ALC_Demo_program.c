/* FILENAME: Testing_ALC_Demo_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 12/23/2022
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
#include "../../../COTS/HAL/LCD/LCD_interface.h"

#include "Testing_ALC_Demo_interface.h"
#include "Testing_ALC_Demo_private.h"
#include "Testing_ALC_Demo_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

FUNC( void ) TSALC_vDispLux( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vLockedPins() ;

	HLCD_vInit() ;

	MGPIOx_ConfigType LED1 =
	{

		.Port 		= GPIO_PORTB, .Pin = GPIOx_PIN0, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_vInit( &LED1 ) ;

	VAR(u16_t) L_u16BrightnessLevel = INITIAL_ZERO ;

	HLDR_vInit( ) ;

	HLCD_vDispString( "LUX:" ) ;

	HLCD_vGoTo( HLCD_LINE2, HLCD_Square1 ) ;

	HLCD_vDispString( "Steps:" ) ;

	while( TRUE )
	{

		L_u16BrightnessLevel = HLDR_u16DigitalOutputValue( ) ;

		HLCD_vGoTo( HLCD_LINE2, HLCD_Square7 ) ;

		HLCD_vDispNumber( L_u16BrightnessLevel ) ;


		if( L_u16BrightnessLevel < VERY_DIM )
		{
			MGPIOx_vSetPinValue( LED1.Port, LED1.Pin, GPIOx_LOW ) ;

			HLCD_vGoTo( HLCD_LINE1, HLCD_Square5 ) ;

			HLCD_vDispString( "VERY BRIGHT" ) ;

			HLCD_vGoTo( HLCD_LINE2, HLCD_Square7 ) ;

			HLCD_vDispNumber( L_u16BrightnessLevel ) ;
		}

		else if( L_u16BrightnessLevel > DARK )
		{
			MGPIOx_vSetPinValue( LED1.Port, LED1.Pin, GPIOx_HIGH ) ;

			HLCD_vGoTo( HLCD_LINE1, HLCD_Square5 ) ;

			HLCD_vDispString( "VERY DARK  " ) ;

			HLCD_vGoTo( HLCD_LINE2, HLCD_Square7 ) ;

			HLCD_vDispNumber( L_u16BrightnessLevel ) ;
		}

	}

}

/**************************************************************************************/
/**************************************************************************************/




























