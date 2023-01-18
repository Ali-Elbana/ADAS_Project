/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../COTS/LIB/LSTD_COMPILER.h"
#include "../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"

#include "../../../COTS/HAL/Bluetooth/Bluetooth_interface.h"
#include "../../../COTS/HAL/DCMOTOR/DCM_interface.h"

#include "Testing_ACC_Demo_interface.h"
#include "Testing_ACC_Demo_private.h"
#include "Testing_ACC_Demo_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

bool_t FillandCheckUserInfo(void);

FUNC(void) TSACC_CarControlDemo(void)
{
    bool_t bHasLoggedIn = FALSE;

    MRCC_vInit();

    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOBEN);
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN);

    MGPIOx_vLockedPins();

    HBluetooth_vInit();

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

    HDCM_vInitMotor(&dcmMotor1);
    HDCM_vInitMotor(&dcmMotor2);
    HDCM_vInitMotor(&dcmMotor3);
    HDCM_vInitMotor(&dcmMotor4);

    while (TRUE)
    {
        if (bHasLoggedIn)
        {
            do
            {
                HBluetooth_vSendString("\n- Unlock your Value-Zagazig Car -\n");
                bHasLoggedIn = FillandCheckUserInfo();
            } while (!bHasLoggedIn);
        }
        else
        {
            // HDCM_vMoveForward(&dcmMotor1);
            // HDCM_vStopMotor(&dcmMotor1);
            // HDCM_vMoveBackward(&dcmMotor1);
        }
    }
}

FUNC(bool_t) FillandCheckUserInfo(void)
{
    bool_t bHasCorrectUsername = FALSE;
    bool_t bHasCorrectPassword = FALSE;
    c8_t L_strRecievedColor[11] = "";
    HBluetooth_vSendString("\nUsername (max: 10 letters): \n");
    HBluetooth_vReceiveString(L_strRecievedColor);

    return (bool_t)(bHasCorrectUsername && bHasCorrectPassword);
}