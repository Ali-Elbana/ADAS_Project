/* FILENAME: ADC_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 12/14/2022
*/

/************************************************************************/
/*                         Include headers                           	*/
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../RCC/MRCC_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


// Global ISR pointer to function.
void ( *MADC_vpPointerToFunction ) (void) = NULL ;


/************************************************************************/
/*                     Functions  implementations                      	*/
/************************************************************************/

void MADC_vInit( void )
{

	// EN CLK on APB2 bus to be able to operate ADC peripheral:
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_ADC1EN ) ;

	// EN/DIS power for ADC to be turned on/off:
	#if ADC_ON == ENABLE

	SET_BIT( ADC->CR2, ADON ) ;

	#elif ADC_ON == DISABLE

	CLR_BIT( ADC->CR2, ADON ) ;

	#endif

	// Select ADC prescalers(2/4/6/8):
	#if ADC_PRESCALER == DIV_BY_2

	CLR_BIT( ADC->CCR, ADCPRE0 ) ;
	CLR_BIT( ADC->CCR, ADCPRE0 ) ;

	#elif ADC_PRESCALER == DIV_BY_4

	SET_BIT( ADC->CCR, ADCPRE0 ) ;
	CLR_BIT( ADC->CCR, ADCPRE0 ) ;

	#elif ADC_PRESCALER == DIV_BY_6

	CLR_BIT( ADC->CCR, ADCPRE0 ) ;
	SET_BIT( ADC->CCR, ADCPRE0 ) ;

	#elif ADC_PRESCALER == DIV_BY_8

	SET_BIT( ADC->CCR, ADCPRE0 ) ;
	SET_BIT( ADC->CCR, ADCPRE0 ) ;

	#endif


	// Select ADC Resolution(12/10/8/6):
	#if RESOLUTION == _12_BITS

	CLR_BIT( ADC->CR1, RES0 ) ;
	CLR_BIT( ADC->CR1, RES1 ) ;

	#elif RESOLUTION == _10_BITS

	SET_BIT( ADC->CR1, RES0 ) ;
	CLR_BIT( ADC->CR1, RES1 ) ;

	#elif RESOLUTION == _8_BITS

	CLR_BIT( ADC->CR1, RES0 ) ;
	SET_BIT( ADC->CR1, RES1 ) ;

	#elif RESOLUTION == _6_BITS

	SET_BIT( ADC->CR1, RES0 ) ;
	SET_BIT( ADC->CR1, RES1 ) ;

	#endif


	// ADC Data Alignment(Right/Left):
	#if DATA_ALIGN == RIGHT

	CLR_BIT( ADC->CR2, ALIGN ) ;

	#elif DATA_ALIGN == LEFT

	SET_BIT( ADC->CR2, ALIGN ) ;

	#endif


	// EN/DIS Injected INT:
	#if JEOCIE_MODE == ENABLE

	SET_BIT( ADC->CR1, JEOCIE ) ;

	#elif JEOCIE_MODE == DISABLE

	CLR_BIT( ADC->CR1, JEOCIE ) ;

	#endif

	// EN/DIS Regular INT:
	#if EOCIE_MODE == ENABLE

	SET_BIT( ADC->CR1, EOCIE ) ;

	#elif EOCIE_MODE == DISABLE

	CLR_BIT( ADC->CR1, EOCIE ) ;

	#endif

	// EN/DIS Overrun interrupt:
	#if OVERRUN_INT == ENABLE

	SET_BIT( ADC->CR1, OVRIE ) ;

	#elif OVERRUN_INT == DISABLE

	CLR_BIT( ADC->CR1, OVRIE ) ;

	#endif

	// Select Regular channel sequence length(1/2/3/.../16):
	#if REG_SQ_LENGTH == _1_CONV

	CLR_BIT( ADC->SQR1, L0 ) ;
	CLR_BIT( ADC->SQR1, L1 ) ;
	CLR_BIT( ADC->SQR1, L2 ) ;
	CLR_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _2_CONV

	SET_BIT( ADC->SQR1, L0 ) ;
	CLR_BIT( ADC->SQR1, L1 ) ;
	CLR_BIT( ADC->SQR1, L2 ) ;
	CLR_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _3_CONV

	CLR_BIT( ADC->SQR1, L0 ) ;
	SET_BIT( ADC->SQR1, L1 ) ;
	CLR_BIT( ADC->SQR1, L2 ) ;
	CLR_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _4_CONV

	SET_BIT( ADC->SQR1, L0 ) ;
	SET_BIT( ADC->SQR1, L1 ) ;
	CLR_BIT( ADC->SQR1, L2 ) ;
	CLR_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _5_CONV

	CLR_BIT( ADC->SQR1, L0 ) ;
	CLR_BIT( ADC->SQR1, L1 ) ;
	SET_BIT( ADC->SQR1, L2 ) ;
	CLR_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _6_CONV

	SET_BIT( ADC->SQR1, L0 ) ;
	CLR_BIT( ADC->SQR1, L1 ) ;
	SET_BIT( ADC->SQR1, L2 ) ;
	CLR_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _7_CONV

	CLR_BIT( ADC->SQR1, L0 ) ;
	SET_BIT( ADC->SQR1, L1 ) ;
	SET_BIT( ADC->SQR1, L2 ) ;
	CLR_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _8_CONV

	SET_BIT( ADC->SQR1, L0 ) ;
	SET_BIT( ADC->SQR1, L1 ) ;
	SET_BIT( ADC->SQR1, L2 ) ;
	CLR_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _9_CONV

	CLR_BIT( ADC->SQR1, L0 ) ;
	CLR_BIT( ADC->SQR1, L1 ) ;
	CLR_BIT( ADC->SQR1, L2 ) ;
	SET_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _10_CONV

	SET_BIT( ADC->SQR1, L0 ) ;
	CLR_BIT( ADC->SQR1, L1 ) ;
	CLR_BIT( ADC->SQR1, L2 ) ;
	SET_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _11_CONV

	CLR_BIT( ADC->SQR1, L0 ) ;
	SET_BIT( ADC->SQR1, L1 ) ;
	CLR_BIT( ADC->SQR1, L2 ) ;
	SET_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _12_CONV

	SET_BIT( ADC->SQR1, L0 ) ;
	SET_BIT( ADC->SQR1, L1 ) ;
	CLR_BIT( ADC->SQR1, L2 ) ;
	SET_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _13_CONV

	CLR_BIT( ADC->SQR1, L0 ) ;
	CLR_BIT( ADC->SQR1, L1 ) ;
	SET_BIT( ADC->SQR1, L2 ) ;
	SET_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _14_CONV

	SET_BIT( ADC->SQR1, L0 ) ;
	CLR_BIT( ADC->SQR1, L1 ) ;
	SET_BIT( ADC->SQR1, L2 ) ;
	SET_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _15_CONV

	CLR_BIT( ADC->SQR1, L0 ) ;
	SET_BIT( ADC->SQR1, L1 ) ;
	SET_BIT( ADC->SQR1, L2 ) ;
	SET_BIT( ADC->SQR1, L3 ) ;

	#elif REG_SQ_LENGTH == _16_CONV

	SET_BIT( ADC->SQR1, L0 ) ;
	SET_BIT( ADC->SQR1, L1 ) ;
	SET_BIT( ADC->SQR1, L2 ) ;
	SET_BIT( ADC->SQR1, L3 ) ;

	#endif

	// EN/DIS SCAN MODE:
	#if SCAN_MODE == ENABLE

	SET_BIT( ADC->CR1, SCAN ) ;

	#elif SCAN_MODE == DISABLE

	CLR_BIT( ADC->CR1, SCAN ) ;

	#endif

	// EN/DIS Discontinuous mode on Regular:
	#if DISC_MODE == ENABLE

	SET_BIT( ADC->CR1, DISCEN ) ;

	#elif DISC_MODE == DISABLE

	CLR_BIT( ADC->CR1, DISCEN ) ;

	#endif

	// Discontinuous mode channel count(1/2/3/4/.../8):
	#if DISC_CHANNEL_NUM == _1_CHANNEL

	CLR_BIT( ADC->CR1, DISCNUM0 ) ;
	CLR_BIT( ADC->CR1, DISCNUM1 ) ;
	CLR_BIT( ADC->CR1, DISCNUM2 ) ;

	#elif DISC_CHANNEL_NUM == _2_CHANNELS

	SET_BIT( ADC->CR1, DISCNUM0 ) ;
	CLR_BIT( ADC->CR1, DISCNUM1 ) ;
	CLR_BIT( ADC->CR1, DISCNUM2 ) ;

	#elif DISC_CHANNEL_NUM == _3_CHANNELS

	CLR_BIT( ADC->CR1, DISCNUM0 ) ;
	SET_BIT( ADC->CR1, DISCNUM1 ) ;
	CLR_BIT( ADC->CR1, DISCNUM2 ) ;

	#elif DISC_CHANNEL_NUM == _4_CHANNELS

	SET_BIT( ADC->CR1, DISCNUM0 ) ;
	SET_BIT( ADC->CR1, DISCNUM1 ) ;
	CLR_BIT( ADC->CR1, DISCNUM2 ) ;

	#elif DISC_CHANNEL_NUM == _5_CHANNELS

	CLR_BIT( ADC->CR1, DISCNUM0 ) ;
	CLR_BIT( ADC->CR1, DISCNUM1 ) ;
	SET_BIT( ADC->CR1, DISCNUM2 ) ;

	#elif DISC_CHANNEL_NUM == _6_CHANNELS

	SET_BIT( ADC->CR1, DISCNUM0 ) ;
	CLR_BIT( ADC->CR1, DISCNUM1 ) ;
	SET_BIT( ADC->CR1, DISCNUM2 ) ;

	#elif DISC_CHANNEL_NUM == _7_CHANNELS

	CLR_BIT( ADC->CR1, DISCNUM0 ) ;
	SET_BIT( ADC->CR1, DISCNUM1 ) ;
	SET_BIT( ADC->CR1, DISCNUM2 ) ;

	#elif DISC_CHANNEL_NUM == _8_CHANNELS

	SET_BIT( ADC->CR1, DISCNUM0 ) ;
	SET_BIT( ADC->CR1, DISCNUM1 ) ;
	SET_BIT( ADC->CR1, DISCNUM2 ) ;


	#endif

	// EN/DIS Continuous mode:
	#if CONT_CONV == ENABLE

	SET_BIT( ADC->CR2, CONT ) ;

	#elif CONT_CONV == DISABLE

	CLR_BIT( ADC->CR2, CONT ) ;

	#endif

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MADC_vSelectChannel( u8_t A_u8ChannelNum )
{

	// Select Regular channel(1/2/3/.../16)
	ADC->SQR3 = (ADC->SQR3 & SQ1_BIT_MANIPULATION) | ( A_u8ChannelNum ) ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

u16_t MADC_u16ConvertToDigital( u8_t A_u8ChannelNum )
{

	// Select Regular channel(1/2/3/.../16)
	ADC->SQR3 = (ADC->SQR3 & SQ1_BIT_MANIPULATION) | ( A_u8ChannelNum ) ;

	// Start conversion of regular channels:
	SET_BIT( ADC->CR2, SWSTART ) ;

	// Poll on the end of coversion flag until it's raised:
	while( GET_BIT(ADC->SR, EOC) != FLAG_SET ) ;

	// Clear the flag:
	CLR_BIT( ADC->SR, EOC ) ;

	// Return ADC Data:
	return ADC->DR ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MADC_vDisable( void )
{

	// DIS CLK on APB2 bus to be able to operate ADC peripheral:
	MRCC_vDisablePeriphralCLK( RCC_APB2, APB2ENR_ADC1EN ) ;

	// Power off ADC:
	CLR_BIT( ADC->CR2, ADON ) ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MADC_vEnable( void )
{

	// EN CLK on APB2 bus to be able to operate ADC peripheral:
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_ADC1EN ) ;

	// Power on ADC:
	SET_BIT( ADC->CR2, ADON ) ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MADC_vRegINT_Disable( void )
{
	CLR_BIT( ADC->CR1, EOCIE ) ;
}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MADC_vRegINTEnable( void )
{
	SET_BIT( ADC->CR1, EOCIE ) ;
}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MADC_vSetCallBack( void (*MEXTI_vpPointerTo_ISR_function) (void) )
{

	if( MEXTI_vpPointerTo_ISR_function != NULL )
	{

		MADC_vpPointerToFunction = MEXTI_vpPointerTo_ISR_function ;

	}

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void ADC_IRQHandler(void)
{

	if( MADC_vpPointerToFunction != NULL )
	{
		MADC_vpPointerToFunction() ;
	}

	// Clear the flags.
	CLR_BIT( ADC->SR, EOC ) ;
	CLR_BIT( ADC->SR, JEOC ) ;
}












