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

#define MAX_INFO_LENGTH (10)

typedef struct {
    c8_t strUsername[MAX_INFO_LENGTH];
    c8_t strPassword[MAX_INFO_LENGTH];
} UserInfo_t;

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


bool_t UserLoginProcess(void);
void ReceiveInputViaBluetooth(P2VAR(c8_t) L_strMessagePlaceholder, P2VAR(c8_t) L_strInfo);
bool_t ValidateUserInfo(P2VAR(c8_t) L_strUsername, P2VAR(c8_t) L_strPassword);
FUNC(void) CarControl(void);

FUNC(void) TSACC_CarControlDemo(void)
{
    bool_t bHasLoggedIn = FALSE;

    MRCC_vInit();
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOBEN);
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN);
    MGPIOx_vLockedPins();
    HBluetooth_vInit();
    HDCM_vInitMotor(&dcmMotor1);
    HDCM_vInitMotor(&dcmMotor2);
    HDCM_vInitMotor(&dcmMotor3);
    HDCM_vInitMotor(&dcmMotor4);

    while (TRUE)
    {
        if (!bHasLoggedIn)
        {
            bHasLoggedIn = UserLoginProcess();
        }
        else
        {
            /* Do nothing */
        }

        CarControl();
    }
}

FUNC(bool_t) UserLoginProcess(void)
{
    bool_t bHasLoggedIn = FALSE;
    c8_t L_strRecieveUsername[MAX_INFO_LENGTH] = "";
    c8_t L_strRecievePassword[MAX_INFO_LENGTH] = "";

    HBluetooth_vSendString("\n- Welcome to your Value-Zagazig Car -\n");

    do
    {
        ReceiveInputViaBluetooth("\nEnter username (max: 10 letters): \n", L_strRecieveUsername);
        ReceiveInputViaBluetooth("\nEnter password (max: 10 letters): \n", L_strRecievePassword);
        bHasLoggedIn = ValidateUserInfo(L_strRecieveUsername, L_strRecievePassword);

        if (bHasLoggedIn)
        {
            HBluetooth_vSendString("\nLogged in successfully.\n");
        }
        else
        {
            HBluetooth_vSendString("\nCouldn't login, invalid login information.\n");
        }

    } while (!bHasLoggedIn);

    return bHasLoggedIn;
}

FUNC(void) ReceiveInputViaBluetooth(P2VAR(c8_t) L_strMessagePlaceholder, P2VAR(c8_t) L_strInfo)
{
    HBluetooth_vSendString(L_strMessagePlaceholder);
    HBluetooth_vReceiveString(L_strInfo);
}

FUNC(bool_t) ValidateUserInfo(P2VAR(c8_t) L_strUsername, P2VAR(c8_t) L_strPassword)
{
    bool_t bHasCorrectInfo = FALSE;

    UserInfo_t L_strUsersInfo[] =
    {
        { "Mohamed", "Mohamed" },
        { "Ahmed", "Ahmed" },
        { "Value", "Zagazig" }
    };

    if (!strlen(L_strUsername) || !strlen(L_strPassword))
    {
        bHasCorrectInfo = FALSE;
    }
    else if ((strlen(L_strUsername) > MAX_INFO_LENGTH) || (strlen(L_strPassword) > MAX_INFO_LENGTH))
    {
        bHasCorrectInfo = FALSE;
    }
    else
    {
        for (u8_t L_intLoopCounter = INITIAL_ZERO; L_intLoopCounter < sizeof L_strUsersInfo; L_intLoopCounter++)
        {
            if (L_strUsersInfo[L_intLoopCounter].strUsername[0] == L_strUsername[0])
            {
                if (HBluetooth_u8CompStrings(L_strUsername, L_strUsersInfo[L_intLoopCounter].strUsername) == SAME_STRING)
                {
                    if (HBluetooth_u8CompStrings(L_strPassword, L_strUsersInfo[L_intLoopCounter].strPassword) == SAME_STRING)
                    {
                        bHasCorrectInfo = TRUE;
                        break;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
        }
    }

    return bHasCorrectInfo;
}

FUNC(void) CarControl(void)
{
    c8_t L_strRecieveCarControl = "";
    HBluetooth_vSendString("\n- Control the car -\n");
    HBluetooth_vSendString("\nw = Move car forward\n");
    HBluetooth_vSendString("\ns = Move car backward\n");
    HBluetooth_vSendString("\na = Move car left\n");
    HBluetooth_vSendString("\nd = Move car right\n");
    HBluetooth_vSendString("\nf = Stop the car\n");
    ReceiveInputViaBluetooth("\nEnter a control letter\n", L_strRecieveCarControl);

    //   Motors Layout
    //
    //
    //   M1 ----------- M2
    //
    //
    //   M3 ----------- M4
    //

    /* Move car forward */
    if (L_strRecieveCarControl == 'w')
    {
        HDCM_vMoveForward(&dcmMotor1);
        HDCM_vMoveForward(&dcmMotor2);
        HDCM_vMoveForward(&dcmMotor3);
        HDCM_vMoveForward(&dcmMotor4);
    }
    else
    {
        /* Do nothing */
    }

    /* Move car backward */
    if (L_strRecieveCarControl == 's')
    {
        HDCM_vMoveBackward(&dcmMotor1);
        HDCM_vMoveBackward(&dcmMotor2);
        HDCM_vMoveBackward(&dcmMotor3);
        HDCM_vMoveBackward(&dcmMotor4);
    }
    else
    {
        /* Do nothing */
    }

    /* Move car left */
    if (L_strRecieveCarControl == 'a')
    {
        HDCM_vMoveBackward(&dcmMotor1);
        HDCM_vMoveForward(&dcmMotor2);
        HDCM_vMoveBackward(&dcmMotor3);
        HDCM_vMoveForward(&dcmMotor4);
    }
    else
    {
        /* Do nothing */
    }

    /* Move car right */
    if (L_strRecieveCarControl == 'a')
    {
        HDCM_vMoveForward(&dcmMotor1);
        HDCM_vMoveBackward(&dcmMotor2);
        HDCM_vMoveForward(&dcmMotor3);
        HDCM_vMoveBackward(&dcmMotor4);
    }
    else
    {
        /* Do nothing */
    }

    /* Stop the car */
    if (L_strRecieveCarControl == 'f')
    {
        HDCM_vStopMotor(&dcmMotor1);
        HDCM_vStopMotor(&dcmMotor2);
        HDCM_vStopMotor(&dcmMotor3);
        HDCM_vStopMotor(&dcmMotor4);
    }
    else
    {
        /* Do nothing */
    }
}