/**
 * @file EXTI_interface.h
 * @author Ali El Bana
 * @brief This file contains the interfacing information for the EXTI module
 * @version 1.0
 * @date 09/02/2022
 */

/* Header file guard */
#ifndef _EXTI_interface_H
#define _EXTI_interface_H

/**
 * @brief Interrupt configuration structure to initialize the interrupt with
 * @struct EXTI_ConfigType
 *
 */
typedef struct
{
	/**
	 * @brief Initialize the interrupt with a certain line ID
	 */
	u8_t LineNum;

	/**
	* @brief Initialize the interrupt with a certain PORT
	*/
	u8_t PortNum ;

	/**
	 * @brief The trigger status to trigger when the interrupt occurs
	 */
	u8_t TriggerStatus;



} EXTI_ConfigType;

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * @brief Initialize the EXTI module
 */
void MEXTI_vInit(void);
/**
 * @brief Initialize the EXTI module with a certain configuration
 * @param[in] A_xINTConfig The configuration structure to initialize the interrupt with
 */
void MEXTI_vInit_WithStruct(EXTI_ConfigType * A_xINTConfig);

/**
 * @brief Enable the interrupt on a certain line ID with a certain trigger status
 * @param[in] A_u8LineID The line ID to enable the interrupt on
 * @param[in] A_u8TriggerStatus The trigger status to trigger when the interrupt occurs
 */
void MEXTI_vEnableLine(u8_t A_u8LineID, u8_t A_u8TriggerStatus);

/**
 * @brief Disable the interrupt on a certain line ID
 * @param[in] A_u8LineID Which line to disable the interrupt on
 */
void MEXTI_vDisableLine(u8_t A_u8LineID);

/**
 * @brief perform a software event interrupt on a certain line
 * @param[in] A_u8LineID The line ID to perform the software event interrupt on
 */
void MEXTI_vSWITrigger(u8_t A_u8LineID);

/**
 * @brief Set the trigger status interrupt on a certain line ID
 * @param[in] A_u8LineID The line ID to enable the interrupt on
 * @param[in] A_u8TriggerStatus The trigger status to trigger when the interrupt occurs
 */
void MEXTI_vSetTrigger(u8_t A_u8LineID, u8_t A_u8TriggerStatus);

/**
 * @brief Set the callback when an interrupt occurs on a certain line ID
 * @param[in] A_u8LineID The line ID to set the callback on
 * @param[in] A_vFptr The callback to call when the interrupt occurs on a certain line
 */
void MEXTI_vSetCallback(u8_t A_u8LineID, void (*A_vFptr)(void));

/**
 * @brief Enable the interrupt on a certain line in a certain port
 * @param[in] A_u8LineID The line ID to to enable the interrupt onto
 * @param[in] A_u8PortID Port that the line belongs to
 */
void MSYSCFG_vSetEXTIPort(u8_t A_u8LineID, u8_t A_u8PortID);

/**
 * @defgroup interrupt_lines Interrupt line IDs
 *
 * @{
 */

/**
 * @def EXTI_LINE0
 * @brief Line 0
 *
 */
#define EXTI_LINE0 (0)
/**
 * @def EXTI_LINE1
 * @brief Line 1
 *
 */
#define EXTI_LINE1 (1)
/**
 * @def EXTI_LINE2
 * @brief Line 2
 *
 */
#define EXTI_LINE2 (2)
/**
 * @def EXTI_LINE3
 * @brief Line 3
 *
 */
#define EXTI_LINE3 (3)
/**
 * @def EXTI_LINE4
 * @brief Line 4
 *
 */
#define EXTI_LINE4 (4)
/**
 * @def EXTI_LINE5
 * @brief Line 5
 *
 */
#define EXTI_LINE5 (5)
/**
 * @def EXTI_LINE6
 * @brief Line 6
 *
 */
#define EXTI_LINE6 (6)
/**
 * @def EXTI_LINE7
 * @brief Line 7
 *
 */
#define EXTI_LINE7 (7)
/**
 * @def EXTI_LINE8
 * @brief Line 8
 *
 */
#define EXTI_LINE8 (8)
/**
 * @def EXTI_LINE9
 * @brief Line 9
 *
 */
#define EXTI_LINE9 (9)
/**
 * @def EXTI_LINE10
 * @brief Line 10
 *
 */
#define EXTI_LINE10 (10)
/**
 * @def EXTI_LINE11
 * @brief Line 11
 *
 */
#define EXTI_LINE11 (11)
/**
 * @def EXTI_LINE12
 * @brief Line 12
 *
 */
#define EXTI_LINE12 (12)
/**
 * @def EXTI_LINE13
 * @brief Line 13
 *
 */
#define EXTI_LINE13 (13)
/**
 * @def EXTI_LINE14
 * @brief Line 14
 *
 */
#define EXTI_LINE14 (14)
/**
 * @def EXTI_LINE15
 * @brief Line 15
 *
 */
#define EXTI_LINE15 (15)

/**
 * @}
 *
 */

/**
 * @defgroup interrupt_trigger_status Interrupt trigger status
 *
 * @{
 */

/**
 * @def EXTI_FallingEdge
 * @brief trigger interrupt on falling edge
 *
 */
#define EXTI_FallingEdge (1)
/**
 * @def EXTI_RisingEdge
 * @brief trigger interrupt on rising edge
 *
 */
#define EXTI_RisingEdge (2)
/**
 * @def EXTI_OnChange
 * @brief trigger interrupt on level change
 *
 */
#define EXTI_OnChange (3)
/**
 * @}
 *
 */

#endif //_EXTI_interface_H
