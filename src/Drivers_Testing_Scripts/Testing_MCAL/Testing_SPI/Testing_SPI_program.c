/* FILENAME: Testing_SPI_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Sun 01/15/2023
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
#include "../../../COTS/MCAL/SysTick/SysTick_interface.h"
#include "../../../COTS/MCAL/SPI/SPI_interface.h"

#include "Testing_SPI_interface.h"
#include "Testing_SPI_private.h"
#include "Testing_SPI_config.h"

/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void TMSPI_vSendChar( void )
{

	u16_t L_u16Mychar = INITIAL_ZERO ;

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOBEN  ) ;
	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN  ) ;

	MGPIOx_vLockedPins() ;

	MGPIOx_ConfigType LED =
	{
		.Port 			= GPIO_PORTA		, .Pin 		 	= GPIOx_PIN10	 ,
		.Mode 		 	= GPIOx_MODE_OUTPUT	, .OutputType	= GPIOx_PUSHPULL ,
		.OutputSpeed 	= GPIOx_LowSpeed	, .InputType 	= GPIOx_NoPull
	} ;

	MGPIOx_vInit( &LED ) ;

	MGPIOx_vSetResetAtomic( LED.Port, LED.Pin, GPIOx_LOW ) ;

	MSPI_vInit( SPI1, SPIx_MSTR, SPIx_FULL_DUPLEX ) ;

	L_u16Mychar = MSPI_u16Transcieve( SPI1, 'A' ) ;

	if( L_u16Mychar == 'A' )
	{
		MGPIOx_vSetResetAtomic( LED.Port, LED.Pin, GPIOx_HIGH ) ;
	}

	else
	{
		MGPIOx_vSetResetAtomic( LED.Port, LED.Pin, GPIOx_LOW ) ;
	}

	while( TRUE )
	{

	}

}

/******************************************************************/
/******************************************************************/






