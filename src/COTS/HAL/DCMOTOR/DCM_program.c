/**
 * @file DCM_program.c
 * @author Mohamed Alaa
 * @brief This file contains the source code of the interfacing information for the DC Motor module
 * @version 1.0
 * @date 8/12/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SysTick/SysTick_interface.h"
#include "../../MCAL/TIM1/TIM1_interface.h"

#include "DCM_interface.h"
#include "DCM_private.h"
#include "DCM_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

FUNC(void) HDCM_vInitMotor(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{

    VAR(MGPIOx_ConfigType) DCMotorPin1Init =
    {
        .Port 			= pMotorConfiguration->u8Port	,
        .Pin   			= pMotorConfiguration->u8Pin1	,
        .Mode      		= GPIOx_MODE_OUTPUT				,
        .OutputType 	= GPIOx_PUSHPULL				,
        .OutputSpeed 	= GPIOx_LowSpeed				,
        .InputType 		= GPIOx_NoPull
    };

    VAR(MGPIOx_ConfigType) DCMotorPin2Init =
    {
        .Port 			= pMotorConfiguration->u8Port	,
        .Pin 			= pMotorConfiguration->u8Pin2	,
        .Mode 			= GPIOx_MODE_OUTPUT				,
        .OutputType 	= GPIOx_PUSHPULL				,
        .OutputSpeed 	= GPIOx_LowSpeed				,
        .InputType 		= GPIOx_NoPull
    };

    MGPIOx_vInit(&DCMotorPin1Init);
    MGPIOx_vInit(&DCMotorPin2Init);

    // Give an initial direction to the DC Motor:
    switch( pMotorConfiguration->u8Direction )
    {

    	case FORWARD  : HDCM_vMoveForward(pMotorConfiguration); 	break;

    	case BACKWARD : HDCM_vMoveBackward(pMotorConfiguration); 	break;

        /* Default case: stop the motor */
        default       : HDCM_vStopMotor(pMotorConfiguration); 		break;

    }

    // Give an initial speed to the DC Motor:
    HDCM_vMotorSpeedCntrl( pMotorConfiguration, pMotorConfiguration->u32SpeedRatio ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) HDCM_vMoveForward(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin1, GPIOx_HIGH);
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin2, GPIOx_LOW);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) HDCM_vMoveBackward(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin1, GPIOx_LOW);
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin2, GPIOx_HIGH);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) HDCM_vStopMotor(P2VAR(DCM_MotorConfiguration) pMotorConfiguration)
{
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin1, GPIOx_LOW);
    MGPIOx_vSetPinValue(pMotorConfiguration->u8Port, pMotorConfiguration->u8Pin2, GPIOx_LOW);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HDCM_vMotorSpeedCntrl( P2VAR(DCM_MotorConfiguration) pMotorConfiguration, VAR(u16_t) A_u16SpeedValue )
{

	MTIM1_vGeneratePWM( pMotorConfiguration->u8SpeedPin, PWM1, CENTER1,
							PSC_VALUE, MAX_SPEED, CR_VALUE ) ;

	switch( pMotorConfiguration->u8SpeedPin )
	{

		case TIM1_CH1: MTIM1_vSetCompareReg1Value( A_u16SpeedValue ) ; break ;

		case TIM1_CH2: MTIM1_vSetCompareReg2Value( A_u16SpeedValue ) ; break ;

		case TIM1_CH3: MTIM1_vSetCompareReg3Value( A_u16SpeedValue ) ; break ;

		case TIM1_CH4: MTIM1_vSetCompareReg4Value( A_u16SpeedValue ) ; break ;

		default:  break ;

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u32_t HDCM_vGetSpeedValue( P2VAR(DCM_MotorConfiguration) pMotorConfiguration )
{

	u32_t L_u32SpeedValue = INITIAL_ZERO ;

	switch( pMotorConfiguration->u8SpeedPin )
	{

		case TIM1_CH1: L_u32SpeedValue = MTIM1_u16GetCaptureReg1Value( ) ; break ;

		case TIM1_CH2: L_u32SpeedValue = MTIM1_u16GetCaptureReg2Value( ) ; break ;

		case TIM1_CH3: L_u32SpeedValue = MTIM1_u16GetCaptureReg3Value( ) ; break ;

		case TIM1_CH4: L_u32SpeedValue = MTIM1_u16GetCaptureReg4Value( ) ; break ;

		default:  break ;

	}

	return L_u32SpeedValue ;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/






