/* FILENAME: LDR_program
 *  Author:  Ali El Bana
 *  Version:  V1.0
 *  DATE:   Thu 12/22/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SysTick/SysTick_interface.h"

#include "LED_private.h"
#include "LED_interface.h"
#include "LED_config.h"

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

void HLED_vInit(LED_LEDConfiguration * pLED_Cfg)
{
    VAR(MGPIOx_ConfigType)
    LED_Cfg =
        {
            .Port = pLED_Cfg->u8Port,
            .Pin = pLED_Cfg->u8Pin,
            .Mode = GPIOx_MODE_OUTPUT,
            .OutputType = GPIOx_PUSHPULL,
            .OutputSpeed = GPIOx_LowSpeed,
            .InputType = GPIOx_NoPull};

    MGPIOx_vInit(&LED_Cfg);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HLED_vTurnLightOn(LED_LEDConfiguration * pLED_Cfg)
{
    MGPIOx_vSetPinValue(pLED_Cfg->u8Port, pLED_Cfg->u8Pin, GPIOx_HIGH);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HLED_vTurnLightOff(LED_LEDConfiguration * pLED_Cfg)
{
    MGPIOx_vSetPinValue(pLED_Cfg->u8Port, pLED_Cfg->u8Pin, GPIOx_LOW);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HLED_vToggleLight(LED_LEDConfiguration * pLED_Cfg)
{
    MGPIOx_vTogglePinValue(pLED_Cfg->u8Port, pLED_Cfg->u8Pin);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HLED_vBlinkLED(LED_LEDConfiguration * pLED_Cfg, u32_t A_u32MilliSecs)
{

    MGPIOx_vSetPinValue(pLED_Cfg->u8Port, pLED_Cfg->u8Pin, GPIOx_HIGH);

    MSysTick_vDelayMilliSec(A_u32MilliSecs);

    MGPIOx_vSetPinValue(pLED_Cfg->u8Port, pLED_Cfg->u8Pin, GPIOx_LOW);

    MSysTick_vDelayMilliSec(A_u32MilliSecs);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/
