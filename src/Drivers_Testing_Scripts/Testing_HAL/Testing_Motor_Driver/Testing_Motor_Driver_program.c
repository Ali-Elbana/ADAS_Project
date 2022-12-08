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

#include "Testing_Motor_Driver_private.h"
#include "Testing_Motor_Driver_interface.h"
#include "Testing_Motor_Driver_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THDC_vTestMotors(void)
{
    MRCC_vInit();

    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN);
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOBEN);

    MGPIOx_vLockedPins();

    HDCM_vInitMotors();
    volatile VAR(u32_t) _32DelayCounter = INITIAL_ZERO;

    while (TRUE)
    {
        HDCM_vMoveMotorsForward();
        for (_32DelayCounter = 0; _32DelayCounter < 1000000; _32DelayCounter++)
            ;
        HDCM_vMoveMotorsBackward();
        for (_32DelayCounter = 0; _32DelayCounter < 1000000; _32DelayCounter++)
            ;
    }
}

/**************************************************************************************/
/**************************************************************************************/
