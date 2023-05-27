/*
 * LCD_programme.c
 *
 *  Created on: Sep 11, 2021
 *      Author: Ali El Bana
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
#include "../../MCAL/SysTick/SysTick_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"


/************************************************************************/
/*                     Functions implementations                      	*/
/************************************************************************/

void HLCD_vInit(void)
{

	MSysTick_vInit( ) ;

	MSysTick_vDelayMilliSec( 1000 ) ;

	// Set your pin directions:
	MGPIOx_ConfigType RS =
	{

		.Port 		= HLCD_CTRL_PORT, .Pin = HLCD_RS_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType RW =
	{

		.Port 		= HLCD_CTRL_PORT, .Pin = HLCD_RW_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType EN =
	{

		.Port 		= HLCD_CTRL_PORT, .Pin = HLCD_EN_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D0 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D0_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D1 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D1_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D2 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D2_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D3 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D3_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D4 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D4_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D5 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D5_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D6 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D6_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_ConfigType D7 =
	{

		.Port 		= HLCD_DATA_PORT, .Pin = D7_PIN, .Mode = GPIOx_MODE_OUTPUT, .OutputType = GPIOx_PUSHPULL, .OutputSpeed = GPIOx_LowSpeed,
		.InputType 	= GPIOx_NoPull

	} ;

	MGPIOx_vInit( &RS ) ;
	MGPIOx_vInit( &RW ) ;
	MGPIOx_vInit( &EN ) ;
	MGPIOx_vInit( &D0 ) ;
	MGPIOx_vInit( &D1 ) ;
	MGPIOx_vInit( &D2 ) ;
	MGPIOx_vInit( &D3 ) ;
	MGPIOx_vInit( &D4 ) ;
	MGPIOx_vInit( &D5 ) ;
	MGPIOx_vInit( &D6 ) ;
	MGPIOx_vInit( &D7 ) ;

	// Start initialization sequence.
	MSysTick_vDelayMilliSec( 50 ) ;

	HLCD_vSendCommand( HLCD_FuctionSet_Cmd ) 	;

	MSysTick_vDelayMilliSec( 1 ) ;

	HLCD_vSendCommand( HLCD_DispOnOffCTRL_Cmd ) ;

	MSysTick_vDelayMilliSec( 1 ) ;

	HLCD_vSendCommand( HLCD_DispClear_Cmd ) 	;

	MSysTick_vDelayMilliSec( 3 ) ;

	HLCD_vSendCommand( HLCD_EntryModeSet_Cmd ) 	;

	MSysTick_vDelayMilliSec( 1 ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vSendCommand( u8_t A_u8Cmd )
{

	// Set RS pin low to send a command.
	MGPIOx_vSetPinValue( HLCD_CTRL_PORT, HLCD_RS_PIN, GPIOx_LOW ) ;

	// Set RW pin low to write the command.
	MGPIOx_vSetPinValue( HLCD_CTRL_PORT, HLCD_RW_PIN, GPIOx_LOW ) ;

	MSysTick_vDelayMilliSec( 1 ) ;

	// Put the command on the data bus.
	GPIO_vSetNibbleLowValue( HLCD_DATA_PORT, A_u8Cmd ) ;

	MSysTick_vDelayMilliSec( 1 ) ;

	// Set the enable pin high.
	MGPIOx_vSetPinValue( HLCD_CTRL_PORT, HLCD_EN_PIN, GPIOx_HIGH ) ;

	MSysTick_vDelayMilliSec( 1 ) ;

	// Set the enable pin low.
	MGPIOx_vSetPinValue( HLCD_CTRL_PORT, HLCD_EN_PIN, GPIOx_LOW ) ;

	MSysTick_vDelayMilliSec( 1 ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vSendData(u8_t A_u8Data)
{

	// Set RS pin high to send data.
	MGPIOx_vSetPinValue( HLCD_CTRL_PORT, HLCD_RS_PIN, GPIOx_HIGH ) ;

	// Set RW pin low to write the data.
	MGPIOx_vSetPinValue( HLCD_CTRL_PORT, HLCD_RW_PIN, GPIOx_LOW ) ;

	MSysTick_vDelayMilliSec( 1 ) ;

	// Put the data on the data bus.
	GPIO_vSetNibbleLowValue( HLCD_DATA_PORT, A_u8Data ) ;

	MSysTick_vDelayMilliSec( 1 ) ;

	// Set the enable pin high.
	MGPIOx_vSetPinValue( HLCD_CTRL_PORT, HLCD_EN_PIN, GPIOx_HIGH ) ;

	MSysTick_vDelayMilliSec( 1 ) ;

	// Set the enable pin low.
	MGPIOx_vSetPinValue( HLCD_CTRL_PORT, HLCD_EN_PIN, GPIOx_LOW) ;

	MSysTick_vDelayMilliSec( 1 ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vClear(void)
{

	MSysTick_vDelayMilliSec( 1 ) ;

	HLCD_vSendCommand( HLCD_DispClear_Cmd ) ;

	MSysTick_vDelayMilliSec( 1 ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vDispString( c8_t * A_c8Char )
{

	for( VAR(u8_t) L_u8I = 0 ; A_c8Char[L_u8I] != '\0' ; L_u8I++ )
	{

		HLCD_vSendData( A_c8Char[L_u8I] ) ;

	}

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vDispNumber( VAR(s32_t) A_s32Num )
{

	VAR(u8_t) L_u8Counter 		=  	0  	;

	VAR(u8_t) LR_u8Digits[10] 	= 	{0} ;

	// In case the number is signed.
	if ( A_s32Num < 0 )
	{

		HLCD_vSendData( '-' ) ;

		A_s32Num = A_s32Num * ( -1 ) ;

	}

	// In case the number the number contains zeros.
	if( A_s32Num == 0 )
	{
		HLCD_vSendData( '0' ) ;

	}

	// Save reversed digits in the array.
	for( L_u8Counter = 0 ; A_s32Num != 0 ; L_u8Counter++ )
	{

		LR_u8Digits[L_u8Counter] = A_s32Num % 10 ;

		A_s32Num /= 10 ;

	}

	// For arrangement the digits.
	for (VAR(s8_t) L_s8ArrangedNums = (L_u8Counter - 1); L_s8ArrangedNums >= 0; L_s8ArrangedNums--)
	{

		HLCD_vSendData( '0' + LR_u8Digits[ L_s8ArrangedNums ] ) ;

	}

}

/**************************************************************************************************************/
/*************************************************************************************************************/

// void HLCD_vDispNum(s32 A_s32Num)
//{
//
//
//	VAR(u32_t) L_u32Rev = 0 ;
//
//	while( A_s32Num >0 )
//	{
//
//		L_u32Rev = L_u32Rev*10 + (A_s32Num % 10) ;
//
//		A_s32Num /= 10 ;
//
//	}
//
//
//	while( L_u32Rev >0 )
//	{
//
//		HLCD_vSendData( (L_u32Rev % 10) + '0' ) ; // Convert from integer to char.
//
//		L_u32Rev /= 10 ;
//
//	}
//
//
//
//
// }

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vSaveCustomChar( u8_t A_u8Address, u8_t * A_u8CustomChar )
{

	// 1-Set CGRAM Address.
	HLCD_vSendCommand( SET_CGRAM_AC_MASK + (NumOf_CGRAM_Patterns * A_u8Address) ) ;

	// 2- Send custom char data.
	for( u8_t L_u8I = FirstByteInCGRAM_Pattern ; L_u8I < LastByteInCGRAM_Pattern ; L_u8I++ )
	{

		HLCD_vSendData( A_u8CustomChar[L_u8I] ) ;

	}

	// 3-Set DDRAM address
	HLCD_vSendCommand( SET_DDRAM_AC_MASK ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vGoTo( u8_t A_u8Row, u8_t A_u8Col )
{

	// Valid Range.
	if ( (A_u8Row <= MAX_IDX_OF_ROWS) && (A_u8Col <= MAX_IDX_OF_COL) )
	{

		switch( A_u8Row )
		{

			case 0:	HLCD_vSendCommand( SET_DDRAM_AC_MASK + A_u8Col + FIRST_ROW_START ) ; break;

			case 1: HLCD_vSendCommand( SET_DDRAM_AC_MASK + A_u8Col + SEC_ROW_START 	 ) ; break;

		}

	}

	else
	{

		// Do Nothing
	}

}

/**************************************************************************************************************/
/*************************************************************************************************************/


void HLCD_vSetShiftLeftOn(void)
{

	MSysTick_vDelayMilliSec( 500 ) ;

	HLCD_vSendCommand( HLCD_EntryModeSet_ShiftLeftOn_Cmd ) ;

	MSysTick_vDelayMilliSec( 500 ) ;

}


/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vSetDispOFF(void)
{

	MSysTick_vDelayMilliSec( 500 ) ;

	HLCD_vSendCommand( HLCD_DispOff_Cmd ) ;

	MSysTick_vDelayMilliSec( 500 ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/


void HLCD_vDispCursorWithBlinking(void)
{

	MSysTick_vDelayMilliSec( 500 ) ;

	HLCD_vSendCommand( HLCD_DispCursorWithBlinking_Cmd ) ;

	MSysTick_vDelayMilliSec( 500 ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vSetCursorBlinkingOFF(void)
{

	MSysTick_vDelayMilliSec( 500 ) ;

	HLCD_vSendCommand( HLCD_SetCursorBlinkingOFF_Cmd ) ;

	MSysTick_vDelayMilliSec( 500 ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vDispShiftLeftString( c8_t * A_c8Char )
{

	VAR(u8_t) L_u8I = 0 ;

	for( L_u8I = 0 ; A_c8Char[L_u8I] != '\0' ; L_u8I++ )
	{

		HLCD_vSendData( A_c8Char[L_u8I] ) ;

	}

	MSysTick_vDelayMilliSec( 500 ) ;

	if( L_u8I > HLCD_CharactersNums )
	{

		for( u8_t i = 0 ; i < L_u8I - HLCD_CharactersNums ; i++ )
		{

			HLCD_vSetShiftLeftOn() ;

		}

	}

}

/**************************************************************************************************************/
/*************************************************************************************************************/

void HLCD_vClearChar( u8_t A_u8Row, u8_t A_u8Col )
{

	HLCD_vGoTo( A_u8Row, A_u8Col ) ;

	HLCD_vSendData( ' ' ) ;

}

/**************************************************************************************************************/
/*************************************************************************************************************/









