/**
 * @file DCM_config.h
 * @author Mohamed Alaa
 * @brief This file contains the configuration information for the DC Motor module
 * @version 1.0
 * @date 8/12/2022
 */

/* Header file guard */
#ifndef _DCM_config_H
#define _DCM_config_H

/************************************************************************/
/*                          Configuration macros                          */
/************************************************************************/

/**
 * @defgroup dc_motor1_configurations DC Motor 1 Configuration
 *
 * @{
 */

/**
 * @def DCM_MOTOR1_SIDE1_PORT
 * @brief Motor 1 Side 1 Port
 *
 */
#define DCM_MOTOR1_SIDE1_PORT (GPIO_PORTA)

/**
 * @def DCM_MOTOR1_SIDE1_PIN
 * @brief Motor 1 Side 2 Pin
 *
 */
#define DCM_MOTOR1_SIDE1_PIN (GPIOx_PIN0)

/**
 * @def DCM_MOTOR1_SIDE2_PORT
 * @brief Motor 1 Side 2 Port
 *
 */
#define DCM_MOTOR1_SIDE2_PORT (GPIO_PORTA)

/**
 * @def DCM_MOTOR1_SIDE2_PIN
 * @brief Motor 1 Side 2 Pin
 *
 */
#define DCM_MOTOR1_SIDE2_PIN (GPIOx_PIN1)

/** @} */
/**
 * @defgroup dc_motor2_configurations DC Motor 2 Configuration
 *
 * @{
 */

/**
 * @def DCM_MOTOR2_SIDE1_PORT
 * @brief Motor 2 Side 1 Port
 *
 */
#define DCM_MOTOR2_SIDE1_PORT (GPIO_PORTA)

/**
 * @def DCM_MOTOR2_SIDE1_PIN
 * @brief Motor 2 Side 2 Pin
 *
 */
#define DCM_MOTOR2_SIDE1_PIN (GPIOx_PIN2)

/**
 * @def DCM_MOTOR2_SIDE2_PORT
 * @brief Motor 2 Side 2 Port
 *
 */
#define DCM_MOTOR2_SIDE2_PORT (GPIO_PORTA)

/**
 * @def DCM_MOTOR2_SIDE2_PIN
 * @brief Motor 2 Side 2 Pin
 *
 */
#define DCM_MOTOR2_SIDE2_PIN (GPIOx_PIN3)

/** @} */
/**
 * @defgroup dc_motor3_configurations DC Motor 3 Configuration
 *
 * @{
 */

/**
 * @def DCM_MOTOR3_SIDE1_PORT
 * @brief Motor 3 Side 1 Port
 *
 */
#define DCM_MOTOR3_SIDE1_PORT (GPIO_PORTA)

/**
 * @def DCM_MOTOR3_SIDE1_PIN
 * @brief Motor 3 Side 2 Pin
 *
 */
#define DCM_MOTOR3_SIDE1_PIN (GPIOx_PIN8)

/**
 * @def DCM_MOTOR3_SIDE2_PORT
 * @brief Motor 3 Side 2 Port
 *
 */
#define DCM_MOTOR3_SIDE2_PORT (GPIO_PORTA)

/**
 * @def DCM_MOTOR3_SIDE2_PIN
 * @brief Motor 3 Side 2 Pin
 *
 */
#define DCM_MOTOR3_SIDE2_PIN (GPIOx_PIN9)

/** @} */
/** @} */
/**
 * @defgroup dc_motor4_configurations DC Motor 4 Configuration
 *
 * @{
 */

/**
 * @def DCM_MOTOR4_SIDE1_PORT
 * @brief Motor 4 Side 1 Port
 *
 */
#define DCM_MOTOR4_SIDE1_PORT (GPIO_PORTA)

/**
 * @def DCM_MOTOR4_SIDE1_PIN
 * @brief Motor 4 Side 2 Pin
 *
 */
#define DCM_MOTOR4_SIDE1_PIN (GPIOx_PIN10)

/**
 * @def DCM_MOTOR4_SIDE2_PORT
 * @brief Motor 4 Side 2 Port
 *
 */
#define DCM_MOTOR4_SIDE2_PORT (GPIO_PORTA)

/**
 * @def DCM_MOTOR4_SIDE2_PIN
 * @brief Motor 4 Side 2 Pin
 *
 */
#define DCM_MOTOR4_SIDE2_PIN (GPIOx_PIN11)

/** @} */

#endif //_DCM_config_H
