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
    /**
     * @brief Initialize the DC Motor with a certain speed pin
     */
    u8_t u8SpeedPin;
    /**
     * @brief Initialize the DC Motor with a certain speed ratio
     */
    u32_t u32SpeedRatio;
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
void HDCM_vInitMotor(DCM_MotorConfiguration *pMotorConfiguration);

/**
 * @brief Move a certain motor forward
 * @param[in] pMotorConfiguration The motor's configuration to move forward
 */
void HDCM_vMoveForward(DCM_MotorConfiguration *pMotorConfiguration);

/**
 * @brief Move a certain motor backward
 * @param[in] pMotorConfiguration The motor's configuration to move backward
 */
void HDCM_vMoveBackward(DCM_MotorConfiguration *pMotorConfiguration);

/**
 * @brief Stop a certain motor's movement completely
 * @param[in] pMotorConfiguration The motor's configuration to stop
 */
void HDCM_vStopMotor(DCM_MotorConfiguration *pMotorConfiguration);

/**
 * @brief Set a certain motor's speed
 * @param[in] pMotorConfiguration The motor's configuration to set its speed
 * @param[in] A_u16SpeedValue The speed value to set the motor to
 */
void HDCM_vMotorSpeedCntrl(DCM_MotorConfiguration *pMotorConfiguration, u16_t A_u16SpeedValue);

/**
 * @brief Get a certain motor's speed
 * @param[in] pMotorConfiguration The motor's configuration to get its speed
 * @return The speed value of the motor
 */
u32_t HDCM_vGetSpeedValue(DCM_MotorConfiguration *pMotorConfiguration);

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
#define FORWARD (CW)

/**
 * @def BACKWARD
 * @brief Motor backward direction
 *
 */
#define BACKWARD (CCW)

/** @} */

/**
 * @defgroup motor_speeds DC Motor Speeds
 *
 * @{
 */

/**
 * @def SPEED_0_PERCENT
 * @brief Motor speed 0%
 */
#define SPEED_0_PERCENT 0

/**
 * @def SPEED_10_PERCENT
 * @brief Motor speed 10%
 */
#define SPEED_10_PERCENT 1000U

/**
 * @def SPEED_20_PERCENT
 * @brief Motor speed 20%
 */
#define SPEED_20_PERCENT 2000U

/**
 * @def SPEED_30_PERCENT
 * @brief Motor speed 30%
 */
#define SPEED_30_PERCENT 3000U

/**
 * @def SPEED_40_PERCENT
 * @brief Motor speed 40%
 */
#define SPEED_40_PERCENT 4000U

/**
 * @def SPEED_50_PERCENT
 * @brief Motor speed 50%
 */
#define SPEED_50_PERCENT 5000U

/**
 * @def SPEED_60_PERCENT
 * @brief Motor speed 60%
 */
#define SPEED_60_PERCENT 6000U

/**
 * @def SPEED_70_PERCENT
 * @brief Motor speed 70%
 */
#define SPEED_70_PERCENT 7000U

/**
 * @def SPEED_80_PERCENT
 * @brief Motor speed 80%
 */
#define SPEED_80_PERCENT 8000U

/**
 * @def SPEED_90_PERCENT
 * @brief Motor speed 90%
 */
#define SPEED_90_PERCENT 9000U

/**
 * @def SPEED_100_PERCENT
 * @brief Motor speed 100%
 */
#define SPEED_100_PERCENT 10000U

/** @} */

#endif //_DCM_interface_H
