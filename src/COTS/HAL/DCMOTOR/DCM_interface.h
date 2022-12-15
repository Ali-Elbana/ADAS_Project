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

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/
#include "DCM_private.h"

/************************************************************************/
/***********************************************************************/

/**
 * @struct DCM_MotorConfiguration
 * @brief DC Motor configuration structure for motor initialization
 * @details DC Motor configuration for motor initialization for a certain port and pin.
 * @details Since DC Motors have 2 sides to be controller, we will intiliaze each motor with 2 pins.
 * @details Taking into consideration that the pins could be on different ports.
 */
typedef struct
{
    /**
     * @brief Initialize the DC Motor on a certain port
     */
    u8_t u8Port;
    /**
     * @brief Initialize the DC Motor on a certain pin
     */
    u8_t u8Pin1;
    /**
     * @brief Initialize the DC Motor on a certain pin
     */
    u8_t u8Pin2;
    /**
     * @brief Initialize the DC Motor with a certain direction
     */
    u8_t u8Direction;

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

// TODO: After developing a timer driver:
void HDCM_vMotorSpeedCntrl(VAR(u8_t) A_u8SpeedRatio);



/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @defgroup motor_directions DC Motor Directions
 *
 * @{
 */

/**
 * @def FORWARD
 * @brief Motor forward direction
 *
 */
#define FORWARD		(CW)

/**
 * @def BACKWARD
 * @brief Motor backward direction
 *
 */
#define BACKWARD (CCW)

/** @} */

#endif //_DCM_interface_H
