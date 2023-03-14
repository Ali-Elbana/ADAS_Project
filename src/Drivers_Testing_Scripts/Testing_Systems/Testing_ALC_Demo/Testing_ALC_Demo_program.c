/* FILENAME: Testing_ALC_Demo_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 12/23/2022
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
#include "../../../COTS/MCAL/TIM1/TIM1_interface.h"
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"

#include "../../../COTS/HAL/LDR/LDR_interface.h"
#include "../../../COTS/HAL/LCD/LCD_interface.h"

#include "Testing_ALC_Demo_interface.h"
#include "Testing_ALC_Demo_private.h"
#include "Testing_ALC_Demo_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

FUNC( void ) TSALC_vDispLux( void )
{

	VAR(u16_t) L_u16BrightnessLevel = INITIAL_ZERO ;

	VAR(f32_t) L_f32SpeedValue 		= INITIAL_ZERO ;

	VAR(f32_t) L_f32SpeedRatio 		= INITIAL_ZERO ;

	VAR(f32_t) L_f32Period 			= INITIAL_ZERO ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vLockedPins() ;

	MSysTick_vInit( ) ;

	MTIM1_vGeneratePWM( TIM1_CH3, PWM1, CENTER1,
						PSC_VALUE, ARR_VALUE, CR_VALUE ) ;

	MTIM1_vReadPWM( ) ;

	MTIM1_vEnableCounter( ) ;

	HLCD_vInit( ) ;

	HLDR_vInit( ) ;

	HLCD_vDispString( "LUX:" ) ;

	HLCD_vGoTo( HLCD_LINE2, HLCD_Square1 ) ;

	HLCD_vDispString( "Speed:" ) ;

	while( TRUE )
	{

		/* Display Brightness number */
		L_u16BrightnessLevel = HLDR_u16DigitalOutputValue( ) ;

		HLCD_vGoTo( HLCD_LINE1, HLCD_Square5 ) ;

		HLCD_vDispNumber( L_u16BrightnessLevel ) ;

		MTIM1_vSetCompareReg3Value( L_u16BrightnessLevel ) ;

		/* Display Motors Speed Ratio */
		L_f32SpeedValue = MTIM1_u16GetCaptureReg2Value( ) 	;

		L_f32SpeedRatio = ( (float)( L_f32SpeedValue / ARR_VALUE ) * 100 )	;

		L_f32Period = MTIM1_u16GetCaptureReg1Value( ) 	;

		HLCD_vGoTo( HLCD_LINE2, HLCD_Square7 ) ;

		HLCD_vDispNumber( (u16_t)L_f32SpeedRatio ) ;

		if( L_f32SpeedRatio < 100 )
		{
			HLCD_vGoTo( HLCD_LINE2, HLCD_Square9 ) ;
			HLCD_vSendData( '%' ) ;
		}
		else
		{
			HLCD_vGoTo( HLCD_LINE2, HLCD_Square10 ) ;
			HLCD_vSendData( '%' ) ;
		}

		MSysTick_vDelayMilliSec( 1 ) ;

		HLCD_vClearChar( HLCD_LINE1, HLCD_Square5 ) ;
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square6 ) ;
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square7 ) ;
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square8 ) ;

		HLCD_vClearChar( HLCD_LINE2, HLCD_Square7 ) ;
		HLCD_vClearChar( HLCD_LINE2, HLCD_Square8 ) ;
		HLCD_vClearChar( HLCD_LINE2, HLCD_Square9 ) ;
		HLCD_vClearChar( HLCD_LINE2, HLCD_Square10 ) ;

		MSysTick_vDelayMilliSec( 1 ) ;

	}

}

/**************************************************************************************/
/**************************************************************************************/




























