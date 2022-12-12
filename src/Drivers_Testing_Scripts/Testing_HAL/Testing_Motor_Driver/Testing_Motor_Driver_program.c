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
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"
#include "../../../COTS/HAL/DCMOTOR/DCM_interface.h"

#include "Testing_Motor_Driver_private.h"
#include "Testing_Motor_Driver_interface.h"
#include "Testing_Motor_Driver_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THDC_vTestMotors(void)
{
    volatile VAR(u32_t) u32DelayCounter = INITIAL_ZERO;
    // Initialize motor 1
    VAR(DCM_MotorConfiguration) GS_pMotor1 = {
        .Side1Port = GPIO_PORTA,
        .Side1Pin = GPIOx_PIN0,
        .Side2Port = GPIO_PORTA,
        .Side2Pin = GPIOx_PIN1,
    };
    // Initialize motor 1
    VAR(DCM_MotorConfiguration) GS_pMotor2 = {
        .Side1Port = GPIO_PORTA,
        .Side1Pin = GPIOx_PIN2,
        .Side2Port = GPIO_PORTA,
        .Side2Pin = GPIOx_PIN3,
    };
    // Initialize motor 1
    VAR(DCM_MotorConfiguration) GS_pMotor3 = {
        .Side1Port = GPIO_PORTA,
        .Side1Pin = GPIOx_PIN8,
        .Side2Port = GPIO_PORTA,
        .Side2Pin = GPIOx_PIN9,
    };
    // Initialize motor 1
    VAR(DCM_MotorConfiguration) GS_pMotor4 = {
        .Side1Port = GPIO_PORTA,
        .Side1Pin = GPIOx_PIN10,
        .Side2Port = GPIO_PORTA,
        .Side2Pin = GPIOx_PIN11,
    };

    MRCC_vInit();
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN);
    // MGPIOx_vLockedPins();
    // MSysTick_vInit();
    HDCM_vInitMotor(&GS_pMotor1);
    HDCM_vInitMotor(&GS_pMotor2);
    HDCM_vInitMotor(&GS_pMotor3);
    HDCM_vInitMotor(&GS_pMotor4);

    while (TRUE)
    {
        HDCM_vMoveForward(&GS_pMotor1);
        HDCM_vMoveForward(&GS_pMotor2);
        HDCM_vMoveForward(&GS_pMotor3);
        HDCM_vMoveForward(&GS_pMotor4);
        // MSysTick_vDelaySec(2);
        for (u32DelayCounter = 0; u32DelayCounter < 10000000; u32DelayCounter++)
            ;
        HDCM_vMoveBackward(&GS_pMotor1);
        HDCM_vMoveBackward(&GS_pMotor2);
        HDCM_vMoveBackward(&GS_pMotor3);
        HDCM_vMoveBackward(&GS_pMotor4);
        // MSysTick_vDelaySec(2);
        for (u32DelayCounter = 0; u32DelayCounter < 10000000; u32DelayCounter++)
            ;
    }
}

/**************************************************************************************/
/**************************************************************************************/
