/*
 * LCD_interface.h
 *
 *  Created on: Sep 11, 2021
 *      Author: Ali El Bana
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_


/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void HLCD_vInit 					( void ) 		 							;

void HLCD_vSendCommand				( u8_t A_u8Cmd ) 						;

void HLCD_vSendData					( u8_t A_u8Data )						;

void HLCD_vClear					( void )									;

void HLCD_vDispString				( c8_t * A_c8Char )					;

void HLCD_vDispNumber				( VAR(s32_t) A_s32Num )						;

void HLCD_vSaveCustomChar			( u8_t A_u8Address, u8_t * A_u8CustomChar ) 	;

void HLCD_vSaveDispChar				( u8_t A_u8Address, u8_t * A_u8CustomChar ) 	;

void HLCD_vGoTo						( u8_t A_u8Row, u8_t A_u8Col )	;

void HLCD_vSetShiftLeftOn			(void)										;

void HLCD_vSetDispOFF				(void)										;

void HLCD_vDispCursorWithBlinking	(void)										;

void HLCD_vSetCursorBlinkingOFF		(void)									 	;

void HLCD_vDispShiftLeftString		( c8_t * A_c8Char )				 	;

void HLCD_vClearChar				( u8_t A_u8Row, u8_t A_u8Col )	;

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

#define MIN_IDX_OF_ROWS  0

#define MAX_IDX_OF_ROWS  1

#define MIN_IDX_OF_COL   0

#define MAX_IDX_OF_COL   15


#define HLCD_LINE1		0

#define HLCD_LINE2		1


#define HLCD_Square1	0

#define HLCD_Square2	1

#define HLCD_Square3	2

#define HLCD_Square4	3

#define HLCD_Square5	4

#define HLCD_Square6	5

#define HLCD_Square7	6

#define HLCD_Square8	7

#define HLCD_Square9	8

#define HLCD_Square10	9

#define HLCD_Square11	10

#define HLCD_Square12	11

#define HLCD_Square13	12

#define HLCD_Square14	13

#define HLCD_Square15	14

#define HLCD_Square16	15


#define CGRAM_AddressOfPattern0	0

#define CGRAM_AddressOfPattern1	1

#define CGRAM_AddressOfPattern2	2

#define CGRAM_AddressOfPattern3	3

#define CGRAM_AddressOfPattern4	4

#define CGRAM_AddressOfPattern5	5

#define CGRAM_AddressOfPattern7	6

#define CGRAM_AddressOfPattern8	7


















#endif /* LCD_LCD_INTERFACE_H_ */
