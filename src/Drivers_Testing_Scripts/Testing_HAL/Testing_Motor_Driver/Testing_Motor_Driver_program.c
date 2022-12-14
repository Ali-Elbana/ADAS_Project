/* FILENAME: Testing_DC_Motor_program
 *  Author:  Ali El Bana
 *  Version:  V1.0
 *  DATE:   Sat 12/03/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../COTS/LIB/LSTD_COMPILER.h"
#include "../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../../COTS/HAL/DCMOTOR/DCM_interface.h"

#include "Testing_Motor_Driver_interface.h"
#include "Testing_Motor_Driver_private.h"
#include "Testing_Motor_Driver_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THDC_vTestMotors(void)
{

    MRCC_vInit() ;

    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN) ;

    MGPIOx_vLockedPins() ;

    volatile VAR(u32_t) u32DelayCounter = INITIAL_ZERO;

    // Initialize motor 1
    VAR(DCM_MotorConfiguration) GS_pMotor1 =
    {
        .u8Port			= GPIO_PORTA,
        .u8Pin1 		= GPIOx_PIN0,
        .u8Pin2 		= GPIOx_PIN1,
        .u8Direction 	= INITIAL_ZERO
    };

    // Initialize motor 2
    // VAR(DCM_MotorConfiguration) GS_pMotor2 =
    // {
    //     .u8Port 		= GPIO_PORTA,
    //     .u8Pin1 		= GPIOx_PIN2,
    //     .u8Pin2 		= GPIOx_PIN3,
    //     .u8Direction 	= FORWARD
    // };

    // // Initialize motor 3
    // VAR(DCM_MotorConfiguration) GS_pMotor3 =
    // {
    //     .u8Port 		= GPIO_PORTA,
    //     .u8Pin1 		= GPIOx_PIN8,
    //     .u8Pin2 		= GPIOx_PIN9,
    //     .u8Direction 	= BACKWARD
    // };

    // // Initialize motor 4
    // VAR(DCM_MotorConfiguration) GS_pMotor4 =
    // {
    //     .u8Port 		= GPIO_PORTA ,
    //     .u8Pin1 		= GPIOx_PIN10,
    //     .u8Pin2 		= GPIOx_PIN11,
    //     .u8Direction 	= BACKWARD
    // };

    HDCM_vInitMotor(&GS_pMotor1);
    // HDCM_vInitMotor(&GS_pMotor2);
    // HDCM_vInitMotor(&GS_pMotor3);
    // HDCM_vInitMotor(&GS_pMotor4);

    while (TRUE)
    {

        for (u32DelayCounter = 0; u32DelayCounter < 10000000; u32DelayCounter++) ;

        HDCM_vMoveForward(&GS_pMotor1);
        // HDCM_vMoveBackward(&GS_pMotor1);
        // HDCM_vMoveBackward(&GS_pMotor2);
        // HDCM_vMoveForward (&GS_pMotor3);
        // HDCM_vMoveForward (&GS_pMotor4);

        for (u32DelayCounter = 0; u32DelayCounter < 10000000; u32DelayCounter++) ;

        HDCM_vStopMotor(&GS_pMotor1);
        // HDCM_vStopMotor(&GS_pMotor2);
        // HDCM_vStopMotor(&GS_pMotor3);
        // HDCM_vStopMotor(&GS_pMotor4);

        for (u32DelayCounter = 0; u32DelayCounter < 10000000; u32DelayCounter++) ;

        HDCM_vMoveBackward(&GS_pMotor1);
    }


}

/**************************************************************************************/
/**************************************************************************************/
