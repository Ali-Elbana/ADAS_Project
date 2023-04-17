/* FILENAME: Exit_State_program 
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

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "../../HAL/BUZZER/BUZZER_interface.h"
#include "../../HAL/Car_Movement/Car_Movement_interface.h"

#include "Exit_State_interface.h"
#include "Exit_State_private.h"
#include "Exit_State_config.h"


static VAR(BUZZER_BuzzerConfiguration)
    Buzzer =
    {
        .u8Port = GPIO_PORTB ,
        .u8Pin  = GPIOx_PIN5
	} ;

/**************************************************************************************/
/**************************************************************************************/

void AExit_vCriteriaON( void )
{

	HCarMove_vStop( ) ;

	HBUZZER_vSoundOff( &Buzzer ) ;

}

/**************************************************************************************/
/**************************************************************************************/





































