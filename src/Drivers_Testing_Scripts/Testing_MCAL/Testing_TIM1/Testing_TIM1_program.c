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

	MSysTick_vInit( ) ;

	MTIM1_vGeneratePWM( TIM1_CH3, PWM1, CENTER1,
						PSC_VALUE, ARR_VALUE, CR_VALUE ) ;

	MTIM1_vEnableCounter( ) ;

	while( TRUE )
	{

		for( u16_t L_u16Iteration = 0; L_u16Iteration < ARR_VALUE; L_u16Iteration += 100 )
		{
			MTIM1_vSetCompareReg3Value( L_u16Iteration ) ;

			MSysTick_vDelayMilliSec( 30 ) ;
		}

	}


}

/**************************************************************************************/
/**************************************************************************************/










