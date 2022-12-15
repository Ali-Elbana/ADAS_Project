/* FILENAME: Testing_ADC_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 12/15/2022
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
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"
#include "../../../COTS/MCAL/ADC/ADC_interface.h"

#include "Testing_ADC_interface.h"
#include "Testing_ADC_private.h"
#include "Testing_ADC_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TMADC_vChangeBlinkingLEDTime(void)
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;

	MGPIOx_vLockedPins( ) ;

	MGPIOx_ConfigType LED =
	{

			.Port 			= GPIO_PORTB 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType ADC1_IN0 =
	{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN0 		,

			.Mode 			= GPIOx_MODE_ANALOG ,

	} ;

	MGPIOx_vInit( &LED ) ;

	MGPIOx_vInit( &ADC1_IN0 ) ;

	MSysTick_vInit( ) ;

	MADC_vInit( ) ;

	VAR(u16_t) L_u16DelayTime = INITIAL_ZERO ;

	VAR(u16_t) L_u16TickTime  = INITIAL_ZERO ;

	while( TRUE )
	{

		L_u16DelayTime = MADC_u16ConvertToDigital( CHANNEL0 ) ;

		L_u16TickTime  = 4500 - L_u16DelayTime  ;

		MGPIOx_vTogglePinValue( LED.Port, LED.Pin ) ;

		MSysTick_vDelayMilliSec( L_u16TickTime ) ;

	}

}

/**************************************************************************************/
/**************************************************************************************/


