/* FILENAME: Testing_LCD_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 12/23/2022
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../../COTS/LIB/LSTD_TYPES.h"
#include "../../../COTS/LIB/LSTD_COMPILER.h"
#include "../../../COTS/LIB/LSTD_VALUES.h"
#include "../../../COTS/LIB/LSTD_BITMATH.h"

#include "../../../COTS/MCAL/RCC/MRCC_interface.h"
#include "../../../COTS/MCAL/GPIO/GPIO_interface.h"

#include "../../../COTS/HAL/LCD/LCD_interface.h"

#include "Testing_LCD_interface.h"
#include "Testing_LCD_private.h"
#include "Testing_LCD_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THLCD_vPrintString( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vLockedPins() ;

	HLCD_vInit() ;

	HLCD_vClear( ) ;

	HLCD_vDispString( " ADAS Project " ) ;

	while( TRUE )
	{

	}


}

/**************************************************************************************/
/**************************************************************************************/



