/* FILENAME: Testing_MobApp_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 03/28/2023
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

#include "../../../COTS/HAL/DCMOTOR/DCM_interface.h"
#include "../../../COTS/HAL/Car_Movement/Car_Movement_interface.h"

#include "../../../COTS/APP/Mob_APP/Mob_APP_interface.h"

#include "Testing_MobApp_interface.h"
#include "Testing_MobApp_private.h"
#include "Testing_MobApp_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TAMob_vMovesCar( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_TIM1EN   ) ;

	MGPIOx_vLockedPins( ) ;

	HCarMove_vInit( ) ;

	MTIM1_vEnableCounter( ) ;

	HCarMove_vSpeedRatio( SPEED_60_PERCENT ) ;

	AMobApp_vInit( ) ;

	while( TRUE )
	{

		AMobApp_vCntrlCar( ) ;

	}

}

/**************************************************************************************/
/**************************************************************************************/





/**************************************************************************************/
/**************************************************************************************/


















