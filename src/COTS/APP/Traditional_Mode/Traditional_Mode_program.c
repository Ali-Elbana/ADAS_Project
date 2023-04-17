/* FILENAME: Traditional_Mode_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 04/17/2023
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../HAL/Bluetooth/Bluetooth_interface.h"
#include "../../HAL/DCMOTOR/DCM_interface.h"
#include "../../HAL/Car_Movement/Car_Movement_interface.h"

#include "../Mob_APP/Mob_APP_interface.h"

#include "Traditional_Mode_interface.h"
#include "Traditional_Mode_private.h"
#include "Traditional_Mode_config.h"

/**************************************************************************************/
/**************************************************************************************/

void ATraditional_vModeON( void )
{

	u32_t L_u32SpeedValue 		= INITIAL_ZERO ;
	c8_t  L_c8RecievedButton 	= INITIAL_ZERO ;

	do
	{

		L_c8RecievedButton = HBluetooth_u8ReceiveByte( ) ;

		switch( L_c8RecievedButton )
		{

			case FORW_CHAR:

				HCarMove_vForward( ) ;

				L_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;

			break ;

			case BACKW_CHAR:

				HCarMove_vBackward( ) ;

				L_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;

			break ;

			case RIGHT_CHAR:

				HCarMove_vRight( ) ;

				L_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;

			break ;

			case LEFT_CHAR:

				HCarMove_vLeft( ) ;

				L_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				AMobApp_vSendSpeedValue( L_u32SpeedValue ) ;

			break ;

			case STOP_CHAR:

				HCarMove_vStop( ) ;

				HBluetooth_vSendString( SPEED0_STR ) ;

			break ;

			case EXIT_MODE_CHAR:

				HCarMove_vStop( ) ;

				HBluetooth_vSendString( SPEED0_STR ) ;

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

	}while( L_c8RecievedButton != EXIT_MODE_CHAR ) ;

}

/**************************************************************************************/
/**************************************************************************************/















