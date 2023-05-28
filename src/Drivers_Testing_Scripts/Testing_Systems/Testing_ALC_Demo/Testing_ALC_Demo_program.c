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
#include "../../../COTS/MCAL/SPI/SPI_interface.h"
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"

#include "../../../COTS/HAL/LDR/LDR_interface.h"
#include "../../../COTS/HAL/LCD/LCD_interface.h"

#include "Testing_ALC_Demo_interface.h"
#include "Testing_ALC_Demo_private.h"
#include "Testing_ALC_Demo_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TSALC_vDispLux( void )
{

	u16_t L_u16BrightnessLevel = INITIAL_ZERO ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_TIM1EN  ) ;

	MGPIOx_vLockedPins( ) ;

	MSysTick_vInit( ) ;

	MTIM1_vGeneratePWM( TIM1_CH3, PWM1, CENTER1,
						PSC_VALUE, ARR_VALUE, CR_VALUE ) ;

	MTIM1_vEnableCounter( ) ;

	HLCD_vInit( ) ;

	HLDR_vInit( ) ;

	HLCD_vDispString( "Do:" ) ;

	while( TRUE )
	{

		/* Get ADC conversion */
		L_u16BrightnessLevel = HLDR_u16DigitalOutputValue( ) ;

		/* Go to the first line and square5 on the LCD */
		HLCD_vGoTo( HLCD_LINE1, HLCD_Square5 ) ;

		/* Display brightness number */
		HLCD_vDispNumber( L_u16BrightnessLevel ) ;

		/* Out the conversion value on the TIM1_CH3 */
		MTIM1_vSetCompareReg3Value( L_u16BrightnessLevel ) ;

		/* Delay 1ms */
		MSysTick_vDelayMilliSec( 1 ) ;

		/* Clear the old ADC conversion value */
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square5 ) ;
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square6 ) ;
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square7 ) ;
		HLCD_vClearChar( HLCD_LINE1, HLCD_Square8 ) ;

		/* Delay 1ms */
		MSysTick_vDelayMilliSec( 1 ) ;

	}

}

/**************************************************************************************/
/**************************************************************************************/




























