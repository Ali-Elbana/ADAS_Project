/* FILENAME: UltraSonic_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 02/24/2023
*/
#ifndef _UltraSonic_interface_H
#define _UltraSonic_interface_H

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

typedef struct
{
    u8_t u8Port ;

    u8_t u8Pin  ;

} HULTSNC_ConfigType ;

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void HULTSNC_vInit( P2VAR(HULTSNC_ConfigType) TRIG_psCfg ) 		;

void HULTSNC_vTrigger( P2VAR(HULTSNC_ConfigType) TRIG_psCfg ) 	;

f32_t HULTSNC_f32GetDistance( void ) 							;



#endif //_UltraSonic_interface_H
