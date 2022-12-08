/**
 * @file DCM_private.h
 * @author Mohamed Alaa
 * @brief This file contains the private information for the DC Motor module
 * @version 1.0
 * @date 8/12/2022
 */

/* Header file guard */
#ifndef _DCM_private_H
#define _DCM_private_H

/**
 * @struct DCM_MotorConfiguration
 * @brief DC Motor configuration structure for motor initialization
 * DC Motor configuration for motor initialization for a certain port and pin
 * Since DC Motors have 2 sides to be controller, we will intiliaze each motor with 2 pins.
 * Taking into consideration that the pins could be on different ports
 */

typedef struct DCM_private
{
    /**
     * @brief Initialize the DC Motor on a certain port
     */
    u8_t Side1Port;
    /**
     * @brief Initialize the DC Motor on a certain pin
     */
    u8_t Side1Pin;
    /**
     * @brief Initialize the DC Motor on a certain port
     */
    u8_t Side2Port;
    /**
     * @brief Initialize the DC Motor on a certain pin
     */
    u8_t Side2Pin;
} DCM_MotorConfiguration;

#endif //_DCM_private_H
