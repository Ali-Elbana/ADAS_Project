/* FILENAME: LDR_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 12/22/2022
*/

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../../MCAL/RCC/MRCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

#include "LDR_interface.h"
#include "LDR_private.h"
#include "LDR_config.h"

/************************************************************************/
/*                        Externed variables                        	*/
/************************************************************************/

extern VAR(MGPIOx_ConfigType) LDR_Vo;

extern VAR(u8_t) LDR_CHANNEL;

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

void HLDR_vInit( void )
{

	MGPIOx_vInit( &LDR_Vo ) ;

	MADC_vInit( ) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u16_t HLDR_u16DigitalOutputValue( void )
{

	VAR(u16_t) L_u16DigitalResult = INITIAL_ZERO ;

	L_u16DigitalResult = MADC_u16ConvertToDigital( LDR_CHANNEL ) ;

	return L_u16DigitalResult ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/








