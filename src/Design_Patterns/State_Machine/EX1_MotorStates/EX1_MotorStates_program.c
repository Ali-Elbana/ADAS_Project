/* FILENAME: EX1_MotorStates_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 05/03/2023
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../COTS/LIB/LSTD_BITMATH.h"
#include "../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../COTS/LIB/LSTD_COMPILER.h"
#include "../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"

#include "../../../COTS/HAL/Bluetooth/Bluetooth_interface.h"
#include "../../../COTS/HAL/LED/LED_interface.h"
#include "../../../COTS/HAL/DCMOTOR/DCM_interface.h"

#include "EX1_MotorStates_interface.h"
#include "EX1_MotorStates_private.h"
#include "EX1_MotorStates_config.h"

static tMotor_enuStates GS_enuMotorCurrentState = OFF 			;

c8_t volatile Gv_c8RecievedButton 				= INITIAL_ZERO 	;

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

/* This is a call back RX function */
static void Button_vCurrentData( void )
{
	Gv_c8RecievedButton = HBluetooth_u8GetDataRegister( ) ;
}

/**************************************************************************************/
/**************************************************************************************/

static void Motor_vTransitions( void )
{

	switch( GS_enuMotorCurrentState )
	{

		case OFF:

			switch( Gv_c8RecievedButton )
			{

				case 'n':

					GS_enuMotorCurrentState = ON ;

				break ;

				default:

					/* Do nothing */

				break ;

			}

		break ;
		/*****************************************************************/
		case ON:

			switch( Gv_c8RecievedButton )
			{

				case 'f':

					GS_enuMotorCurrentState = OFF ;

				break ;

				default:

					/* Do nothing */

				break ;

			}

		break ;

	}

}

/**************************************************************************************/
/**************************************************************************************/

void DPMotorStates_vExecution( void )
{

	Gv_c8RecievedButton 	= INITIAL_ZERO 	;
	GS_enuMotorCurrentState = OFF 			;

	LED_LEDConfiguration GREEN =
	{
		.u8Port = GPIO_PORTA ,
		.u8Pin 	= GPIOx_PIN0
	} ;

	LED_LEDConfiguration RED =
	{
		.u8Port = GPIO_PORTA ,
		.u8Pin 	= GPIOx_PIN1
	} ;

	LED_LEDConfiguration MOTOR =
	{
		.u8Port = GPIO_PORTA ,
		.u8Pin 	= GPIOx_PIN2
	} ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN  ) ;

	MGPIOx_vLockedPins( ) ;

	MSysTick_vInit( ) ;

	MSysTick_vDisableException( ) ;

	HLED_vInit( &GREEN ) ;
	HLED_vInit( &RED   ) ;
	HLED_vInit( &MOTOR ) ;

	HLED_vTurnLightOff( &GREEN ) ;
	HLED_vTurnLightOff( &RED   ) ;
	HLED_vTurnLightOff( &MOTOR ) ;

	HBluetooth_vInit( ) ;

	HBluetooth_vEnableAsynchReceive( ) ;

	HBluetooth_u8AsynchReceiveByte( &Button_vCurrentData ) ;

	HBluetooth_vSendString( "\nSuccessfully connected\n" ) ;

	while( TRUE )
	{

		Motor_vTransitions( ) ;

		switch( GS_enuMotorCurrentState )
		{

			case ON:

				HBluetooth_vSendString( "\nON STATE\n" ) ;

				/*  Turn off Red LED */
				HLED_vTurnLightOff( &RED ) ;

				/* Turn on motor */
				HLED_vTurnLightOn( &MOTOR ) ;

				/* Blink Green LED */
				HLED_vBlinkLED( &GREEN, 250 ) ;

			break ;
			/*****************************************************************/
			case OFF:

				HBluetooth_vSendString( "\nOFF STATE\n" ) ;

				/*  Turn off Green LED */
				HLED_vTurnLightOff( &GREEN ) ;

				/* Turn off motor */
				HLED_vTurnLightOff( &MOTOR ) ;

				/* Turn on Red LED */
				HLED_vTurnLightOn( &RED ) ;

			break ;

		}

	}

}

/**************************************************************************************/
/**************************************************************************************/







