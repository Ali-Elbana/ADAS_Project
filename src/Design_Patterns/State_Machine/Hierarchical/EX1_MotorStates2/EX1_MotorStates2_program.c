/* FILENAME: EX1_MotorStates_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 05/09/2023
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../../COTS/LIB/LSTD_BITMATH.h"
#include "../../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../../COTS/LIB/LSTD_COMPILER.h"
#include "../../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../../../COTS/MCAL/SysTick/SysTick_interface.h"

#include "../../../../COTS/HAL/Bluetooth/Bluetooth_interface.h"
#include "../../../../COTS/HAL/LED/LED_interface.h"

#include "EX1_MotorStates2_config.h"
#include "EX1_MotorStates2_interface.h"
#include "EX1_MotorStates2_private.h"

c8_t volatile GV_c8RecievedButton = INITIAL_ZERO 	;

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

LED_LEDConfiguration YELLOW =
{
	.u8Port = GPIO_PORTA ,
	.u8Pin 	= GPIOx_PIN2
} ;

LED_LEDConfiguration MOTOR =
{
	.u8Port = GPIO_PORTA ,
	.u8Pin 	= GPIOx_PIN3
} ;

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

/* This is a call back RX function */
static void Button_vCurrentData( void )
{
	GV_c8RecievedButton = HBluetooth_u8GetDataRegister( ) ;
}

/**************************************************************************************/
/**************************************************************************************/

void DPTransition_vState( HStateMachine* A_strcHSM )
{

	/* Execute exit actions for the root state */
	switch( A_strcHSM->motor_state )
	{

		case MOTOR_OFF:

			switch( GV_c8RecievedButton )
			{

				case 'N':

					A_strcHSM->motor_state 	= MOTOR_ON 		;
					A_strcHSM->led_state 	= GREEN_LED 	;

				break ;

				default:

					/* Do nothing */

				break ;

			}

			/* Execute exit actions for the motor off sub state */
			switch( A_strcHSM->led_state )
			{

				case RED_LED:

					switch( GV_c8RecievedButton )
					{

						case 'y':

							A_strcHSM->led_state = YELLOW_LED ;

						break;

						default:

							/* Do nothing */

						break ;

					}

				break ;

				case YELLOW_LED:

					switch( GV_c8RecievedButton )
					{

						case 'r':

							A_strcHSM->led_state = RED_LED ;

						break;

						default:

							/* Do nothing */

						break ;

					}

				break ;

				default:

					/* Do nothing */

				break ;

			}

		break ;
		/*****************************************************************/
		case MOTOR_ON:

			switch( GV_c8RecievedButton )
			{

				case 'F':

					A_strcHSM->motor_state 	= MOTOR_OFF ;
					A_strcHSM->led_state 	= RED_LED 	;

				break ;

				default:

					/* Do nothing */

				break ;

			}

			/* Execute exit actions for the motor on sub state */
			switch( A_strcHSM->led_state )
			{

				case GREEN_LED:

					switch( GV_c8RecievedButton )
					{

						case 'y':

							A_strcHSM->led_state = YELLOW_LED ;

						break;

						default:

							/* Do nothing */

						break ;

					}

				break ;

				case YELLOW_LED:

					switch( GV_c8RecievedButton )
					{

						case 'g':

							A_strcHSM->led_state = GREEN_LED ;

						break;

						default:

							/* Do nothing */

						break ;

					}

				break ;

				default:

					/* Do nothing */

				break ;

			}

		break ;
		/*****************************************************************/
		default:

			/* Do nothing */

		break ;

	}

}

/**************************************************************************************/
/**************************************************************************************/

void DPHandleMotor_vOFFState( HStateMachine* A_strcHSM )
{

	/* Turn off green led */
	HLED_vTurnLightOff( &GREEN ) ;

	/* Turn off yellow led */
	HLED_vTurnLightOff( &YELLOW ) ;

	/* Turn off motor */
	HLED_vTurnLightOff( &MOTOR ) ;

	/* Invoke the sub-state machine */
	switch( A_strcHSM->led_state )
	{

		case RED_LED:

			HLED_vTurnLightOff( &YELLOW ) ;
			HLED_vTurnLightOn( &RED ) ;

		break ;
		/*****************************************************************/
		case YELLOW_LED:

			HLED_vTurnLightOff( &RED ) ;
			HLED_vBlinkLED( &YELLOW, 250 ) ;

		break ;

		default:

			/* Do nothing */

		break ;

	}

}

/**************************************************************************************/
/**************************************************************************************/

void DPHandleMotor_vONState( HStateMachine* A_strcHSM )
{

	/* Turn off red led */
	HLED_vTurnLightOff( &RED ) ;

	/* Turn off yellow led */
	HLED_vTurnLightOff( &YELLOW ) ;

	/* Turn on motor */
	HLED_vTurnLightOn( &MOTOR ) ;

	HLED_vTurnLightOn( &GREEN ) ;

	/* Invoke the sub-state machine */
	switch( A_strcHSM->led_state )
	{

		case GREEN_LED:

			HLED_vTurnLightOff( &YELLOW ) ;
			HLED_vTurnLightOn( &GREEN ) ;

		break ;
		/*****************************************************************/
		case YELLOW_LED:

			HLED_vTurnLightOff( &GREEN ) ;
			HLED_vBlinkLED( &YELLOW, 250 ) ;

		break ;

	}

}

/**************************************************************************************/
/**************************************************************************************/

void DPUpdate_vStateMachine( HStateMachine* A_strcHSM )
{

	switch( A_strcHSM->motor_state )
	{

		case MOTOR_OFF:

			DPHandleMotor_vOFFState( A_strcHSM ) ;

		break ;


		case MOTOR_ON:

			DPHandleMotor_vONState( A_strcHSM ) ;

		break ;

		default:

			/* Do nothing */

		break ;
	}

}

/**************************************************************************************/
/**************************************************************************************/

void DPExecute_vHMotorStates( void )
{

	GV_c8RecievedButton = INITIAL_ZERO ;

	HStateMachine SM ;

	SM.motor_state 	= MOTOR_OFF ;
	SM.led_state	= RED_LED	;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN  ) ;

	MGPIOx_vLockedPins( ) ;

	MSysTick_vInit( ) ;

	MSysTick_vDisableException( ) ;

	HLED_vInit( &GREEN 	) ;
	HLED_vInit( &RED   	) ;
	HLED_vInit( &YELLOW ) ;
	HLED_vInit( &MOTOR 	) ;

	HLED_vTurnLightOff( &GREEN 	) ;
	HLED_vTurnLightOff( &RED   	) ;
	HLED_vTurnLightOff( &YELLOW ) ;
	HLED_vTurnLightOff( &MOTOR 	) ;

	HBluetooth_vInit( ) ;

	HBluetooth_vEnableAsynchReceive( ) ;

	HBluetooth_u8AsynchReceiveByte( &Button_vCurrentData ) ;

	HBluetooth_vSendString( "\nSuccessfully connected\n" ) ;

	while( TRUE )
	{

		DPTransition_vState( &SM ) ;

		DPUpdate_vStateMachine( &SM ) ;

	}

}

/**************************************************************************************/
/**************************************************************************************/















