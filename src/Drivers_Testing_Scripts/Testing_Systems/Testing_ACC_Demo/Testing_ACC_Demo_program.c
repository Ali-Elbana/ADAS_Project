/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../COTS/LIB/LSTD_COMPILER.h"
#include "../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../COTS/Services/UsersLogin/UsersLogin_interface.h"

#include "../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"

#include "../../../COTS/HAL/Bluetooth/Bluetooth_interface.h"
#include "../../../COTS/HAL/CarControl/CarControl_interface.h"

#include "Testing_ACC_Demo_interface.h"
#include "Testing_ACC_Demo_private.h"
#include "Testing_ACC_Demo_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

FUNC(void) TSACC_CarControlDemo(void)
{
    bool_t bHasLoggedIn = FALSE;
    c8_t L_strRecieveCarControl = '5';

    MRCC_vInit();
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOBEN);
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN);
    MGPIOx_vLockedPins();
    HBluetooth_vInit();
    HCarControl_vInitCar();
    HBluetooth_vSendString("- Welcome to your Value-Zagazig Car -\n");

    while (TRUE)
    {
        if (!bHasLoggedIn)
        {
            bHasLoggedIn = UsersLogin_vUserLoginProcess();
        }
        else
        {
            /* Do nothing */
        }

        do
        {
            HBluetooth_vSendString("- Control the car -\n");
            HBluetooth_vSendString("1 = Move car forward\n");
            HBluetooth_vSendString("2 = Move car backward\n");
            HBluetooth_vSendString("3 = Move car left\n");
            HBluetooth_vSendString("4 = Move car right\n");
            HBluetooth_vSendString("5 = Stop the car\n");
            HBluetooth_vSendString("6 = Exit\n");
            L_strRecieveCarControl = HBluetooth_ExchangeByte("Enter a control letter\n");

            /* Move car forward */
            if (L_strRecieveCarControl == '1')
            {
                HCarControl_vMoveForward();
            }
            else
            {
                /* Do nothing */
            }

            /* Move car backward */
            if (L_strRecieveCarControl == '2')
            {
                HCarControl_vMoveBackward();
            }
            else
            {
                /* Do nothing */
            }

            /* Move car left */
            if (L_strRecieveCarControl == '3')
            {
                HCarControl_vTurnLeft();
            }
            else
            {
                /* Do nothing */
            }

            /* Move car right */
            if (L_strRecieveCarControl == '4')
            {
                HCarControl_vTurnRight();
            }
            else
            {
                /* Do nothing */
            }

            /* Stop the car || exit the menu */
            if ((L_strRecieveCarControl == '5') || (L_strRecieveCarControl == '6'))
            {
                HCarControl_vStopCar();
            }
            else
            {
                /* Do nothing */
            }

        } while (L_strRecieveCarControl != '6');
    }
}