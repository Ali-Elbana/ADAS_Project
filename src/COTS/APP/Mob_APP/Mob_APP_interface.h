/* FILENAME: Mob_APP_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sun 03/26/2023
*/
#ifndef _Mob_APP_interface_H
#define _Mob_APP_interface_H


#define DECIMAL 	10
#define SPEED0_STR 	"*S0*"

#define TRAD_MODE_CHAR 	'T'
#define NCC_MODE_CHAR 	'N'
#define ACC_MODE_CHAR 	'A'
#define FCW_MODE_CHAR 	'F'
#define EXIT_SYS_CHAR 	'E'

#define FORW_CHAR 		'f'
#define BACKW_CHAR 		'b'
#define RIGHT_CHAR 		'r'
#define LEFT_CHAR 		'l'
#define STOP_CHAR 		's'
#define EXIT_MODE_CHAR 	'e'
#define INC_SPEED_CHAR	'+'
#define DEC_SPEED_CHAR	'-'

#define HYSTRS_VALUE	3

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void AMobApp_vInit( void ) ;

void AMobApp_vSendSpeedValue( u32_t A_u32SpeedValue ) ;

void AMobApp_vCntrlCar( void ) ;



#endif //_Mob_APP_interface_H
