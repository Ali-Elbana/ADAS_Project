/* FILENAME: Testing_RTOS_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 05/01/2023
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../COTS/LIB/LSTD_TYPES.h"
#include "../../COTS/LIB/LSTD_COMPILER.h"
#include "../../COTS/LIB/LSTD_VALUES.h"
#include "../../COTS/LIB/LSTD_BITMATH.h"

#include "../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../COTS/MCAL/NVIC/NVIC_interface.h"
#include "../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../COTS/MCAL/SysTick/SysTick_interface.h"

#include "../../COTS/HAL/LED/LED_interface.h"

#include "../../COTS/MyRTOS/MyRTOS_interface.h"

#include "Testing_RTOS_interface.h"
#include "Testing_RTOS_private.h"
#include "Testing_RTOS_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TRTOS_vBlinkLEDs( void )
{

	LED_LEDConfiguration GREEN =
	{
		.u8Port = GPIO_PORTA ,
		.u8Pin 	= GPIOx_PIN0
	} ;

	LED_LEDConfiguration BLUE =
	{
		.u8Port = GPIO_PORTA ,
		.u8Pin 	= GPIOx_PIN1
	} ;

	void ToggleGreenLED( void )
	{
		HLED_vToggleLight( &BLUE ) ;
	}

	void ToggleBlueLED( void )
	{
		HLED_vToggleLight( &BLUE ) ;
	}

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN  ) ;

	MGPIOx_vLockedPins( ) ;

	HLED_vInit( &GREEN ) ;
	HLED_vInit( &BLUE  ) ;

	RTOS_u8CreateTask( &ToggleGreenLED, 1 /* 100ms */, 0, 0 ) ;
	RTOS_u8CreateTask( &ToggleBlueLED , 2 /* 200ms */, 1, 0 ) ;

	RTOS_vStartOS( ) ;

	while( TRUE )
	{

	}

}

/**************************************************************************************/
/**************************************************************************************/












