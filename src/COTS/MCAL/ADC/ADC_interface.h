/**
 * @file ADC_interface.h
 * @brief This file contains the interfacing information of ADC Module in STM32F103C8 ARM Microcontroller
 * @details This file contains the prototyping of the APIs of ADC Module in STM32F103C8 ARM Microcontroller
 * @author Ali El Bana
 * @version 1.0
 * @date 12/14/2022
 *
 */

#ifndef _ADC_interface_H
#define _ADC_interface_H

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief This function is responsible for initializing the ADC module
 * 
 */
void MADC_vInit(void);

/**
 * @brief This function is responsible for converting the analog value to digital value
 * 
 *
 * @return u16_t The digital value of the analog value
 */
u16_t MADC_u16ConvertToDigital(u8_t A_u8ChannelNum);

/**
 * @brief This function is responsible for disabling the ADC module
 * 
 */
void MADC_vDisable(void);

/**
 * @brief This function is responsible for enabling the ADC module
 * 
 */
void MADC_vEnable(void);

/**
 * @brief This function is responsible for disabling the ADC module interrupt
 * 
 */
void MADC_vRegINT_Disable(void);

/**
 * @brief This function is responsible for enabling the ADC module interrupt
 * 
 */
void MADC_vRegINTEnable(void);

/**
 * @brief This function is responsible for selecting the channel of the ADC module
 * 
 */
void MADC_vSelectChannel(u8_t A_u8ChannelNum);

/**
 * @brief This function is responsible for setting the callback function of the ADC module
 *
 * @param[in] MEXTI_vpPointerTo_ISR_function A pointer to the callback function
 */
void MADC_vSetCallBack(void (*MEXTI_vpPointerTo_ISR_function)(void));

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @defgroup adc_channels ADC Channels
 * @{
 */

/**
 * @def CHANNEL0
 * @brief Channel 0
 * @details This macro is used to select channel 0
 */
#define CHANNEL0 0

/**
 * @def CHANNEL1
 * @brief Channel 1
 * @details This macro is used to select channel 1
 */
#define CHANNEL1 1

/**
 * @def CHANNEL2
 * @brief Channel 2
 * @details This macro is used to select channel 2
 */
#define CHANNEL2 2

/**
 * @def CHANNEL3
 * @brief Channel 3
 * @details This macro is used to select channel 3
 */
#define CHANNEL3 3

/**
 * @def CHANNEL4
 * @brief Channel 4
 * @details This macro is used to select channel 4
 */
#define CHANNEL4 4

/**
 * @def CHANNEL5
 * @brief Channel 5
 * @details This macro is used to select channel 5
 */
#define CHANNEL5 5

/**
 * @def CHANNEL6
 * @brief Channel 6
 * @details This macro is used to select channel 6
 */
#define CHANNEL6 6

/**
 * @def CHANNEL7
 * @brief Channel 7
 * @details This macro is used to select channel 7
 */
#define CHANNEL7 7

/**
 * @def CHANNEL8
 * @brief Channel 8
 * @details This macro is used to select channel 8
 */
#define CHANNEL8 8

/**
 * @def CHANNEL9
 * @brief Channel 9
 * @details This macro is used to select channel 9
 */
#define CHANNEL9 9

/**
 * @def CHANNEL10
 * @brief Channel 10
 * @details This macro is used to select channel 10
 */
#define CHANNEL10 10

/**
 * @def CHANNEL11
 * @brief Channel 11
 * @details This macro is used to select channel 11
 */
#define CHANNEL11 11

/**
 * @def CHANNEL12
 * @brief Channel 12
 * @details This macro is used to select channel 12
 */
#define CHANNEL12 12

/**
 * @def CHANNEL13
 * @brief Channel 13
 * @details This macro is used to select channel 13
 */
#define CHANNEL13 13

/**
 * @def CHANNEL14
 * @brief Channel 14
 * @details This macro is used to select channel 14
 */
#define CHANNEL14 14

/**
 * @def CHANNEL15
 * @brief Channel 15
 * @details This macro is used to select channel 15
 */
#define CHANNEL15 15

/**
 * @def CHANNEL16
 * @brief Channel 16
 * @details This macro is used to select channel 16
 */
#define CHANNEL16 16

/**
 * @def CHANNEL17
 * @brief Channel 17
 * @details This macro is used to select channel 17
 */
#define CHANNEL17 17

/**
 * @def CHANNEL18
 * @brief Channel 18
 * @details This macro is used to select channel 18
 */
#define CHANNEL18 18

/** @} */

#endif //_ADC_interface_H
