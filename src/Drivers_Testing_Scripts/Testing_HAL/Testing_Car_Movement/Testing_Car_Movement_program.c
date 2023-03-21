/* FILENAME: Testing_Car_Movement_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 03/14/2023
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

#include "../../../COTS/HAL/DCMOTOR/DCM_interface.h"
#include "../../../COTS/HAL/Car_Movement/Car_Movement_interface.h"

#include "Testing_Car_Movement_interface.h"
#include "Testing_Car_Movement_private.h"
#include "Testing_Car_Movement_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THCarMov_vTestCarMovement( void )
{

	#define DELLAY_SEC	5

	MRCC_vInit() ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_TIM1EN  ) ;

	MGPIOx_vLockedPins() ;

	MSysTick_vInit( ) ;

	HCarMove_vInit( ) ;

	MTIM1_vEnableCounter(  ) ;

	HCarMove_vSpeedRatio( SPEED_50_PERCENT ) ;

    while (TRUE)
    {

    	HCarMove_vForward( ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HCarMove_vBackward( ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HCarMove_vRight( ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HCarMove_vLeft( ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HCarMove_vStop( ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

    }

}

/**************************************************************************************/
/**************************************************************************************/















