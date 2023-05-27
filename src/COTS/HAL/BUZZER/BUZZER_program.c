/**
 * @file BUZZER_program.c
 * @author Mohamed Alaa
 * @brief This file contains the logical operations of the buzzer module
 * @version 1.0
 * @date 12/22/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "BUZZER_private.h"
#include "BUZZER_interface.h"
#include "BUZZER_config.h"

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

void HBUZZER_vInit(BUZZER_BuzzerConfiguration * pBuzzer_Cfg)
{
    VAR(MGPIOx_ConfigType) Buzzer_Cfg =
        {
            .Port = pBuzzer_Cfg->u8Port,
            .Pin = pBuzzer_Cfg->u8Pin,
            .Mode = GPIOx_MODE_OUTPUT,
            .OutputType = GPIOx_PUSHPULL,
            .OutputSpeed = GPIOx_LowSpeed,
            .InputType = GPIOx_NoPull};

    MGPIOx_vInit(&Buzzer_Cfg);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HBUZZER_vSoundOn(BUZZER_BuzzerConfiguration * pBuzzer_Cfg)
{
    MGPIOx_vSetPinValue(pBuzzer_Cfg->u8Port, pBuzzer_Cfg->u8Pin, GPIOx_HIGH);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HBUZZER_vSoundOff(BUZZER_BuzzerConfiguration * pBuzzer_Cfg)
{
    MGPIOx_vSetPinValue(pBuzzer_Cfg->u8Port, pBuzzer_Cfg->u8Pin, GPIOx_LOW);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HBUZZER_vToggleSound(BUZZER_BuzzerConfiguration * pBuzzer_Cfg)
{
    MGPIOx_vTogglePinValue(pBuzzer_Cfg->u8Port, pBuzzer_Cfg->u8Pin);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/
