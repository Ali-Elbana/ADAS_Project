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

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vLockedPins() ;

	HLCD_vInit( ) ;

	HLDR_vInit( ) ;

	MTIM1_vGeneratePWM( TIM1_CH3, PWM1, CENTER1,
						PSC_VALUE, ARR_VALUE, CR_VALUE ) ;

	MTIM1_vEnableCounter( ) ;

	HLCD_vDispString( "LUX:" ) ;

	HLCD_vGoTo( HLCD_LINE2, HLCD_Square1 ) ;

	HLCD_vDispString( "Speed:" ) ;

	while( TRUE )
	{

		L_u16BrightnessLevel = HLDR_u16DigitalOutputValue( ) ;

		HLCD_vGoTo( HLCD_LINE1, HLCD_Square5 ) ;

		HLCD_vDispNumber( L_u16BrightnessLevel ) ;

		MTIM1_vSetCompareReg3Value( L_u16BrightnessLevel ) ;

		HLCD_vClearChar( HLCD_LINE1, HLCD_Square5 ) ;
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square6 ) ;
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square7 ) ;
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square8 ) ;

	}

}

/**************************************************************************************/
/**************************************************************************************/




























