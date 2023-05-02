/* FILENAME: RTOS_config  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 09/07/2022
*/
#ifndef _RTOS_config_H
#define _RTOS_config_H


typedef enum
{

	NO_ERROR 			,

	PRIORTY_ERROR 		,

	TASK_RESERVED_ERROR	,

	TASK_EMPTY_ERROR	,

	TASK_SUSP_ERROR

} Error_enState;

typedef enum
{

	EMPTY 		,

	NOT_EMPTY 	,

} Priority_enState;


/* Write the maximum and minimum number of tasks in your container system */
#define MAX_TASK_NUM		20U
#define MIN_TASK_NUM		0

/* Define your Tick time */
#define RTOS_TICK_TIME      100000U /* 100 MilliSecond */


#endif //_RTOS_config_H
