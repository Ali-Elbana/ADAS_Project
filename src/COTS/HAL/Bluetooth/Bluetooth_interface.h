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

void HBluetooth_vInit(void);

void HBluetooth_vSendByte(VAR(u8_t) A_u8Byte);

u8_t HBluetooth_u8ReceiveByte(void);

void HBluetooth_vSendString(P2VAR(c8_t) A_ptrc8String);

void HBluetooth_vReceiveString(P2VAR(c8_t) A_c8YourString);

u8_t HBluetooth_u8CompStrings(P2VAR(c8_t) String1, P2VAR(c8_t) String2);

void HBluetooth_vEnable(void);

void HBluetooth_vDisable(void);

void HBluetooth_ExchangeString(P2VAR(c8_t) L_strMessagePlaceholder, P2VAR(c8_t) L_strInfo);
u8_t HBluetooth_ExchangeByte(P2VAR(c8_t) L_strMessagePlaceholder);

#endif //_Bluetooth_interface_H
