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
#include "DCM_private.h"
#include "DCM_interface.h"
#include "DCM_config.h"

STATIC P2VAR(DCM_MotorConfiguration) GS_pMotor1;
STATIC P2VAR(DCM_MotorConfiguration) GS_pMotor2;
STATIC P2VAR(DCM_MotorConfiguration) GS_pMotor3;
STATIC P2VAR(DCM_MotorConfiguration) GS_pMotor4;

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

FUNC(void) HDCM_vInitMotor(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    VAR(MGPIOx_ConfigType) DCMotorSide1Init =
    {
        .Port = pMotorConfiguration->Side1Port,
        .Pin = pMotorConfiguration->Side1Pin,
        .Mode = GPIOx_MODE_OUTPUT,
        .OutputType = GPIOx_PUSHPULL,
        .OutputSpeed = GPIOx_LowSpeed,
        .InputType = GPIOx_NoPull
    };

    VAR(MGPIOx_ConfigType) DCMotorSide2Init =
    {
        .Port = pMotorConfiguration->Side2Port,
        .Pin = pMotorConfiguration->Side2Pin,
        .Mode = GPIOx_MODE_OUTPUT,
        .OutputType = GPIOx_PUSHPULL,
        .OutputSpeed = GPIOx_LowSpeed,
        .InputType = GPIOx_NoPull
    };

    MGPIOx_vInit(&DCMotorSide1Init);
    MGPIOx_vInit(&DCMotorSide2Init);
}

FUNC(void) HDCM_vMoveForward(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    MGPIOx_vSetPinValue(pMotorConfiguration->Side1Port, pMotorConfiguration->Side1Pin, GPIOx_HIGH);
    MGPIOx_vSetPinValue(pMotorConfiguration->Side2Port, pMotorConfiguration->Side2Pin, GPIOx_LOW);
}

FUNC(void) HDCM_vMoveBackward(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    MGPIOx_vSetPinValue(pMotorConfiguration->Side1Port, pMotorConfiguration->Side1Pin, GPIOx_LOW);
    MGPIOx_vSetPinValue(pMotorConfiguration->Side2Port, pMotorConfiguration->Side2Pin, GPIOx_HIGH);
}

FUNC(void) HDCM_vStopMotor(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    MGPIOx_vSetPinValue(pMotorConfiguration->Side1Port, pMotorConfiguration->Side1Pin, GPIOx_LOW);
    MGPIOx_vSetPinValue(pMotorConfiguration->Side2Port, pMotorConfiguration->Side2Pin, GPIOx_LOW);
}