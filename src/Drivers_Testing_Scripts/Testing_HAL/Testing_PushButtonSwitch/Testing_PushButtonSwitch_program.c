/* FILENAME: Testing_PushButtonSwitch_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 12/02/2022
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


#include "Testing_PushButtonSwitch_interface.h"
#include "Testing_PushButtonSwitch_private.h"
#include "Testing_PushButtonSwitch_config.h"


/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THPushButton( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;

	MGPIOx_vLockedPins( ) ;

	MGPIOx_ConfigType switch1 =
	{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_INPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_PullDown		// Connecting 3.3v to the input PIN

	} ;


	MGPIOx_ConfigType LED1 =
	{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

	} ;


	MGPIOx_vInit( &switch1 ) ;

	MGPIOx_vInit( &LED1 ) ;

	while( TRUE )
	{

		if( MGPIOx_u8GetPinValue(switch1.Port, switch1.Pin) == PRESSED )
		{

			// Debouncing the pressed period.
			while( MGPIOx_u8GetPinValue(switch1.Port, switch1.Pin) == PRESSED ) ;

			// Debouncing the released period.
			for( VAR( u32_t) i = INITIAL_ZERO; i < 2500; i++ ) ;

			// Do the Action.
			MGPIOx_vTogglePinValue( LED1.Port, LED1.Pin ) ;

		}

	}

}

/**************************************************************************************/
/**************************************************************************************/
































