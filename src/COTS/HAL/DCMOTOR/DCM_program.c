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

/**
 * @brief Initialize a single motor
 * Initialize a certain GPIO Port & Pin based on the passed motor configuration
 * @param[in] pMotorConfiguration The motor configuration to initialize a a certain GPIO Port & Pin
 * @see DCM_MotorConfiguration
 */
STATIC FUNC(void) HDCM_vInitSingleMotor(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
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

FUNC(void) HDCM_vInitMotors(VAR(void))
{
    // Initialize motor 1
    GS_pMotor1->Side1Port = DCM_MOTOR1_SIDE1_PORT;
    GS_pMotor1->Side1Pin = DCM_MOTOR1_SIDE1_PIN;
    GS_pMotor1->Side2Port = DCM_MOTOR1_SIDE2_PORT;
    GS_pMotor1->Side2Pin = DCM_MOTOR1_SIDE2_PIN;

    HDCM_vInitSingleMotor(GS_pMotor1);

    // Initialize motor 2
    GS_pMotor2->Side1Port = DCM_MOTOR2_SIDE1_PORT;
    GS_pMotor2->Side1Pin = DCM_MOTOR2_SIDE1_PIN;
    GS_pMotor2->Side2Port = DCM_MOTOR2_SIDE2_PORT;
    GS_pMotor2->Side2Pin = DCM_MOTOR2_SIDE2_PIN;

    HDCM_vInitSingleMotor(GS_pMotor2);

    // Initialize motor 3
    GS_pMotor3->Side1Port = DCM_MOTOR3_SIDE1_PORT;
    GS_pMotor3->Side1Pin = DCM_MOTOR3_SIDE1_PIN;
    GS_pMotor3->Side2Port = DCM_MOTOR3_SIDE2_PORT;
    GS_pMotor3->Side2Pin = DCM_MOTOR3_SIDE2_PIN;

    HDCM_vInitSingleMotor(GS_pMotor3);

    // Initialize motor 4
    GS_pMotor4->Side1Port = DCM_MOTOR4_SIDE1_PORT;
    GS_pMotor4->Side1Pin = DCM_MOTOR4_SIDE1_PIN;
    GS_pMotor4->Side2Port = DCM_MOTOR4_SIDE2_PORT;
    GS_pMotor4->Side2Pin = DCM_MOTOR4_SIDE2_PIN;

    HDCM_vInitSingleMotor(GS_pMotor4);
}

FUNC(void) HDCM_vMoveMotorsForward(VAR(void))
{
    // Motor 1
    MGPIOx_vSetPinValue(GS_pMotor1->Side1Port, GS_pMotor1->Side1Pin, GPIOx_HIGH);
    MGPIOx_vSetPinValue(GS_pMotor1->Side2Port, GS_pMotor1->Side2Pin, GPIOx_LOW);

    // Motor 2
    MGPIOx_vSetPinValue(GS_pMotor2->Side1Port, GS_pMotor2->Side1Pin, GPIOx_HIGH);
    MGPIOx_vSetPinValue(GS_pMotor2->Side2Port, GS_pMotor2->Side2Pin, GPIOx_LOW);

    // Motor 3
    MGPIOx_vSetPinValue(GS_pMotor3->Side1Port, GS_pMotor3->Side1Pin, GPIOx_HIGH);
    MGPIOx_vSetPinValue(GS_pMotor3->Side2Port, GS_pMotor3->Side2Pin, GPIOx_LOW);

    // Motor 4
    MGPIOx_vSetPinValue(GS_pMotor4->Side1Port, GS_pMotor4->Side1Pin, GPIOx_HIGH);
    MGPIOx_vSetPinValue(GS_pMotor4->Side2Port, GS_pMotor4->Side2Pin, GPIOx_LOW);
}

FUNC(void) HDCM_vMoveMotorsBackward(VAR(void))
{
    // Motor 1
    MGPIOx_vSetPinValue(GS_pMotor1->Side1Port, GS_pMotor1->Side1Pin, GPIOx_LOW);
    MGPIOx_vSetPinValue(GS_pMotor1->Side2Port, GS_pMotor1->Side2Pin, GPIOx_HIGH);

    // Motor 2
    MGPIOx_vSetPinValue(GS_pMotor2->Side1Port, GS_pMotor2->Side1Pin, GPIOx_LOW);
    MGPIOx_vSetPinValue(GS_pMotor2->Side2Port, GS_pMotor2->Side2Pin, GPIOx_HIGH);

    // Motor 3
    MGPIOx_vSetPinValue(GS_pMotor3->Side1Port, GS_pMotor3->Side1Pin, GPIOx_LOW);
    MGPIOx_vSetPinValue(GS_pMotor3->Side2Port, GS_pMotor3->Side2Pin, GPIOx_HIGH);

    // Motor 4
    MGPIOx_vSetPinValue(GS_pMotor4->Side1Port, GS_pMotor4->Side1Pin, GPIOx_LOW);
    MGPIOx_vSetPinValue(GS_pMotor4->Side2Port, GS_pMotor4->Side2Pin, GPIOx_HIGH);
}