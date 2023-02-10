/* FILENAME: Testing_TIM1_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 02/07/2023
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

//#include "../../../COTS/MCAL/GPIO/GPIO_private.h"

#include "../../../COTS/MCAL/NVIC/NVIC_interface.h"
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"
#include "../../../COTS/MCAL/TIM1/TIM1_interface.h"

#include "Testing_TIM1_interface.h"
#include "Testing_TIM1_private.h"
#include "Testing_TIM1_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TMTIM1_vGeneratePWM( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vLockedPins( ) ;

	MGPIOx_ConfigType T1_CH1 =
	{
		.Port 			= GPIO_PORTA 			, 	.Pin 		= GPIOx_PIN8 		,
		.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
		.OutputSpeed 	= GPIOx_LowSpeed		, 	.InputType 	= GPIOx_NoPull		,
		.AF_Type 		= GPIOx_AF1
	} ;

	MGPIOx_vInit( &T1_CH1 ) ;

	MSysTick_vInit( ) ;

	MTIM1_vPWMInit( TIM1_CH1 , PWM1, CENTER3,
					PSC_VALUE, ARR_VALUE, CR_VALUE ) ;

	while( TRUE )
	{

		for( u16_t L_u16Iteration = 0; L_u16Iteration < 1000; L_u16Iteration += 7 )
		{
			MTIM1_vSetCompareReg1Value( L_u16Iteration ) ;

			MSysTick_vDelayMilliSec( 50 ) ;
		}

	}


}

/**************************************************************************************/
/**************************************************************************************/










