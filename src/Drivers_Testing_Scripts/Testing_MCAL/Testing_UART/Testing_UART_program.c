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
#include "../../../COTS/MCAL/NVIC/NVIC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"
#include "../../../COTS/MCAL/UART/UART_interface.h"

#include "../../../COTS/HAL/LED/LED_interface.h"

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

	USART_InitType MyUART1 =
	{
		.BaudRate 			 = __BAUDRATE__ , 	.DataWidth 			= MODE_8BIT ,

		.StopBits 			 = STOP_BIT_1 	, 	.Parity_Enable 		= DISABLE 	,

		.Parity_Selection 	 = EVEN_PARITY 	,	.TransferDirection 	= TX_RX		,

		.HardwareFlowControl = DISABLE 		,	.Oversampling 		= OVER_SAMPLING_16
	} ;

	USART_ClockInitTypeDef MyUARTCLK = { DISABLE, 0, 0, 0 } ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;

	MGPIOx_vLockedPins() ;

	MGPIOx_vInit( &GREEN ) ;
	MGPIOx_vInit( &BLUE  ) ;

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

void TMUART_vRxIRQ( void )
{

	c8_t volatile L_strRecievedColor = INITIAL_ZERO ;

	LED_LEDConfiguration GREEN =
	{
		.u8Port = GPIO_PORTA,
		.u8Pin 	= GPIOx_PIN0
	} ;

	LED_LEDConfiguration BLUE =
	{
		.u8Port = GPIO_PORTA,
		.u8Pin 	= GPIOx_PIN1
	} ;

	USART_InitType MyUART1 =
	{
		.BaudRate 			 = __BAUDRATE__ , 	.DataWidth 			= MODE_8BIT ,

		.StopBits 			 = STOP_BIT_1 	, 	.Parity_Enable 		= DISABLE 	,

		.Parity_Selection 	 = EVEN_PARITY 	,	.TransferDirection 	= TX_RX		,

		.HardwareFlowControl = DISABLE 		,	.Oversampling 		= OVER_SAMPLING_16
	} ;

	USART_ClockInitTypeDef MyUARTCLK = { DISABLE, 0, 0, 0 } ;

	void Toggle_BLUELED( void )
	{

		L_strRecievedColor = MUSART_u8ReadDataRegister( USART1_REG ) ;

		if( L_strRecievedColor == 'b' )
		{
			HLED_vToggleLight( &BLUE ) ;
		}
		else
		{
			MUSART_vTransmitString( USART1_REG, "Wrong Character" ) ;
		}

	}

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_SYSCFGEN ) ;

	MGPIOx_vLockedPins() ;

	HLED_vInit( &GREEN ) ;
	HLED_vInit( &BLUE  ) ;

	// Initialization of USART1:
	MUSART_vInit( &MyUART1, &MyUARTCLK, USART1_REG ) ;

	// RXNEIE Pending Flag Enabled:
	MUSART_vRxIntSetStatus( USART1_REG, ENABLE ) ;

	// USART1 IRQ Active Flag Enabled:
	MNVIC_vEnablePeriphral( USART1 ) ;

	MUSART1_vSetCallBack( &Toggle_BLUELED ) ;

	HLED_vTurnLightOff( &GREEN ) ;
	HLED_vTurnLightOff( &BLUE  ) ;

	MUSART_vTransmitString( USART1_REG, "\nWelcome\n" ) ;

	while( TRUE )
	{

		HLED_vBlinkLED( &GREEN, 200 ) ;

	}

}

/**************************************************************************************/
/**************************************************************************************/
















