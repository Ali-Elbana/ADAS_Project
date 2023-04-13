/* FILENAME: Mob_APP_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sun 03/26/2023
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "stdlib.h"
#include "string.h"

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../HAL/Bluetooth/Bluetooth_interface.h"
#include "../../HAL/DCMOTOR/DCM_interface.h"
#include "../../HAL/Car_Movement/Car_Movement_interface.h"

#include "../ACC/ACC_interface.h"

#include "Mob_APP_interface.h"
#include "Mob_APP_private.h"
#include "Mob_APP_config.h"

static c8_t GS_c8RecievedButton = INITIAL_ZERO ;
static u32_t GS_u32SpeedValue 	= INITIAL_ZERO ;

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void AMobApp_vInit( void )
{

	// Initialization of Bluetooth Module
	HBluetooth_vInit( ) ;

	HBluetooth_vSendString( "\nSuccessfully connected\n" ) ;

}

/**************************************************************************************/
/**************************************************************************************/
void AMobApp_vSendSpeedValue( u8_t A_u8SpeedValue )
{

	char L_strSpeedIndc[6] = "*S" ;

	char L_strSpeedStr[4] ;

	// Convert the speed value from integer to string and store it in speedStr.
	itoa( A_u8SpeedValue, L_strSpeedStr, DECIMAL ) ;

	// Concatenate "*S" with the speed value string to result a string like that "*S100".
	strcat( L_strSpeedIndc, L_strSpeedStr ) ;

	// Concatenate speed value string with "*" to result a string like that "*S100*"
	strcat( L_strSpeedIndc, "*" ) ;

	// Then send this string through bluetooth to the speed indicator.
	HBluetooth_vSendString( L_strSpeedIndc ) ;

}

/**************************************************************************************/
/**************************************************************************************/

void AMobApp_vCntrlCar( void )
{

	do
	{

		GS_c8RecievedButton = HBluetooth_u8ReceiveByte( ) ;

		switch( GS_c8RecievedButton )
		{


			case 'a':

				AACC_vStopsCar( ) ;

			break ;

			case 'f':

				HCarMove_vForward( ) ;

				GS_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				AMobApp_vSendSpeedValue( GS_u32SpeedValue ) ;

			break ;

			case 'b':

				HCarMove_vBackward( ) ;

				GS_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				AMobApp_vSendSpeedValue( GS_u32SpeedValue ) ;

			break ;

			case 'r':

				HCarMove_vRight( ) ;

				GS_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				AMobApp_vSendSpeedValue( GS_u32SpeedValue ) ;

			break ;

			case 'l':

				HCarMove_vLeft( ) ;

				GS_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				AMobApp_vSendSpeedValue( GS_u32SpeedValue ) ;

			break ;

			case 's':

				HCarMove_vStop( ) ;

				HBluetooth_vSendString( "*S0*" ) ;

			break ;

			case 'e':

				HCarMove_vStop( ) ;

				HBluetooth_vSendString( "*S0*" ) ;

			break ;

			case '+':

				GS_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				if( GS_u32SpeedValue >= SPEED_100_PERCENT )
				{
					GS_u32SpeedValue = SPEED_100_PERCENT ;

					AMobApp_vSendSpeedValue( GS_u32SpeedValue ) ;
				}
				else
				{
					GS_u32SpeedValue += SPEED_10_PERCENT ;

					HCarMove_vSpeedRatio( GS_u32SpeedValue ) ;

					AMobApp_vSendSpeedValue( GS_u32SpeedValue ) ;
				}

			break ;

			case '-':

				GS_u32SpeedValue = HCarMove_u32GetCarSpeed(  ) ;

				if( GS_u32SpeedValue <= SPEED_0_PERCENT )
				{
					GS_u32SpeedValue = SPEED_0_PERCENT ;

					AMobApp_vSendSpeedValue( GS_u32SpeedValue ) ;
				}
				else
				{
					GS_u32SpeedValue -= SPEED_10_PERCENT ;

					HCarMove_vSpeedRatio( GS_u32SpeedValue ) ;

					AMobApp_vSendSpeedValue( GS_u32SpeedValue ) ;
				}

			break ;

			default: /* Do Nothing */ break ;

		}

	}while( GS_c8RecievedButton != 'e' ) ;

}

/**************************************************************************************/
/**************************************************************************************/



