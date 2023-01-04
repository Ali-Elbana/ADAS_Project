/* FILENAME: UART_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 10/14/2022
*/
#ifndef _UART_interface_H
#define _UART_interface_H



/************************************************************************/
/*                        Peripherals declaration                       */
/************************************************************************/

#define USART1_BASE_ADDRESS	0x40011000
#define USART2_BASE_ADDRESS	0x40004400
#define USART6_BASE_ADDRESS	0x40011400

typedef struct
{

	volatile u32_t SR_REG 	;

	volatile u32_t DR_REG 	;

	volatile u32_t BRR_REG 	;

	volatile u32_t CR1_REG 	;

	volatile u32_t CR2_REG 	;

	volatile u32_t CR3_REG 	;

	volatile u32_t GTPR_REG ;

} USART_MemoryMapType ;


#define USART1_REG ( ( USART_MemoryMapType*) USART1_BASE_ADDRESS)
#define USART2_REG ( ( USART_MemoryMapType*) USART2_BASE_ADDRESS)
#define USART6_REG ( ( USART_MemoryMapType*) USART6_BASE_ADDRESS)


typedef struct
{
	u32_t BaudRate			;

	u8_t DataWidth			;

	u8_t StopBits			;

	u8_t Parity_Enable		;

	u8_t Parity_Selection	;

	u8_t TransferDirection	; // TX_ONLY  RX_ONLY  TX_RX

	u8_t HardwareFlowControl;

	u8_t Oversampling		;

}USART_InitType ;


typedef struct
{
	u8_t ClockOutput		;

	u8_t ClockPolarity		;

	u8_t ClockPhase			;

	u8_t LastBitClockPulse	;

}USART_ClockInitTypeDef ;


/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void MUSART_vInit( USART_InitType *A_InitStruct,
				USART_ClockInitTypeDef *A_ClockInitStruct, USART_MemoryMapType *A_USARTx ) ;

void MUSART_vEnable( USART_MemoryMapType *A_USARTx ) ;

void MUSART_vDisable( USART_MemoryMapType *A_USARTx ) ;

void MUSART_vTransmitByte( USART_MemoryMapType *A_USARTx, u8_t A_u8Byte ) ;

void MUSART_vTransmitString( USART_MemoryMapType *A_USARTx, c8_t *A_ptrc8String ) ;

u8_t MUSART_u8ReceiveByteSynchNonBlocking ( USART_MemoryMapType *A_USARTx ) ;

u8_t MUSART_u8ReceiveByteSynchBlocking ( USART_MemoryMapType *A_USARTx ) ;

u8_t * MUSART_ptrReceiveStringSynchNonBlocking( USART_MemoryMapType *A_USARTx ) ;

u8_t MUSART_u8ReadDataRegister( USART_MemoryMapType *A_USARTx ) ;

void MUSART_vClearFlags( USART_MemoryMapType *A_USARTx ) ;

void MUSART_vRxIntSetStatus(USART_MemoryMapType *A_USARTx, u8_t A_u8Status) ;

void MUSART1_vSetCallBack( void (*Fptr) (void) ) ;

void MUSART2_vSetCallBack( void (*Fptr) (void) ) ;

void MUSART6_vSetCallBack( void (*Fptr) (void) ) ;


/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

#define OVER_SAMPLING_16	0
#define OVER_SAMPLING_8 	1

#define TX_ONLY             0
#define RX_ONLY             1
#define TX_RX               2

#define EVEN_PARITY         0
#define ODD_PARITY          1

#define MODE_8BIT			0
#define MODE_9BIT			1

#define STOP_BIT_1			0
#define STOP_BIT_0_5		1
#define STOP_BIT_2			2
#define STOP_BIT_1_5		3

#define ENABLE				1
#define DISABLE				0

#define __BAUDRATE__ 9600




















#endif //_UART_interface_H
