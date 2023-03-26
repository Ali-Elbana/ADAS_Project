/* FILENAME: Mob_APP_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sun 03/26/2023
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/RCC/MRCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "../../HAL/Bluetooth/Bluetooth_interface.h"
#include "../../HAL/Car_Movement/Car_Movement_interface.h"

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

void AMobApp_vCntrlCar( void )
{

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

	do
	{

		HBluetooth_vReceiveString( L_strRecievedButton ) ;

		/* Check buttons states */
		L_u8ForwCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strForward  	) ;
		L_u8BackCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strBackward 	) ;
		L_u8RightCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strRight    	) ;
		L_u8LeftCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strLeft 		) ;
		L_u8StopCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strStop 	   	) ;
		L_u8ExitCheck 	= HBluetooth_u8CompStrings( L_strRecievedButton, L_strExit 	   	) ;

		if( L_u8ForwCheck == SAME_STRING )
		{
			HCarMove_vForward( ) ;
		}
		else if( L_u8BackCheck == SAME_STRING )
		{
	        HCarMove_vBackward( ) ;
		}
		else if( L_u8RightCheck == SAME_STRING )
		{
			HCarMove_vRight( ) ;
		}
		else if( L_u8LeftCheck == SAME_STRING )
		{
			HCarMove_vLeft( ) ;
		}
		else if( L_u8StopCheck == SAME_STRING )
		{
			HCarMove_vStop( ) ;
		}
		else if( L_u8ExitCheck == SAME_STRING )
		{
			HCarMove_vStop( ) ;
		}
		else
		{
			/* Do nothing */
		}


	}while( L_u8ExitCheck != SAME_STRING ) ;

}

/**************************************************************************************/
/**************************************************************************************/




















