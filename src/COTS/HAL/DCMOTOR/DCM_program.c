/**
 * @file DCM_program.c
 * @author Mohamed Alaa
 * @brief This file contains the source code of the interfacing information for the DC Motor module
 * @version 1.0
 * @date 8/12/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SysTick/SysTick_interface.h"

#include "DCM_interface.h"
#include "DCM_private.h"
#include "DCM_config.h"

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

FUNC(void) HDCM_vInitMotor(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{

    VAR(MGPIOx_ConfigType) DCMotorPin1Init =
    {
        .Port 			= pMotorConfiguration->u8Port,
        .Pin   			= pMotorConfiguration->u8Pin1,
        .Mode      		= GPIOx_MODE_OUTPUT,
        .OutputType 	= GPIOx_PUSHPULL,
        .OutputSpeed 	= GPIOx_LowSpeed,
        .InputType 		= GPIOx_NoPull
    };

    VAR(MGPIOx_ConfigType) DCMotorPin2Init =
    {
        .Port 			= pMotorConfiguration->u8Port,
        .Pin 			= pMotorConfiguration->u8Pin2,
        .Mode 			= GPIOx_MODE_OUTPUT,
        .OutputType 	= GPIOx_PUSHPULL,
        .OutputSpeed 	= GPIOx_LowSpeed,
        .InputType 		= GPIOx_NoPull
    };

    MGPIOx_vInit(&DCMotorPin1Init);
    MGPIOx_vInit(&DCMotorPin2Init);

    // Give an initial direction to the DC Motor:
    switch( pMotorConfiguration->u8Direction )
    {

    	case FORWARD  : HDCM_vMoveForward(pMotorConfiguration); 	break;

    	case BACKWARD : HDCM_vMoveBackward(pMotorConfiguration); 	break;

        /* Default case: stop the motor */
        default       : HDCM_vStopMotor(pMotorConfiguration); 		break;

    }

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) HDCM_vMoveForward(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin1, GPIOx_HIGH);
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin2, GPIOx_LOW);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) HDCM_vMoveBackward(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin1, GPIOx_LOW);
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin2, GPIOx_HIGH);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) HDCM_vStopMotor(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin1, GPIOx_LOW);
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin2, GPIOx_LOW);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/






