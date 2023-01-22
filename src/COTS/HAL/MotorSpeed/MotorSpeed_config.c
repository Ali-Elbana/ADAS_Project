/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"

#include "../../MCAL/GPIO/GPIO_interface.h"

#include "MotorSpeed_interface.h"
#include "MotorSpeed_config.h"

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

VAR(MGPIOx_ConfigType) MotorSpeedPinLayout =
{
    .Port 			= HMOTORSPEED_PORT,
    .Pin   			= HMOTORSPEED_PIN,
    .Mode      		= GPIOx_MODE_INPUT,
    .OutputType 	= GPIOx_PUSHPULL,
    .OutputSpeed 	= GPIOx_LowSpeed,
    .InputType 		= GPIOx_PullUp
};