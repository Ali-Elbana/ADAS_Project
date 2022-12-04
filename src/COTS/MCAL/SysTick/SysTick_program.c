/**
 * @file SysTick_program.c
 * @author Ali El Bana
 * @brief This file contains the source code of the interfacing for the Systick modules
 * @version 1.0
 * @date 09/04/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"
#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_config.h"

STATIC P2FUNC(VAR(void), GS_vCallbackFunc)(void) = NULL;
STATIC VAR(u8_t) GS_u8MyIntervalMode = INITIAL_ZERO;

/*******************************************************************************************************************/
/******************************************************************************************************************/

STATIC FUNC(void) MSysTick_EnableException(void)
{
	SET_BIT(SysTick->CTRL, TICKINT);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

STATIC FUNC(void) MSysTick_DisableException(void)
{
	CLR_BIT(SysTick->CTRL, TICKINT);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) MSysTick_vInit(void)
{
// Choose the input CLK source.
#if CLK_SOURCE == AHB_DividedBy8
	CLR_BIT(SysTick->CTRL, CLKSOURCE);
#elif CLK_SOURCE == AHB
	SET_BIT(SysTick->CTRL, CLKSOURCE);
#endif

// SysTick exception request enable.
#if Exception_Request == Dont_AssertRequest
	MSysTick_DisableException();
#elif Exception_Request == AssertRequest
	MSysTick_EnableException();
#endif

	// Enable the peripheral interrupt.
	MSysTick_vEnable();
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) MSysTick_vSetBusyWait(VAR(u32_t) A_u32Ticks)
{
	SysTick->VAL = INITIAL_ZERO;

	// Load Ticks to the load register.
	SysTick->LOAD = A_u32Ticks;

	// Start Timer.
	MSysTick_vEnable();

	// Wait till the flag is raised (= 1).
	while (!GET_BIT(SysTick->CTRL, COUNTFLAG));

	// Stop the timer.
	MSysTick_vDisable();

	// Clear the LOAD and VAL registers
	SysTick->LOAD = INITIAL_ZERO;
	SysTick->VAL = INITIAL_ZERO;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) MSysTick_vSetSingleInterval(VAR(u32_t) A_u32Ticks, P2FUNC(VAR(void), A_Fptr)(void))
{
	// Save the callback.
	GS_vCallbackFunc = A_Fptr;

	// Load Ticks to the load register.
	SysTick->LOAD = A_u32Ticks;

	// Start Timer.
	MSysTick_vEnable();

	// Set interval mode to single.
	GS_u8MyIntervalMode = SINGLE_INTERVAL_MODE;

	// Enable the IRQ.
	MSysTick_EnableException();
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) MSysTick_vSetPeriodicInterval(VAR(u32_t) A_u32Ticks, P2FUNC(VAR(void), A_Fptr)(void))
{
	// Save the callback.
	GS_vCallbackFunc = A_Fptr;

	// Load Ticks to the load register.
	SysTick->LOAD = A_u32Ticks;

	// Start Timer.
	MSysTick_vEnable();

	// Set interval mode to single.
	GS_u8MyIntervalMode = PERIODIC_INTERVAL_MODE;

	// Enable the IRQ.
	MSysTick_EnableException();
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) MSysTick_vStopInterval(void)
{
	// Disable the IRQ.
	MSysTick_DisableException();

	// Stop the timer.
	MSysTick_vDisable();

	// Clear the LOAD and VAL registers
	SysTick->LOAD = INITIAL_ZERO;
	SysTick->VAL = INITIAL_ZERO;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

VAR(u32_t) MSysTick_u32GetElapsedTime(void)
{
	VAR(u32_t) L_u32ElapsedTime = INITIAL_ZERO;
	L_u32ElapsedTime = (SysTick->LOAD - MSysTick_u32GetRemainingTime());
	return L_u32ElapsedTime;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

VAR(u32_t) MSysTick_u32GetRemainingTime(void)
{
	VAR(u32_t) L_u32RemainingTime = INITIAL_ZERO;
	L_u32RemainingTime = SysTick->VAL;
	return L_u32RemainingTime;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) MSysTick_vEnable(void)
{
	// Enable the peripheral interrupt.
	MSysTick_EnableException();
	// Start Timer.
	SET_BIT(SysTick->CTRL, COUNTER_ENABLE);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) MSysTick_vDisable(void)
{
	// Disable the peripheral interrupt.
	MSysTick_DisableException();
	// Stop the timer.
	CLR_BIT(SysTick->CTRL, COUNTER_ENABLE);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

FUNC(void) SysTick_Handler(void)
{
	volatile VAR(u8_t) L_u8ReadFlag = INITIAL_ZERO;

	if (GS_vCallbackFunc != NULL)
	{
		// Callback notification.
		GS_vCallbackFunc();
	}

	if (GS_u8MyIntervalMode == SINGLE_INTERVAL_MODE)
	{
		// Disable the IRQ.
		MSysTick_DisableException();

		// Stop the timer.
		MSysTick_vDisable();

		// Clear the LOAD and VAL registers
		SysTick->LOAD = INITIAL_ZERO;
		SysTick->VAL = INITIAL_ZERO;

		GS_u8MyIntervalMode = PERIODIC_INTERVAL_MODE;
	}

	// Clear IRQ flag.
	L_u8ReadFlag = GET_BIT(SysTick->CTRL, COUNTFLAG);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/
