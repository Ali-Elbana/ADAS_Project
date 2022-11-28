/* FILENAME: EXTI_program
 *  Author:  Ali El Bana
 *  Version:  V1.0
 *  DATE:   Fri 09/02/2022
 */

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "SYSCFG_private.h"

STATIC P2FUNC(VAR(void), GS_vEXTI_Callback)[EXTI_IRQs](VAR(void)) = { NULL };

STATIC VAR(u8_t) GS_u8EXTI_EnabledLine_ID = INITIAL_ZERO;

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

void MSYSCFG_vSetEXTIPort(VAR(u8_t) A_u8LineID, VAR(u8_t) A_u8PortID)
{

	VAR(u8_t) L_u8Index = A_u8LineID / 4;
	VAR(u8_t) L_u8ShiftAmount = A_u8LineID % 4;

	CLR_BITs(MSYSCFG->EXTICR[L_u8Index], 0b1111, L_u8ShiftAmount, 4);
	SET_BITs(MSYSCFG->EXTICR[L_u8Index], A_u8PortID, L_u8ShiftAmount, 4);
}

void MEXTI_vInit(void)
{
	VAR(u8_t) L_u8ShiftedOffset = INITIAL_ZERO;

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
	GS_u8EXTI_EnabledLine_ID = L_u8ShiftedOffset;

	// Clear all flags.
	MEXTI->PR = 0xffffffff;

	// Enable EXTI on a line.
	MEXTI->IMR = 0;

	MEXTI->IMR = (ENABLE << L_u8ShiftedOffset);

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

FUNC(void) MEXTI_vEnableLine(VAR(u8_t) A_u8LineID, VAR(u8_t) A_u8TriggerStatus)
{
	if (A_u8LineID <= 23)
	{
		SET_BIT(MEXTI->IMR, A_u8LineID);

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

	// Get the enabled line ID.
	GS_u8EXTI_EnabledLine_ID = A_u8LineID;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vDisableLine(u8 A_u8LineID)
{

	if (A_u8LineID <= 23)
	{

		CLR_BIT(MEXTI->IMR, A_u8LineID);
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vSWITrigger(u8 A_u8LineID)
{

	if (A_u8LineID <= 23)
	{

		SET_BIT(MEXTI->SWIER, A_u8LineID);
	}

	// Get the enabled line ID.
	GS_u8EXTI_EnabledLine_ID = A_u8LineID;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MEXTI_vSetTrigger(u8 A_u8LineID, u8 A_u8TriggerStatus)
{

	if (A_u8LineID <= 23)
	{

		SET_BIT(MEXTI->IMR, A_u8LineID);

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

	// Get the enabled line ID.
	GS_u8EXTI_EnabledLine_ID = A_u8LineID;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void EXTI_vSetCallback(VAR(u8_t) A_u8LineID, P2FUNC(VAR(void), A_vFptr)(void))
{
	if (A_u8LineID <= 23)
	{
		switch (A_u8LineID)
		{
		case EXTI_LINE0:
			GS_vEXTI_Callback[EXTI_LINE0] = A_vFptr;
			break;
		case EXTI_LINE1:
			GS_vEXTI_Callback[EXTI_LINE1] = A_vFptr;
			break;
		case EXTI_LINE2:
			GS_vEXTI_Callback[EXTI_LINE2] = A_vFptr;
			break;
		case EXTI_LINE3:
			GS_vEXTI_Callback[EXTI_LINE3] = A_vFptr;
			break;
		case EXTI_LINE4:
			GS_vEXTI_Callback[EXTI_LINE4] = A_vFptr;
			break;
		case EXTI_LINE5:
			GS_vEXTI_Callback[EXTI_LINE5] = A_vFptr;
			break;
		case EXTI_LINE6:
			GS_vEXTI_Callback[EXTI_LINE6] = A_vFptr;
			break;
		case EXTI_LINE7:
			GS_vEXTI_Callback[EXTI_LINE7] = A_vFptr;
			break;
		case EXTI_LINE8:
			GS_vEXTI_Callback[EXTI_LINE8] = A_vFptr;
			break;
		case EXTI_LINE9:
			GS_vEXTI_Callback[EXTI_LINE9] = A_vFptr;
			break;
		case EXTI_LINE10:
			GS_vEXTI_Callback[EXTI_LINE10] = A_vFptr;
			break;
		case EXTI_LINE11:
			GS_vEXTI_Callback[EXTI_LINE11] = A_vFptr;
			break;
		case EXTI_LINE12:
			GS_vEXTI_Callback[EXTI_LINE12] = A_vFptr;
			break;
		case EXTI_LINE13:
			GS_vEXTI_Callback[EXTI_LINE13] = A_vFptr;
			break;
		case EXTI_LINE14:
			GS_vEXTI_Callback[EXTI_LINE14] = A_vFptr;
			break;
		case EXTI_LINE15:
			GS_vEXTI_Callback[EXTI_LINE15] = A_vFptr;
			break;
		}
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

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
