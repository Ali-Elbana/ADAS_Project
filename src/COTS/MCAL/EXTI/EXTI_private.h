/* FILENAME: EXTI_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 09/02/2022
*/
#ifndef _EXTI_private_H
#define _EXTI_private_H



#define EXTI_BASE_ADDRESS 0x40013C00




typedef struct
{

	u32 IMR 	;

	u32 EMR 	;

	u32 RTSR 	;

	u32 FTSR 	;

	u32 SWIER 	;

	u32 PR		;

} EXTI_Type ;




#define MEXTI ( (volatile EXTI_Type*) (EXTI_BASE_ADDRESS) )





#define ENABLE  1
#define DISABLE	2


#define EXTI_IRQs 23



#endif //_EXTI_private_H
