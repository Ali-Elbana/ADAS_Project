/**
 * @file MRCC_program.c
 * @author Ali El Bana & Mo Alaa
 * @brief This file contains the source code of the interfacing for the RCC module
 * @version 2.0
 * @date 11/9/2022
 */



/************************************************************************/
/*                         Include headers                           	*/
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "MRCC_interface.h"
#include "MRCC_private.h"
#include "MRCC_config.h"



/************************************************************************/
/*                     Functions  implementations                      	*/
/************************************************************************/

void MRCC_vInit( void )
{

	// PLLI2S (ON/OFF).
	#if PLLI2S == ENABLE

		SET_BIT( RCC->CR, RCC_CR_PLLI2SON ) ;

	#elif PLLI2S == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_PLLI2SON ) ;

	#endif


	// PLL (ON/OFF).
	#if PLL == ENABLE

		SET_BIT( RCC->CR, RCC_CR_PLLON ) ;

	#elif PLL == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_PLLON ) ;

	#endif


	// CSS (ON/OFF).
	#if CSS == ENABLE

		SET_BIT( RCC->CR, RCC_CR_CSSON ) ;

	#elif CSS == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_CSSON ) ;

	#endif


	// HSEBYP.
	#if HSEBYP == BYBASED

		SET_BIT( RCC->CR, RCC_CR_HSEBYP ) ;

	#elif HSEBYP == NOTBYBASED

		CLR_BIT( RCC->CR, RCC_CR_HSEBYP ) ;

	#endif


	// Select CLK switch (HSI/HSE/PLL).
	#if SW == HSI

		CLR_BIT( RCC->CFGR, RCC_CFGR_SW_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_SW_b1 ) ;

	#elif SW == HSE

		SET_BIT( RCC->CFGR, RCC_CFGR_SW_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_SW_b1 ) ;

	#elif SW == PLLCLK

		CLR_BIT( RCC->CFGR, RCC_CFGR_SW_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_SW_b1 ) ;

	#endif

		// Select CLK switch status (HSI/HSE/PLL).
		#if SWS == HSI

			CLR_BIT( RCC->CFGR, RCC_CFGR_SWS_b0 ) ;
			CLR_BIT( RCC->CFGR, RCC_CFGR_SWS_b1 ) ;

		#elif SWS == HSE

			SET_BIT( RCC->CFGR, RCC_CFGR_SWS_b0 ) ;
			CLR_BIT( RCC->CFGR, RCC_CFGR_SWS_b1 ) ;

		#elif SWS == PLLCLK

			CLR_BIT( RCC->CFGR, RCC_CFGR_SWS_b0 ) ;
			SET_BIT( RCC->CFGR, RCC_CFGR_SWS_b1 ) ;

		#endif


	// MCO2 selection:
	#if MCO2 == SYSCLK

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2_b1 ) ;

	#elif MCO2 == PLLI2SCLK

		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2_b1 ) ;

	#elif MCO2 == HSE

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2_b1 ) ;

	#elif MCO2 == PLLCLK

		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2_b1 ) ;

	#endif


	// MCO2 prescaler:
	#if MCO2PRE == NoDivision

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b1 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b2 ) ;

	#elif MCO2PRE == DivisionBy2

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b2 ) ;

	#elif MCO2PRE == DivisionBy3

		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b2 ) ;

	#elif MCO2PRE == DivisionBy4

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b2 ) ;

	#elif MCO2PRE == DivisionBy5

		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC2PRE_b2 ) ;

	#endif


	// MCO1 selection:
	#if MCO1 == HSI

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1_b1 ) ;

	#elif MCO1 == LSE

		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1_b1 ) ;

	#elif MCO1 == HSE

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1_b1 ) ;

	#elif MCO1 == PLLCLK

		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1_b1 ) ;

	#endif


	// MCO1 prescaler:
	#if MCO1PRE == NoDivision

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b1 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b2 ) ;

	#elif MCO1PRE == DivisionBy2

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b2 ) ;

	#elif MCO1PRE == DivisionBy3

		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b2 ) ;

	#elif MCO1PRE == DivisionBy4

		CLR_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b2 ) ;

	#elif MCO1PRE == DivisionBy5

		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_MOC1PRE_b2 ) ;

	#endif


	// AHB prescalers:
	#if HPRE == NoDivision

		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b1 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b2 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b3 ) ;

	#elif HPRE == SYSCLKby2

		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b0 ) ;
        CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b1 ) ;
        CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b2 ) ;
        SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b3 ) ;

	#elif HPRE == SYSCLKby4

		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b1 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b2 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b3 ) ;

	#elif HPRE == SYSCLKby8

		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b1 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b2 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b3 ) ;

	#elif HPRE == SYSCLKby16

		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b1 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b2 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b3 ) ;

	#elif HPRE == SYSCLKby64

		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b2 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b3 ) ;

	#elif HPRE == SYSCLKby128

		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b2 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b3 ) ;

	#elif HPRE == SYSCLKby256

		CLR_BIT( RCC->CFGR, RCC_CFGR_HPRE_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b2 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b3 ) ;

	#elif HPRE == SYSCLKby512

		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b2 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_HPRE_b3 ) ;

	#endif


	// APB1 prescalers:
	#if PPRE1 == NoDivision

		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b1 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b2 ) ;

	#elif PPRE1 == AHBby2

		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b2 ) ;

	#elif PPRE1 == AHBby4

		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b2 ) ;

	#elif PPRE1 == AHBby8

		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b2 ) ;

	#elif PPRE1 == AHBby16

		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE1_b2 ) ;

	#endif

	// APB2 prescalers:
	#if PPRE2 == NoDivision

		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b1 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b2 ) ;

	#elif PPRE2 == AHBby2

		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b2 ) ;

	#elif PPRE2 == AHBby4

		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b0 ) ;
		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b2 ) ;

	#elif PPRE2 == AHBby8

		CLR_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b2 ) ;

	#elif PPRE2 == AHBby16

		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b0 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b1 ) ;
		SET_BIT( RCC->CFGR, RCC_CFGR_PPRE2_b2 ) ;

#endif


	// PLL configurations:



	// Enable the selected CLK (HSI ON/HSE ON/PLL ON): //
	// HSE (ON/OFF).
	#if HSE_EN == ENABLE

		SET_BIT( RCC->CR, RCC_CR_HSEON ) ;

	#elif HSE_EN == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_HSEON ) ;

	#endif


	// HSI (ON/OFF).
	#if HSI_EN == ENABLE

		SET_BIT( RCC->CR, RCC_CR_HSION ) ;

	#elif HSI_EN == DISABLE

		CLR_BIT( RCC->CR, RCC_CR_HSION ) ;

	#endif

}

/******************************************************************/
/******************************************************************/

void MRCC_vEnablePeriphralCLK( u32_t A_u32BusID, u32_t A_u32PeriphralID )
{

	switch( A_u32BusID )
	{

		case RCC_AHB1 :

			SET_BIT( RCC->AHB1ENR, A_u32PeriphralID ) ;

		break ;


		case RCC_AHB2 :

			SET_BIT( RCC->AHB2ENR, A_u32PeriphralID ) ;


		break ;


		case RCC_APB1 :

			SET_BIT( RCC->APB1ENR, A_u32PeriphralID ) ;

		break ;


		case RCC_APB2 :

			SET_BIT( RCC->APB2ENR, A_u32PeriphralID ) ;

		break ;

		case RCC_AHB1LPENR:

			SET_BIT( RCC->AHB1LPENR, A_u32PeriphralID ) ;

		break ;

		default:

			// Error wrong Bus ID

		break ;

	}

}

/******************************************************************/
/******************************************************************/

void MRCC_vDisablePeriphralCLK(  u32_t A_u32BusID, u32_t A_u32PeriphralID )
{

	switch( A_u32BusID )
	{

		case RCC_AHB1 :

			CLR_BIT( RCC->AHB1ENR, A_u32PeriphralID ) ;

		break ;


		case RCC_AHB2 :

			CLR_BIT( RCC->AHB2ENR, A_u32PeriphralID ) ;


		break ;


		case RCC_APB1 :

			CLR_BIT( RCC->APB1ENR, A_u32PeriphralID ) ;

		break ;


		case RCC_APB2 :

			CLR_BIT( RCC->APB2ENR, A_u32PeriphralID ) ;

		break ;


		case RCC_AHB1LPENR:

			CLR_BIT( RCC->AHB1LPENR, A_u32PeriphralID ) ;

		break ;


		default:

			// Error wrong Bus ID

		break ;

	}

}

/******************************************************************/
/******************************************************************/









