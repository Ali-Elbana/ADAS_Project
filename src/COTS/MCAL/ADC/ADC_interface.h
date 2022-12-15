/* FILENAME: ADC_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 12/14/2022
*/
#ifndef _ADC_interface_H
#define _ADC_interface_H










typedef struct
{


	u8_t Port ;




} MADC_ConfigType ;


/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/


void MADC_vInit( void ) ;

u16_t MADC_u16ConvertToDigital( VAR(u8_t) A_u8ChannelNum ) ;

void MADC_vDisable( void ) ;

void MADC_vEnable( void ) ;

void MADC_vRegINT_Disable( void ) ;

void MADC_vRegINTEnable( void ) ;

void MADC_vSelectMode( VAR(u8_t) A_u8ModeNum ) ;

void MADC_vSelectChannel( VAR(u8_t) A_u8ChannelNum ) ;

void MADC_vStartConversion( VAR(u8_t) A_u8ChannelNum ) ;

void MADC_vSelectChannelsOrder( VAR(u8_t) A_u8ChannelOrder ) ;

void MADC_vSelectSampleTime( VAR(u8_t) A_u8ChannelNum, VAR(u8_t) A_u8SampleTime ) ;

void MADC_vSelectResolution( VAR(u8_t) A_u8Resolution ) ;

u16_t MADC_u16GetADCData( void ) ;

void MADC_vInitStruct( P2VAR(MADC_ConfigType) A_ADCConfig ) ;

void MADC_vSetCallBack( void (*MEXTI_vpPointerTo_ISR_function) (void) ) ;



/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

#define CHANNEL0 	0
#define CHANNEL1 	1
#define CHANNEL2 	2
#define CHANNEL3 	3
#define CHANNEL4 	4
#define CHANNEL5 	5
#define CHANNEL6 	6
#define CHANNEL7 	7
#define CHANNEL8 	8
#define CHANNEL9 	9
#define CHANNEL10 	10
#define CHANNEL11 	11
#define CHANNEL12 	12
#define CHANNEL13 	13
#define CHANNEL14 	14
#define CHANNEL15 	15
#define CHANNEL16	16
#define CHANNEL17 	17
#define CHANNEL18 	18










#endif //_ADC_interface_H
