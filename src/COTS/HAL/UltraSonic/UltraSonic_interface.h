/**
 * @file UltraSonic_interface.h
 * @brief This file is a header file that contains the Ultrasonic sensor functions prototypes
 * @version 1.0
 * @date 02/24/2023
 * @author Ali El Bana
 */

#ifndef _UltraSonic_interface_H
#define _UltraSonic_interface_H

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @brief Ultrasonic Configurations
 * @struct HULTSNC_ConfigType
 */
typedef struct
{
    /**
     * @brief Trigger Port
     */
    u8_t u8Port;
    /**
     * @brief Trigger Pin
     */
    u8_t u8Pin;
} HULTSNC_ConfigType;

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief This function is responsible for initializing the ultrasonic sensor
 * @param TRIG_psCfg pointer to a struct that holds the trigger pin configurations
 */
void HULTSNC_vInit(HULTSNC_ConfigType * TRIG_psCfg);

/**
 * @brief This function is responsible for triggering the ultrasonic sensor
 * @param TRIG_psCfg pointer to a struct that holds the trigger pin configurations
 */
void HULTSNC_vTrigger(HULTSNC_ConfigType * TRIG_psCfg);

/**
 * @brief This function is responsible for getting the distance measured by the ultrasonic sensor
 * @return distance measured by the ultrasonic sensor
 */
f32_t HULTSNC_f32GetDistance(void);

#endif //_UltraSonic_interface_H
