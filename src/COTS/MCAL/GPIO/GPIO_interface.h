/**
 * @file GPIO_interface.h
 * @author Ali El Bana & Mo Alaa
 * @brief This file contains the interfacing information for the GPIO module
 * @version 2.0
 * @date 11/9/2022
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

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
	/**
	 * @brief Configures a speific GPIO port
	 */
	u8_t Port;
	/**
	 * @brief Configures a speific GPIO pin
	 */
	u8_t Pin;
	/**
	 * @brief Configures a speific GPIO mode
	 */
	u8_t Mode;
	/**
	 * @brief Configures a speific GPIO output's type
	 */
	u8_t OutputType;
	/**
	 * @brief Configures a speific GPIO output's speed
	 */
	u8_t OutputSpeed;
	/**
	 * @brief Configures a speific GPIO input type
	 */
	u8_t InputType;
	/**
	 * @brief Configures a speific GPIO Alternative function
	 */
	u8_t AF_Type;

} MGPIOx_ConfigType;

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief Locks the prohibited GPIO PINs.
 */
void MGPIOx_vLockedPins(void);

/**
 * @brief Sets a certain pin's mode on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8Mode The mode to apply the pin
 */
void MGPIOx_vSetPinMode(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8Mode);

/**
 * @brief Sets a certain pin's output type on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8OutputType The output type to apply on the pin
 */
void MGPIOx_vSetPinOutputType(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8OutputType);

/**
 * @brief Sets a certain pin's output speed on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8OutputSpeed The output speed to apply on the pin
 */
void MGPIOx_vSetPinOutputSpeed(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8OutputSpeed);

/**
 * @brief Sets a certain pin's input pull type on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8InputPullType The input pull type to apply on the pin
 */
void MGPIOx_vSetPinInputPullType(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8InputPullType);

/**
 * @brief Gets the value currently on a certain pin
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @return The current value on the pin
 */
u8_t MGPIOx_u8GetPinValue(u8_t A_u8PortID, u8_t A_u8PinID);

/**
 * @brief Sets a certain pin's output value on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8PinValue The set value to set on the pin
 */
void MGPIOx_vSetPinValue(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8PinValue);

/**
 * @brief Resets a certain pin's output value on a speific port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8SetResetPinValue The reset value to set on the pin
 */
void MGPIOx_vSetResetAtomic(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8SetResetPinValue);

/**
 * @brief Applys an alternative function on a certain pin
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to update its mode
 * @param[in] A_u8AFID The alternative function to apply on the pin
 */
void MGPIOx_vSetAlternateFunctionON(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8AFID);

/**
 * @brief Updates a port's configuration lock
 * @param[in] A_u8PortID The port to update the pin's mode
 */
void MGPIOx_vSetPortConfigLock(u8_t A_u8PortID);

/**
 * @brief Initialize the GPIO with a certain configuration
 * @param[in] A_xPinConfig The initialization configuration for the GPIO
 */
void MGPIOx_vInit(MGPIOx_ConfigType * A_xPinConfig);

/**
 * @brief Toggles a certain's pin's value on a certain port
 * @param[in] A_u8PortID The port that the pin belongs to
 * @param[in] A_u8PinID The pin to toggle its value
 */
void MGPIOx_vTogglePinValue(u8_t A_u8PortID, u8_t A_u8PinID);

/**
 * @brief Sets a certain port's output value
 * @param[in] A_u8PortID The port to out the value on
 * @param[in] A_u16PortValue The value to set on the port
 */
void GPIO_vSetNibbleLowValue(u8_t A_u8PortID, u16_t A_u16PortValue);

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @defgroup gpio_modes GPIO Modes
 *
 * @{
 */

/**
 * @def GPIOx_MODE_INPUT
 * @brief Control input mode
 *
 */
#define GPIOx_MODE_INPUT (0b00)

/**
 * @def GPIOx_MODE_OUTPUT
 * @brief Control output mode
 *
 */
#define GPIOx_MODE_OUTPUT (0b01)

/**
 * @def GPIOx_MODE_AF
 * @brief Control alternate function mode
 *
 */
#define GPIOx_MODE_AF (0b10)

/**
 * @def GPIOx_MODE_ANALOG
 * @brief Control analog mode
 *
 */
#define GPIOx_MODE_ANALOG (0b11)

/** @} */

/**
 * @defgroup gpio_ports GPIO Ports
 *
 * @{
 */

/**
 * @def GPIO_PORTA
 * @brief GPIO Port A
 *
 */
#define GPIO_PORTA (0)

/**
 * @def GPIO_PORTB
 * @brief GPIO Port B
 *
 */
#define GPIO_PORTB (1)

/**
 * @def GPIO_PORTC
 * @brief GPIO Port C
 *
 */
#define GPIO_PORTC (2)

/** @} */

/**
 * @defgroup gpio_output_types GPIO Output Types
 *
 * @{
 */

/**
 * @def GPIOx_OPENDRAIN
 * @brief GPIO open-drain
 *
 */
#define GPIOx_OPENDRAIN (1)

/**
 * @def GPIOx_PUSHPULL
 * @brief GPIO push-pull
 *
 */
#define GPIOx_PUSHPULL (2)

/** @} */

/**
 * @defgroup gpio_pin_speed GPIO PIN Speed
 *
 * @{
 */

/**
 * @def GPIOx_LowSpeed
 * @brief GPIO low speed
 *
 */
#define GPIOx_LowSpeed (0b00)

/**
 * @def GPIOx_MediumSpeed
 * @brief GPIO medium speed
 *
 */
#define GPIOx_MediumSpeed (0b01)

/**
 * @def GPIOx_HighSpeed
 * @brief GPIO high speed
 *
 */
#define GPIOx_HighSpeed (0b10)

/**
 * @def GPIOx_VeryHighSpeed
 * @brief GPIO very high speed
 *
 */
#define GPIOx_VeryHighSpeed (0b11)

/** @} */

/**
 * @defgroup gpio_pull_types GPIO Pull Types
 *
 * @{
 */

/**
 * @def GPIOx_NoPull
 * @brief GPIO No PULL
 *
 */
#define GPIOx_NoPull (0b00)

/**
 * @def GPIOx_PullUp
 * @brief GPIO Pull UP
 *
 */
#define GPIOx_PullUp (0b01)

/**
 * @def GPIOx_PullDown
 * @brief GPIO Pull Down
 *
 */
#define GPIOx_PullDown (0b10)

/** @} */

/**
 * @defgroup gpio_output_values GPIO Output Values
 *
 * @{
 */

/**
 * @def GPIOx_HIGH
 * @brief GPIO output high
 *
 */
#define GPIOx_HIGH (1)

/**
 * @def GPIOx_LOW
 * @brief GPIO output low
 *
 */
#define GPIOx_LOW (2)

/** @} */

/**
 * @defgroup gpio_output_pins GPIO Output PINs
 *
 * @{
 */

/**
 * @def GPIOx_PIN0
 * @brief GPIO PIN 0
 *
 */
#define GPIOx_PIN0 (0)

/**
 * @def GPIOx_PIN1
 * @brief GPIO PIN 1
 *
 */
#define GPIOx_PIN1 (1)

/**
 * @def GPIOx_PIN2
 * @brief GPIO PIN 2
 *
 */
#define GPIOx_PIN2 (2)

/**
 * @def GPIOx_PIN3
 * @brief GPIO PIN 3
 *
 */
#define GPIOx_PIN3 (3)

/**
 * @def GPIOx_PIN4
 * @brief GPIO PIN 4
 *
 */
#define GPIOx_PIN4 (4)

/**
 * @def GPIOx_PIN5
 * @brief GPIO PIN 5
 *
 */
#define GPIOx_PIN5 (5)

/**
 * @def GPIOx_PIN6
 * @brief GPIO PIN 6
 *
 */
#define GPIOx_PIN6 (6)

/**
 * @def GPIOx_PIN7
 * @brief GPIO PIN 7
 *
 */
#define GPIOx_PIN7 (7)

/**
 * @def GPIOx_PIN8
 * @brief GPIO PIN 8
 *
 */
#define GPIOx_PIN8 (8)

/**
 * @def GPIOx_PIN9
 * @brief brief GPIO PIN 9
 *
 */
#define GPIOx_PIN9 (9)

/**
 * @def GPIOx_PIN10
 * @brief GPIO PIN 10
 *
 */
#define GPIOx_PIN10 (10)

/**
 * @def GPIOx_PIN11
 * @brief GPIO PIN 11
 *
 */
#define GPIOx_PIN11 (11)

/**
 * @def GPIOx_PIN12
 * @brief GPIO PIN 12
 *
 */
#define GPIOx_PIN12 (12)

/**
 * @def GPIOx_PIN13
 * @brief GPIO PIN 13
 *
 */
#define GPIOx_PIN13 (13)

/**
 * @def GPIOx_PIN14
 * @brief GPIO PIN 14
 *
 */
#define GPIOx_PIN14 (14)

/**
 * @def GPIOx_PIN15
 * @brief GPIO PIN 15
 *
 */
#define GPIOx_PIN15 (15)

/** @} */

/**
 * @defgroup gpio_alternate_functions GPIO Alternate Functions
 *
 * @{
 */

/**
 * @def GPIOx_AF0
 * @brief GPIO Alternate function 0
 *
 */
#define GPIOx_AF0 (0)

/**
 * @def GPIOx_AF1
 * @brief GPIO Alternate function 1
 *
 */
#define GPIOx_AF1 (1)

/**
 * @def GPIOx_AF2
 * @brief GPIO Alternate function 2
 *
 */
#define GPIOx_AF2 (2)

/**
 * @def GPIOx_AF3
 * @brief GPIO Alternate function 3
 *
 */
#define GPIOx_AF3 (3)

/**
 * @def GPIOx_AF4
 * @brief GPIO Alternate function 4
 *
 */
#define GPIOx_AF4 (4)

/**
 * @def GPIOx_AF5
 * @brief GPIO Alternate function 5
 *
 */
#define GPIOx_AF5 (5)

/**
 * @def GPIOx_AF6
 * @brief GPIO Alternate function 6
 *
 */
#define GPIOx_AF6 (6)

/**
 * @def GPIOx_AF7
 * @brief GPIO Alternate function 7
 *
 */
#define GPIOx_AF7 (7)

/**
 * @def GPIOx_AF8
 * @brief GPIO Alternate function 8
 *
 */
#define GPIOx_AF8 (8)

/**
 * @def GPIOx_AF9
 * @brief GPIO Alternate function 9
 *
 */
#define GPIOx_AF9 (9)

/**
 * @def GPIOx_AF10
 * @brief GPIO Alternate function 10
 *
 */
#define GPIOx_AF10 (10)

/**
 * @def GPIOx_AF11
 * @brief GPIO Alternate function 11
 *
 */
#define GPIOx_AF11 (11)

/**
 * @def GPIOx_AF12
 * @brief GPIO Alternate function 12
 *
 */
#define GPIOx_AF12 (12)

/**
 * @def GPIOx_AF13
 * @brief GPIO Alternate function 13
 *
 */
#define GPIOx_AF13 (13)

/**
 * @def GPIOx_AF14
 * @brief GPIO Alternate function 14
 *
 */
#define GPIOx_AF14 (14)

/**
 * @def GPIOx_AF15
 * @brief GPIO Alternate function 15
 *
 */
#define GPIOx_AF15 (15)

/** @} */

/**
 * @def GPIOA_LOW_NIBBLE_HIGH
 * @brief GPIO Port A low nibble high
 */
#define GPIOA_LOW_NIBBLE_HIGH 0xFF

/**
 * @def GPIOA_LOW_NIBBLE_LOW
 * @brief GPIO Port A low nibble low
 */
#define GPIOA_LOW_NIBBLE_LOW 0x00

#endif //_GPIO_interface_H
