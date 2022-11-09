

/************************************************************************/
/*                         Include headers                           	*/
/************************************************************************/

#include "COTS/LIB/LSTD_TYPES.h"
#include "COTS/LIB/LSTD_COMPILER.h"
#include "COTS/LIB/LSTD_VALUES.h"
#include "COTS/LIB/LSTD_BITMATH.h"

#include "COTS/MCAL/RCC/MRCC_interface.h"
#include "COTS/MCAL/GPIO/GPIO_interface.h"


/************************************************************************/
/*                          Application                        		   	*/
/************************************************************************/

int main(void)
{

	MRCC_vInit( ) ;

	MRCC_vEnablePeriphralCLK( RCC_AHB1, AHB1ENR_GPIOAEN ) ;

	MGPIOx_ConfigType LED =
	{

			.Port 			= GPIO_PORTA 		,

			.Pin 			= GPIOx_PIN1 		,

			.Mode 			= GPIOx_MODE_OUTPUT ,

			.OutputType 	= GPIOx_PUSHPULL 	,

			.OutputSpeed 	= GPIOx_LowSpeed 	,

			.InputType 		= GPIOx_NoPull

	} ;


	MGPIOx_vInit( &LED ) ;

	MGPIOx_vSetPinValue( LED.Port, LED.Pin, GPIOx_HIGH ) ;

	while( TRUE )
	{

		for( VAR( u32_t) i = INITIAL_ZERO; i < 250000; i++ ) ;

		MGPIOx_vTogglePinValue( LED.Port, LED.Pin ) ;

		for( VAR( u32_t) i = INITIAL_ZERO; i < 250000; i++ ) ;

	}

}









