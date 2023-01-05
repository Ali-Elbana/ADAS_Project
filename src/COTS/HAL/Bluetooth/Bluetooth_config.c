/*
 * Bluetooth_config.c
 *
 *  Created on: Jan 5, 2023
 *      Author: Ali El Bana
 */
/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/RCC/MRCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/UART/UART_interface.h"

#include "Bluetooth_config.h"

/************************************************************************/
/*                     Configuration parameters                         */
/************************************************************************/

USART_InitType Bluetooth_Config =
{
	.BaudRate 			 = __BAUDRATE__ , 	.DataWidth 			= MODE_8BIT ,

	.StopBits 			 = STOP_BIT_1 	, 	.Parity_Enable 		= DISABLE 	,

	.Parity_Selection 	 = EVEN_PARITY 	,	.TransferDirection 	= TX_RX		,

	.HardwareFlowControl = DISABLE 		,	.Oversampling 		= OVER_SAMPLING_16
} ;

USART_ClockInitTypeDef Bluetooth_CLK = { DISABLE, 0, 0, 0 } ;

/*******************************************************************************************************************/
/******************************************************************************************************************/

USART_MemoryMapType * Bluetooth_UART_ID = USART1_REG ;

/*******************************************************************************************************************/
/******************************************************************************************************************/


