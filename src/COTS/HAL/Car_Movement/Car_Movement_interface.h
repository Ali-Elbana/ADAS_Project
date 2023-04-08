/* FILENAME: Car_Movement_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 03/14/2023
*/
#ifndef _Car_Movement_interface_H
#define _Car_Movement_interface_H


/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void HCarMove_vInit( void ) ;

void HCarMove_vSpeedRatio( VAR(u16_t) A_u16SpeedRatio ) ;

void HCarMove_vForward( void ) ;

void HCarMove_vBackward( void ) ;

void HCarMove_vRight( void ) ;

void HCarMove_vLeft( void ) ;

void HCarMove_vStop( void ) ;

u32_t HCarMove_u32GetCarSpeed( void ) ;


#endif //_Car_Movement_interface_H
