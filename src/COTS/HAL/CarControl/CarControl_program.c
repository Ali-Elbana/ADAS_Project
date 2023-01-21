/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../HAL/DCMOTOR/DCM_interface.h"

#include "CarControl_interface.h"
#include "CarControl_private.h"
#include "CarControl_config.h"

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

// Initialize motor 1
VAR(DCM_MotorConfiguration) dcmMotor1 =
{
    .u8Port = GPIO_PORTA,
    .u8Pin1 = GPIOx_PIN0,
    .u8Pin2 = GPIOx_PIN1,
    .u8Direction = INITIAL_ZERO
};

// Initialize motor 2
VAR(DCM_MotorConfiguration) dcmMotor2 =
{
    .u8Port 		= GPIO_PORTA,
    .u8Pin1 		= GPIOx_PIN2,
    .u8Pin2 		= GPIOx_PIN3,
    .u8Direction 	= INITIAL_ZERO
};

// // Initialize motor 3
VAR(DCM_MotorConfiguration) dcmMotor3 =
{
    .u8Port 		= GPIO_PORTA,
    .u8Pin1 		= GPIOx_PIN8,
    .u8Pin2 		= GPIOx_PIN9,
    .u8Direction 	= INITIAL_ZERO
};

// // Initialize motor 4
VAR(DCM_MotorConfiguration) dcmMotor4 =
{
    .u8Port 		= GPIO_PORTA ,
    .u8Pin1 		= GPIOx_PIN10,
    .u8Pin2 		= GPIOx_PIN11,
    .u8Direction 	= INITIAL_ZERO
};

//   Motors Layout
//   M1 ----- M2
//   M3 ----- M4

FUNC(void) HCarControl_vInitCar(void)
{
    HDCM_vInitMotor(&dcmMotor1);
    HDCM_vInitMotor(&dcmMotor2);
    HDCM_vInitMotor(&dcmMotor3);
    HDCM_vInitMotor(&dcmMotor4);
}

FUNC(void) HCarControl_vMoveForward(void)
{
    HDCM_vMoveForward(&dcmMotor1);
    HDCM_vMoveForward(&dcmMotor2);
    HDCM_vMoveForward(&dcmMotor3);
    HDCM_vMoveForward(&dcmMotor4);
}

FUNC(void) HCarControl_vMoveBackward(void)
{
    HDCM_vMoveBackward(&dcmMotor1);
    HDCM_vMoveBackward(&dcmMotor2);
    HDCM_vMoveBackward(&dcmMotor3);
    HDCM_vMoveBackward(&dcmMotor4);
}

FUNC(void) HCarControl_vTurnRight(void)
{
    HDCM_vMoveForward(&dcmMotor1);
    HDCM_vMoveBackward(&dcmMotor2);
    HDCM_vMoveForward(&dcmMotor3);
    HDCM_vMoveBackward(&dcmMotor4);
}

FUNC(void) HCarControl_vTurnLeft(void)
{
    HDCM_vMoveBackward(&dcmMotor1);
    HDCM_vMoveForward(&dcmMotor2);
    HDCM_vMoveBackward(&dcmMotor3);
    HDCM_vMoveForward(&dcmMotor4);
}

FUNC(void) HCarControl_vStopCar(void)
{
    HDCM_vStopMotor(&dcmMotor1);
    HDCM_vStopMotor(&dcmMotor2);
    HDCM_vStopMotor(&dcmMotor3);
    HDCM_vStopMotor(&dcmMotor4);
}