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
 * @brief MDIO Configuration structure for a speific PIN initialization
 * @struct EXTI_ConfigType
 *
 */
typedef struct
{
	/**
	 * @brief Configures a speific GPIO port
	 */
	u8_t LineNum;
	/**
	 * @brief Configures a speific GPIO port
	 */
	u8_t TriggerStatus;

} EXTI_ConfigType;

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

/**
 * Initialize the EXTI module
 */
void MEXTI_vInit(void);

/**
 * @brief Sets a certain pin's mode on a speific port
 * @param[in] A_u8LineID The port that the pin belongs to
 * @param[in] A_u8TriggerStatus The pin to update its mode
 */
void MEXTI_vEnableLine(u8_t A_u8LineID, u8_t A_u8TriggerStatus);

void MEXTI_vDisableLine(u8_t A_u8LineID);

void MEXTI_vSWITrigger(u8_t A_u8LineID);

void MEXTI_vSetTrigger(u8_t A_u8LineID, u8_t A_u8TriggerStatus);

void EXTI_vSetCallback(u8_t A_u8LineID, void (*A_vFptr)(void));

/**
 * Initialize the EXTI module with a certain configuration
 * @see MEXTI_vInit
 */
void MEXTI_vInit_WithStruct(P2VAR(EXTI_ConfigType) A_xConfig);

void MSYSCFG_vSetEXTIPort(u8_t A_u8LineID, u8_t A_u8PortID);

#define EXTI_LINE0 0
#define EXTI_LINE1 1
#define EXTI_LINE2 2
#define EXTI_LINE3 3
#define EXTI_LINE4 4
#define EXTI_LINE5 5
#define EXTI_LINE6 6
#define EXTI_LINE7 7
#define EXTI_LINE8 8
#define EXTI_LINE9 9
#define EXTI_LINE10 10
#define EXTI_LINE11 11
#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15

#define EXTI_FallingEdge 1
#define EXTI_RisingEdge 2
#define EXTI_OnChange 3

#endif //_EXTI_interface_H