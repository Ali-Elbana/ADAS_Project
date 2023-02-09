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
#include "../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../../COTS/HAL/LED/LED_interface.h"

#include "Testing_LED_Driver_private.h"
#include "Testing_LED_Driver_interface.h"
#include "Testing_LED_Driver_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THLED_vTestLED(void)
{
    VAR(u32_t)
    L_u32DelayCounter = INITIAL_ZERO;

    VAR(LED_LEDConfiguration)
    LED1 =
        {
            .u8Port = GPIO_PORTA,
            .u8Pin = GPIOx_PIN0};

    VAR(LED_LEDConfiguration)
    LED2 =
        {
            .u8Port = GPIO_PORTB,
            .u8Pin = GPIOx_PIN1};

    VAR(LED_LEDConfiguration)
    LED3 =
        {
            .u8Port = GPIO_PORTB,
            .u8Pin = GPIOx_PIN10};

    MRCC_vInit();
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN);
    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOBEN);
    MGPIOx_vLockedPins();

    HLED_vInit(&LED1);
    HLED_vInit(&LED2);
    HLED_vInit(&LED3);

    while (TRUE)
    {
        HLED_vTurnLightOn(&LED1);
        HLED_vTurnLightOn(&LED2);
        HLED_vTurnLightOn(&LED3);

        for (L_u32DelayCounter = INITIAL_ZERO; L_u32DelayCounter < 1000000; L_u32DelayCounter++)
            ;

        HLED_vTurnLightOff(&LED1);
        HLED_vTurnLightOff(&LED2);
        HLED_vTurnLightOff(&LED3);

        for (L_u32DelayCounter = INITIAL_ZERO; L_u32DelayCounter < 1000000; L_u32DelayCounter++)
            ;

        // HLED_vToggleLight(&LED1);
        // HLED_vToggleLight(&LED2);
        // HLED_vToggleLight(&LED3);

        // for (L_u32DelayCounter = INITIAL_ZERO; L_u32DelayCounter < 1000000; L_u32DelayCounter++)
        //     ;
    }
}

/**************************************************************************************/
/**************************************************************************************/

void THLED_vBlinkLED( void )
{

    VAR(LED_LEDConfiguration)
    LED =
        {
            .u8Port = GPIO_PORTC ,
            .u8Pin  = GPIOx_PIN13
        };

    MRCC_vInit( ) ;

    MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOCEN ) ;

    MGPIOx_vLockedPins( ) ;

    HLED_vInit(&LED) ;

    while (TRUE)
    {

    	HLED_vBlinkLED( &LED, 200 ) ;

    }

}

/**************************************************************************************/
/**************************************************************************************/











