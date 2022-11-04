/* FILENAME: GPIO_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 08/22/2022
*/
#ifndef _GPIO_interface_H
#define _GPIO_interface_H

typedef struct
{
	VAR(u8_t) Port;
	VAR(u8_t) Pin;
	VAR(u8_t) Mode;
	VAR(u8_t) OutputType;
	VAR(u8_t) OutputSpeed;
	VAR(u8_t) InputType;
	VAR(u8_t) AF_Type;
} MGPIOx_ConfigType;


FUNC(void) MGPIOx_vSetPinMode(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8Mode);

FUNC(void) MGPIOx_vSetPinOutputType(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8OutputType);

FUNC(void) MGPIOx_vSetPinOutputSpeed(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8OutputSpeed);

FUNC(void) MGPIOx_vSetPinInputPullType(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8InputPullType);

FUNC(u8_t) MGPIOx_u8GetPinValue(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID);

FUNC(void) MGPIOx_vSetPinValue(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8PinValue);

FUNC(void) MGPIOx_vSetResetPinValue(VAR(u8_t) A_u8PortID,VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8SetResetPinValue);

FUNC(void) MGPIOx_vSetAlternateFunctionON(VAR(u8_t) A_u8PortID,VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8AFID);

FUNC(void) MGPIOx_vSetPortConfigLock(VAR(u8_t) A_u8PortID);

FUNC(void) MGPIOx_vInit(P2VAR(MGPIOx_ConfigType) A_xPinConfig);
FUNC(void) MGPIOx_vTogglePinValue(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID);


#define GPIOx_MODE_INPUT 	0b00
#define GPIOx_MODE_OUTPUT	0b01
#define GPIOx_MODE_AF		0b10
#define GPIOx_MODE_ANALOG	0b11

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

#define GPIOx_OPENDRAIN 1
#define GPIOx_PUSHPULL  2

#define GPIOx_LowSpeed 		0b00
#define GPIOx_MediumSpeed 	0b01
#define GPIOx_HighSpeed 	0b10
#define GPIOx_VeryHighSpeed 0b11

#define GPIOx_NoPull 		0b00
#define GPIOx_PullUp 		0b01
#define GPIOx_PullDown 		0b10


#define GPIOx_HIGH 1
#define GPIOx_LOW  2



#define GPIOx_PIN0  0
#define GPIOx_PIN1  1
#define GPIOx_PIN2  2
#define GPIOx_PIN3  3
#define GPIOx_PIN4  4
#define GPIOx_PIN5  5
#define GPIOx_PIN6  6
#define GPIOx_PIN7  7
#define GPIOx_PIN8  8
#define GPIOx_PIN9  9
#define GPIOx_PIN10 10
#define GPIOx_PIN11 11
#define GPIOx_PIN12 12
#define GPIOx_PIN13 13
#define GPIOx_PIN14 14
#define GPIOx_PIN15 15


#define GPIOx_AF0  0
#define GPIOx_AF1  1
#define GPIOx_AF2  2
#define GPIOx_AF3  3
#define GPIOx_AF4  4
#define GPIOx_AF5  5
#define GPIOx_AF6  6
#define GPIOx_AF7  7
#define GPIOx_AF8  8
#define GPIOx_AF9  9
#define GPIOx_AF10 10
#define GPIOx_AF11 11
#define GPIOx_AF12 12
#define GPIOx_AF13 13
#define GPIOx_AF14 14
#define GPIOx_AF15 15


#endif //_GPIO_interface_H
