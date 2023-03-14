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


    u8_t u8SpeedPin;


    u8_t u8SpeedRatio ;


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


void HDCM_vMotorSpeedCntrl( P2VAR(DCM_MotorConfiguration) pMotorConfiguration, VAR(u16_t) A_u16SpeedRatio ) ;

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


#define SPEED_0_PERCENT		0
#define SPEED_10_PERCENT	10
#define SPEED_20_PERCENT	20
#define SPEED_30_PERCENT	30
#define SPEED_40_PERCENT	40
#define SPEED_50_PERCENT	50
#define SPEED_60_PERCENT	60
#define SPEED_70_PERCENT	70
#define SPEED_80_PERCENT	80
#define SPEED_90_PERCENT	90
#define SPEED_100_PERCENT	100


#endif //_DCM_interface_H
