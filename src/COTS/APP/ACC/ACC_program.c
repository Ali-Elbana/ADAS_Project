/* FILENAME: ACC_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 04/13/2023
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "stdlib.h"

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "../../HAL/Bluetooth/Bluetooth_interface.h"
#include "../../HAL/DCMOTOR/DCM_interface.h"
#include "../../HAL/Car_Movement/Car_Movement_interface.h"
#include "../../HAL/UltraSonic/UltraSonic_interface.h"

#include "../Mob_APP/Mob_APP_interface.h"

#include "ACC_interface.h"
#include "ACC_private.h"
#include "ACC_config.h"


static VAR(HULTSNC_ConfigType)
TRIG =
      {
         .u8Port = GPIO_PORTB ,
         .u8Pin  = GPIOx_PIN8
      };

/**************************************************************************************/
/**************************************************************************************/

void AACC_vInit( void )
{

    HULTSNC_vInit( &TRIG ) ;

}

/**************************************************************************************/
/**************************************************************************************/

void AACC_vStopsCar( void )
{

	char distance[6] = "" ;

	u32_t L_u32SpeedValue = INITIAL_ZERO ;

	f32_t L_f32Distance = INITIAL_ZERO ;

	HULTSNC_vTrigger( &TRIG ) ;

	L_f32Distance = HULTSNC_f32GetDistance(  ) ;

	while( L_f32Distance < ACC_SAFE_DIST )
	{

		HCarMove_vStop( ) ;

		HBluetooth_vSendString( "*S0*" ) ;

    	HULTSNC_vTrigger( &TRIG ) ;

    	L_f32Distance = HULTSNC_f32GetDistance(  ) ;

	}

	HCarMove_vForward( ) ;

	L_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

	AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;

}

/**************************************************************************************/
/**************************************************************************************/
























