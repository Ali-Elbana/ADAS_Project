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

#include "../../MCAL/RCC/MRCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "../../HAL/Bluetooth/Bluetooth_interface.h"
#include "../../HAL/DCMOTOR/DCM_interface.h"
#include "../../HAL/Car_Movement/Car_Movement_interface.h"

#include "Mob_APP_interface.h"
#include "Mob_APP_private.h"
#include "Mob_APP_config.h"


c8_t L_strRecievedButton[4] = "0" 		;
c8_t L_strExit[5] 			= "EXIT" 	;
c8_t L_strForward[2] 		= "F" 		;
c8_t L_strBackward[2] 		= "B" 		;
c8_t L_strRight[2] 			= "R" 		;
c8_t L_strLeft[2] 			= "L" 		;
c8_t L_strStop[2] 			= "S" 		;

u8_t L_u8ExitCheck			= INITIAL_ZERO	;
u8_t L_u8ForwCheck			= INITIAL_ZERO	;
u8_t L_u8BackCheck			= INITIAL_ZERO	;
u8_t L_u8RightCheck			= INITIAL_ZERO	;
u8_t L_u8LeftCheck			= INITIAL_ZERO	;
u8_t L_u8StopCheck			= INITIAL_ZERO	;

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



//		HBluetooth_vReceiveString( L_strRecievedButton ) ;
//
//		/* Check buttons states */
//		L_u8ForwCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strForward  	) ;
//		L_u8BackCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strBackward 	) ;
//		L_u8RightCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strRight    	) ;
//		L_u8LeftCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strLeft 		) ;
//		L_u8StopCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strStop 	   	) ;
//		L_u8ExitCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strExit 	   	) ;
//
//		if( L_u8ForwCheck == SAME_STRING )
//		{
//			HCarMove_vForward( ) ;
//		}
//		else if( L_u8BackCheck == SAME_STRING )
//		{
//	        HCarMove_vBackward( ) ;
//		}
//		else if( L_u8RightCheck == SAME_STRING )
//		{
//			HCarMove_vRight( ) ;
//		}
//		else if( L_u8LeftCheck == SAME_STRING )
//		{
//			HCarMove_vLeft( ) ;
//		}
//		else if( L_u8StopCheck == SAME_STRING )
//		{
//			HCarMove_vStop( ) ;
//		}
//		else if( L_u8ExitCheck == SAME_STRING )
//		{
//			HCarMove_vStop( ) ;
//		}
//		else
//		{
//			/* Do nothing */
//		}

















