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

void MSysTick_vInit(void)
{

	// Reset timer value.
	SysTick->VAL = INITIAL_ZERO;

// Choose the input CLK source.
#if CLK_SOURCE == AHB_DividedBy8
	CLR_BIT(SysTick->CTRL, CLKSOURCE);

#elif CLK_SOURCE == AHB
	SET_BIT(SysTick->CTRL, CLKSOURCE);
#endif

// SysTick exception request enable.
#if Exception_Request == Dont_AssertRequest
	CLR_BIT(SysTick->CTRL, TICKINT);

#elif Exception_Request == AssertRequest
	SET_BIT(SysTick->CTRL, TICKINT);
#endif
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vSetBusyWait(u32_t A_u32Ticks)
{

	// Load Ticks to the load register.
	SysTick->LOAD = A_u32Ticks;

	// Reset timer value.
	SysTick->VAL = INITIAL_ZERO;

	// Start Timer.
	SET_BIT(SysTick->CTRL, COUNTER_ENABLE);

	// Wait till the flag is raised (= 1).
	while (GET_BIT(SysTick->CTRL, COUNTFLAG) == FLAG_CLEARED)
		;

	// Stop the timer.
	CLR_BIT(SysTick->CTRL, COUNTER_ENABLE);

	// Clear the LOAD and VAL registers
	SysTick->LOAD = INITIAL_ZERO;
	SysTick->VAL = INITIAL_ZERO;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/
void MSysTick_vDelay(u32_t A_u32Ticks, u32_t A_u32TickType)
{

	u32_t l_u32TickNum = INITIAL_ZERO;

	if (A_u32TickType == MILLI_SEC)
	{
		l_u32TickNum = (A_u32Ticks * 1000) - 1;
	}

	else if (A_u32TickType == MICRO_SEC)
	{
		l_u32TickNum = A_u32Ticks - 1;
	}

	else if (A_u32TickType == SEC)
	{
		l_u32TickNum = (A_u32Ticks * 1000000) - 1;
	}

	else
	{
		// error
	}

	if (l_u32TickNum < MAX_TICKS)
	{

		// Load Ticks to the load register.
		SysTick->LOAD = l_u32TickNum;

		// Reset timer value.
		SysTick->VAL = INITIAL_ZERO;

		// Start Timer.
		SET_BIT(SysTick->CTRL, COUNTER_ENABLE);

		// Wait till the flag is raised (= 1).
		while (GET_BIT(SysTick->CTRL, COUNTFLAG) == FLAG_CLEARED)
			;

		// Stop the timer.
		CLR_BIT(SysTick->CTRL, COUNTER_ENABLE);

		// Clear the LOAD and VAL registers
		SysTick->LOAD = INITIAL_ZERO;
		SysTick->VAL = INITIAL_ZERO;
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vDelayMicroSec(u32_t A_u32Ticks)
{

	u32_t
	l_u32TickNum = INITIAL_ZERO;

	l_u32TickNum = (A_u32Ticks)-1;

	if (l_u32TickNum < MAX_TICKS)
	{

		// Load Ticks to the load register.
		SysTick->LOAD = l_u32TickNum;

		// Reset timer value.
		SysTick->VAL = INITIAL_ZERO;

		// Start Timer.
		SET_BIT(SysTick->CTRL, COUNTER_ENABLE);

		// Wait till the flag is raised (= 1).
		while (GET_BIT(SysTick->CTRL, COUNTFLAG) == FLAG_CLEARED)
			;

		// Stop the timer.
		CLR_BIT(SysTick->CTRL, COUNTER_ENABLE);

		// Clear the LOAD and VAL registers
		SysTick->LOAD = INITIAL_ZERO;
		SysTick->VAL = INITIAL_ZERO;
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vDelayMilliSec(u32_t A_u32Ticks)
{

	u32_t
	l_u32TickNum = INITIAL_ZERO;

	l_u32TickNum = (A_u32Ticks * 1000) - 1;

	if (l_u32TickNum < MAX_TICKS)
	{

		// Load Ticks to the load register.
		SysTick->LOAD = l_u32TickNum;

		// Reset timer value.
		SysTick->VAL = INITIAL_ZERO;

		// Start Timer.
		SET_BIT(SysTick->CTRL, COUNTER_ENABLE);

		// Wait till the flag is raised (= 1).
		while (GET_BIT(SysTick->CTRL, COUNTFLAG) == FLAG_CLEARED)
			;

		// Stop the timer.
		CLR_BIT(SysTick->CTRL, COUNTER_ENABLE);

		// Clear the LOAD and VAL registers
		SysTick->LOAD = INITIAL_ZERO;
		SysTick->VAL = INITIAL_ZERO;
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vDelaySec(u32_t A_u32Ticks)
{

	u32_t
	l_u32TickNum = INITIAL_ZERO;

	l_u32TickNum = (A_u32Ticks * 1000000) - 1;

	if (l_u32TickNum < MAX_TICKS)
	{

		// Load Ticks to the load register.
		SysTick->LOAD = l_u32TickNum;

		// Reset timer value.
		SysTick->VAL = INITIAL_ZERO;

		// Start Timer.
		SET_BIT(SysTick->CTRL, COUNTER_ENABLE);

		// Wait till the flag is raised (= 1).
		while (GET_BIT(SysTick->CTRL, COUNTFLAG) == FLAG_CLEARED)
			;

		// Stop the timer.
		CLR_BIT(SysTick->CTRL, COUNTER_ENABLE);

		// Clear the LOAD and VAL registers
		SysTick->LOAD = INITIAL_ZERO;
		SysTick->VAL = INITIAL_ZERO;
	}
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vSetSingleInterval(u32_t A_u32Ticks, void (*A_Fptr)(void))
{

	// Save the callback.
	GS_vCallbackFunc = A_Fptr;

	// Reset timer value.
	SysTick->VAL = INITIAL_ZERO;

	// Load Ticks to the load register.
	SysTick->LOAD = A_u32Ticks;

	// Start Timer.
	SET_BIT(SysTick->CTRL, COUNTER_ENABLE);

	// Set interval mode to single.
	GS_u8MyIntervalMode = SINGLE_INTERVAL_MODE;

	// Enable the IRQ.
	SET_BIT(SysTick->CTRL, TICKINT);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vSetPeriodicInterval(u32_t A_u32Ticks, void (*A_Fptr)(void))
{

	// Save the callback.
	GS_vCallbackFunc = A_Fptr;

	// Reset timer value.
	SysTick->VAL = INITIAL_ZERO;

	// Load Ticks to the load register.
	SysTick->LOAD = A_u32Ticks;

	// Start Timer.
	SET_BIT(SysTick->CTRL, COUNTER_ENABLE);

	// Set interval mode to single.
	GS_u8MyIntervalMode = PERIODIC_INTERVAL_MODE;

	// Enable the IRQ.
	SET_BIT(SysTick->CTRL, TICKINT);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vStopInterval(void)
{

	// Disable the IRQ.
	SET_BIT(SysTick->CTRL, TICKINT);

	// Stop the timer.
	SET_BIT(SysTick->CTRL, TICKINT);

	// Clear the LOAD and VAL registers
	SysTick->LOAD = INITIAL_ZERO;
	SysTick->VAL = INITIAL_ZERO;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u32_t
MSysTick_u32GetElapsedTime(void)
{
	u32_t
	L_u32ElapsedTime = INITIAL_ZERO;

	L_u32ElapsedTime = (SysTick->LOAD - SysTick->VAL);

	return L_u32ElapsedTime;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u32_t
MSysTick_u32GetRemainingTime(void)
{
	u32_t
	L_u32RemainingTime = INITIAL_ZERO;

	L_u32RemainingTime = SysTick->VAL;

	return L_u32RemainingTime;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vEnable(void)
{

	// Start Timer.
	SET_BIT(SysTick->CTRL, COUNTER_ENABLE);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vDisable(void)
{

	// Disable the peripheral interrupt.
	SET_BIT(SysTick->CTRL, TICKINT);

	// Stop the timer.
	CLR_BIT(SysTick->CTRL, COUNTER_ENABLE);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vDisableException(void)
{
	CLR_BIT(SysTick->CTRL, TICKINT);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MSysTick_vEnableException(void)
{
	SET_BIT(SysTick->CTRL, TICKINT);
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

/**
 * @brief This function is responsible for handling the Systick interrupt
 * @details This function is called by the NVIC when the Systick interrupt is raised
 */
void SysTick_Handler(void)
{

	volatile u8_t L_u8ReadFlag = INITIAL_ZERO;

	if (GS_vCallbackFunc != NULL)
	{
		// Callback notification.
		GS_vCallbackFunc();
	}

	if (GS_u8MyIntervalMode == SINGLE_INTERVAL_MODE)
	{
		// Disable the IRQ.
		CLR_BIT(SysTick->CTRL, TICKINT);

		// Stop the timer.
		CLR_BIT(SysTick->CTRL, COUNTER_ENABLE);

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
