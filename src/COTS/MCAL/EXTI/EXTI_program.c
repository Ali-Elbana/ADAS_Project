/**
 * @file EXTI_program.c
 * @author Ali El Bana
 * @brief This file contains the source code of the interfacing for the EXTI module
 * @version 1.0
 * @date 09/02/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "SYSCFG_private.h"

STATIC P2FUNC(void, GS_vEXTI_Callback[EXTI_IRQs])(void) = {NULL};

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void MSYSCFG_vSetEXTIPort(u8_t A_u8LineID, u8_t A_u8PortID)
{
	u8_t L_u8Index = A_u8LineID / 4;
	u8_t L_u8ShiftAmount = A_u8LineID % 4;

	CLR_BITs(MSYSCFG->EXTICR[L_u8Index], 0b1111, L_u8ShiftAmount, 4);
	SET_BITs(MSYSCFG->EXTICR[L_u8Index], A_u8PortID, L_u8ShiftAmount, 4);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vInit(void)
{

	u8_t L_u8ShiftedOffset = INITIAL_ZERO;

#if EXTI_LINE0_EN == ENABLE
	L_u8ShiftedOffset = 0;
#elif EXTI_LINE1_EN == ENABLE
	L_u8ShiftedOffset = 1;
#elif EXTI_LINE2_EN == ENABLE
	L_u8ShiftedOffset = 2;
#elif EXTI_LINE3_EN == ENABLE
	L_u8ShiftedOffset = 3;
#elif EXTI_LINE4_EN == ENABLE
	L_u8ShiftedOffset = 4;
#elif EXTI_LINE5_EN == ENABLE
	L_u8ShiftedOffset = 5;
#elif EXTI_LINE6_EN == ENABLE
	L_u8ShiftedOffset = 6;
#elif EXTI_LINE7_EN == ENABLE
	L_u8ShiftedOffset = 7;
#elif EXTI_LINE8_EN == ENABLE
	L_u8ShiftedOffset = 8;
#elif EXTI_LINE9_EN == ENABLE
	L_u8ShiftedOffset = 9;
#elif EXTI_LINE10_EN == ENABLE
	L_u8ShiftedOffset = 10;
#elif EXTI_LINE11_EN == ENABLE
	L_u8ShiftedOffset = 11;
#elif EXTI_LINE12_EN == ENABLE
	L_u8ShiftedOffset = 12;
#elif EXTI_LINE13_EN == ENABLE
	L_u8ShiftedOffset = 13;
#elif EXTI_LINE14_EN == ENABLE
	L_u8ShiftedOffset = 14;
#elif EXTI_LINE15_EN == ENABLE
	L_u8ShiftedOffset = 15;
#endif

	// Get the enabled line ID.
	// GS_u8EXTI_EnabledLine_ID = L_u8ShiftedOffset;

	// Clear all flags.
	MEXTI->PR = 0xffffffff;

	// Enable EXTI on a line.
	MEXTI->IMR = 0;

	MEXTI->IMR |= (ENABLE << L_u8ShiftedOffset);

// Set EXTI Triggered status on a line.
#if EXTI_LINE0_TRIGGER == EXTI_RisingEdge

	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE0_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE0_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	///////////////////////////////////////////////////////////
#elif EXTI_LINE1_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE1_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE1_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	///////////////////////////////////////////////////////////
#elif EXTI_LINE2_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE2_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE2_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	///////////////////////////////////////////////////////////
#elif EXTI_LINE3_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE3_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE3_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	///////////////////////////////////////////////////////////
#elif EXTI_LINE4_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE4_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE4_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	///////////////////////////////////////////////////////////
#elif EXTI_LINE5_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE5_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE5_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	//////////////////////////////////////////////////////////
#elif EXTI_LINE6_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE6_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE6_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	//////////////////////////////////////////////////////////
#elif EXTI_LINE7_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE7_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE7_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	//////////////////////////////////////////////////////////
#elif EXTI_LINE8_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE8_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE8_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	/////////////////////////////////////////////////////////
#elif EXTI_LINE9_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE9_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE9_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	/////////////////////////////////////////////////////////
#elif EXTI_LINE10_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE10_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE10_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	/////////////////////////////////////////////////////////
#elif EXTI_LINE11_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE11_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE11_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	////////////////////////////////////////////////////////
#elif EXTI_LINE12_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE12_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE12_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	///////////////////////////////////////////////////////
#elif EXTI_LINE13_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE13_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE13_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	///////////////////////////////////////////////////////
#elif EXTI_LINE14_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE14_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE14_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

	///////////////////////////////////////////////////////
#elif EXTI_LINE15_TRIGGER == EXTI_RisingEdge
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);

#elif EXTI_LINE15_TRIGGER == EXTI_FallingEdge
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#elif EXTI_LINE15_TRIGGER == EXTI_OnChange
	SET_BIT(MEXTI->RTSR, L_u8ShiftedOffset);
	SET_BIT(MEXTI->FTSR, L_u8ShiftedOffset);

#endif
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vInit_WithStruct(EXTI_ConfigType *A_xINTConfig)
{

	MEXTI_vEnableLine(A_xINTConfig->LineNum, A_xINTConfig->TriggerStatus);

	MSYSCFG_vSetEXTIPort(A_xINTConfig->LineNum, A_xINTConfig->PortNum);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vEnableLine(u8_t A_u8LineID, u8_t A_u8TriggerStatus)
{

	if (A_u8LineID < EXTI_MAX_EXTI_NUM)
	{

		SET_BIT(MEXTI->IMR, A_u8LineID);

		MEXTI_vSetTrigger(A_u8LineID, A_u8TriggerStatus);
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vDisableLine(u8_t A_u8LineID)
{

	if (A_u8LineID < EXTI_MAX_EXTI_NUM)
	{
		CLR_BIT(MEXTI->IMR, A_u8LineID);
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vSWITrigger(u8_t A_u8LineID)
{

	if (A_u8LineID < EXTI_MAX_EXTI_NUM)
	{
		SET_BIT(MEXTI->SWIER, A_u8LineID);
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vSetTrigger(u8_t A_u8LineID, u8_t A_u8TriggerStatus)
{

	if (A_u8LineID < EXTI_MAX_EXTI_NUM)
	{

		switch (A_u8TriggerStatus)
		{
		case EXTI_RisingEdge:
			SET_BIT(MEXTI->RTSR, A_u8LineID);

			CLR_BIT(MEXTI->FTSR, A_u8LineID);
			break;

		case EXTI_FallingEdge:
			SET_BIT(MEXTI->FTSR, A_u8LineID);

			CLR_BIT(MEXTI->RTSR, A_u8LineID);
			break;

		case EXTI_OnChange:
			SET_BIT(MEXTI->RTSR, A_u8LineID);

			SET_BIT(MEXTI->FTSR, A_u8LineID);
			break;
		}
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vSetCallback(u8_t A_u8LineID, void (*A_vFptr)(void))
{

	if (A_u8LineID < EXTI_MAX_EXTI_NUM)
	{
		GS_vEXTI_Callback[A_u8LineID] = A_vFptr;
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief This function is responsible for clearing the pending flag of the External interrupt 0 module
 *
 */
void EXTI0_IRQHandler(void)
{

	if (GS_vEXTI_Callback[EXTI_LINE0] != NULL)
	{
		GS_vEXTI_Callback[EXTI_LINE0]();
	}

	// Clear the flag.
	SET_BIT(MEXTI->PR, EXTI_LINE0);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief This function is responsible for clearing the pending flag of the External interrupt 1 module
 *
 */
void EXTI1_IRQHandler(void)
{

	if (GS_vEXTI_Callback[EXTI_LINE1] != NULL)
	{
		GS_vEXTI_Callback[EXTI_LINE1]();
	}

	// Clear the flag.
	SET_BIT(MEXTI->PR, EXTI_LINE1);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief This function is responsible for clearing the pending flag of the External interrupt 2 module
 *
 */
void EXTI2_IRQHandler(void)
{

	if (GS_vEXTI_Callback[EXTI_LINE2] != NULL)
	{
		GS_vEXTI_Callback[EXTI_LINE2]();
	}

	// Clear the flag.
	SET_BIT(MEXTI->PR, EXTI_LINE2);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief This function is responsible for clearing the pending flag of the External interrupt 3 module
 *
 */
void EXTI3_IRQHandler(void)
{

	if (GS_vEXTI_Callback[EXTI_LINE3] != NULL)
	{
		GS_vEXTI_Callback[EXTI_LINE3]();
	}

	// Clear the flag.
	SET_BIT(MEXTI->PR, EXTI_LINE3);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief This function is responsible for clearing the pending flag of the External interrupt 4 module
 *
 */
void EXTI4_IRQHandler(void)
{

	if (GS_vEXTI_Callback[EXTI_LINE4] != NULL)
	{
		GS_vEXTI_Callback[EXTI_LINE4]();
	}

	// Clear the flag.
	SET_BIT(MEXTI->PR, EXTI_LINE4);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief This function is responsible for clearing the pending flag of the External interrupt 5-9 module
 *
 */
void EXTI9_5_IRQHandler(void)
{
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief This function is responsible for clearing the pending flag of the External interrupt 10-15 module
 *
 */
void EXTI15_10_IRQHandler(void)
{
}

/*******************************************************************************************************************/
/******************************************************************************************************************/
