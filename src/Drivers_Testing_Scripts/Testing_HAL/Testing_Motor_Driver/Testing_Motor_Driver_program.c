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
// #include "../../../COTS/MCAL/SysTick/SysTick_interface.h"
#include "../../../COTS/HAL/DCMOTOR/DCM_interface.h"

#include "Testing_Motor_Driver_private.h"
#include "Testing_Motor_Driver_interface.h"
#include "Testing_Motor_Driver_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THDC_vTestMotors(void)
{
    VAR(u32_t) u32DelayCounter = INITIAL_ZERO;
    MRCC_vInit();
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN);
    // MGPIOx_vLockedPins();
    // MSysTick_vInit();
    HDCM_vInitMotors();
    HDCM_vMoveMotorsForward();
    // MSysTick_vSetBusyWait(1000000);

    while (TRUE)
    {
        // HDCM_vMoveMotorsForward();
        // for (u32DelayCounter = 0; u32DelayCounter < 10000000; u32DelayCounter++)
        //     ;
        // HDCM_vMoveMotorsBackward();
        // for (u32DelayCounter = 0; u32DelayCounter < 10000000; u32DelayCounter++)
        //     ;
    }
}

/**************************************************************************************/
/**************************************************************************************/
