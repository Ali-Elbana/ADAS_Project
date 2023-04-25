/* FILENAME: UART_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 10/14/2022
*/

/************************************************************************/
/*                         Include headers                           	*/
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "string.h"

#include "../RCC/MRCC_interface.h"
#include "../GPIO/GPIO_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

/************************************************************************/
/*                     Functions  implementations                      	*/
/************************************************************************/

u8_t G_u8String[20] ;

void (*MUSART1_CallBack)(void);
void (*MUSART2_CallBack)(void);
void (*MUSART6_CallBack)(void);

/******************************************************************/
/******************************************************************/

void MUSART_vInit( USART_InitType *A_InitStruct,
				USART_ClockInitTypeDef *A_ClockInitStruct, USART_MemoryMapType *A_USARTx )
{

	if( A_USARTx == USART1_REG )
	{

		MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_USART1EN ) ;

		/*configer Tx1 as alt fun*/
		MGPIOx_ConfigType TX1 =
		{
			.Port 			= USART1_PORT		,	.Pin 		= TX1_PIN		,
			.Mode 			= GPIOx_MODE_AF		,	.OutputType = GPIOx_PUSHPULL,
			.OutputSpeed 	= GPIOx_MediumSpeed	,	.InputType 	= GPIOx_NoPull	,
			.AF_Type 		= GPIOx_AF7
		} ;

		MGPIOx_vInit( &TX1 ) ;

		/*configer Rx1 as alt fun*/
		MGPIOx_ConfigType RX1 =
		{
			.Port 			= USART1_PORT		, 	.Pin 		= RX1_PIN		,
			.Mode 			= GPIOx_MODE_AF		, 	.OutputType = GPIOx_PUSHPULL,
			.OutputSpeed 	= GPIOx_MediumSpeed	, 	.InputType 	= GPIOx_NoPull	,
			.AF_Type 		= GPIOx_AF7
		} ;

		MGPIOx_vInit( &RX1 ) ;

	}
	else if( A_USARTx == USART2_REG )
	{

		MRCC_vEnablePeriphralCLK( RCC_APB2, APB1ENR_USART2EN ) ;

		/*configer Tx2 as alt fun*/
		MGPIOx_ConfigType TX2 =
		{
			.Port 			= USART2_PORT		,	.Pin 		= TX2_PIN		,
			.Mode 			= GPIOx_MODE_AF		,	.OutputType = GPIOx_PUSHPULL,
			.OutputSpeed 	= GPIOx_MediumSpeed	,	.InputType 	= GPIOx_NoPull	,
			.AF_Type 		= GPIOx_AF7
		} ;

		MGPIOx_vInit( &TX2 ) ;

		/*configer Rx2 as alt fun*/
		MGPIOx_ConfigType RX2 =
		{
			.Port 			= USART2_PORT		, 	.Pin 		= RX2_PIN		,
			.Mode 			= GPIOx_MODE_AF		, 	.OutputType = GPIOx_PUSHPULL,
			.OutputSpeed 	= GPIOx_MediumSpeed	, 	.InputType 	= GPIOx_NoPull	,
			.AF_Type 		= GPIOx_AF7
		} ;

		MGPIOx_vInit( &RX2 ) ;

	}
	else if( A_USARTx == USART6_REG )
	{

		MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_USART6EN ) ;

		/*configer Tx6 as alt fun*/
		MGPIOx_ConfigType TX6 =
		{
			.Port 			= USART6_PORT		,	.Pin 		= TX6_PIN		,
			.Mode 			= GPIOx_MODE_AF		,	.OutputType = GPIOx_PUSHPULL,
			.OutputSpeed 	= GPIOx_MediumSpeed	,	.InputType 	= GPIOx_NoPull	,
			.AF_Type 		= GPIOx_AF7
		} ;

		MGPIOx_vInit( &TX6 ) ;

		/*configer Rx6 as alt fun*/
		MGPIOx_ConfigType RX6 =
		{
			.Port 			= USART6_PORT		, 	.Pin 		= RX6_PIN		,
			.Mode 			= GPIOx_MODE_AF		, 	.OutputType = GPIOx_PUSHPULL,
			.OutputSpeed 	= GPIOx_MediumSpeed	, 	.InputType 	= GPIOx_NoPull	,
			.AF_Type 		= GPIOx_AF7
		} ;

		MGPIOx_vInit( &RX6 ) ;

	}

	// BuadRate/Over-sampling selections:
	switch( A_InitStruct->Oversampling )
	{

		case OVER_SAMPLING_16:

			A_USARTx->BRR_REG = UART_BRR_SAMPLING16( __PCLK__ , A_InitStruct->BaudRate ) ;

		break;

		case OVER_SAMPLING_8:

			A_USARTx->BRR_REG = UART_BRR_SAMPLING16( __PCLK__ , A_InitStruct->BaudRate ) ;

		break;

	}

	A_USARTx->CR1_REG = ( A_InitStruct->Oversampling << MUSART_CR1_OVER8_BIT ) 	|
						( A_InitStruct->DataWidth << MUSART_CR1_M_BIT ) 		|
						( A_InitStruct->Parity_Enable << MUSART_CR1_PCE_BIT ) 	|
						( A_InitStruct->Parity_Selection << MUSART_CR1_PS_BIT ) ;

	switch (A_InitStruct->TransferDirection)
	{
		case TX_ONLY:

			SET_BIT( A_USARTx->CR1_REG, MUSART_CR1_TE_BIT ) ;

		break ;

		case RX_ONLY:

			SET_BIT( A_USARTx->CR1_REG, MUSART_CR1_RE_BIT ) ;

		break ;

		case TX_RX  :

			SET_BIT( A_USARTx->CR1_REG, MUSART_CR1_TE_BIT ) ;
			SET_BIT( A_USARTx->CR1_REG, MUSART_CR1_RE_BIT ) ;

		break ;

	}

	A_USARTx->CR2_REG = ( A_InitStruct->StopBits << MUSART_CR2_STOP_BIT )			 	 |
						( A_ClockInitStruct->ClockOutput << MUSART_CR2_CLKEN_BIT )       |
						( A_ClockInitStruct->ClockPhase << MUSART_CR2_CPHA_BIT )         |
						( A_ClockInitStruct->ClockPolarity << MUSART_CR2_CPOL_BIT )      |
						( A_ClockInitStruct->LastBitClockPulse << MUSART_CR2_LBCL_BIT )  ;

	A_USARTx->SR_REG = 0 ; // Clear all the flags.

	SET_BIT( A_USARTx->CR1_REG, MUSART_CR1_UE_BIT ) ; // EN the peripheral.

}

/******************************************************************/
/******************************************************************/

void MUSART_vEnable( USART_MemoryMapType *A_USARTx )
{
	SET_BIT( A_USARTx->CR1_REG, MUSART_CR1_UE_BIT ) ;
}

/******************************************************************/
/******************************************************************/

void MUSART_vDisable( USART_MemoryMapType *A_USARTx )
{
	CLR_BIT( A_USARTx->CR1_REG, MUSART_CR1_UE_BIT ) ;
}

/******************************************************************/
/******************************************************************/

void MUSART_vTransmitByte( USART_MemoryMapType *A_USARTx, u8_t A_u8Byte )
{

	while( GET_BIT( A_USARTx->SR_REG, MUSART_SR_TXE_BIT ) == 0 ) ;

	A_USARTx->DR_REG = A_u8Byte ;

	while( GET_BIT( A_USARTx->SR_REG, MUSART_SR_TC_BIT ) == 0 ) ;

	// Clear the TC flag:
	CLR_BIT( A_USARTx->SR_REG, MUSART_SR_TC_BIT ) ;

}

/******************************************************************/
/******************************************************************/

void MUSART_vTransmitString( USART_MemoryMapType *A_USARTx, c8_t *A_ptrc8String )
{

	u8_t loc_u8Iterator = INITIAL_ZERO ;

	while( A_ptrc8String[loc_u8Iterator] != '\0' )
	{

		MUSART_vTransmitByte( A_USARTx, A_ptrc8String[loc_u8Iterator] ) ;

		loc_u8Iterator++ ;

	}

}

/******************************************************************/
/******************************************************************/

u8_t MUSART_u8ReceiveByteSynchNonBlocking ( USART_MemoryMapType *A_USARTx )
{

	u8_t  loc_u8Data 	= INITIAL_ZERO ;

	u32_t loc_u8TimeOut = INITIAL_ZERO ;

	while( (GET_BIT(A_USARTx->SR_REG, MUSART_SR_RXNE_BIT) == 0) && (loc_u8TimeOut < THRESHOLD_VALUE) )
	{
		loc_u8TimeOut++;
	}

	if ( loc_u8TimeOut == THRESHOLD_VALUE )
	{
		loc_u8Data = 255 ; // To detect the error.
	}
	else
	{
		loc_u8Data = A_USARTx->DR_REG ;
	}

	return loc_u8Data ;

}

/******************************************************************/
/******************************************************************/

u8_t MUSART_u8ReceiveByteSynchBlocking ( USART_MemoryMapType *A_USARTx )
{

	while( GET_BIT(A_USARTx->SR_REG, MUSART_SR_RXNE_BIT) == 0 ) ;

	return A_USARTx->DR_REG ;

}

/******************************************************************/
/******************************************************************/

u8_t * MUSART_ptrReceiveStringSynchNonBlocking( USART_MemoryMapType *A_USARTx )
{

	u8_t loc_u8Iterator = INITIAL_ZERO ;

	u8_t loc_u8DataCome ;

	while( ( loc_u8DataCome = MUSART_u8ReceiveByteSynchNonBlocking(A_USARTx) ) != 13 )
	{
		G_u8String[ loc_u8Iterator ] = loc_u8DataCome ;

		loc_u8Iterator++;
	}

	G_u8String[loc_u8Iterator] = '\0' ;

	return( G_u8String ) ;

}

/******************************************************************/
/******************************************************************/

void MUSART_vRecieveString( USART_MemoryMapType *A_USARTx, c8_t A_c8YourString[] )
{

	u32_t L_u32Counter = INITIAL_ZERO ;

	A_c8YourString[L_u32Counter] = MUSART_u8ReceiveByteSynchBlocking( A_USARTx ) ;

	while( A_c8YourString[L_u32Counter] != '\0' )
	{

		L_u32Counter++ ;

		A_c8YourString[L_u32Counter] = MUSART_u8ReceiveByteSynchBlocking( A_USARTx ) ;

		if( (A_c8YourString[L_u32Counter] == '\n') || (A_c8YourString[L_u32Counter] == '\r') )
		{
			A_c8YourString[L_u32Counter] = '\0' ;
		}

	}

}

/******************************************************************/
/******************************************************************/

u8_t MUSART_u8CompareString( c8_t *String1, c8_t *String2 )
{

	u8_t L_u8TheComparingResult = INITIAL_ZERO ;

    if( strcmp( String1, String2 ) == SAME_STRING )
	{
    	L_u8TheComparingResult =  SAME_STRING ;
    }
    else
	{
    	L_u8TheComparingResult = DIFFERENT_STRING ;
    }

	return L_u8TheComparingResult ;

}

/******************************************************************/
/******************************************************************/

u8_t MUSART_u8ReadDataRegister( USART_MemoryMapType *A_USARTx )
{
	return A_USARTx->DR_REG ;
}

/******************************************************************/
/******************************************************************/

void MUSART_vClearFlags( USART_MemoryMapType *A_USARTx )
{
	A_USARTx->SR_REG = 0 ;
}

/******************************************************************/
/******************************************************************/

void MUSART_vRxIntSetStatus(USART_MemoryMapType *A_USARTx, u8_t A_u8Status)
{

	switch(A_u8Status)
	{

		case ENABLE : SET_BIT( A_USARTx->CR1_REG, (MUSART_CR1_RXNEIE_BIT) ); break ;

		case DISABLE: CLR_BIT( A_USARTx->CR1_REG, (MUSART_CR1_RXNEIE_BIT) ); break ;

	}

}

/******************************************************************/
/******************************************************************/

void MUSART1_vSetCallBack( void (*Fptr) (void) )
{
	MUSART1_CallBack = Fptr ;
}

/******************************************************************/
/******************************************************************/

void MUSART2_vSetCallBack( void (*Fptr) (void) )
{
	MUSART2_CallBack = Fptr ;
}

/******************************************************************/
/******************************************************************/

void MUSART6_vSetCallBack( void (*Fptr) (void) )
{
	MUSART6_CallBack = Fptr ;
}

/******************************************************************/
/******************************************************************/

void USART1_IRQHandler(void)
{

	MUSART1_CallBack( ) ;

}

/******************************************************************/
/******************************************************************/

void USART2_IRQHandler(void)
{

	USART2_REG -> SR_REG = 0 ;

	MUSART2_CallBack( ) ;

}

/******************************************************************/
/******************************************************************/

void USART6_IRQHandler(void)
{

	USART6_REG->SR_REG = 0 ;

	MUSART6_CallBack( ) ;

}

/******************************************************************/
/******************************************************************/






































