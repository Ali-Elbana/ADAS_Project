/* FILENAME: BUZZER_interface.h
 *  Author:  Mohamed Alaa
 *  Version:  V1.0
 *  DATE:   1/27/2022
 */
#ifndef _BUZZER_INTERFACE_H
#define _BUZZER_INTERFACE_H

/**
 * @brief This function is used to initialize the Buzzer
 */
void HBUZZER_vInit(void);

/**
 * @brief This function is used to turn the Buzzer on
 */
void HBUZZER_vTurnLightOn(void);

/**
 * @brief This function is used to turn the Buzzer off
 */
void HBUZZER_vTurnLightOff(void);

/**
 * @brief This function is used to toggle the Buzzer
 */
void HBUZZER_vToggleLight(void);

#endif //_BUZZER_INTERFACE_H
