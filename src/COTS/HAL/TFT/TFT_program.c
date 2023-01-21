/* FILENAME: TFT_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 10/13/2022
*/

/************************************************************************/
/*                         Include headers                           	*/
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/RCC/MRCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SysTick/SysTick_interface.h"
#include "../../MCAL/SPI/SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

extern MGPIOx_ConfigType TFT_A0  ;
extern MGPIOx_ConfigType TFT_RST ;

static u16_t CurrentXStart 	= INITIAL_ZERO ;
static u16_t CurrentXEnd 	= INITIAL_ZERO ;
static u16_t CurrentYStart 	= INITIAL_ZERO ;
static u16_t CurrentYEnd 	= INITIAL_ZERO ;

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vWriteCMD( u16_t A_u16CMD )
{

	MGPIOx_vSetPinValue( TFT_A0.Port, TFT_A0.Pin, GPIOx_LOW ) ;

	(void)MSPI_u16Transcieve( SPI_SRC, A_u16CMD ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vWriteData( u16_t A_u16Data )
{

	MGPIOx_vSetPinValue( TFT_A0.Port, TFT_A0.Pin, GPIOx_HIGH ) ;

	(void)MSPI_u16Transcieve( SPI_SRC, A_u16Data ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vResetSequence( void )
{

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_HIGH ) ;

	MSysTick_vDelayMicroSec( 150 ) ; //100us

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_LOW ) ;

	MSysTick_vDelayMicroSec( 5 ) ; //1us

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_HIGH ) ;

	MSysTick_vDelayMicroSec( 150 ) ; //100us

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_LOW ) ;

	MSysTick_vDelayMicroSec( 5 ) ; //1us

	MGPIOx_vSetPinValue( TFT_RST.Port, TFT_RST.Pin, GPIOx_HIGH ) ;

	MSysTick_vDelayMilliSec( 150 ) ; //120ms

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vInit( void )
{

	// Set pin directions:
	MGPIOx_vInit( &TFT_A0  ) ;
	MGPIOx_vInit( &TFT_RST ) ;

	MSPI_vInit( SPI_SRC, SPI_RELATION, SPI_DATA_DIRECTION ) ;

	MSysTick_vInit( ) ;

	// Rest sequence:
	HTFT_vResetSequence( ) ;

	// Send SLPOUT CMD (0x11):
	HTFT_vWriteCMD( SLPOUT_CMD ) ;

	// Wait 15ms:
	MSysTick_vDelayMilliSec( 15 ) ;

	// Send color mode CMD -> RGB565:
	HTFT_vWriteCMD( COLOR_MODE_CMD  ) ;
	HTFT_vWriteData( RGB565_CMD ) ;

	// DISPON CMD (0X29):
	HTFT_vWriteCMD( DISPON_CMD ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vShowImage( u16_t const *A_u16Image, u32_t A_u32ImageSize )
{

	// Set X position:
	HTFT_vWriteCMD( XPOSITION_CMD ) ;

	// Xstart: 0, Xend: 127
	HTFT_vWriteData( 0 ) 	;
	HTFT_vWriteData( 0 ) 	;
	HTFT_vWriteData( 0 ) 	;
	HTFT_vWriteData( 127 ) 	;

	// Set Y position:
	HTFT_vWriteCMD( YPOSITION_CMD ) ;

	// Ystart: 0, Yend: 159
	HTFT_vWriteData( 0 ) 	;
	HTFT_vWriteData( 0 ) 	;
	HTFT_vWriteData( 0 ) 	;
	HTFT_vWriteData( 159 ) 	;

	// Send image data:
	HTFT_vWriteCMD( MEMORY_WRITE_CMD ) ;

	for( u16_t PX = INITIAL_ZERO; PX < A_u32ImageSize; PX++ )
	{

		HTFT_vWriteData( A_u16Image[PX] >> 8 	  ) ; // MSB
		HTFT_vWriteData( A_u16Image[PX] & 0x00FF  ) ; // LSB

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vSetXPosition( u16_t A_u16XStart, u16_t A_u16XEnd )
{

	CurrentXStart 	= A_u16XStart 	;
	CurrentXEnd 	= A_u16XEnd 	;

	HTFT_vWriteCMD( XPOSITION_CMD ) ;

	// Xstart: 0, Xend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( A_u16XStart ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( A_u16XEnd ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vSetYPosition( u16_t A_u16YStart, u16_t A_u16YEnd )
{

	CurrentYStart 	= A_u16YStart 	;
	CurrentYEnd 	= A_u16YEnd 	;

	HTFT_vWriteCMD( YPOSITION_CMD ) ;

	// Ystart: 0, Yend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( A_u16YStart ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( A_u16YEnd ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vFillRectangle( u16_t A_u16Color )
{

	u32_t PXLS_Num = (CurrentXEnd-CurrentXStart) * (CurrentYEnd-CurrentYStart) ;

	HTFT_vWriteCMD( MEMORY_WRITE_CMD ) ;

	for( u8_t PX = 0; PX < PXLS_Num ; PX++ )
	{

		HTFT_vWriteData( A_u16Color >> 8 	) ; // MSB
		HTFT_vWriteData( A_u16Color & 0x00FF  ) ; // LSB

	}

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HTFT_vFillBackground( u16_t A_u16Color )
{

	// Set X position:
	HTFT_vWriteCMD( XPOSITION_CMD ) ;

	// Xstart: 0, Xend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 127 ) ;

	// Set Y position:
	HTFT_vWriteCMD( YPOSITION_CMD ) ;

	// Ystart: 0, Yend: 127
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 0 ) ;
	HTFT_vWriteData( 159 ) ;

	HTFT_vFillRectangle( A_u16Color ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/








