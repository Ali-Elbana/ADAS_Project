/**
 * @file UART_interface.h
 * @author Ali El Bana
 * @brief This file contains the interfacing information of UART driver
 * @version 1.0
 * @date 10/14/2022
 */

/* Header file guard */
#ifndef _UART_interface_H
#define _UART_interface_H

/************************************************************************/
/*                        Peripherals declaration                       */
/************************************************************************/

/**
 * @defgroup uart_addresses UART Addresses
 * @{
 */

/**
 * @def USART1_BASE_ADDRESS
 * USART1 base address in the memory
 */
#define USART1_BASE_ADDRESS (0x40011000)

/**
 * @def USART2_BASE_ADDRESS
 * USART2 base address in the memory
 */
#define USART2_BASE_ADDRESS (0x40004400)

/**
 * @def USART6_BASE_ADDRESS
 * USART6 base address in the memory
 */
#define USART6_BASE_ADDRESS (0x40011400)

/** @} */

/**
 * @defgroup uart_registers UART Registers
 * @{
 */

/**
 * @def USART1_REG
 * USART1 registers map
 */
#define USART1_REG ((USART_MemoryMapType *)USART1_BASE_ADDRESS)

/**
 * @def USART2_REG
 * USART2 registers map
 */
#define USART2_REG ((USART_MemoryMapType *)USART2_BASE_ADDRESS)

/**
 * @def USART6_REG
 * USART6 registers map
 */
#define USART6_REG ((USART_MemoryMapType *)USART6_BASE_ADDRESS)

/** @} */

/**
 * @brief USART declaration structure for its registers
 * @struct USART_MemoryMapType
 */
typedef struct
{
	/**
	 * @brief USART Status Register
	 */
	volatile u32_t SR_REG;
	/**
	 * @brief USART Data Register
	 */
	volatile u32_t DR_REG;
	/**
	 * @brief USART Baud Rate Register
	 */
	volatile u32_t BRR_REG;
	/**
	 * @brief USART Control Register 1
	 */
	volatile u32_t CR1_REG;
	/**
	 * @brief USART Control Register 2
	 */
	volatile u32_t CR2_REG;
	/**
	 * @brief USART Control Register 3
	 */
	volatile u32_t CR3_REG;
	/**
	 * @brief USART Guard time and prescaler register
	 */
	volatile u32_t GTPR_REG;
} USART_MemoryMapType;

/**
 * @brief USART Clock declaration structure for
 * @struct USART_InitType
 *
 */
typedef struct
{
	/**
	 * @brief UART Baud Rate
	 */
	u32_t BaudRate;
	/**
	 * @brief UART Data Width
	 */
	u8_t DataWidth;
	/**
	 * @brief UART Stop Bits
	 */
	u8_t StopBits;
	/**
	 * @brief UART Parity Enable
	 */
	u8_t Parity_Enable;
	/**
	 * @brief UART Parity Selection
	 */
	u8_t Parity_Selection;
	/**
	 * @brief UART Transfer Direction
	 * @note Accepted values are: TX_ONLY, RX_ONLY, TX_RX
	 */
	u8_t TransferDirection;
	/**
	 * @brief UART Hardware Flow Control
	 */
	u8_t HardwareFlowControl;
	/**
	 * @brief UART Oversampling
	 */
	u8_t Oversampling;
} USART_InitType;

/**
 * @brief USART Clock declaration structure for its registers
 * @struct USART_ClockInitTypeDef
 */
typedef struct
{
	/**
	 * @brief USART Clock Enable
	 */
	u8_t ClockOutput;
	/**
	 * @brief USART Clock Polarity
	 */
	u8_t ClockPolarity;
	/**
	 * @brief USART Clock Phase
	 */
	u8_t ClockPhase;
	/**
	 * @brief USART Last Bit Clock Pulse
	 */
	u8_t LastBitClockPulse;
} USART_ClockInitTypeDef;

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief Sets a certain pin's output value on a speific port
 * @param[in] A_InitStruct Pointer to a structure that contains the configuration information for the specified USART peripheral.
 * @param[in] A_ClockInitStruct Pointer to a structure that contains the configuration information for the specified USART peripheral.
 * @param[in] A_USARTx Pointer to USARTx registers map
 */
void MUSART_vInit(P2VAR(USART_InitType) A_InitStruct, P2VAR(USART_ClockInitTypeDef) A_ClockInitStruct, P2VAR(USART_MemoryMapType) A_USARTx);

/**
 * @brief Enables the USART peripheral
 * @param[in] A_USARTx Pointer to USARTx registers map
 */
void MUSART_vEnable(P2VAR(USART_MemoryMapType) A_USARTx);

/**
 * @brief Disables the USART peripheral
 * @param[in] A_USARTx Pointer to USARTx registers map
 */
void MUSART_vDisable(P2VAR(USART_MemoryMapType) A_USARTx);

/**
 * @brief Transmits a byte using the USART peripheral
 * @param[in] A_USARTx Pointer to USARTx registers map
 * @param[in] A_u8Byte Byte to be transmitted
 */
void MUSART_vTransmitByte(P2VAR(USART_MemoryMapType) A_USARTx, u8_t A_u8Byte);

/**
 * @brief Transmits a string using the USART peripheral
 * @param[in] A_USARTx Pointer to USARTx registers map
 * @param[in] A_ptrc8String Pointer to the string to be transmitted
 */
void MUSART_vTransmitString(P2VAR(USART_MemoryMapType) A_USARTx, P2VAR(c8_t) A_ptrc8String);

/**
 * @brief Receives a byte using the USART peripheral (non-blocking)
 * @param[in] A_USARTx Pointer to USARTx registers map
 * @return Received byte from the USART peripheral
 */
u8_t MUSART_u8ReceiveByteSynchNonBlocking(P2VAR(USART_MemoryMapType) A_USARTx);

/**
 * @brief Receives a byte using the USART peripheral (blocking)
 * @param[in] A_USARTx Pointer to USARTx registers map
 * @return Received byte from the USART peripheral
 */
u8_t MUSART_u8ReceiveByteSynchBlocking(P2VAR(USART_MemoryMapType) A_USARTx);

/**
 * @brief Receives a string using the USART peripheral (non-blocking)
 * @param[in] A_USARTx Pointer to USARTx registers map
 * @return Pointer to the received string from the USART peripheral
 */
u8_t *MUSART_ptrReceiveStringSynchNonBlocking(P2VAR(USART_MemoryMapType) A_USARTx);

/**
 * @brief Receives a string using the USART peripheral (blocking)
 * @param[in] A_USARTx Pointer to USARTx registers map
 * @param[in] A_c8YourString Pointer to the string to be transmitted
 */
void MUSART_vRecieveString(P2VAR(USART_MemoryMapType) A_USARTx, c8_t A_c8YourString[]);

/**
 * @brief Compares two strings using the USART peripheral
 * @param[in] String1 Pointer to the first string
 * @param[in] String2 Pointer to the second string
 * @return SAME_STRING if the strings are equal, DIFFERENT_STRING if not
 * @see SAME_STRING DIFFERENT_STRING
 */
u8_t MUSART_u8CompareString(P2VAR(c8_t) String1, P2VAR(c8_t) String2);

/**
 * @brief Reads the status register of the USART peripheral
 * @param[in] A_USARTx Pointer to USARTx registers map
 * @return Status register value
 */
u8_t MUSART_u8ReadDataRegister(P2VAR(USART_MemoryMapType) A_USARTx);

/**
 * @brief Clears the status register of the USART peripheral
 * @param[in] A_USARTx Pointer to USARTx registers map
 */
void MUSART_vClearFlags(P2VAR(USART_MemoryMapType) A_USARTx);

/**
 * @brief Set the status of the RX interrupt
 * @param[in] A_USARTx Pointer to USARTx registers map
 * @param[in] A_u8Status Status of the RX interrupt (ENABLE/DISABLE)
 * @see ENABLE DISABLE
 */
void MUSART_vRxIntSetStatus(P2VAR(USART_MemoryMapType) A_USARTx, u8_t A_u8Status);

/**
 * @brief Set UART1 RX callback function
 * @param[in] Fptr Pointer to the callback function
 */
void MUSART1_vSetCallBack(P2FUNC(void, Fptr)(void));

/**
 * @brief Set UART2 RX callback function
 * @param[in] Fptr Pointer to the callback function
 */
void MUSART2_vSetCallBack(P2FUNC(void, Fptr)(void));

/**
 * @brief Set UART6 RX callback function
 * @param[in] Fptr Pointer to the callback function
 */
void MUSART6_vSetCallBack(P2FUNC(void, Fptr)(void));

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @defgroup uart_over_sampling UART Oversampling
 * @{
 */

/**
 * @def OVER_SAMPLING_16
 * Oversampling by 16
 */
#define OVER_SAMPLING_16 (0)

/**
 * @def OVER_SAMPLING_8
 * Oversampling by 8
 */
#define OVER_SAMPLING_8 (1)
/** @} */

/**
 * @defgroup uart_operating_modes UART Operating Modes
 * @{
 */

/**
 * @def TX_ONLY
 * Transmit only mode
 */
#define TX_ONLY (0)

/**
 * @def RX_ONLY
 * Receive only mode
 */
#define RX_ONLY (1)

/**
 * @def TX_RX
 * Transmit and Receive mode
 */
#define TX_RX (2)
/** @} */

/**
 * @defgroup uart_parity UART Parity
 * @{
 */

/**
 * @def EVEN_PARITY
 * Even parity
 */
#define EVEN_PARITY (0)

/**
 * @def ODD_PARITY
 * Odd parity
 */
#define ODD_PARITY (1)
/** @} */

/**
 * @defgroup uart_bit_sizes UART Bit Sizes
 * @{
 */

/**
 * @def MODE_8BIT
 * 8-bit mode for UART
 */
#define MODE_8BIT (0)

/**
 * @def MODE_9BIT
 * 9-bit mode for UART
 */
#define MODE_9BIT (1)
/** @} */

/**
 * @defgroup uart_stop_bits UART Stop Bits
 * @{
 */

/**
 * @def STOP_BIT_1
 * 1 stop bit
 */
#define STOP_BIT_1 (0)

/**
 * @def STOP_BIT_0_5
 * 0.5 stop bits
 */
#define STOP_BIT_0_5 (1)

/**
 * @def STOP_BIT_2
 * 2 stop bits
 */
#define STOP_BIT_2 (2)

/**
 * @def STOP_BIT_1_5
 * 1.5 stop bits
 */
#define STOP_BIT_1_5 (3)

/** @} */

/**
 * @def ENABLE
 * Enable Status
 */
#define ENABLE 1

/**
 * @def DISABLE
 * Disable Status
 */
#define DISABLE 0

/**
 * @def __BAUDRATE__
 * Default baud rate of the UART peripheral
 */
#define __BAUDRATE__ 9600

#endif //_UART_interface_H
