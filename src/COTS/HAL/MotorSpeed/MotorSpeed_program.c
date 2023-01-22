/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SysTick/SysTick_interface.h"
#include "../../HAL/DCMOTOR/DCM_interface.h"

#include "MotorSpeed_private.h"
#include "MotorSpeed_interface.h"
#include "MotorSpeed_config.h"

/************************************************************************/
/*                     Eextern variables                                */
/************************************************************************/

extern VAR(MGPIOx_ConfigType) MotorSpeedPinLayout;

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

FUNC(void) HMotorSpeed_vInit(void)
{
    MGPIOx_vInit(&MotorSpeedPinLayout);
    MSysTick_vInit();
}

FUNC(u32_t) HMotorSpeed_u32GetRevPerSec(void)
{
    // (1 / HMOTORSPEED_DISC_HOLES_NUM) * 1000
    // 1000 is to convert from sec to ms
    VAR(u32_t) L_u32CountingRPMDelay = (1000 / HMOTORSPEED_DISC_HOLES_NUM);
    VAR(u32_t) L_u32CountingRPMCounter = INITIAL_ZERO;
    VAR(u32_t) L_u32RevPerSec = INITIAL_ZERO;
    MSysTick_vEnable();

    while (L_u32CountingRPMCounter < L_u32CountingRPMDelay)
    {
        MGPIOx_u8GetPinValue(HMOTORSPEED_PORT, HMOTORSPEED_PIN) && L_u32RevPerSec++;
        MSysTick_vDelayMilliSec((u32_t) L_u32CountingRPMDelay);
        L_u32CountingRPMCounter++;
    }

    MSysTick_vDisable();
    return L_u32RevPerSec;
}

FUNC(u32_t) HMotorSpeed_u32GetRevPerMin(void)
{
    return (HMotorSpeed_u32GetRevolutionsNum() * 60);
}