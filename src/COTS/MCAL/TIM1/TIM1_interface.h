/* FILENAME: TIM1_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 01/24/2023
*/
#ifndef _TIM1_interface_H
#define _TIM1_interface_H

/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void MTIM1_vInit( void ) ;

void MTIM1_vSetCounterValue( u16_t A_u16CNT_Value ) ;

void MTIM1_vSetPrescalerValue( u16_t A_u16PSC_Value ) ;

void MTIM1_vSetAutoReloadValue( u16_t A_u16ARR_Value ) ;

void MTIM1_vSetRepetitionValue( u16_t A_u16RCR_Value ) ;

void MTIM1_vSetCompareReg1Value( u16_t A_u16CCR1_Value ) ;

u16_t MTIM1_vGetCaptureReg1Value( void ) ;

void MTIM1_vSetCompareReg2Value( u16_t A_u16CCR2_Value ) ;

u16_t MTIM1_vGetCaptureReg2Value( void ) ;

void MTIM1_vSetCompareReg3Value( u16_t A_u16CCR3_Value ) ;

u16_t MTIM1_vGetCaptureReg3Value( void ) ;

void MTIM1_vSetCompareReg4Value( u16_t A_u16CCR4_Value ) ;

u16_t MTIM1_vGetCaptureReg4Value( void ) ;




#endif //_TIM1_interface_H
