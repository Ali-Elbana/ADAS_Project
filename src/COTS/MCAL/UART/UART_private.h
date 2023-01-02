/* FILENAME: UART_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 10/14/2022
*/
#ifndef _UART_private_H
#define _UART_private_H


#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            ((u32_t)((((u64_t)(_PCLK_))*25U)/(4U*((u64_t)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U) + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            ((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             ((u32_t)((((u64_t)(_PCLK_))*25U)/(2U*((u64_t)(_BAUD_)))))
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U) + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + ((UART DIVFRAQ & 0xF8) << 1) + (UART DIVFRAQ & 0x07U) */
#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             ((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                        ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))


/**********************************************/
/* 				SR BITS Mapping 			  */
/**********************************************/
/*	Parity error					*/
#define MUSART_SR_PE_BIT	0
/*	Framing error					*/
#define MUSART_SR_FE_BIT	1
/*	Noise error flag				*/
#define MUSART_SR_NE_BIT	2
/*	Overrun error					*/
#define MUSART_SR_ORE_BIT	3
/*	IDLE line detected				*/
#define MUSART_SR_IDLE_BIT	4
/*	Read data register not empty	*/
#define MUSART_SR_RXNE_BIT	5
/*	Transmission complete			*/
#define MUSART_SR_TC_BIT	6
/*	Transmit data register empty	*/
#define MUSART_SR_TXE_BIT	7
/*	LIN break detection flag		*/
#define MUSART_SR_LBD_BIT	8
/*	CTS flag						*/
#define MUSART_SR_CTS_BIT	9

/**********************************************/
/* 				CR1 BITS Mapping 			  */
/**********************************************/
/*	Send break	bit	*/
#define MUSART_CR1_SBK_BIT	0
/*	Recevier Wakeup	bit	*/
#define MUSART_CR1_RWU_BIT	1
/*	Recevier Enable bit	*/
#define MUSART_CR1_RE_BIT	2
/*	Transmitter Enable bit	*/
#define MUSART_CR1_TE_BIT	3
/*	IDLE interrupt enable bit	*/
#define MUSART_CR1_IDLEIE_BIT	4
/*	RXNEIE interrupt enable bit	*/
#define MUSART_CR1_RXNEIE_BIT	5
/*	Transmission complete interrupt enable bit	*/
#define MUSART_CR1_TCIE_BIT		6
/*	TXE interrupt enable bit	*/
#define MUSART_CR1_TXEIE_BIT	7
/*	PE interrupt enable bit	*/
#define MUSART_CR1_PEIE_BIT		8
/*	Parity selection bit	*/
#define MUSART_CR1_PS_BIT		9
/*	Parity control enable bit	*/
#define MUSART_CR1_PCE_BIT		10
/*	Wakeup method bit	*/
#define MUSART_CR1_WAKE_BIT		11
/*	Word length bit	*/
#define MUSART_CR1_M_BIT		12
/*	USART enable bit	*/
#define MUSART_CR1_UE_BIT		13
/*	USART Oversampling bit	*/
#define MUSART_CR1_OVER8_BIT    15

/**********************************************/
/* 				CR2 BITS Mapping 			  */
/**********************************************/
/*	Address of the USART node bits	*/
#define MUSART_CR2_ADD0_BIT		0
#define MUSART_CR2_ADD1_BIT		1
#define MUSART_CR2_ADD2_BIT		2
#define MUSART_CR2_ADD3_BIT		3
/*	lin break detection length bit	*/
#define MUSART_CR2_LBDL_BIT	5
/*	LIN break detection interrupt enable bit	*/
#define MUSART_CR2_LBDIE_BIT		6
/*	Last bit clock pulse bit	*/
#define MUSART_CR2_LBCL_BIT		8
/*	Clock phase bit	*/
#define MUSART_CR2_CPHA_BIT		9
/*	Clock polarity bit	*/
#define MUSART_CR2_CPOL_BIT		10
/*	Clock enable bit	*/
#define MUSART_CR2_CLKEN_BIT	11
/*	STOP bit start */
#define MUSART_CR2_STOP_BIT		12
/*	STOP bits 	*/
#define MUSART_CR2_STOP0_BIT	12
#define MUSART_CR2_STOP1_BIT	13
/*	LIN mode enable bit	*/
#define MUSART_CR2_LINEN_BIT	14

/**********************************************/
/* 				CR3 BITS Mapping 			  */
/**********************************************/
/*	CTS interrupt enable bit	*/
#define MUSART_CR3_CTSIE_BIT	10
/*	CTS enable bit	*/
#define MUSART_CR3_CTSE_BIT		9
/*	RTS enable bit	*/
#define MUSART_CR3_RTSE_BIT		8
/*	DMA enable transmitter bit	*/
#define MUSART_CR3_DMAT_BIT		7
/*	DMA enable receiver bit	*/
#define MUSART_CR3_DMAR_BIT		6
/*	Smartcard mode enable bit	*/
#define MUSART_CR3_SCEN_BIT		5
/*	Smartcard NACK enable bit	*/
#define MUSART_CR3_NACK_BIT		4
/*	Half-duplex selection bit	*/
#define MUSART_CR3_HDSEL_BIT	3
/*	IrDA low-power bit	*/
#define MUSART_CR3_IRLP_BIT		2
/*	IrDA mode enable bit	*/
#define MUSART_CR3_IREN_BIT		1
/*	Error interrupt enable bit	*/
#define MUSART_CR3_EIE_BIT		0







#endif //_UART_private_H
