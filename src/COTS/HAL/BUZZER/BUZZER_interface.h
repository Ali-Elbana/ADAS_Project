/* FILENAME: BUZZER_interface.h
 *  Author:  Mohamed Alaa
 *  Version:  V1.0
 *  DATE:   1/27/2022
 */
#ifndef _BUZZER_INTERFACE_H
#define _BUZZER_INTERFACE_H

/************************************************************************/
/***********************************************************************/

/**
 * @struct BUZZER_BuzzerConfiguration
 * @brief Buzzer configuration structure for Buzzer initialization
 * @details This structure is used to initialize the Buzzer with a certain port and pin
 */
typedef struct
{
    /**
     * @brief Initialize the Buzzer on a certain port
     */
    u8_t u8Port;
    /**
     * @brief Initialize the Buzzer on a certain pin
     */
    u8_t u8Pin;
} BUZZER_BuzzerConfiguration;

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief This function is used to initialize the Buzzer
 * @param[in] pBuzzer_Cfg Pointer to Buzzer configuration structure to initialize the Buzzer with a certain port and pin
 */
void HBUZZER_vInit(P2VAR(BUZZER_BuzzerConfiguration) pBuzzer_Cfg);

/**
 * @brief This function is used to sound the Buzzer on
 * @param[in] pBuzzer_Cfg Pointer to Buzzer configuration to sound on the Buzzer
 */
void HBUZZER_vSoundOn(P2VAR(BUZZER_BuzzerConfiguration) pBuzzer_Cfg);

/**
 * @brief This function is used to sound the Buzzer off
 * @param[in] pBuzzer_Cfg Pointer to Buzzer configuration to sound off the Buzzer
 */
void HBUZZER_vSoundOff(P2VAR(BUZZER_BuzzerConfiguration) pBuzzer_Cfg);

/**
 * @brief This function is used to toggle the sound of the buzzer
 * @param[in] pBuzzer_Cfg Pointer to Buzzer configuration to toggle the sound of the Buzzer
 */
void HBUZZER_vToggleSound(P2VAR(BUZZER_BuzzerConfiguration) pBuzzer_Cfg);

#endif //_BUZZER_INTERFACE_H
