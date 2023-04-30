/* FILENAME: Testing_SysTick_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sat 12/10/2022
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
#include "../../../COTS/MCAL/EXTI/EXTI_interface.h"
#include "../../../COTS/MCAL/NVIC/NVIC_interface.h"
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"

#include "../../../COTS/HAL/LED/LED_interface.h"

#include "Testing_SysTick_interface.h"
#include "Testing_SysTick_private.h"
#include "Testing_SysTick_config.h"


/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TMSysTick_vToggleLED_BusyWait(void)
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vLockedPins( ) ;


	MGPIOx_ConfigType LED =
	{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

	} ;


	MGPIOx_vInit( &LED ) ;

	MSysTick_vInit( ) ;

	while( TRUE )
	{

		MGPIOx_vTogglePinValue( LED.Port, LED.Pin ) ;

		MSysTick_vDelaySec( 15 ) ; // 15 Secs

	}

}

/**************************************************************************************/
/**************************************************************************************/

void TMSysTick_vToggleLED_IRQ(void)
{

	LED_LEDConfiguration GREEN =
	{
		.u8Port = GPIO_PORTA ,
		.u8Pin 	= GPIOx_PIN0
	} ;

	void ToggleLED( void )
	{
		HLED_vToggleLight( &GREEN ) ;
	}

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;

	MGPIOx_vLockedPins( ) ;

	MSysTick_vInit( ) ;

	HLED_vInit( &GREEN  ) ;

	MSysTick_vSetPeriodicInterval( 100000, &ToggleLED ) ;

	while( TRUE )
	{

	}

}

/**************************************************************************************/
/**************************************************************************************/









