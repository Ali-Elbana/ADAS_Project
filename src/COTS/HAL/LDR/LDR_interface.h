/* FILENAME: LDR_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 12/22/2022
*/
#ifndef _LDR_interface_H
#define _LDR_interface_H


/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

#define DARK 		3500

#define VERY_DIM	3000

#define MODERATE	2000

#define OVERCAST	1500

#define VERY_BRIGHT	1000

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void HLDR_vInit( void ) ;

u16_t HLDR_u16DigitalOutputValue( void ) ;


#endif //_LDR_interface_H
