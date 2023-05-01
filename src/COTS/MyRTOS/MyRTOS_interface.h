/* FILENAME: RTOS_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 09/07/2022
*/
#ifndef _RTOS_interface_H
#define _RTOS_interface_H

#include "MyRTOS_config.h"

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

Error_enState RTOS_u8CreateTask( void A_CopyHandler(void), u8_t A_u8Periodicity,
						u8_t A_u8Priority, u8_t A_u8FirstDelay ) ;

void Scheduler( void ) ;

void RTOS_vStartOS( void ) ;

Error_enState RTOS_u8DeleteTask( u8_t A_u8Priority ) 	;

Error_enState RTOS_u8SuspendTask( u8_t A_u8Priority ) 	;

Error_enState RTOS_u8ResumeTask( u8_t A_u8Priority )  	;


#endif //_RTOS_interface_H
