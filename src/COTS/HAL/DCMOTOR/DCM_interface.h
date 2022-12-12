/**
 * @file DCM_interface.h
 * @author Mohamed Alaa
 * @brief This file contains the interfacing information for the DC Motor module
 * @version 1.0
 * @date 8/12/2022
 */

/* Header file guard */
#ifndef _DCM_interface_H
#define _DCM_interface_H

/**
 * @struct DCM_MotorConfiguration
 * @brief DC Motor configuration structure for motor initialization
 * DC Motor configuration for motor initialization for a certain port and pin.
 * Since DC Motors have 2 sides to be controller, we will intiliaze each motor with 2 pins.
 * Taking into consideration that the pins could be on different ports.
 */
typedef struct
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

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief Initialize a motor
 * Initialize a motor with a certain GPIO Port & Pin based on the passed motor configuration
 * @param[in] pMotorConfiguration The motor configuration to be initialized
 * @see DCM_MotorConfiguration
 */
void HDCM_vInitMotor(P2VAR(DCM_MotorConfiguration) pMotorConfiguration);

/**
 * @brief Move a certain motor forward
 * @param[in] pMotorConfiguration The motor's configuration to move forward
 */
void HDCM_vMoveForward(P2VAR(DCM_MotorConfiguration) pMotorConfiguration);

/**
 * @brief Move a certain motor backward
 * @param[in] pMotorConfiguration The motor's configuration to move backward
 */
void HDCM_vMoveBackward(P2VAR(DCM_MotorConfiguration) pMotorConfiguration);

/**
 * @brief Stop a certain motor's movement completely
 * @param[in] pMotorConfiguration The motor's configuration to stop
 */
void HDCM_vStopMotor(P2VAR(DCM_MotorConfiguration) pMotorConfiguration);

#endif //_DCM_interface_H
