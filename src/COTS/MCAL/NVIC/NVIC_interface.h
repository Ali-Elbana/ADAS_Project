/**
 * @file NVIC_interface.h
 * @author Ali El Bana
 * @brief This file contains the interface information and addresses for the NVIC module
 * @version 2.0
 * @date 08/25/2022
 */

/* Header file guard */
#ifndef _NVIC_interface_H
#define _NVIC_interface_H

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief Enable the interrupt of a certain peripheral in NVIC
 * @param[in] A_u8INTID The peripheral's interrupt ID
 * @see MNVIC_vDisablePeriphral
 */
void MNVIC_vEnablePeriphral(u8_t A_u8INTID);

/**
 * @brief Disable the interrupt of a certain peripheral in NVIC
 * @param[in] A_u8INTID The peripheral's interrupt ID
 * @see MNVIC_vEnablePeriphral
 */
void MNVIC_vDisablePeriphral(u8_t A_u8INTID);

/**
 * @brief Set the pending flag of the peripheral
 * @note Used mostly for testing
 * @param[in] A_u8INTID The peripheral's interrupt ID
 * @see MNVIC_vClearPendingFlag
 */
void MNVIC_vSetPendingFlag(u8_t A_u8INTID);

/**
 * @brief Clear the pending flag of the peripheral
 * @note Used mostly for testing
 * @param[in] A_u8INTID The peripheral's interrupt ID
 * @see MNVIC_vSetPendingFlag
 */
void MNVIC_vClearPendingFlag(u8_t A_u8INTID);

/**
 * @brief Get the current state of the interrupt active flag of a certain peripheral in NVIC
 * @param[in] A_u8INTID The peripheral's interrupt ID
 * @return The current state of the interrupt active flag
 */
u8_t MNVIC_u8GetActive(u8_t A_u8INTID);

/**
 * @brief Configures the group and sub-group priority configuration
 * @param[in] A_u8PriorityOption The peripheral's interrupt ID
 */
void MNVIC_vSetPriorityConfig(u8_t A_u8PriorityOption);

/**
 * @brief Set the group and the sub-group priorities for the required interrupt
 * @param[in] A_s8INTID The port that the pin belongs to
 * @param[in] A_u8GroupPriority The pin to update its mode
 * @param[in] A_u8SubPriority The alternative function to apply on the pin
 * @see group_prioty
 * @see sub_group_prioty
 */
void MNVIC_vSetPriority(s8_t A_s8INTID, u8_t A_u8GroupPriority, u8_t A_u8SubPriority);

/**
 * @brief Get a certain interrupt's priority
 * @param[in] A_s8INTID
 * @return The priority for the corresponding interrupt
 */
u32_t NVIC_GetPriority(s8_t A_s8INTID);

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/**
 * @defgroup interrupt_prioty_grouping Interrupt priority grouping
 * @brief Interrupt priority grouping values
 * @details Interrupt priority grouping values for PRIGROUP in AIRCR register
 * @see SCB_MemoryMapType::AIRCR
 *
 * @{
 */

/**
 * @def _16GROUP_NoSub_Priorities
 * @brief `16` groups and `0` sub-groups
 * @details This tells the system there is going to be `16` groups and `0` sub-groups
 * @see GROUP_4BITS
 *
 */
#define _16GROUP_NoSub_Priorities (0b011)
/**
 * @def _8GROUP_2Sub_Priorities
 * @brief `8` groups and `2` sub-groups
 * @details This tells the system there is going to be `8` groups and `2` sub-groups
 * @see GROUP_3BITS
 *
 */
#define _8GROUP_2Sub_Priorities (0b100)
/**
 * @def _4GROUP_4Sub_Priorities
 * @brief `4` groups and `4` sub-groups
 * @details This tells the system there is going to be `4` groups and `4` sub-groups
 * @see GROUP_2BITS
 *
 */
#define _4GROUP_4Sub_Priorities (0b101)
/**
 * @def _2GROUP_8Sub_Priorities
 * @brief `2` groups and `8` sub-groups
 * @details This tells the system there is going to be `2` groups and `8` sub-groups
 * @see GROUP_1BITS
 *
 */
#define _2GROUP_8Sub_Priorities (0b110)
/**
 * @def NoGROUP_16Sub_Priorities
 * @brief `0` groups and `16` sub-groups
 * @details This tells the system there is going to be `0` groups and `16` sub-groups
 * @see GROUP_0BITS
 *
 */
#define NoGROUP_16Sub_Priorities (0b111)
/** @} */

/**
 * @defgroup interrupt_prioty_grouping Interrupt priority grouping
 * @brief Interrupt priority grouping values
 * @details Interrupt priority grouping values for PRIGROUP in AIRCR register
 * @see SCB_MemoryMapType::AIRCR
 *
 * @{
 */

/**
 * @def GROUP_4BITS
 * @brief `16` groups and `0` sub-groups
 * @details This tells the system there is going to be `16` groups and `0` sub-groups
 *
 */
#define GROUP_4BITS (0b011)
/**
 * @def GROUP_3BITS
 * @brief `8` groups and `2` sub-groups
 * @details This tells the system there is going to be `8` groups and `2` sub-groups
 *
 */
#define GROUP_3BITS (0b100)
/**
 * @def GROUP_2BITS
 * @brief `4` groups and `4` sub-groups
 * @details This tells the system there is going to be `4` groups and `4` sub-groups
 *
 */
#define GROUP_2BITS (0b101)
/**
 * @def GROUP_1BITS
 * @brief `2` groups and `8` sub-groups
 * @details This tells the system there is going to be `2` groups and `8` sub-groups
 *
 */
#define GROUP_1BITS (0b110)
/**
 * @def GROUP_0BITS
 * @brief `0` groups and `16` sub-groups
 * @details This tells the system there is going to be `0` groups and `16` sub-groups
 *
 */
#define GROUP_0BITS (0b111)
/** @} */

/**
 * @defgroup group_prioty Group priorities
 * @brief The group priority values
 * @see MNVIC_vSetPriority
 * @see sub_group_prioty
 * @{
 */
/**
 * @def NO_GROUP_PRIORITY
 * @brief No group priority
 */
#define NO_GROUP_PRIORITY (0)
/**
 * @def GROUP_PRIORITY_0
 * @brief Priority: 0
 */
#define GROUP_PRIORITY_0 (0)
/**
 * @def GROUP_PRIORITY_1
 * @brief Priority: 1
 */
#define GROUP_PRIORITY_1 (1)
/**
 * @def GROUP_PRIORITY_2
 * @brief Priority: 2
 */
#define GROUP_PRIORITY_2 (2)
/**
 * @def GROUP_PRIORITY_3
 * @brief Priority: 3
 */
#define GROUP_PRIORITY_3 (3)
/**
 * @def GROUP_PRIORITY_4
 * @brief Priority: 4
 */
#define GROUP_PRIORITY_4 (4)
/**
 * @def GROUP_PRIORITY_5
 * @brief Priority: 5
 */
#define GROUP_PRIORITY_5 (5)
/**
 * @def GROUP_PRIORITY_6
 * @brief Priority: 6
 */
#define GROUP_PRIORITY_6 (6)
/**
 * @def GROUP_PRIORITY_7
 * @brief Priority: 7
 */
#define GROUP_PRIORITY_7 (7)
/**
 * @def GROUP_PRIORITY_8
 * @brief Priority: 8
 */
#define GROUP_PRIORITY_8 (8)
/**
 * @def GROUP_PRIORITY_9
 * @brief Priority: 9
 */
#define GROUP_PRIORITY_9 (9)
/**
 * @def GROUP_PRIORITY_10
 * @brief Priority: 10
 */
#define GROUP_PRIORITY_10 (10)
/**
 * @def GROUP_PRIORITY_11
 * @brief Priority: 11
 */
#define GROUP_PRIORITY_11 (11)
/**
 * @def GROUP_PRIORITY_12
 * @brief Priority: 12
 */
#define GROUP_PRIORITY_12 (12)
/**
 * @def GROUP_PRIORITY_13
 * @brief Priority: 13
 */
#define GROUP_PRIORITY_13 (13)
/**
 * @def GROUP_PRIORITY_14
 * @brief Priority: 14
 */
#define GROUP_PRIORITY_14 (14)
/**
 * @def GROUP_PRIORITY_15
 * @brief Priority: 15
 */
#define GROUP_PRIORITY_15 (15)
/** @} */

/**
 * @defgroup sub_group_prioty Sub-Group priorities
 * @brief The sub-group priority values
 * @see MNVIC_vSetPriority
 * @see group_prioty
 *
 * @{
 */
/**
 * @def NO_SUB_PRIORITY
 * @brief No sub-group priority
 *
 */
#define NO_SUB_PRIORITY (0)
/**
 * @def SUB_PRIORITY_0
 * @brief Priority: 0
 */
#define SUB_PRIORITY_0 (0)
/**
 * @def SUB_PRIORITY_1
 * @brief Priority: 1
 */
#define SUB_PRIORITY_1 (1)
/**
 * @def SUB_PRIORITY_2
 * @brief Priority: 2
 */
#define SUB_PRIORITY_2 (2)
/**
 * @def SUB_PRIORITY_3
 * @brief Priority: 3
 */
#define SUB_PRIORITY_3 (3)
/**
 * @def SUB_PRIORITY_4
 * @brief Priority: 4
 */
#define SUB_PRIORITY_4 (4)
/**
 * @def SUB_PRIORITY_5
 * @brief Priority: 5
 */
#define SUB_PRIORITY_5 (5)
/**
 * @def SUB_PRIORITY_6
 * @brief Priority: 6
 */
#define SUB_PRIORITY_6 (6)
/**
 * @def SUB_PRIORITY_7
 * @brief Priority: 7
 */
#define SUB_PRIORITY_7 (7)
/**
 * @def SUB_PRIORITY_8
 * @brief Priority: 8
 */
#define SUB_PRIORITY_8 (8)
/**
 * @def SUB_PRIORITY_9
 * @brief Priority: 9
 */
#define SUB_PRIORITY_9 (9)
/**
 * @def SUB_PRIORITY_10
 * @brief Priority: 10
 */
#define SUB_PRIORITY_10 (10)
/**
 * @def SUB_PRIORITY_11
 * @brief Priority: 11
 */
#define SUB_PRIORITY_11 (11)
/**
 * @def SUB_PRIORITY_12
 * @brief Priority: 12
 */
#define SUB_PRIORITY_12 (12)
/**
 * @def SUB_PRIORITY_13
 * @brief Priority: 13
 */
#define SUB_PRIORITY_13 (13)
/**
 * @def SUB_PRIORITY_14
 * @brief Priority: 14
 */
#define SUB_PRIORITY_14 (14)
/**
 * @def SUB_PRIORITY_15
 * @brief Priority: 15
 */
#define SUB_PRIORITY_15 (15)
/** @} */

/**
 * @defgroup vector_table NVIC Vector Table
 * @brief NVIC vector table
 * @details NVIC vector table that contains each peripheral's priority.
 * @details The lower the value, the higher the priority
 * @{
 */
/**
 * @def WWDG
 * @brief Window Watchdog (WWDG) Interrupt
 */
#define WWDG (0)
/**
 * @def EXTI16
 * @brief EXTI Line 16 interrupt / PVD through EXTI line detection interrupt
 */
#define EXTI16 (1)
/**
 * @def EXTI21
 * @brief EXTI Line 21 interrupt / Tamper and TimeStamp interrupts through the EXTI line
 */
#define EXTI21 (2)
/**
 * @def EXTI22
 * @brief EXTI Line 22 interrupt / RTC (Real-time clock) wakeup interrupt through the EXTI line
 */
#define EXTI22 (3)
/**
 * @def FLASH
 * @brief Flash global interrupt
 */
#define FLASH (4)
/**
 * @def RCC
 * @brief RCC global interrupt
 */
#define RCC (5)
/**
 * @def EXTI0
 * @brief EXTI Line 0 interrupt
 */
#define EXTI0 (6)
/**
 * @def EXTI1
 * @brief EXTI Line 1 interrupt
 */
#define EXTI1 (7)
/**
 * @def EXTI2
 * @brief EXTI Line 2 interrupt
 */
#define EXTI2 (8)
/**
 * @def EXTI3
 * @brief EXTI Line 3 interrupt
 */
#define EXTI3 (9)
/**
 * @def EXTI4
 * @brief EXTI Line 4 interrupt
 */
#define EXTI4 (10)
/**
 * @def DMA1_STREAM0
 * @brief DMA1 (Direct Memory Access) Steam 0 global interrupt
 */
#define DMA1_STREAM0 (11)
/**
 * @def DMA1_STREAM1
 * @brief DMA1 (Direct Memory Access) Steam 1 global interrupt
 */
#define DMA1_STREAM1 (12)
/**
 * @def DMA1_STREAM2
 * @brief DMA1 (Direct Memory Access) Steam 2 global interrupt
 */
#define DMA1_STREAM2 (13)
/**
 * @def DMA1_STREAM3
 * @brief DMA1 (Direct Memory Access) Steam 3 global interrupt
 */
#define DMA1_STREAM3 (14)
/**
 * @def DMA1_STREAM4
 * @brief DMA1 (Direct Memory Access) Steam 4 global interrupt
 */
#define DMA1_STREAM4 (15)
/**
 * @def DMA1_STREAM5
 * @brief DMA1 (Direct Memory Access) Steam 5 global interrupt
 */
#define DMA1_STREAM5 (16)
/**
 * @def DMA1_STREAM6
 * @brief DMA1 (Direct Memory Access) Steam 6 global interrupt
 */
#define DMA1_STREAM6 (17)
/**
 * @def ADC
 * @brief ADC (Analog-To-Digital Converter) ADC1 global interrupt
 */
#define ADC (18)
/**
 * @def EXTI9
 * @brief EXTI Lines [9:5] interrupts
 */
#define EXTI9 (23)
/**
 * @def TIM1_BRK_TIM9
 * @brief TIM1 (Timer 1) break interrupt and TIM9 (Timer 9) global interrupt
 */
#define TIM1_BRK_TIM9 (24)
/**
 * @def TIM1_UP_TIM10
 * @brief TIM1 (Timer 1) udpate interrupt and TIM10 (Timer 10) global interrupt
 */
#define TIM1_UP_TIM10 (25)
/**
 * @def TIM1_TRG_COM_TIM11
 * @brief TIM1 (Timer 1) trigger and commutation itnerrupts and TIM11 (Timer 11) global interrupts
 */
#define TIM1_TRG_COM_TIM11 (26)
/**
 * @def TIM1_CC
 * @brief TIM1 (Timer 1) capture compare interrupt
 */
#define TIM1_CC (27)
/**
 * @def TIM2
 * @brief TIM2 (Timer 2) global interrupt
 */
#define TIM2 (28)
/**
 * @def TIM3
 * @brief TIM3 (Timer 3) global interrupt
 */
#define TIM3 (29)
/**
 * @def TIM4
 * @brief TIM4 (Timer 4) global interrupt
 */
#define TIM4 (30)
/**
 * @def I2C1_EV
 * @brief I2C1 (Inter-integrated Circuit 1) event interrupt
 */
#define I2C1_EV (31)
/**
 * @def I2C1_ER
 * @brief I2C1 (Inter-integrated Circuit 1) error interrupt
 */
#define I2C1_ER (32)
/**
 * @def I2C2_EV
 * @brief I2C2 (Inter-integrated Circuit 2) event interrupt
 */
#define I2C2_EV (33)
/**
 * @def I2C2_ER
 * @brief I2C2 (Inter-integrated Circuit 2) error interrupt
 */
#define I2C2_ER (34)
/**
 * @def SPI1
 * @brief SPI1 (Serial Peripheral Interface 1) global interrupt
 */
#define SPI1 (35)
/**
 * @def SPI2
 * @brief SPI2 (Serial Peripheral Interface 2) global interrupt
 */
#define SPI2 (36)
/**
 * @def USART1
 * @brief USART1 (Universal Synchronous/Asynchronous Receiver/Transmitter 1) global interrupt
 */
#define USART1 (37)
/**
 * @def USART2
 * @brief USART2 (Universal Synchronous/Asynchronous Receiver/Transmitter 2) global interrupt
 */
#define USART2 (38)
/**
 * @def EXTI15_10
 * @brief EXTI Line[15:10] interrupts
 */
#define EXTI15_10 (30)
/**
 * @def EXTI17
 * @brief EXTI Line 17 interrupt / RTC Alarms (A and B) through EXTI line interrupt
 */
#define EXTI17 (41)
/**
 * @def EXTI18
 * @brief EXTI Line 18 interrupt / USB On-The-Go FS Wakeup through EXTI line interrupt
 */
#define EXTI18 (42)
/**
 * @def DMA1_STREAM7
 * @brief DMA1 (Direct Memory Access) Steam 7 global interrupt
 */
#define DMA1_STREAM7 (47)
/**
 * @def SDIO
 * @brief SDIO (Secure Digital Input Output) global interrupt
 */
#define SDIO (49)
/**
 * @def TIM5
 * @brief TIM5 (Timer 5) global interrupt
 */
#define TIM5 (50)
/**
 * @def SPI3
 * @brief SPI3 (Serial Peripheral Interface 3) global interrupt
 */
#define SPI3 (51)
/**
 * @def DMA2_STREAM0
 * @brief DMA2 (Direct Memory Access 2) Steam 0 global interrupt
 */
#define DMA2_STREAM0 (56)
/**
 * @def DMA2_STREAM1
 * @brief DMA2 (Direct Memory Access 2) Steam 1 global interrupt
 */
#define DMA2_STREAM1 (57)
/**
 * @def DMA2_STREAM2
 * @brief DMA2 (Direct Memory Access 2) Steam 2 global interrupt
 */
#define DMA2_STREAM2 (58)
/**
 * @def DMA2_STREAM3
 * @brief DMA2 (Direct Memory Access 2) Steam 3 global interrupt
 */
#define DMA2_STREAM3 (59)
/**
 * @def DMA2_STREAM4
 * @brief DMA2 (Direct Memory Access 2) Steam 4 global interrupt
 */
#define DMA2_STREAM4 (60)
/**
 * @def OTG_FS
 * @brief USB On The Go FS global interrupt
 */
#define OTG_FS (67)
/**
 * @def DMA2_STREAM5
 * @brief DMA2 (Direct Memory Access 2) Steam 5 global interrupt
 */
#define DMA2_STREAM5 (68)
/**
 * @def DMA2_STREAM6
 * @brief DMA2 (Direct Memory Access 2) Steam 6 global interrupt
 */
#define DMA2_STREAM6 (69)
/**
 * @def DMA2_STREAM7
 * @brief DMA2 (Direct Memory Access 2) Steam 7 global interrupt
 */
#define DMA2_STREAM7 (70)
/**
 * @def USART6
 * @brief USART6 (Universal Synchronous/Asynchronous Receiver/Transmitter 6) global interrupt
 */
#define USART6 (71)
/**
 * @def I2C3_EV
 * @brief I2C3 (Inter-integrated Circuit 3) event interrupt
 */
#define I2C3_EV (72)
/**
 * @def I2C3_ER
 * @brief I2C3 (Inter-integrated Circuit 3) error interrupt
 */
#define I2C3_ER (73)
/**
 * @def FPU
 * @brief FPU (Floating Point Unit) global interrupt
 */
#define FPU (81)
/**
 * @def SPI4
 * @brief SPI4 (Serial Peripheral Interface 4) global interrupt
 */
#define SPI4 (84)
/** @} */

#endif //_NVIC_interface_H
