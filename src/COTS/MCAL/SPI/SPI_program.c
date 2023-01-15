/* FILENAME: SPI_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 10/12/2022
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

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

/******************************************************************/
/******************************************************************/

void (*MSPI1_CallBack)(void);
void (*MSPI2_CallBack)(void);
void (*MSPI3_CallBack)(void);

/************************************************************************/
/*                     Functions  implementations                      	*/
/************************************************************************/

void MSPI_vInit( SPI_MemoryMapType * A_SPIx, u8_t A_u8RelationShip, u8_t A_u8DataDirection )
{

	if( A_SPIx == SPI1 )
	{

		MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_SPI1EN ) ;

		// PINs configurations.
		MGPIOx_ConfigType MOSI1 =
		{
			.Port 			= GPIO_PORTA 			, 	.Pin 		= GPIOx_PIN7 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_VeryHighSpeed	, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF5
		} ;

		MGPIOx_ConfigType MISO1 =
		{
			.Port 			= GPIO_PORTA 			, 	.Pin 		= GPIOx_PIN6 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_VeryHighSpeed	, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF5
		} ;

		MGPIOx_ConfigType SCK1 =
		{
			.Port 			= GPIO_PORTA 			, 	.Pin 		= GPIOx_PIN5 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_VeryHighSpeed	, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF5
		} ;

		MGPIOx_vInit( &MOSI1 ) ;
		MGPIOx_vInit( &MISO1 ) ;
		MGPIOx_vInit( &SCK1  ) ;

	}
	else if( A_SPIx == SPI2 )
	{

		MRCC_vEnablePeriphralCLK( RCC_APB1, APB1ENR_SPI2EN ) ;

		// PINs configurations.
		MGPIOx_ConfigType MOSI2 =
		{
			.Port 			= GPIO_PORTB 			, 	.Pin 		= GPIOx_PIN15 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_VeryHighSpeed	, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF5
		} ;

		MGPIOx_ConfigType MISO2 =
		{
			.Port 			= GPIO_PORTB 			, 	.Pin 		= GPIOx_PIN14 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_VeryHighSpeed	, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF5
		} ;

		MGPIOx_ConfigType SCK2 =
		{
			.Port 			= GPIO_PORTB 			, 	.Pin 		= GPIOx_PIN13 	 	,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_VeryHighSpeed	, 	.InputType 	= GPIOx_NoPull	 	,
			.AF_Type 		= GPIOx_AF5
		} ;

		MGPIOx_vInit( &MOSI2 ) ;
		MGPIOx_vInit( &MISO2 ) ;
		MGPIOx_vInit( &SCK2  ) ;

	}
	else if( A_SPIx == SPI3 )
	{

		MRCC_vEnablePeriphralCLK( RCC_APB1, APB1ENR_SPI3EN ) ;

		// PINs configurations.
		MGPIOx_ConfigType MOSI3 =
		{
			.Port 			= GPIO_PORTB 			, 	.Pin 		= GPIOx_PIN5 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_VeryHighSpeed	, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF5
		} ;

		MGPIOx_ConfigType MISO3 =
		{
			.Port 			= GPIO_PORTB 			, 	.Pin 		= GPIOx_PIN4 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_VeryHighSpeed	, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF5
		} ;

		MGPIOx_ConfigType SCK3 =
		{
			.Port 			= GPIO_PORTB 			, 	.Pin 		= GPIOx_PIN3 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_VeryHighSpeed	, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF5
		} ;

		MGPIOx_vInit( &MOSI3 ) ;
		MGPIOx_vInit( &MISO3 ) ;
		MGPIOx_vInit( &SCK3  ) ;

	}

	if( A_u8RelationShip == SPIx_MSTR )
	{
		// BUAD RATE.
		SPI1->CR1 = (A_SPIx->CR1 & ( ~(BR_MODE) << 3 )) | ( BR_MODE << 3 )  ;
	}

	// CPHA, CPOL.
	SET_BIT( A_SPIx->CR1, CPHA ) ;
	SET_BIT( A_SPIx->CR1, CPOL ) ;

	// Data format.
	#if DFF_MODE == EIGHT_BITS

		CLR_BIT( A_SPIx->CR1, DFF ) ;

	#elif DFF_MODE == SIXTEEN_BITS

		SET_BIT( A_SPIx->CR1, DFF ) ;

	#endif

	// MSB/LSB first.
	CLR_BIT( A_SPIx->CR1, LSBFIRST ) ;

	// Select SW slave management.
	switch( A_u8RelationShip )
	{
		case SPIx_MSTR:

			SET_BIT( A_SPIx->CR1, SSM ) ;
			SET_BIT( A_SPIx->CR1, SSI ) ;

		break ;

		case SPIx_SLAVE:

			SET_BIT( A_SPIx->CR1, SSM ) ;
			CLR_BIT( A_SPIx->CR1, SSI ) ;

		break ;

	}

	// Select Motorola or TI Mode:
	CLR_BIT( A_SPIx->CR2, FRF ) ; // Motorola

	// MASTER/SLAVE Mode.
	switch( A_u8RelationShip )
	{
		case SPIx_MSTR:  SET_BIT( A_SPIx->CR1, MSTR ) ; break ;

		case SPIx_SLAVE: CLR_BIT( A_SPIx->CR1, MSTR ) ; break ;
	}

	// Data direction:
	switch( A_u8RelationShip )
	{

		case SPIx_MSTR:

			switch( A_u8DataDirection )
			{

				case SPIx_FULL_DUPLEX:

					CLR_BIT( A_SPIx->CR1, BIDIMODE ) ;
					CLR_BIT( A_SPIx->CR1, RXONLY   ) ;

				break ;

				case SPIx_SIMPLEX	 :

					CLR_BIT( A_SPIx->CR1, BIDIMODE ) ;

					#if SIMPLEX_MODE == SIMPLEX_TX

						CLR_BIT( A_SPIx->CR1, RXONLY ) ;

					#elif SIMPLEX_MODE == SIMPLEX_RX

						SET_BIT( A_SPIx->CR1, RXONLY ) ;

					#endif

				break ;

				case SPIx_HALF_DUPLEX:

					#if HALF_DUPLEX_MODE == HALF_DUPLEX_TX

						SET_BIT( A_SPIx->CR1, BIDIMODE ) ;
						SET_BIT( A_SPIx->CR1, BIDIOE   ) ;

					#elif HALF_DUPLEX_MODE == HALF_DUPLEX_RX

						SET_BIT( A_SPIx->CR1, BIDIMODE ) ;
						CLR_BIT( A_SPIx->CR1, BIDIOE   ) ;

					#endif

				break ;

			}

		break;

		case SPIx_SLAVE:

			switch( A_u8DataDirection )
			{

				case SPIx_FULL_DUPLEX:

					CLR_BIT( A_SPIx->CR1, BIDIMODE ) ;
					CLR_BIT( A_SPIx->CR1, RXONLY   ) ;

				break ;

				case SPIx_SIMPLEX	 :

					CLR_BIT( A_SPIx->CR1, BIDIMODE ) ;

					#if SIMPLEX_MODE == SIMPLEX_TX

						CLR_BIT( A_SPIx->CR1, RXONLY ) ;

					#elif SIMPLEX_MODE == SIMPLEX_RX

						SET_BIT( A_SPIx->CR1, RXONLY ) ;

					#endif

				break ;

				case SPIx_HALF_DUPLEX:

					#if HALF_DUPLEX_MODE == HALF_DUPLEX_TX

						SET_BIT( A_SPIx->CR1, BIDIMODE ) ;
						SET_BIT( A_SPIx->CR1, BIDIOE   ) ;

					#elif HALF_DUPLEX_MODE == HALF_DUPLEX_RX

						SET_BIT( A_SPIx->CR1, BIDIMODE ) ;
						CLR_BIT( A_SPIx->CR1, BIDIOE   ) ;

					#endif

				break ;

			}

		break;

	}

	// Multi-master mode:
	#if MULTI_MSTR_MODE == ENABLE

		CLR_BIT( A_SPIx->CR2, SSOE ) ;

	#elif MULTI_MSTR_MODE == DISABLE

		SET_BIT( A_SPIx->CR2, SSOE ) ;

	#endif

	// EN/DIS IRQ:
	#if TXNEIE_MODE == ENABLE

		SET_BIT( A_SPIx->CR2, TXEIE ) ;

	#elif TXNEIE_MODE == DISABLE

		CLR_BIT( A_SPIx->CR2, TXEIE ) ;

	#endif

	#if RXNEIE_MODE == ENABLE

		SET_BIT( A_SPIx->CR2, RXNEIE ) ;

	#elif RXNEIE_MODE == DISABLE

		CLR_BIT( A_SPIx->CR2, RXNEIE ) ;

	#endif

	// EN/DIS SPI.
	SET_BIT( A_SPIx->CR1, SPE ) ;

}

/******************************************************************/
/******************************************************************/

u16_t MSPI_u16Transcieve( SPI_MemoryMapType * A_SPIx, u16_t A_u16Data )
{

	SPI1->DR = A_u16Data ;

	// Wait for transmission complete.
	while( GET_BIT( A_SPIx->SR, TXE ) == FLAG_CLEARED )
	{
		asm("NOP") ;
	}

	// Wait for the last transmission bit.
	while( GET_BIT( A_SPIx->SR, BSY ) == FLAG_SET )
	{
		asm("NOP") ;
	}

	// Wait for reception complete.
	while( GET_BIT( A_SPIx->SR, RXNE ) == FLAG_CLEARED )
	{
		asm("NOP") ;
	}


	return A_SPIx->DR ;

}

/******************************************************************/
/******************************************************************/

void MSPI_vMasterTransmit( SPI_MemoryMapType * A_SPIx, u16_t A_u16Data )
{

	// Start transmission.
	SPI1->DR = A_u16Data ;

	// Wait for transmission complete.
	while( GET_BIT( A_SPIx->SR, TXE ) == FLAG_CLEARED )
	{
		asm("NOP") ;
	}

	// Wait for the last transmission bit.
	while( GET_BIT( A_SPIx->SR, BSY ) == FLAG_SET )
	{
		asm("NOP") ;
	}

}

/******************************************************************/
/******************************************************************/

u16_t MSPI_u16MasterRecieve( SPI_MemoryMapType * A_SPIx )
{

	// Wait for reception complete.
	while( GET_BIT( A_SPIx->SR, RXNE ) == FLAG_CLEARED )
	{
		asm("NOP") ;
	}

	// Return data register.
	return A_SPIx->DR ;

}

/******************************************************************/
/******************************************************************/

void MSPI_vSlaveTransmit( SPI_MemoryMapType * A_SPIx, u16_t A_u16Data )
{

	// Start transmission.
	SPI1->DR = A_u16Data ;

	// Wait for transmission complete.
	while( GET_BIT( A_SPIx->SR, TXE ) == FLAG_CLEARED )
	{
		asm("NOP") ;
	}

	// Wait for the last transmission bit.
	while( GET_BIT( A_SPIx->SR, BSY ) == FLAG_SET )
	{
		asm("NOP") ;
	}

}

/******************************************************************/
/******************************************************************/

u16_t MSPI_u16SlaveRecieve( SPI_MemoryMapType * A_SPIx )
{

	// Wait for reception complete.
	while( GET_BIT( A_SPIx->SR, RXNE ) == FLAG_CLEARED )
	{
		asm("NOP") ;
	}

	// Return data register.
	return A_SPIx->DR ;

}

/******************************************************************/
/******************************************************************/

void MSPI_vDISABLE( SPI_MemoryMapType * A_SPIx, u8_t A_u8RelationShip, u8_t A_u8DataDirection )
{

	switch( A_u8DataDirection )
	{

		case SPIx_FULL_DUPLEX:

			// Wait for reception complete.
			while( GET_BIT( A_SPIx->SR, RXNE ) == FLAG_CLEARED ) ;

			// Wait for transmission complete.
			while( GET_BIT( A_SPIx->SR, TXE ) == FLAG_CLEARED ) ;

			// Wait for the last transmission bit.
			while( GET_BIT( A_SPIx->SR, BSY ) == FLAG_SET ) ;

			// Disabling the SPIx.
			CLR_BIT( A_SPIx->CR1, SPE ) ;

		break ;


		case SPIx_SIMPLEX	 :

		#if SIMPLEX_MODE == SIMPLEX_TX

			// Wait for transmission complete.
			while( GET_BIT( A_SPIx->SR, TXE ) == FLAG_CLEARED ) ;

			// Wait for the last transmission bit.
			while( GET_BIT( A_SPIx->SR, BSY ) == FLAG_SET ) ;

			// Disabling the SPIx.
			CLR_BIT( A_SPIx->CR1, SPE ) ;

		#elif SIMPLEX_MODE == SIMPLEX_RX

			switch( A_u8RelationShip )
			{

				case SPIx_MSTR:

					// Wait for reception complete.
					while( GET_BIT( A_SPIx->SR, RXNE ) == FLAG_CLEARED ) ;

					// Disabling the SPIx.
					CLR_BIT( A_SPIx->CR1, SPE ) ;

				break ;

				case SPIx_SLAVE:

					// Disabling the SPIx.
					CLR_BIT( A_SPIx->CR1, SPE ) ;

					// Wait for the last transmission bit.
					while( GET_BIT( A_SPIx->SR, BSY ) == FLAG_SET ) ;

				break ;

			}

		#endif

		break ;


		case SPIx_HALF_DUPLEX:

			#if HALF_DUPLEX_MODE == HALF_DUPLEX_TX

			// Wait for transmission complete.
			while( GET_BIT( A_SPIx->SR, TXE ) == FLAG_CLEARED ) ;

			// Wait for the last transmission bit.
			while( GET_BIT( A_SPIx->SR, BSY ) == FLAG_SET ) ;

			// Disabling the SPIx.
			CLR_BIT( A_SPIx->CR1, SPE ) ;

			#elif HALF_DUPLEX_MODE == HALF_DUPLEX_RX

				switch( A_u8RelationShip )
				{

					case SPIx_MSTR:

						// Wait for reception complete.
						while( GET_BIT( A_SPIx->SR, RXNE ) == FLAG_CLEARED ) ;

						// Disabling the SPIx.
						CLR_BIT( A_SPIx->CR1, SPE ) ;

					break ;

					case SPIx_SLAVE:

						// Disabling the SPIx.
						CLR_BIT( A_SPIx->CR1, SPE ) ;

						// Wait for the last transmission bit.
						while( GET_BIT( A_SPIx->SR, BSY ) == FLAG_SET ) ;

					break ;

				}

			#endif

		break ;

	}

	if( A_SPIx == SPI1 )
	{
		MRCC_vDisablePeriphralCLK( RCC_APB2, APB2ENR_SPI1EN ) ;
	}
	else if( A_SPIx == SPI2 )
	{
		MRCC_vDisablePeriphralCLK( RCC_APB1, APB1ENR_SPI2EN ) ;
	}
	else if( A_SPIx == SPI3 )
	{
		MRCC_vDisablePeriphralCLK( RCC_APB1, APB1ENR_SPI3EN ) ;
	}

}

/******************************************************************/
/******************************************************************/

void MSPI1_vSetCallBack( void (*Fptr) (void) )
{
	MSPI1_CallBack = Fptr ;
}

/******************************************************************/
/******************************************************************/

void MSPI2_vSetCallBack( void (*Fptr) (void) )
{
	MSPI2_CallBack = Fptr ;
}

/******************************************************************/
/******************************************************************/

void MSPI3_vSetCallBack( void (*Fptr) (void) )
{
	MSPI3_CallBack = Fptr ;
}

/******************************************************************/
/******************************************************************/

void SPI1_IRQHandler(void)
{

	// CLEAR FLAGS:
	SPI1->SR = SR_RESET ;

	MSPI1_CallBack() ;

}

/******************************************************************/
/******************************************************************/

void SPI2_IRQHandler(void)
{

	// CLEAR FLAGS:
	SPI2->SR = SR_RESET ;

	MSPI2_CallBack() ;

}

/******************************************************************/
/******************************************************************/

void SPI3_IRQHandler(void)
{

	// CLEAR FLAGS:
	SPI3->SR = SR_RESET ;

	MSPI3_CallBack() ;

}

/******************************************************************/
/******************************************************************/








