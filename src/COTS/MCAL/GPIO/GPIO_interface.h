/**
 * @file GPIO_interface.h
 * @author Ali El Bana
 * @brief This file contains the interfacing information for the GPIO module
 * @version 1.0
 * @date %d/%m/%Y
 */

/* Header file guard */
#ifndef _GPIO_interface_H
#define _GPIO_interface_H

/**
 * @brief MDIO Configuration structure for a speific PIN initialization
 * @struct MGPIOx_ConfigType
 *
 */
typedef struct
{
	/*! Configures a speific GPIO port */
	VAR(u8_t) Port;
	/*! Configures a speific GPIO pin */
	VAR(u8_t) Pin;
	/*! Configures a speific GPIO mode */
	VAR(u8_t) Mode;
	/*! Configures a speific GPIO output's type */
	VAR(u8_t) OutputType;
	/*! Configures a speific GPIO output's speed */
	VAR(u8_t) OutputSpeed;
	/*! Configures a speific GPIO input type */
	VAR(u8_t) InputType;
	/*! Configures a speific GPIO Alternative function */
	VAR(u8_t) AF_Type;
} MGPIOx_ConfigType;

/************************************************************************/
/*                        Functions' prototypes                        */
/************************************************************************/

/**
 * @brief Sets a certain pin's mode on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8Mode The mode to apply the pin
 */
void MGPIOx_vSetPinMode(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8Mode);

/**
 * @brief Sets a certain pin's output type on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8OutputType The output type to apply on the pin
 */
void MGPIOx_vSetPinOutputType(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8OutputType);

/**
 * @brief Sets a certain pin's output speed on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8OutputSpeed The output speed to apply on the pin
 */
void MGPIOx_vSetPinOutputSpeed(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8OutputSpeed);

/**
 * @brief Sets a certain pin's input pull type on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8InputPullType The input pull type to apply on the pin
 */
void MGPIOx_vSetPinInputPullType(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8InputPullType);

/**
 * @brief Gets the value currently on a certain pin
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @return The current value on the pin
 */
u8_t MGPIOx_u8GetPinValue(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID);

/**
 * @brief Sets a certain pin's output value on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8PinValue The set value to set on the pin
 */
void MGPIOx_vSetPinValue(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8PinValue);

/**
 * @brief Resets a certain pin's output value on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8SetResetPinValue The reset value to set on the pin
 */
void MGPIOx_vSetResetPinValue(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8SetResetPinValue);

/**
 * @brief Applys an alternative function on a certain pin
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8AFID The alternative function to apply on the pin
 */
void MGPIOx_vSetAlternateFunctionON(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID, VAR(u8_t) A_u8AFID);

/**
 * @brief Updates a port's configuration lock
 * @param[in] A_u8PortID The port to update the pin's mode
 */
void MGPIOx_vSetPortConfigLock(VAR(u8_t) A_u8PortID);

/**
 * @brief Initialize the GPIO with a certain configuration
 * @param[in] A_xPinConfig The initialization configuration for the GPIO
 */
void MGPIOx_vInit(P2VAR(MGPIOx_ConfigType) A_xPinConfig);

/**
 * @brief Toggles a certain's pin's value on a certain port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to toggle its value
 */
void MGPIOx_vTogglePinValue(VAR(u8_t) A_u8PortID, VAR(u8_t) A_u8PinID);

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

// #define GPIOx_MODE_INPUT 	0b00
// #define GPIOx_MODE_OUTPUT	0b01
// #define GPIOx_MODE_AF		0b10
// #define GPIOx_MODE_ANALOG	0b11

// #define GPIO_PORTA 0
// #define GPIO_PORTB 1
// #define GPIO_PORTC 2

// #define GPIOx_OPENDRAIN 1
// #define GPIOx_PUSHPULL  2

// #define GPIOx_LowSpeed 		0b00
// #define GPIOx_MediumSpeed 	0b01
// #define GPIOx_HighSpeed 	0b10
// #define GPIOx_VeryHighSpeed 0b11

// #define GPIOx_NoPull 		0b00
// #define GPIOx_PullUp 		0b01
// #define GPIOx_PullDown 		0b10


// #define GPIOx_HIGH 1
// #define GPIOx_LOW  2



// #define GPIOx_PIN0  0
// #define GPIOx_PIN1  1
// #define GPIOx_PIN2  2
// #define GPIOx_PIN3  3
// #define GPIOx_PIN4  4
// #define GPIOx_PIN5  5
// #define GPIOx_PIN6  6
// #define GPIOx_PIN7  7
// #define GPIOx_PIN8  8
// #define GPIOx_PIN9  9
// #define GPIOx_PIN10 10
// #define GPIOx_PIN11 11
// #define GPIOx_PIN12 12
// #define GPIOx_PIN13 13
// #define GPIOx_PIN14 14
// #define GPIOx_PIN15 15


// #define GPIOx_AF0  0
// #define GPIOx_AF1  1
// #define GPIOx_AF2  2
// #define GPIOx_AF3  3
// #define GPIOx_AF4  4
// #define GPIOx_AF5  5
// #define GPIOx_AF6  6
// #define GPIOx_AF7  7
// #define GPIOx_AF8  8
// #define GPIOx_AF9  9
// #define GPIOx_AF10 10
// #define GPIOx_AF11 11
// #define GPIOx_AF12 12
// #define GPIOx_AF13 13
// #define GPIOx_AF14 14
// #define GPIOx_AF15 15


#endif //_GPIO_interface_H
