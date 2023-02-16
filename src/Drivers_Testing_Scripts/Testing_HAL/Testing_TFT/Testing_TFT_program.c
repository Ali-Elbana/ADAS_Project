/* FILENAME: Testing_TFT_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Fri 01/20/2023
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

#include "../../../COTS/HAL/TFT/TFT_interface.h"

#include "../../../Images/MyImage.h"
#include "../../../Images/MyCat.h"
#include "../../../Images/MyDad.h"

#include "Testing_TFT_interface.h"
#include "Testing_TFT_private.h"
#include "Testing_TFT_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void THTFT_vDispImage( void )
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_vLockedPins() ;

	HTFT_vInit( ) ;

	HTFT_vShowImage( Dad_Image, sizeof(Image) / sizeof(Image[0]) ) ;

	while( TRUE )
	{

	}

}

/**************************************************************************************/
/**************************************************************************************/




