/* FILENAME: Testing_DC_Motor_program
 *  Author:  Ali El Bana
 *  Version:  V1.0
 *  DATE:   Sat 12/03/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../COTS/LIB/LSTD_COMPILER.h"
#include "../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"
#include "../../../COTS/MCAL/TIM1/TIM1_interface.h"
#include "../../../COTS/MCAL/SPI/SPI_interface.h"

#include "../../../COTS/HAL/DCMOTOR/DCM_interface.h"

#include "Testing_Motor_Driver_interface.h"
#include "Testing_Motor_Driver_private.h"
#include "Testing_Motor_Driver_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THDC_vTestMotors(void)
{

	#define DELLAY_SEC	5

    MRCC_vInit() ;

    MRCC_vEnablePeriphralCLK(RCC_AHB1, AHB1ENR_GPIOAEN) ;

    MGPIOx_vLockedPins() ;

    MSysTick_vInit( ) ;

    // Initialize motor 1
    VAR(DCM_MotorConfiguration) GS_pMotor1 =
    {
        .u8Port			= GPIO_PORTA,
        .u8Pin1 		= GPIOx_PIN3,
        .u8Pin2 		= GPIOx_PIN4,
        .u8Direction 	= INITIAL_ZERO
    };

    HDCM_vInitMotor(&GS_pMotor1);

    while (TRUE)
    {

        HDCM_vMoveForward(&GS_pMotor1) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HDCM_vStopMotor(&GS_pMotor1) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HDCM_vMoveBackward(&GS_pMotor1) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HDCM_vStopMotor(&GS_pMotor1) ;

       MSysTick_vDelaySec( DELLAY_SEC ) ;

    }

}

/**************************************************************************************/
/**************************************************************************************/

void THDC_vChangeMotorSpeed( void )
{

	#define DELLAY_SEC	5

    MRCC_vInit() ;

    MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;
    MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_TIM1EN  ) ;

    MGPIOx_vLockedPins() ;

    MSysTick_vInit( ) ;

    // Initialize motor 1
    VAR(DCM_MotorConfiguration) GS_pMotor1 =
    {
        .u8Port			= GPIO_PORTA	,
        .u8Pin1 		= GPIOx_PIN3	,
        .u8Pin2 		= GPIOx_PIN4	,
        .u8Direction 	= FORWARD		,
		.u8SpeedPin		= TIM1_CH4		,
		.u32SpeedRatio	= SPEED_10_PERCENT
    };


    HDCM_vInitMotor(&GS_pMotor1);

    MTIM1_vEnableCounter(  ) ;

    MSPI_vInit( SPI2, SPIx_MSTR, SPIx_FULL_DUPLEX ) ;

    while (TRUE)
    {

    	HDCM_vMotorSpeedCntrl( &GS_pMotor1, SPEED_20_PERCENT ) ;

    	MSPI_vMasterTransmit( SPI2, MTIM1_u16GetCaptureReg4Value( ) ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HDCM_vMotorSpeedCntrl( &GS_pMotor1, SPEED_40_PERCENT ) ;

        MSPI_vMasterTransmit( SPI2, MTIM1_u16GetCaptureReg4Value( ) ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HDCM_vMotorSpeedCntrl( &GS_pMotor1, SPEED_60_PERCENT ) ;

        MSPI_vMasterTransmit( SPI2, MTIM1_u16GetCaptureReg4Value( ) ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HDCM_vMotorSpeedCntrl( &GS_pMotor1, SPEED_80_PERCENT ) ;

        MSPI_vMasterTransmit( SPI2, MTIM1_u16GetCaptureReg4Value( ) ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

        HDCM_vMotorSpeedCntrl( &GS_pMotor1, SPEED_100_PERCENT ) ;

        MSPI_vMasterTransmit( SPI2, MTIM1_u16GetCaptureReg4Value( ) ) ;

        MSysTick_vDelaySec( DELLAY_SEC ) ;

    }

}

/**************************************************************************************/
/**************************************************************************************/



































