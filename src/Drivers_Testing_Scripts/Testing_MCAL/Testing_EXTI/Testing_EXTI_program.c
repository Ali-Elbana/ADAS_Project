/* FILENAME: Testing_EXTI_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 12/09/2022
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

#include "Testing_EXTI_interface.h"
#include "Testing_EXTI_private.h"
#include "Testing_EXTI_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void ToggleLED( void )
{

	MGPIOx_vTogglePinValue( GPIO_PORTA, GPIOx_PIN1 ) ;

}



void TMEXTI_vToggleLED( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_SYSCFGEN ) ;

	MGPIOx_vLockedPins( ) ;

	MGPIOx_ConfigType LED =
	{

		.Port 			= GPIO_PORTA 		,

		.Pin 			= GPIOx_PIN1 		,

		.Mode 			= GPIOx_MODE_OUTPUT ,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_NoPull

	};

	MGPIOx_ConfigType IRQ =
	{

		.Port 			= GPIO_PORTA 		,

		.Pin 			= GPIOx_PIN0 		,

		.Mode 			= GPIOx_MODE_INPUT 	,

		.OutputType 	= GPIOx_NoPull 		,

		.OutputSpeed 	= GPIOx_LowSpeed 	,

		.InputType 		= GPIOx_PullDown
	};

	EXTI_ConfigType EXTI0_Config =
	{

		.LineNum = EXTI_LINE0 ,

		.PortNum = GPIO_PORTA ,

		.TriggerStatus = EXTI_FallingEdge

	};


	MGPIOx_vInit( &LED ) ;

	MGPIOx_vInit( &IRQ ) ;

	MNVIC_vEnablePeriphral( EXTI0 ) ;

	MEXTI_vSetCallback( EXTI_LINE0, ToggleLED ) ;

	MEXTI_vInit_WithStruct( &EXTI0_Config ) ;

	while( TRUE ) ;

}

/**************************************************************************************/
/**************************************************************************************/







