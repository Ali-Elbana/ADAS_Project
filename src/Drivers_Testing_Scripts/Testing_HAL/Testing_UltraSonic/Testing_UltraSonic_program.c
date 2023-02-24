/* FILENAME: Testing_UltraSonic_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 02/24/2023
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

#include "../../../COTS/HAL/UltraSonic/UltraSonic_interface.h"
#include "../../../COTS/HAL/BUZZER/BUZZER_interface.h"

#include "Testing_UltraSonic_interface.h"
#include "Testing_UltraSonic_private.h"
#include "Testing_UltraSonic_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TULTSNC_vMeasureDistance( void )
{

    VAR(HULTSNC_ConfigType)
    TRIG =
        {
            .u8Port = GPIO_PORTA ,
            .u8Pin  = GPIOx_PIN7
        };

    VAR(BUZZER_BuzzerConfiguration)
    BUZZER =
        {
            .u8Port = GPIO_PORTA ,
            .u8Pin  = GPIOx_PIN0
        };

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	// EN TIM1 CLK:
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_TIM1EN ) ;

	MGPIOx_vLockedPins( ) ;

	MSysTick_vInit( ) ;

	HULTSNC_vInit( &TRIG ) ;

	HBUZZER_vInit(&BUZZER) ;

    while (TRUE)
    {

    	f32_t L_f32Distance = INITIAL_ZERO ;

    	HBUZZER_vSoundOff( &BUZZER ) ;

    	HULTSNC_vTrigger( &TRIG ) ;

    	L_f32Distance = HULTSNC_f32GetDistance(  ) ;

    	if( L_f32Distance < 10 )
    	{
    		HBUZZER_vSoundOn( &BUZZER ) ;
    	}

    	else
    	{
    		HBUZZER_vSoundOff( &BUZZER ) ;
    	}

    }

}

/**************************************************************************************/
/**************************************************************************************/





