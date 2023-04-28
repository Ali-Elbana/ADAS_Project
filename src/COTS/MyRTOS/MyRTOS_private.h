/* FILENAME: RTOS_private  
*  Author:  Ali El-Bana
*  Version:  V1.0
*  DATE:   Wed 09/07/2022
*  Description: Private file for OS module
*/
#ifndef _RTOS_private_H
#define _RTOS_private_H


typedef enum
{

	SUSPENDED ,

	RUNNING

} Running_enState;

typedef struct 
{
	
	void (*TaskHandler) ( void ) 		;
	
	u8_t periodicity 					;
	
	Running_enState Task_RunningState 	;

} Task ;












#endif //_RTOS_private_H
