

/************************************************************************/
/*                         Include headers                           	*/
/************************************************************************/

#include "COTS/LIB/LSTD_TYPES.h"
#include "COTS/LIB/LSTD_COMPILER.h"
#include "COTS/LIB/LSTD_VALUES.h"
#include "COTS/LIB/LSTD_BITMATH.h"

#include "COTS/MCAL/RCC/MRCC_interface.h"
#include "COTS/MCAL/GPIO/GPIO_interface.h"

#include "Drivers_Testing_Scripts/Testing_MCAL/Testing_GPIO/Testing_GPIO_interface.h"


/************************************************************************/
/*              	Testing Scripts Software Switches                   */
/************************************************************************/

#define TestingGPIO_Output RUN

#define TestingGPIO_Input  STOP

/************************************************************************/
/*                          Application                        		   	*/
/************************************************************************/

int main(void)
{


	#if TestingGPIO_Output == RUN

	TMGPIO_vOutputPins( ) ;

	#endif

	#if TestingGPIO_Input == RUN

	TMGPIO_vInputPins( ) ;

	#endif


	while(TRUE) ;

}









