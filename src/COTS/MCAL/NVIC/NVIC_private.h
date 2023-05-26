/**
 * @file NVIC_private.h
 * @author Ali El Bana
 * @brief This file contains the registers information and addresses for the NVIC module
 * @version 2.0
 * @date 08/22/2022
 */

/* Header file guard */
#ifndef _NVIC_private_H
#define _NVIC_private_H

/**
 * @brief NVIC configuration structure for NVIC memory map
 * @struct NVIC_MemoryMapType
 *
 */
typedef struct
{
    /**
     * @brief Interrupt set-enable register
     * @details This register is responsible for enabling the interrupt
     * @note Writing 0 has no effect at all
     * @note Writing 1 enables the interrupt
     * @see ICERx
     */
    u32_t ISERx[8];
    /**
     * @note This is a reserved register
     */
    u32_t RESERVED0x[24];
    /**
     * @brief Interrupt clear-enable register
     * @details This register is responsible for disabling the interrupt
     * @note Writing 0 has no effect at all
     * @note Writing 1 disables the interrupt
     * @see ISERx
     */
    u32_t ICERx[8];
    /**
     * @note This is a reserved register
     */
    u32_t RSERVED1x[24];
    /**
     * @brief Interrupt set-pending register
     * @details Mostly used in testing the NVIC module
     * @note Writing 0 has no effect at all
     * @note Writing 1 changes the interrupt state to pending
     * @note Writing 1 on a certain bit that already has a value of 1, it stays pending and the value doesn't change
     * @see ICPRx
     *
     */
    u32_t ISPRx[8];
    /**
     * @note This is a reserved register
     */
    u32_t RESERVED2x[24];
    /**
     * @brief Interrupt clear-pending register
     * @details Mostly used in testing the NVIC module
     * @note Writing 0 has no effect at all
     * @note Writing 1 removes the pending interrupt state
     * @note Writing 1 on a certain bit that already has a value of 1, it stays pending and the value doesn't change
     * @see ISPRx
     *
     */
    u32_t ICPRx[8];
    /**
     * @note This is a reserved register
     */
    u32_t RESERVED3x[24];
    /**
     * @brief Interrupt active bit register
     * @note This is a read-only register
     *
     */
    u32_t IABRx[8];
    /**
     * @note This is a reserved register
     */
    u32_t RESERVED4x[56];
    /**
     * @brief Interrupt priority register
     * @details 
     * @see group_prioty
     * @see sub_group_prioty
     * @note Interrupt priority register
     */
    u8_t IPRx[240];

} NVIC_MemoryMapType;

/**
 * @brief System control block memory map structure
 * @details provides system implementation information, and system control.
 * @details This includes configuration, control, and reporting of the system exceptions
 * @struct SCB_MemoryMapType
 *
 */
typedef struct
{
    /**
     * @brief CPUID base register
     * @details This register contains the the processor part number, version, and implementation information
     */
    u32_t CPUID;
    /**
     * @brief Interrupt control and state register
     * @details This register is responsible for enabling the interrupt
     */
    u32_t ICSR;
    /**
     * @brief Vector table offset register
     * @details Interrupt control and state register
     */
    u32_t VTOR;
    /**
     * @brief Application interrupt and reset control register
     * @details This register provides priority grouping control for the exception model, endian status for data accesses, and reset control for the system
     * @details To write on this register, password `0x5FA` must be written to the VECTKEY field, otherwise the write attempt is ignored
     * @see VECTKEY_PASSWORD for the VECTKEY field password value
     */
    u32_t AIRCR;
    /**
     * @brief System control register
     * @details The SCR controls features of entry to and exit from low power state
     */
    u32_t SCR;
    /**
     * @brief configuration and control register
     * @details The CCR controls entry to Thread mode and enables:
     * - The handlers for NMI, hard fault and faults escalated by FAULTMASK to ignore bus faults
     * - Trapping of divide by zero and unaligned accesses
     * - Access to the STIR by unprivileged software
     */
    u32_t CCR;
    /**
     * @brief System handler priority register 1
     * @details The SHPR1-SHPR3 registers set the priority level, 0 to 255 of the exception handlers that have configurable priority.
     * @see SHPR2
     * @see SHPR3
     */
    u32_t SHPR1;
    /**
     * @brief System handler priority register 2
     * @details The SHPR1-SHPR3 registers set the priority level, 0 to 255 of the exception handlers that have configurable priority.
     * @see SHPR1
     * @see SHPR3
     */
    u32_t SHPR2;
    /**
     * @brief System handler priority register 3
     * @details The SHPR1-SHPR3 registers set the priority level, 0 to 255 of the exception handlers that have configurable priority.
     * @see SHPR1
     * @see SHPR2
     */
    u32_t SHPR3;
    /**
     * @brief System handler control and state register
     * @details The SHCSR enables the system handlers, and indicates:
     * - The pending status of the bus fault, memory management fault, and SVC exceptions
     * - The active status of the system handlers.
     * @note If you disable a system handler and the corresponding fault occurs, the processor treats the fault as a hard fault.
     */
    u32_t SHCSR;
    /**
     * @brief Configurable fault status register
     * @details This registers consists of 3 sub-registers:
     * - Usage Fault Status Register (UFSR)
     * @details 
     * - Bus Fault Status Register (BFSR)
     * @details 
     * - Memory Management Fault Status Register (MMFSR)
     * @details System handler control and state register
     */
    u32_t CFSR;
    /**
     * @brief Harf fault status register
     * @details The HFSR gives information about events that activate the hard fault handler.
     * @details This register is read, write to clear.
     * @details This means that bits in the register read normally, but writing 1 to any bit clears that bit to 0
     */
    u32_t HFSR;
    /**
     * @note This is a reserved register
     */
    u32_t RESERVED;
    /**
     * @brief Memory management fault address register
     * @details Memory management fault address register
     */
    u32_t MMFAR;
    /**
     * @brief Bus fault address register
     * @details Bus fault address register
     */
    u32_t BFAR;
} SCB_MemoryMapType;

/**
 * @defgroup nvic_addresses NVIC Addresses
 * @brief NVIC registers base addresses
 *
 * @{
 */

/**
 * @def NVIC_BASE_ADDRESS
 * @brief NVIC base address
 *
 */
#define NVIC_BASE_ADDRESS (0xE000E100)

/**
 * @def SCB_BASE_ADDRESS
 * @brief SCB base address
 *
 */
#define SCB_BASE_ADDRESS (0xE000ED00)
/** @} */

/**
 * @defgroup nvic_registers NVIC Registers
 * @brief NVIC registers 
 *
 * @{
 */

/**
 * @def MSCB
 * MSCB register
 *
 */
#define MSCB ((volatile P2VAR(SCB_MemoryMapType))(SCB_BASE_ADDRESS))
/**
 * @def MNVIC
 * MNVIC register
 *
 */
#define MNVIC ((volatile P2VAR(NVIC_MemoryMapType))(NVIC_BASE_ADDRESS))
/** @} */

#define MNVIC_STIR *((volatile 32 *)(0xE000EF00))

/**
 * @def VECTKEY_PASSWORD
 * @brief VECTKEY Password
 * @details This is the VECTKEY field password that must provides on every write attempt on the AIRCR register
 * @see SCB_MemoryMapType::AIRCR
 *
 */
#define VECTKEY_PASSWORD (0x05FA0000)

/**
 * @defgroup nvic_settable_priorities NVIC Settable Priorities
 * @brief NVIC Settable Priorities for the hardware interrupts
 *
 * @{
 */

/**
 * @def PEND_SV
 * Pendable request for system service
 *
 */
#define PEND_SV (-6)
/**
 * @def SYSTICK
 * System tick timer
 *
 */
#define SYSTICK (-5)
/**
 * @def SV_CALL
 * System service call via SWI instruction
 *
 */
#define SV_CALL (-4)
/**
 * @def MEMORY_MANAGE
 * Memory management
 *
 */
#define MEMORY_MANAGE (-3)
/**
 * @def BUS_FAULT
 * Pre-fetch fault, memory access fault
 *
 */
#define BUS_FAULT (-2)
/**
 * @def USAGE_FAULT
 * Undefined instruction or illegal state
 *
 */
#define USAGE_FAULT (-1)
/** @} */

#endif //_NVIC_private_H
