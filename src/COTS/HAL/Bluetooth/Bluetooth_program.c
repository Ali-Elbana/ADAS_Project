/* FILENAME: Bluetooth_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 01/05/2023
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

#include "Bluetooth_interface.h"
#include "Bluetooth_private.h"
#include "Bluetooth_config.h"

/************************************************************************/
/*                        Externed variables                        	*/
/************************************************************************/

extern USART_InitType		 	Bluetooth_Config 	;

extern USART_ClockInitTypeDef 	Bluetooth_CLK		;

extern USART_MemoryMapType * 	Bluetooth_UART_ID 	;

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

void HBluetooth_vInit( void )
{

	MUSART_vInit( &Bluetooth_Config, &Bluetooth_CLK, Bluetooth_UART_ID ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HBluetooth_vSendByte( u8_t A_u8Byte )
{

	MUSART_vTransmitByte( Bluetooth_UART_ID, A_u8Byte ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u8_t HBluetooth_u8ReceiveByte( void )
{

	u8_t L_u8ReceivedByte = INITIAL_ZERO ;

	L_u8ReceivedByte = MUSART_u8ReceiveByteSynchBlocking( Bluetooth_UART_ID ) ;

	return L_u8ReceivedByte ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HBluetooth_vSendString( c8_t *A_ptrc8String )
{

	MUSART_vTransmitString( Bluetooth_UART_ID, A_ptrc8String ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HBluetooth_vReceiveString( c8_t A_c8YourString[] )
{

	MUSART_vRecieveString( Bluetooth_UART_ID, A_c8YourString ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u8_t HBluetooth_u8CompStrings( c8_t *String1, c8_t *String2 )
{

	u8_t L_u8Result = INITIAL_ZERO ;

	L_u8Result = MUSART_u8CompareString( String1, String2 ) ;

	return L_u8Result ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HBluetooth_vEnable( void )
{

	MUSART_vEnable( Bluetooth_UART_ID ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void HBluetooth_vDisable( void )
{

	MUSART_vDisable( Bluetooth_UART_ID ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/





