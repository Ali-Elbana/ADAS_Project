/* FILENAME: LED_interface.h
 *  Author:  Mohamed Alaa
 *  Version:  V1.0
 *  DATE:   1/27/2022
 */
#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H

/************************************************************************/
/***********************************************************************/

/**
 * @struct LED_LEDConfiguration
 * @brief LED configuration structure for LED initialization
 * @details This structure is used to initialize the LED with a certain port and pin
 */
typedef struct
{
    /**
     * @brief Initialize the LED on a certain port
     */
    u8_t u8Port;
    /**
     * @brief Initialize the LED on a certain pin
     */
    u8_t u8Pin;

} LED_LEDConfiguration;

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief This function is used to initialize the LED
 * @param[in] pLED_Cfg Pointer to LED configuration to initialize the LED with a certain port and pin
 */
void HLED_vInit(LED_LEDConfiguration * pLED_Cfg);

/**
 * @brief This function is used to turn the LED on
 * @param[in] pLED_Cfg Pointer to LED configuration to turn on the LED
 */
void HLED_vTurnLightOn(LED_LEDConfiguration * pLED_Cfg);

/**
 * @brief This function is used to turn the LED off
 * @param[in] pLED_Cfg Pointer to LED configuration to turn off the LED
 */
void HLED_vTurnLightOff(LED_LEDConfiguration * pLED_Cfg);

/**
 * @brief This function is used to toggle the LED
 * @param[in] pLED_Cfg LED configuration toggle the LED
 */
void HLED_vToggleLight(LED_LEDConfiguration * pLED_Cfg);

/**
 * @brief This function is used to blink the LED
 * @param[in] pLED_Cfg LED configuration
 * @param[in] A_u32MilliSecs number of milli seconds to blink the LED
 */
void HLED_vBlinkLED(LED_LEDConfiguration * pLED_Cfg, u32_t A_u32MilliSecs);

#endif //_LED_INTERFACE_H
