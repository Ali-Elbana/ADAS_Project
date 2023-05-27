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

/**
 * @defgroup spi_peripherals SPI Peripherals
 * @{
 */

/**
 * @defgroup spi_addresses SPI Addresses
 * @{
 */

/**
 * @def SPI1_BASE_ADDRESS
 * SPI1 Base Address
*/
#define SPI1_BASE_ADDRESS 0x40013000

/**
 * @def SPI2_BASE_ADDRESS
 * SPI2 Base Address
 */
#define SPI2_BASE_ADDRESS 0x40003800

/**
 * @def SPI3_BASE_ADDRESS
 * SPI3 Base Address
 */
#define SPI3_BASE_ADDRESS 0x40003C00

/**
 * @def SPI4_BASE_ADDRESS
 * SPI4 Base Address
 */
#define SPI4_BASE_ADDRESS 0x40013400

/** @} */

/**
 * @defgroup spi_registers SPI Registers
 * @{
 */

/**
 * @def SPI1
 * SPI1 Peripheral
 */
#define SPI1 ((SPI_MemoryMapType *)SPI1_BASE_ADDRESS)

/**
 * @def SPI2
 * SPI2 Peripheral
 */
#define SPI2 ((SPI_MemoryMapType *)SPI2_BASE_ADDRESS)

/**
 * @def SPI3
 * SPI3 Peripheral
 */
#define SPI3 ((SPI_MemoryMapType *)SPI3_BASE_ADDRESS)

/** @} */

/** @} */

/**
 * @brief SPI Registers
 * @struct SPI_MemoryMapType
 */
typedef struct
{
	/**
	 * @brief SPI Control Register 1
	 */
	volatile u32_t CR1;
	/**
	 * @brief SPI Control Register 2
	 */
	volatile u32_t CR2;
	/**
	 * @brief SPI Status Register
	 */
	volatile u32_t SR;
	/**
	 * @brief SPI Data Register
	 */
	volatile u32_t DR;
	/**
	 * @brief SPI CRC Polynomial Register
	 */
	volatile u32_t CRCPR;
	/**
	 * @brief SPI RX CRC Register
	 */
	volatile u32_t RXCRCR;
	/**
	 * @brief SPI TX CRC Register
	 */
	volatile u32_t TXCRCR;
	/**
	 * @brief SPI I2S Configuration Register
	 */
	volatile u32_t I2SCFGR;
	/**
	 * @brief SPI I2S Prescaler Register
	 */
	volatile u32_t I2SPR;
} SPI_MemoryMapType;

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief This function is responsible for initializing the SPI module
 *
 * @param[in] A_SPIx SPI peripheral to initialize
 * @param[in] A_u8RelationShip SPI Master or Slave
 * @param[in] A_u8DataDirection SPI Data Direction
 */
void MSPI_vInit(SPI_MemoryMapType *A_SPIx, u8_t A_u8RelationShip, u8_t A_u8DataDirection);

/**
 * @brief This function is responsible for sending data through the SPI module
 *
 * @param A_SPIx SPI peripheral to send data through
 * @param A_u16Data Data to be sent
 * @return u16_t Received data from the slave
 */
u16_t MSPI_u16Transcieve(SPI_MemoryMapType *A_SPIx, u16_t A_u16Data);

/**
 * @brief This function is responsible for sending data through the SPI module
 *
 * @param A_SPIx SPI peripheral to send data through
 * @param A_u16Data Data to be sent
 */
void MSPI_vMasterTransmit(SPI_MemoryMapType *A_SPIx, u16_t A_u16Data);

/**
 * @brief This function is responsible for receiving data through the SPI module
 *
 * @param A_SPIx SPI peripheral to receive data through
 * @return u16_t Received data from the slave
 */
u16_t MSPI_u16MasterRecieve(SPI_MemoryMapType *A_SPIx);

/**
 * @brief This function is responsible for sending data through the SPI module
 *
 * @param A_SPIx SPI peripheral to send data through
 * @param A_u16Data Data to be sent
 */
void MSPI_vSlaveTransmit(SPI_MemoryMapType *A_SPIx, u16_t A_u16Data);

/**
 * @brief This function is responsible for receiving data through the SPI module
 *
 * @param A_SPIx SPI peripheral to receive data through
 * @return u16_t Received data from the master
 */
u16_t MSPI_u16SlaveRecieve(SPI_MemoryMapType *A_SPIx);

/**
 * @brief This function is responsible for disabling the SPI module
 *
 * @param A_SPIx SPI peripheral to disable
 * @param A_u8RelationShip SPI Master or Slave
 * @param A_u8DataDirection SPI Data Direction
 */
void MSPI_vDISABLE(SPI_MemoryMapType *A_SPIx, u8_t A_u8RelationShip, u8_t A_u8DataDirection);

/**
 * @brief This function is responsible for setting the callback function for SPI1
 *
 * @param Fptr Pointer to the callback function
 */
void MSPI1_vSetCallBack(void (*Fptr)(void));

/**
 * @brief This function is responsible for setting the callback function for SPI2
 *
 * @param Fptr Pointer to the callback function
 */
void MSPI2_vSetCallBack(void (*Fptr)(void));

/**
 * @brief This function is responsible for setting the callback function for SPI3
 *
 * @param Fptr Pointer to the callback function
 */
void MSPI3_vSetCallBack(void (*Fptr)(void));

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @defgroup spi_interfacing_macros SPI Interfacing Macros
 * @{
 */

/**
 * @def SPIx_MSTR
 * SPI Master
 */
#define SPIx_MSTR 1

/**
 * @def SPIx_SLAVE
 * SPI Slave
 */
#define SPIx_SLAVE 2

/**
 * @def SPIx_SIMPLEX
 * SPI Simplex
 */
#define SPIx_SIMPLEX 1

/**
 * @def SPIx_HALF_DUPLEX
 * SPI Half Duplex
 */
#define SPIx_HALF_DUPLEX 2

/**
 * @def SPIx_FULL_DUPLEX
 * SPI Full Duplex
 */
#define SPIx_FULL_DUPLEX 3

/** @} */

#endif //_SPI_interface_H
