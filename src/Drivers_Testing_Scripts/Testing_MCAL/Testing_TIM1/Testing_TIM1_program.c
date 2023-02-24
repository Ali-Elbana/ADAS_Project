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

#include "../../../COTS/HAL/LED/LED_interface.h"

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

	MTIM1_vGeneratePWM( TIM1_CH3, PWM1, EDGE,
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

void TMTIM1_vMeasurePWM( void )
{

    VAR(LED_LEDConfiguration)
    LED =
        {
            .u8Port = GPIO_PORTA ,
            .u8Pin  = GPIOx_PIN0
        };

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vLockedPins( ) ;

	HLED_vInit(&LED) ;

	MSysTick_vInit( ) ;

	MTIM1_vGeneratePWM( TIM1_CH3, PWM1, CENTER1,
						PSC_VALUE, ARR_VALUE, CR_VALUE ) ;

	MTIM1_vReadPWM( ) ;

	MTIM1_vEnableCounter( ) ;

	while( TRUE )
	{

		MTIM1_vSetCompareReg3Value( 2000 ) ;

		f32_t L_f32TON 			= MTIM1_u16GetCaptureReg2Value( ) 	;

		f32_t L_f32DutyCycle 	= ( (float)( L_f32TON / ARR_VALUE ) * 100 )	;

		f32_t L_f32Period		= MTIM1_u16GetCaptureReg1Value( ) 	;

		if( L_f32DutyCycle == 50 )
		{
			HLED_vTurnLightOn(&LED);
		}

	}

}

/**************************************************************************************/
/**************************************************************************************/

void TMTIM1_vMeasurePulseTime( void )
{

	MGPIOx_ConfigType Pulse =
	{
		.Port 			= GPIO_PORTA		, .Pin 		 	= GPIOx_PIN12	 ,
		.Mode 		 	= GPIOx_MODE_OUTPUT	, .OutputType	= GPIOx_PUSHPULL ,
		.OutputSpeed 	= GPIOx_LowSpeed	, .InputType 	= GPIOx_NoPull
	} ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	// EN TIM1 CLK:
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_TIM1EN ) ;

	MGPIOx_vLockedPins( ) ;

	MGPIOx_vInit( &Pulse ) ;

	MSysTick_vInit( ) ;

	MTIM1_vSetPrescalerValue( 7 ) ;

	MTIM1_vSetAutoReloadValue( 10000 ) ;

	MTIM1_vReadPWM( ) ;

	MTIM1_vEnableCounter( ) ;

	while( TRUE )
	{

		//MTIM1_vSetCounterValue( 0x0000 ) ;

		MGPIOx_vSetResetAtomic( Pulse.Port, Pulse.Pin, GPIOx_LOW ) ;

		MSysTick_vDelayMicroSec( 2 ) ;

		MGPIOx_vSetResetAtomic( Pulse.Port, Pulse.Pin, GPIOx_HIGH ) ;

		//MTIM1_vEnableCounter( ) ;

		MSysTick_vDelayMicroSec( 1000 ) ;

		//MTIM1_vDisableCounter( ) ;

		MGPIOx_vSetResetAtomic( Pulse.Port , Pulse.Pin , GPIOx_LOW  ) ;

		u16_t L_u16Counts1	= MTIM1_u16GetCaptureReg1Value( ) 	;

		u16_t L_u16Counts2 	= MTIM1_u16GetCaptureReg2Value( ) 	;

	}

}

/**************************************************************************************/
/**************************************************************************************/







