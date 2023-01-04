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

	c8_t L_strRecievedColor[6] 	= "0" 			;
	u8_t L_u8BlueColorCheck		= INITIAL_ZERO	;
	u8_t L_u8GreenColorCheck	= INITIAL_ZERO	;
	u8_t L_u8ExitCheck			= INITIAL_ZERO	;
	c8_t L_strBlueColor[5] 		= "BLUE" 		;
	c8_t L_strGreenColor[6] 	= "GREEN" 		;
	c8_t L_strExit[5] 			= "EXIT" 		;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;

	MGPIOx_vLockedPins() ;

	MGPIOx_ConfigType GREEN =
	{
		.Port 			= GPIO_PORTA		, .Pin 		 	= GPIOx_PIN10	 ,
		.Mode 		 	= GPIOx_MODE_OUTPUT	, .OutputType	= GPIOx_PUSHPULL ,
		.OutputSpeed 	= GPIOx_LowSpeed	, .InputType 	= GPIOx_NoPull
	} ;

	MGPIOx_ConfigType BLUE =
	{
		.Port 			= GPIO_PORTA		, 	.Pin 		= GPIOx_PIN11	 ,
		.Mode 			= GPIOx_MODE_OUTPUT	, 	.OutputType = GPIOx_PUSHPULL ,
		.OutputSpeed 	= GPIOx_LowSpeed	,	.InputType 	= GPIOx_NoPull
	} ;

	MGPIOx_vInit( &GREEN ) ;
	MGPIOx_vInit( &BLUE  ) ;

	USART_InitType MyUART1 =
	{
		.BaudRate 			 = __BAUDRATE__ , 	.DataWidth 			= MODE_8BIT ,

		.StopBits 			 = STOP_BIT_1 	, 	.Parity_Enable 		= DISABLE 	,

		.Parity_Selection 	 = EVEN_PARITY 	,	.TransferDirection 	= TX_RX		,

		.HardwareFlowControl = DISABLE 		,	.Oversampling 		= OVER_SAMPLING_16
	} ;

	USART_ClockInitTypeDef MyUARTCLK = { DISABLE, 0, 0, 0 } ;

	// Initialization of USART1
	MUSART_vInit( &MyUART1, &MyUARTCLK, USART1_REG ) ;

	MGPIOx_vSetResetAtomic( GREEN.Port, GREEN.Pin, GPIOx_LOW ) ;
	MGPIOx_vSetResetAtomic( BLUE.Port , BLUE.Pin , GPIOx_LOW ) ;

	do
	{

		MUSART_vTransmitString( USART1_REG, "\nSelect the LED color: \n" ) ;

		/* Don't forget to enter (Enter) -> "\n" after every string you enterd */
		MUSART_vRecieveString( USART1_REG, L_strRecievedColor ) ;

		L_u8BlueColorCheck 	= MUSART_u8CompareString( L_strRecievedColor, L_strBlueColor  ) ;
		L_u8GreenColorCheck = MUSART_u8CompareString( L_strRecievedColor, L_strGreenColor ) ;
		L_u8ExitCheck 		= MUSART_u8CompareString( L_strRecievedColor, L_strExit 	  ) ;

		if( L_u8GreenColorCheck == SAME_STRING )
		{
			MGPIOx_vSetResetAtomic( GREEN.Port, GREEN.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetResetAtomic( BLUE.Port , BLUE.Pin , GPIOx_LOW  ) ;
		}
		else if( L_u8BlueColorCheck == SAME_STRING )
		{
			MGPIOx_vSetResetAtomic( BLUE.Port , BLUE.Pin , GPIOx_HIGH ) ;
			MGPIOx_vSetResetAtomic( GREEN.Port, GREEN.Pin, GPIOx_LOW  ) ;
		}
		else if( L_u8ExitCheck == SAME_STRING )
		{
			MGPIOx_vSetResetAtomic( BLUE.Port , BLUE.Pin , GPIOx_LOW  ) ;
			MGPIOx_vSetResetAtomic( GREEN.Port, GREEN.Pin, GPIOx_LOW  ) ;
		}
		else
		{
			MGPIOx_vSetResetAtomic( GREEN.Port, GREEN.Pin, GPIOx_HIGH ) ;
			MGPIOx_vSetResetAtomic( BLUE.Port , BLUE.Pin , GPIOx_HIGH ) ;
		}

	}while( L_u8ExitCheck != SAME_STRING ) ;

	while( TRUE )
	{

	}

}

/**************************************************************************************/
/**************************************************************************************/





