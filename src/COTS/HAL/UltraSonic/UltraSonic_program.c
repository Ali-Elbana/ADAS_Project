/* FILENAME: UltraSonic_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 02/24/2023
*/
/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/RCC/MRCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SysTick/SysTick_interface.h"
#include "../../MCAL/TIM1/TIM1_interface.h"

#include "UltraSonic_interface.h"
#include "UltraSonic_private.h"
#include "UltraSonic_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void HULTSNC_vInit( P2VAR(HULTSNC_ConfigType) TRIG_psCfg )
{

    VAR(MGPIOx_ConfigType) TRIG_Cfg =
    {
		.Port 			= TRIG_psCfg->u8Port, .Pin 		 	= TRIG_psCfg->u8Pin	,
		.Mode 		 	= GPIOx_MODE_OUTPUT	, .OutputType	= GPIOx_PUSHPULL 	,
		.OutputSpeed 	= GPIOx_LowSpeed	, .InputType 	= GPIOx_NoPull
    } ;

    MGPIOx_vInit( &TRIG_Cfg ) ;

	MTIM1_vSetPrescalerValue( 7 ) ;

	MTIM1_vSetAutoReloadValue( 60000 ) ;

	MTIM1_vReadPWM( ) ;

	MTIM1_vEnableCounter( ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HULTSNC_vTrigger( P2VAR(HULTSNC_ConfigType) TRIG_psCfg )
{

	MGPIOx_vSetResetAtomic( TRIG_psCfg->u8Port, TRIG_psCfg->u8Pin, GPIOx_LOW ) ;

	MSysTick_vDelayMicroSec( 2 ) ;

	MGPIOx_vSetResetAtomic( TRIG_psCfg->u8Port, TRIG_psCfg->u8Pin, GPIOx_HIGH ) ;

	MSysTick_vDelayMicroSec( 10 ) ;

	MGPIOx_vSetResetAtomic( TRIG_psCfg->u8Port, TRIG_psCfg->u8Pin, GPIOx_LOW  ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/

f32_t HULTSNC_f32GetDistance( void )
{

	f32_t L_f32PulseTime	= MTIM1_u16GetCaptureReg2Value( ) 	;

	f32_t L_f32Period		= MTIM1_u16GetCaptureReg1Value( ) 	;

	f32_t L_f32Distance		= INITIAL_ZERO						;

	L_f32Distance = (float)( L_f32PulseTime * 0.0174 ) ;

	return L_f32Distance ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/











