/* FILENAME: EX1_MotorStates_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 05/09/2023
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../../COTS/LIB/LSTD_BITMATH.h"
#include "../../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../../COTS/LIB/LSTD_COMPILER.h"
#include "../../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../../../COTS/MCAL/SysTick/SysTick_interface.h"

#include "../../../../COTS/HAL/Bluetooth/Bluetooth_interface.h"
#include "../../../../COTS/HAL/LED/LED_interface.h"

#include "EX1_MotorStates2_config.h"
#include "EX1_MotorStates2_interface.h"
#include "EX1_MotorStates2_private.h"

static tMotor_enuRootStates GS_enuMotorCurrentState = MOTOR_OFF ;

c8_t volatile G_c8RecievedButton 					= INITIAL_ZERO 	;

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

/* This is a call back RX function */
static void Button_vCurrentData( void )
{
	G_c8RecievedButton = HBluetooth_u8GetDataRegister( ) ;
}

/**************************************************************************************/
/**************************************************************************************/



/**************************************************************************************/
/**************************************************************************************/





/**************************************************************************************/
/**************************************************************************************/












