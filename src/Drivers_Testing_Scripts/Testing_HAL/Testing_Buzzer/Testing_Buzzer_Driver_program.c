/**
 * @file Testing_LED_Driver_program.c
 * @author Mohamed Alaa
 * @version V1.0
 * @date 2020-10-20
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../COTS/LIB/LSTD_COMPILER.h"

#include "../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../../COTS/HAL/Buzzer/Buzzer_interface.h"

#include "Testing_Buzzer_Driver_private.h"
#include "Testing_Buzzer_Driver_interface.h"
#include "Testing_Buzzer_Driver_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THBuzzer_vTestBuzzer(void)
{
    u32_t L_u32DelayCounter = INITIAL_ZERO;

    BUZZER_BuzzerConfiguration Buzzer1 =
        {
            .u8Port = GPIO_PORTA,
            .u8Pin = GPIOx_PIN0};

    BUZZER_BuzzerConfiguration Buzzer2 =
        {
            .u8Port = GPIO_PORTB,
            .u8Pin = GPIOx_PIN1};

    BUZZER_BuzzerConfiguration Buzzer3 =
        {
            .u8Port = GPIO_PORTB,
            .u8Pin = GPIOx_PIN10};

    MRCC_vInit();
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN);
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOBEN);
    MGPIOx_vLockedPins();

    HBUZZER_vInit(&Buzzer1);
    HBUZZER_vInit(&Buzzer2);
    HBUZZER_vInit(&Buzzer3);

    while (TRUE)
    {
        HBUZZER_vSoundOn(&Buzzer1);
        HBUZZER_vSoundOn(&Buzzer2);
        HBUZZER_vSoundOn(&Buzzer3);

        for (L_u32DelayCounter = INITIAL_ZERO; L_u32DelayCounter < 1000000; L_u32DelayCounter++)
            ;

        HBUZZER_vSoundOff(&Buzzer1);
        HBUZZER_vSoundOff(&Buzzer2);
        HBUZZER_vSoundOff(&Buzzer3);

        for (L_u32DelayCounter = INITIAL_ZERO; L_u32DelayCounter < 1000000; L_u32DelayCounter++)
            ;

        HBUZZER_vToggleSound(&Buzzer1);
        HBUZZER_vToggleSound(&Buzzer2);
        HBUZZER_vToggleSound(&Buzzer3);

        for (L_u32DelayCounter = INITIAL_ZERO; L_u32DelayCounter < 1000000; L_u32DelayCounter++)
            ;
    }
}