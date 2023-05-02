/* FILENAME: RTOS_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 09/07/2022
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../COTS/LIB/LSTD_TYPES.h"
#include "../../COTS/LIB/LSTD_COMPILER.h"
#include "../../COTS/LIB/LSTD_VALUES.h"
#include "../../COTS/LIB/LSTD_BITMATH.h"

#include "../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../COTS/MCAL/GPIO/GPIO_interface.h"
#include "../../COTS/MCAL/SysTick/SysTick_interface.h"

#include "MyRTOS_config.h"
#include "MyRTOS_interface.h"
#include "MyRTOS_private.h"



Task SystemTasks[ MAX_TASK_NUM ] 	= { INITIAL_ZERO } ;

Task Empty_TaskSystem 				= { INITIAL_ZERO } ;

u8_t TaskTiming[ MAX_TASK_NUM ]		= { INITIAL_ZERO } ;

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

Error_enState RTOS_u8CreateTask( void A_CopyHandler(void), u8_t A_u8Periodicity,
								 u8_t A_u8Priority		 , u8_t A_u8FirstDelay )
{

	Error_enState L_enuTaskErrorState = NO_ERROR ;

	/* Verify that the priority index within the correct range */
	if( (A_u8Priority >= MIN_TASK_NUM) && (A_u8Priority < MAX_TASK_NUM) )
	{

		/* Verify that the required priority is free */
		if( SystemTasks[A_u8Priority].TaskHandler == EMPTY )
		{

			SystemTasks[A_u8Priority].TaskHandler 		= A_CopyHandler 	;

			SystemTasks[A_u8Priority].periodicity 		= A_u8Periodicity 	;

			TaskTiming[A_u8Priority]					= A_u8FirstDelay	;

			SystemTasks[A_u8Priority].Task_RunningState = RUNNING			;

		}
		else
		{
			/* This task is already reserved */
			L_enuTaskErrorState = TASK_RESERVED_ERROR ;
		}

	}
	else
	{
		/* Wrong priority number */
		L_enuTaskErrorState = PRIORTY_ERROR ;
	}

	return L_enuTaskErrorState ;

}

/******************************************************************************************************/
/*****************************************************************************************************/

void Scheduler( void )
{

	u8_t L_u8Counter = INITIAL_ZERO ;

	/* Loop on all tasks */
	for( L_u8Counter = MIN_TASK_NUM; L_u8Counter < MAX_TASK_NUM; L_u8Counter++ )
	{

		/* Verify that the required priority is reserved */
		if( SystemTasks[L_u8Counter].TaskHandler != EMPTY )
		{

			if( SystemTasks[L_u8Counter].Task_RunningState == RUNNING )
			{

				/* Verify that it is the tick time to execute it */
				if( TaskTiming[L_u8Counter] == 0 )
				{
					/* Run the task */
					SystemTasks[L_u8Counter].TaskHandler( ) ;

					/* Reload the periodicity */
					TaskTiming[L_u8Counter] = SystemTasks[L_u8Counter].periodicity ;
				}
				else
				{
					/* Decrement the timing until it reach to the tick time to be executed */
					TaskTiming[L_u8Counter]-- ;
				}

			}
			else
			{
				/* Do nothing */
			}

		}
		else
		{
			/* Do nothing */
		}

	}

}

/******************************************************************************************************/
/*****************************************************************************************************/
Error_enState RTOS_u8DeleteTask( u8_t A_u8Priority )
{

	Error_enState L_enuErrorState = NO_ERROR ;

	/* Verify that the required priority is registered */
	if( SystemTasks[A_u8Priority].TaskHandler != EMPTY )
	{

		/* Task exist, execute the removal */
		SystemTasks[A_u8Priority] = Empty_TaskSystem ;

	}
	else
	{
		/* Task not exist */
		L_enuErrorState = TASK_EMPTY_ERROR ;
	}

	return L_enuErrorState ;

}

/******************************************************************************************************/
/*****************************************************************************************************/

Error_enState RTOS_u8SuspendTask( u8_t A_u8Priority )
{

	Error_enState L_enuErrorState = NO_ERROR ;

	/* Verify that the required priority is registered */
	if( SystemTasks[A_u8Priority].TaskHandler != EMPTY )
	{

		/* Task exist, suspend it */
		SystemTasks[A_u8Priority].Task_RunningState == SUSPENDED ;

	}
	else
	{
		/* Task not exist */
		L_enuErrorState = TASK_EMPTY_ERROR ;
	}

	return L_enuErrorState ;

}

/******************************************************************************************************/
/*****************************************************************************************************/

Error_enState RTOS_u8ResumeTask( u8_t A_u8Priority )
{

	Error_enState L_enuErrorState = NO_ERROR ;

	/* Verify that the required priority is registered */
	if( SystemTasks[A_u8Priority].TaskHandler != EMPTY )
	{

		/* Task exist, run it */
		SystemTasks[A_u8Priority].Task_RunningState == RUNNING ;

	}
	else
	{
		/* Task not exist */
		L_enuErrorState = TASK_EMPTY_ERROR ;
	}

	return L_enuErrorState ;

}

/******************************************************************************************************/
/*****************************************************************************************************/

void RTOS_vStartOS( void )
{

	MSysTick_vSetPeriodicInterval( RTOS_TICK_TIME, &Scheduler ) ;

}

/******************************************************************************************************/
/*****************************************************************************************************/






