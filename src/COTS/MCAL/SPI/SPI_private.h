/* FILENAME: SPI_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 10/12/2022
*/
#ifndef _SPI_private_H
#define _SPI_private_H


// CR1 BITS
#define CPHA 		0
#define CPOL 		1
#define	MSTR 		2
#define SPE  		6
#define LSBFIRST 	7
#define SSI			8
#define SSM			9
#define	RXONLY		10
#define	DFF			11
#define	CRCNEXT		12
#define	CRCEN		13
#define BIDIOE		14
#define BIDIMODE	15

// CR2 BITS
#define	RXDMAEN	0
#define	TXDMAEN	1
#define	SSOE	2
#define	FRF		4
#define	ERRIE	5
#define	RXNEIE	6
#define	TXEIE	7

// SR BITS
#define	RXNE	0
#define	TXE		1
#define	CHSIDE	2
#define	UDR		3
#define	CRCERR	4
#define	MODF	5
#define	OVR		6
#define	BSY		7
#define	FRE		8




// Configuration options:
#define FIRST_CLK_Captured 	1
#define SECOND_CLK_Captured	0

#define CLK_IdleAt0	0
#define CLK_IdleAt1	1

#define SLAVE 	0
#define MASTER	1

#define CLK_By2		0b000U
#define CLK_By4		0b001U
#define CLK_By8		0b010U
#define CLK_By16	0b011U
#define CLK_By32	0b100U
#define CLK_By64	0b101U
#define CLK_By128	0b110U
#define CLK_By256	0b111U

#define ENABLE 	1
#define DISABLE	0

#define MSB_First 0
#define LSB_First 1

#define FULL_DUPLEX 0
#define RX_ONLY    	1

#define EIGHT_BITS   0
#define SIXTEEN_BITS 1

#define CRC_PHASE   	1
#define NO_CRC_PHASE	0

#define OneLine 	1
#define TwoLines	0

#define MOTOROLA 	0
#define TI      	1

#define EMPTY   	0
#define NOTEMPTY	1

#define LEFT 	0
#define RIGHT	1

#define OCCURRED    	1
#define NOT_OCCURRED	0

#define MATCHED    	0
#define NOT_MATCHED	1

#define FAULT_OCCURRED   	1
#define NO_FAULT_OCCURRED	0

#define BUSY   		1
#define NOT_BUSY 	0

#define ERROR   	1
#define NO_ERROR	0

// HALF DUPLEX TX/RX:
#define HALF_DUPLEX_TX 1
#define HALF_DUPLEX_RX 2

// SIMPLEX TX/RX:
#define SIMPLEX_TX 1
#define SIMPLEX_RX 2

// Reset Flags
#define SR_RESET 0x0002








#endif //_SPI_private_H
