/* FILENAME: Testing_UART_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 01/02/2023
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
#include "../../../COTS/MCAL/UART/UART_interface.h"

#include "Testing_UART_interface.h"
#include "Testing_UART_private.h"
#include "Testing_UART_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TMUART_vRGBLED( void )
{

	u8_t L_u8RecievedColor = INITIAL_ZERO ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_USART1EN ) ;

	MGPIOx_vLockedPins() ;

	MGPIOx_ConfigType TX =
	{

		.Port 			= GPIO_PORTB 		,

		.Pin 			= GPIOx_PIN6 		,

		.Mode 			= GPIOx_MODE_AF 	,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_MediumSpeed ,

		.InputType 		= GPIOx_NoPull		,

		.AF_Type 		= GPIOx_AF7

	} ;

	MGPIOx_ConfigType RX =
	{

		.Port 			= GPIO_PORTB 		,

		.Pin 			= GPIOx_PIN7 		,

		.Mode 			= GPIOx_MODE_AF 	,

		.OutputType 	= GPIOx_PUSHPULL 	,

		.OutputSpeed 	= GPIOx_MediumSpeed ,

		.InputType 		= GPIOx_NoPull		,

		.AF_Type 		= GPIOx_AF7

	} ;

	MGPIOx_ConfigType GREEN =
	{

		.Port 		= GPIO_PORTA, .Pin = GPIOx_PIN10, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType BLUE =
	{

		.Port 		= GPIO_PORTA, .Pin = GPIOx_PIN11, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;


	MGPIOx_vInit( &TX 	 ) ;
	MGPIOx_vInit( &RX 	 ) ;
	MGPIOx_vInit( &GREEN ) ;
	MGPIOx_vInit( &BLUE  ) ;

	USART_InitType MyUART1 =
	{

		.BaudRate  				= 9600 			,

		.DataWidth 				= MODE_8BIT 	,

		.StopBits  				= STOP_BIT_1 	,

		.Parity_Enable 			= DISABLE 		,

		.Parity_Selection 		= EVEN_PARITY 	,

		.TransferDirection 		= TX_RX			,

		.HardwareFlowControl 	= DISABLE 		,

		.Oversampling 			= OVER_SAMPLING_16

	} ;

	USART_ClockInitTypeDef MyUARTCLK = { DISABLE, 0, 0, 0 } ;

	// Initialization of USART1
	MUSART_vInit( &MyUART1, &MyUARTCLK, USART1_REG ) ;

	// Transmit char
	//MUSART_vTransmitByte( USART1_REG, 'B' ) ;

	MGPIOx_vSetResetAtomic( GREEN.Port, GREEN.Pin, GPIOx_LOW ) ;
	MGPIOx_vSetResetAtomic( BLUE.Port , BLUE.Pin , GPIOx_LOW ) ;

	while( TRUE )
	{

		do
		{

			MUSART_vTransmitString( USART1_REG, "\nSelect the LED color: \n" ) ;

			L_u8RecievedColor = MUSART_u8ReceiveByteSynchBlocking( USART1_REG ) ;

			if( L_u8RecievedColor == 'G' )
			{
				MGPIOx_vSetResetAtomic( GREEN.Port, GREEN.Pin, GPIOx_HIGH ) ;
				MGPIOx_vSetResetAtomic( BLUE.Port , BLUE.Pin , GPIOx_LOW  ) ;
			}
			else if( L_u8RecievedColor == 'B' )
			{
				MGPIOx_vSetResetAtomic( BLUE.Port , BLUE.Pin , GPIOx_HIGH ) ;
				MGPIOx_vSetResetAtomic( GREEN.Port, GREEN.Pin, GPIOx_LOW  ) ;
			}
			else
			{
				MGPIOx_vSetResetAtomic( GREEN.Port, GREEN.Pin, GPIOx_HIGH ) ;
				MGPIOx_vSetResetAtomic( BLUE.Port , BLUE.Pin , GPIOx_HIGH ) ;
			}

		}while( L_u8RecievedColor != 0 ) ;

	}

}

/**************************************************************************************/
/**************************************************************************************/





