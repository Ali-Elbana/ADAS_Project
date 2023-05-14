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

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "../../HAL/Bluetooth/Bluetooth_interface.h"
#include "../../HAL/DCMOTOR/DCM_interface.h"
#include "../../HAL/Car_Movement/Car_Movement_interface.h"
#include "../../HAL/UltraSonic/UltraSonic_interface.h"
#include "../../HAL/BUZZER/BUZZER_interface.h"

#include "../Traditional_Mode/Traditional_Mode_interface.h"
#include "../NCC/NCC_interface.h"
#include "../ACC/ACC_interface.h"
#include "../FCW/FCW_interface.h"
#include "../Exit_State/Exit_State_interface.h"

#include "Mob_APP_interface.h"
#include "Mob_APP_private.h"
#include "Mob_APP_config.h"

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
void AMobApp_vSendSpeedValue( u32_t A_u32SpeedValue )
{

	char L_strSpeedIndc[9] = "*S" ;

	char L_strSpeedStr[6] ;

	// Convert the speed value from integer to string and store it in speedStr.
	itoa( A_u32SpeedValue, L_strSpeedStr, DECIMAL ) ;

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

	c8_t L_c8RecievedState = TRAD_MODE_CHAR ;

	HBluetooth_vSendString( "\nCar is ready to be controlled\n" ) ;

	while( TRUE )
	{

		HBluetooth_vDisableAsynchReceive( ) ;

		HBluetooth_vSendString( "\nSelect one of these modes:\n" ) ;
		HBluetooth_vSendString( "\n1-Traditional Mode\n" ) ;
		HBluetooth_vSendString( "\n2-NCC Mode\n" ) ;
		HBluetooth_vSendString( "\n3-ACC Mode\n" ) ;
		HBluetooth_vSendString( "\n4-FCW Mode\n" ) ;
		HBluetooth_vSendString( "\n5-Exit Mode\n" ) ;

		L_c8RecievedState = HBluetooth_u8ReceiveByte( ) ;

		switch( L_c8RecievedState )
		{

			case TRAD_MODE_CHAR	: ATraditional_vModeON( ) ; break ;

			case NCC_MODE_CHAR	: ANCC_vModeON( ) 		  ; break ;

			case ACC_MODE_CHAR	: AACC_vModeON( )         ; break ;

			case FCW_MODE_CHAR	: AFCW_vModeON( )         ;	break ;

			default				: ATraditional_vModeON( ) ;	break ;

		}

	}

}

/**************************************************************************************/
/**************************************************************************************/








































