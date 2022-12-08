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
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief Initialize all motors
 */
void HDCM_vInitMotors(VAR(void));

/**
 * @brief Move all motors forward
 */
void HDCM_vMoveMotorsForward(VAR(void));

/**
 * @brief Move all motors backward
 */
void HDCM_vMoveMotorsBackward(VAR(void));

#endif //_DCM_interface_H
