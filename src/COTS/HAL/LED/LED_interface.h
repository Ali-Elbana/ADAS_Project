/* FILENAME: LED_interface.h
 *  Author:  Mohamed Alaa
 *  Version:  V1.0
 *  DATE:   1/27/2022
 */
#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H

/**
 * @brief This function is used to initialize the LED
 */
void HLED_vInit(void);

/**
 * @brief This function is used to turn the LED on
 */
void HLED_vTurnLightOn(void);

/**
 * @brief This function is used to turn the LED off
 */
void HLED_vTurnLightOff(void);

/**
 * @brief This function is used to toggle the LED
 */
void HLED_vToggleLight(void);

#endif //_LED_INTERFACE_H
