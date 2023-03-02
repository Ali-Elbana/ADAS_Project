/*
 * LCD_config.h
 *
 *  Created on: Sep 11, 2021
 *      Author: Ali El Bana
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

#include "LCD_private.h"



#define HLCD_CTRL_PORT 	GPIO_PORTB

#define HLCD_RS_PIN   	GPIOx_PIN12
#define HLCD_RW_PIN 	GPIOx_PIN13
#define HLCD_EN_PIN 	GPIOx_PIN14


#define HLCD_DATA_PORT	GPIO_PORTA

#define D0_PIN GPIOx_PIN0
#define D1_PIN GPIOx_PIN1
#define D2_PIN GPIOx_PIN2
#define D3_PIN GPIOx_PIN3
#define D4_PIN GPIOx_PIN4
#define D5_PIN GPIOx_PIN5
#define D6_PIN GPIOx_PIN6
#define D7_PIN GPIOx_PIN7


#define HLCD_FuctionSet_Cmd 				FuctionSetCmd

#define HLCD_DispOnOffCTRL_Cmd 				DispOnOffCTRLCmd

#define HLCD_DispOff_Cmd					DispOffCmd

#define HLCD_DispCursorWithBlinking_Cmd 	DispCursorWithBlinkingCmd

#define HLCD_SetCursorBlinkingOFF_Cmd 		SetCursorBlinkingOFFCmd

#define HLCD_DispClear_Cmd  				DispClearCmd

#define HLCD_EntryModeSet_Cmd				EntryModeSet_Cmd

#define HLCD_EntryModeSet_ShiftLeftOn_Cmd	EntryModeSet_ShiftLeftOn_Cmd


#define HLCD_CharactersNums 	16


#define FIRST_ROW_IDX   			0

#define FIRST_ROW_START 			0x00

#define SEC_ROW_START   			0x40

#define SET_DDRAM_AC_MASK   		0x80

#define SET_CGRAM_AC_MASK			0x40

#define NumOf_CGRAM_Patterns 		8

#define FirstByteInCGRAM_Pattern	0

#define LastByteInCGRAM_Pattern		8




#endif /* LCD_LCD_CONFIG_H_ */
