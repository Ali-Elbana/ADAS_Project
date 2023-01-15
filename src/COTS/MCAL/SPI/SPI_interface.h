/* FILENAME: SPI_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 10/12/2022
*/
#ifndef _SPI_interface_H
#define _SPI_interface_H

/************************************************************************/
/*                        Peripherals declaration                       */
/************************************************************************/

#define SPI1_BASE_ADDRESS	0x40013000
#define SPI2_BASE_ADDRESS	0x40003800
#define SPI3_BASE_ADDRESS	0x40003C00
#define SPI4_BASE_ADDRESS	0x40013400

typedef struct
{

	volatile u32_t CR1 	 	;

	volatile u32_t CR2 	 	;

	volatile u32_t SR 		;

	volatile u32_t DR 		;

	volatile u32_t CRCPR 	;

	volatile u32_t RXCRCR 	;

	volatile u32_t TXCRCR 	;

	volatile u32_t I2SCFGR	;

	volatile u32_t I2SPR 	;

} SPI_MemoryMapType ;


#define SPI1 ( ( SPI_MemoryMapType*) SPI1_BASE_ADDRESS)
#define SPI2 ( ( SPI_MemoryMapType*) SPI2_BASE_ADDRESS)
#define SPI3 ( ( SPI_MemoryMapType*) SPI3_BASE_ADDRESS)

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void MSPI_vInit( SPI_MemoryMapType * A_SPIx, u8_t A_u8RelationShip, u8_t A_u8DataDirection ) ;

u16_t MSPI_u16Transcieve( SPI_MemoryMapType * A_SPIx, u16_t A_u16Data ) ;

void MSPI_vMasterTransmit( SPI_MemoryMapType * A_SPIx, u16_t A_u16Data ) ;

u16_t MSPI_u16MasterRecieve( SPI_MemoryMapType * A_SPIx ) ;

void MSPI_vSlaveTransmit( SPI_MemoryMapType * A_SPIx, u16_t A_u16Data ) ;

u16_t MSPI_u16SlaveRecieve( SPI_MemoryMapType * A_SPIx ) ;

void MSPI_vDISABLE( SPI_MemoryMapType * A_SPIx, u8_t A_u8RelationShip, u8_t A_u8DataDirection ) ;

void MSPI1_vSetCallBack( void (*Fptr) (void) ) ;

void MSPI2_vSetCallBack( void (*Fptr) (void) ) ;

void MSPI3_vSetCallBack( void (*Fptr) (void) ) ;

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

#define SPIx_MSTR 	1
#define SPIx_SLAVE	2

#define SPIx_SIMPLEX 		1
#define SPIx_HALF_DUPLEX	2
#define SPIx_FULL_DUPLEX	3








#endif //_SPI_interface_H
