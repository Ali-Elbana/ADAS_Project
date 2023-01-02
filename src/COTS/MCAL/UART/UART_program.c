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

void MUSART_vTransmitString( USART_MemoryMapType *A_USARTx, u8_t *A_ptru8String )
{

	u8_t loc_u8Iterator = INITIAL_ZERO ;

	while( A_ptru8String[loc_u8Iterator] != '\0' )
	{

		MUSART_vTransmitByte( A_USARTx, A_ptru8String[loc_u8Iterator] ) ;

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

	USART1_REG->SR_REG = 0 ;

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






































