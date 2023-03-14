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

void MTIM1_vSetRepetitionValue( u8_t A_u8RCR_Value ) ;

void MTIM1_vSetCompareReg1Value( u16_t A_u16CCR1_Value ) ;

u16_t MTIM1_u16GetCaptureReg1Value( void ) ;

void MTIM1_vSetCompareReg2Value( u16_t A_u16CCR2_Value ) ;

u16_t MTIM1_u16GetCaptureReg2Value( void ) ;

void MTIM1_vSetCompareReg3Value( u16_t A_u16CCR3_Value ) ;

u16_t MTIM1_u16GetCaptureReg3Value( void ) ;

void MTIM1_vSetCompareReg4Value( u16_t A_u16CCR4_Value ) ;

u16_t MTIM1_u16GetCaptureReg4Value( void ) ;

void MTIM1_vGeneratePWM( u8_t A_u8T1CHx, u8_t A_u8PWM_Mode, u8_t A_u8CenterMode,
					u16_t A_u16PSC_Value, u16_t A_u16ARR_Value, u16_t A_u16CCRx_Value ) ;

void MTIM1_vReadPWM( void ) ;

void MTIM1_vEnableCounter( void ) ;

void MTIM1_vDisableCounter( void ) ;

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

#define T1CHx_PORT 				GPIO_PORTA
#define T1CH1_PIN				GPIOx_PIN8
#define T1CH2_PIN				GPIOx_PIN9
#define T1CH3_PIN				GPIOx_PIN10
#define T1CH4_PIN				GPIOx_PIN11

#define PSC_VALUE              	7
#define ARR_VALUE              	4000
#define CR_VALUE              	0

#define TIM1_CH1 1
#define TIM1_CH2 2
#define TIM1_CH3 3
#define TIM1_CH4 4

#define  FROZEN             	1
#define  OC1REF_HIGH         	2
#define  OC1REF_LOW          	3
#define  OC1REF_TOGGLE       	4
#define  OC1REF_FORCED_LOW   	5
#define  OC1REF_FORCED_HIGH  	6
#define  PWM1                	7
#define  PWM2                	8

#define EDGE                    1
#define CENTER1                 2
#define CENTER2                 3
#define CENTER3                 4


#endif //_TIM1_interface_H
