/* FILENAME: Testing_GPIO_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 11/29/2022
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../COTS/LIB/LSTD_TYPES.h"
#include "../../COTS/LIB/LSTD_COMPILER.h"
#include "../../COTS/LIB/LSTD_VALUES.h"
#include "../../COTS/LIB/LSTD_BITMATH.h"

#include "../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../COTS/MCAL/GPIO/GPIO_interface.h"

#include "Testing_GPIO_interface.h"
#include "Testing_GPIO_private.h"
#include "Testing_GPIO_config.h"

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

void TestingGPIO_OutputPins( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;

	MGPIOx_vLockedPins( ) ;

	MGPIOx_ConfigType LED1 =
	{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

	} ;


	MGPIOx_ConfigType LED2 =
	{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

	} ;


	MGPIOx_vInit( &LED1 ) ;

	MGPIOx_vInit( &LED2 ) ;


	while( TRUE )
	{

		MGPIOx_vSetResetAtomic( LED1.Port, LED1.Pin, GPIOx_HIGH ) ;
		MGPIOx_vSetResetAtomic( LED2.Port, LED2.Pin, GPIOx_HIGH ) ;

		for( VAR( u32_t) i = INITIAL_ZERO; i < 250000; i++ ) ;

		MGPIOx_vSetResetAtomic( LED1.Port, LED1.Pin, GPIOx_LOW ) ;
		MGPIOx_vSetResetAtomic( LED2.Port, LED2.Pin, GPIOx_LOW ) ;

		for( VAR( u32_t) i = INITIAL_ZERO; i < 250000; i++ ) ;

	}

}

/**************************************************************************************/
/**************************************************************************************/








































