/* FILENAME: Bluetooth_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 01/05/2023
*/
#ifndef _Bluetooth_interface_H
#define _Bluetooth_interface_H

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void HBluetooth_vInit( void ) ;

void HBluetooth_vSendByte( u8_t A_u8Byte ) ;

u8_t HBluetooth_u8ReceiveByte( void ) ;

void HBluetooth_u8AsynchReceiveByte( void (*Fptr) (void) ) ;

void HBluetooth_vSendString( c8_t *A_ptrc8String ) ;

void HBluetooth_vReceiveString( c8_t A_c8YourString[] ) ;

u8_t HBluetooth_u8CompStrings( c8_t *String1, c8_t *String2 ) ;

void HBluetooth_vEnable( void ) ;

void HBluetooth_vDisable( void ) ;

u8_t HBluetooth_u8GetDataRegister( void ) ;


#endif //_Bluetooth_interface_H
