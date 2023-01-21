/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../HAL/Bluetooth/Bluetooth_interface.h"

#include "UsersLogin_private.h"
#include "UsersLogin_interface.h"
#include "UsersLogin_config.h"

STATIC FUNC(bool_t) UsersLogin_boolValidateUserInfo(P2VAR(c8_t) L_strUsername, P2VAR(c8_t) L_strPassword)
{
    bool_t bHasCorrectInfo = FALSE;

    UserInfo_t L_strUsersInfo[] =
    {
        { "Mohamed", "Mohamed" },
        { "Ahmed", "Ahmed" },
        { "Value", "Zagazig" }
    };

    if (!L_strUsername[0] || !L_strPassword[0])
    {
        bHasCorrectInfo = FALSE;
        // HBluetooth_vSendString(L_strUsername);
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

FUNC(bool_t) UsersLogin_vUserLoginProcess(void)
{
    bool_t bHasLoggedIn = FALSE;
    c8_t L_strRecieveUsername[MAX_INFO_LENGTH] = "";
    c8_t L_strRecievePassword[MAX_INFO_LENGTH] = "";

    do
    {
        HBluetooth_ExchangeString("\nEnter username (max: 10 letters): \n", L_strRecieveUsername);
        HBluetooth_ExchangeString("\nEnter password (max: 10 letters): \n", L_strRecievePassword);
        bHasLoggedIn = UsersLogin_boolValidateUserInfo(L_strRecieveUsername, L_strRecievePassword);

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