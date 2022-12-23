/* FILENAME: Testing_GPIO_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 11/29/2022
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

#include "Testing_GPIO_interface.h"
#include "Testing_GPIO_private.h"
#include "Testing_GPIO_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TMGPIO_vPushPullOutputPins( void )
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

void TMGPIO_vPullDownInputPins( void )
{


	VAR( u8_t ) L_u8InputPIN ;

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

		L_u8InputPIN = MGPIOx_u8GetPinValue(switch1.Port, switch1.Pin) ;

		// Using DIP switch check those cases:
		if( L_u8InputPIN == 1 )
		{
			MGPIOx_vSetPinValue( LED1.Port, LED1.Pin, GPIOx_HIGH ) ;
		}

		else
		{
			MGPIOx_vSetPinValue( LED1.Port, LED1.Pin, GPIOx_LOW ) ;
		}

	}


}

/**************************************************************************************/
/**************************************************************************************/

void TMGPIO_vOpenDrainOutputPIN( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;

	MGPIOx_vLockedPins( ) ;

	MGPIOx_ConfigType switch1 =
	{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_INPUT 	,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_PullDown		// Connecting 3.3v to the input PIN

	} ;


	MGPIOx_ConfigType OD_PIN =
	{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_OPENDRAIN 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_PullUp

	} ;


	MGPIOx_vInit( &switch1 ) ;

	MGPIOx_vInit( &OD_PIN ) ;

	while( TRUE )
	{

		if( MGPIOx_u8GetPinValue(switch1.Port, switch1.Pin) == PRESSED )
		{

			// Debouncing the pressed period.
			while( MGPIOx_u8GetPinValue(switch1.Port, switch1.Pin) == PRESSED ) ;

			// Debouncing the released period.
			for( VAR( u32_t) i = INITIAL_ZERO; i < 2500; i++ ) ;

			// Do the Action.
			MGPIOx_vTogglePinValue( OD_PIN.Port, OD_PIN.Pin ) ;

		}

	}

}

/**************************************************************************************/
/**************************************************************************************/
void TMGPIO_vOutputPortValue( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;

	MGPIOx_vLockedPins( ) ;

	MGPIOx_ConfigType D0 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D0_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D1 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D1_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D2 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D2_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D3 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D3_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D4 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D4_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D5 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D5_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D6 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D6_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D7 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D7_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;


	MGPIOx_vInit( &D0 ) ;
	MGPIOx_vInit( &D1 ) ;
	MGPIOx_vInit( &D2 ) ;
	MGPIOx_vInit( &D3 ) ;
	MGPIOx_vInit( &D4 ) ;
	MGPIOx_vInit( &D5 ) ;
	MGPIOx_vInit( &D6 ) ;
	MGPIOx_vInit( &D7 ) ;

	GPIO_vSetPortValue( HLCD_DATA_PORT, GPIOA_LOW_NIBBLE_HIGH ) ;

	while (TRUE)
	{


	}


}


/**************************************************************************************/
/**************************************************************************************/


































