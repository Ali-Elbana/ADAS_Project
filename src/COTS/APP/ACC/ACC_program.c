/* FILENAME: ACC_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 04/13/2023
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

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

u32_t L_u32SpeedValue 				= INITIAL_ZERO 	;
f32_t L_f32Distance 				= INITIAL_ZERO 	;
c8_t volatile G_c8ACCRecievedButton = INITIAL_ZERO 	;
u8_t volatile Gv_u8InISR		 	= FALSE			;

static VAR(HULTSNC_ConfigType)
TRIG =
      {
         .u8Port = GPIO_PORTB ,
         .u8Pin  = GPIOx_PIN8
      };

/**************************************************************************************/
/**************************************************************************************/

/* This is a call back RX function */
static void Button_vCurrentData( void )
{
	G_c8ACCRecievedButton 	= HBluetooth_u8GetDataRegister( ) 	;

	Gv_u8InISR		 		= TRUE								;
}

/**************************************************************************************/
/**************************************************************************************/

void AACC_vModeON( void )
{

	G_c8ACCRecievedButton 		= INITIAL_ZERO 	;
	Gv_u8InISR		 			= FALSE			;

	HBluetooth_vSendString( "\nACC Mode ON\n" ) ;

	HBluetooth_vEnableAsynchReceive( ) ;

	HBluetooth_u8AsynchReceiveByte( &Button_vCurrentData ) ;

	do
	{

		HULTSNC_vTrigger( &TRIG ) ;

		L_f32Distance = HULTSNC_f32GetDistance(  ) ;

		if( L_f32Distance < ACC_SAFE_DIST )
		{
			HCarMove_vStop( ) ;

			HBluetooth_vSendString( SPEED0_STR ) ;
		}
		else if( L_f32Distance >= ACC_SAFE_DIST + HYSTRS_VALUE )
		{
			HCarMove_vForward( ) ;

			L_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

			AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;
		}
		else
		{
			/* Do Nothing */
		}

		if( Gv_u8InISR == TRUE )
		{

			Gv_u8InISR = FALSE ;

			switch( G_c8ACCRecievedButton )
			{

				case EXIT_MODE_CHAR:

					HCarMove_vStop( ) ;

					HBluetooth_vSendString( SPEED0_STR ) ;

					HBluetooth_vSendString( "\nACC Mode Off\n" ) ;

					HBluetooth_u8AsynchReceiveByte( NULL ) ;

				break ;

				case INC_SPEED_CHAR:

					L_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

					if( L_u32SpeedValue >= SPEED_100_PERCENT )
					{
						L_u32SpeedValue = SPEED_100_PERCENT ;

						AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;
					}
					else
					{
						L_u32SpeedValue += SPEED_10_PERCENT ;

						HCarMove_vSpeedRatio( L_u32SpeedValue ) ;

						AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;
					}

				break ;

				case DEC_SPEED_CHAR:

					L_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

					if( L_u32SpeedValue <= SPEED_0_PERCENT )
					{
						L_u32SpeedValue = SPEED_0_PERCENT ;

						AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;
					}
					else
					{
						L_u32SpeedValue -= SPEED_10_PERCENT ;

						HCarMove_vSpeedRatio( L_u32SpeedValue ) ;

						AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;
					}

				break ;

				default: /* Do Nothing */ break ;
			}

		}
		else
		{
			/* Do nothing */
		}

	}while( G_c8ACCRecievedButton != EXIT_MODE_CHAR ) ;

}

/**************************************************************************************/
/**************************************************************************************/
























