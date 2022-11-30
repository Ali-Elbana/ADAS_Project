/**
 * @file MRCC_private.h
 * @author Ali El Bana & Mo Alaa
 * @brief This file contains the registers information and addresses for the RCC module
 * @version 2.0
 * @date 11/9/2022
 */

/* Header file guard */
#ifndef MCAL_RCC_MRCC_PRIVATE_H_
#define MCAL_RCC_MRCC_PRIVATE_H_



/************************************************************************/
/*                        Peripherals declaration                       */
/************************************************************************/

/**
 * @brief RCC declaration structure for its registers
 * @struct RCC_MemoryMapType
 *
 */
typedef struct
{

	/**
	 * @brief clock control register
	 */
	u32_t CR 			;

	/**
	 * @brief PLL configuration register
	 */
	u32_t PLLCFGR 		;

	/**
	 * @brief clock configuration register
	 */
	u32_t CFGR 			;

	/**
	 * @brief clock interrupt register
	 */
	u32_t CIR     		;

	/**
	 * @brief AHB1 peripheral reset register
	 */
	u32_t AHB1RSTR 		;

	/**
	 * @brief AHB2 peripheral reset register
	 */
	u32_t AHB2RSTR 		;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved1 	;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved2 	;

	/**
	 * @brief APB1 peripheral reset register
	 */
	u32_t APB1RSTR 		;

	/**
	 * @brief APB2 peripheral reset register
	 */
	u32_t APB2RSTR 		;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved3 	;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved4 	;

	/**
	 * @brief AHB1 peripheral clock enable register
	 */
	u32_t AHB1ENR 		;

	/**
	 * @brief AHB2 peripheral clock enable register
	 */
	u32_t AHB2ENR 		;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved5 	;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved6 	;

	/**
	 * @brief APB1 peripheral clock enable register
	 */
	u32_t APB1ENR 		;

	/**
	 * @brief APB2 peripheral clock enable register
	 */
	u32_t APB2ENR 		;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved7 	;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved8 	;

	/**
	 * @brief AHB1 peripheral clock enable in low power mode register
	 */
	u32_t AHB1LPENR		;

	/**
	 * @brief AHB2 peripheral clock enable in low power mode register
	 */
	u32_t AHB2LPENR		;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved9 	;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved10 	;

	/**
	 * @brief APB1 peripheral clock enable in low power mode register
	 */
	u32_t APB1LPENR 	;

	/**
	 * @brief APB2 peripheral clock enable in low power mode register
	 */
	u32_t APB2LPENR 	;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved11 	;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved12 	;

	/**
	 * @brief RCC Backup domain control register
	 */
	u32_t BDCR 			;

	/**
	 * @brief clock control & status register
	 */
	u32_t CSR 			;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved13 	;

	/**
	 * @brief Reserved register
	 */
	u32_t Reserved14 	;

	/**
	 * @brief RCC spread spectrum clock generation register
	 */
	u32_t SSCGR 		;

	/**
	 * @brief PLLI2S configuration register
	 */
	u32_t PLLI2SCFGR 	;

	/**
	 * @brief Dedicated Clocks Configuration Register
	 */
	u32_t DCKCFGR		;


} RCC_MemoryMapType ;


/**
 * @def RCC_BASE_ADDRESS
 * RCC Base Address
 *
 */
#define RCC_BASE_ADDRESS 0x40023800

/**
 * @def RCC
 * RCC register
 *
 */
#define RCC ( (volatile P2VAR(RCC_MemoryMapType) ) (RCC_BASE_ADDRESS) ) // Is a pointer to the struct.


/************************************************************************/
/*                        Peripheral registers                          */
/************************************************************************/

#define RCC_CR_PLLI2SRDY  27
#define RCC_CR_PLLI2SON   26
#define RCC_CR_PLLRDY	  25
#define RCC_CR_PLLON	  24
#define RCC_CR_CSSON	  19
#define RCC_CR_HSEBYP	  18
#define RCC_CR_HSERDY	  17
#define RCC_CR_HSEON	  16
#define RCC_CR_HSIRDY	  1
#define RCC_CR_HSION	  0


#define RCC_PLLCFGR_PLLQ_b0 24
#define RCC_PLLCFGR_PLLQ_b1 25
#define RCC_PLLCFGR_PLLQ_b2 26
#define RCC_PLLCFGR_PLLQ_b3 27
#define RCC_PLLCFGR_PLLSRC 	22
#define RCC_PLLCFGR_PLLP_b0 16
#define RCC_PLLCFGR_PLLP_b1 17
#define RCC_PLLCFGR_PLLN_b0 6
#define RCC_PLLCFGR_PLLN_b1 7
#define RCC_PLLCFGR_PLLN_b2 8
#define RCC_PLLCFGR_PLLN_b3 9
#define RCC_PLLCFGR_PLLN_b4 10
#define RCC_PLLCFGR_PLLN_b5 11
#define RCC_PLLCFGR_PLLN_b6 12
#define RCC_PLLCFGR_PLLN_b7 13
#define RCC_PLLCFGR_PLLN_b8 14
#define RCC_PLLCFGR_PLLM_b0 0
#define RCC_PLLCFGR_PLLM_b1 1
#define RCC_PLLCFGR_PLLM_b2 2
#define RCC_PLLCFGR_PLLM_b3 3
#define RCC_PLLCFGR_PLLM_b4 4
#define RCC_PLLCFGR_PLLM_b5 5


#define RCC_CFGR_MOC2_b0	  	30
#define RCC_CFGR_MOC2_b1	  	31
#define RCC_CFGR_MOC2PRE_b0	  	27
#define RCC_CFGR_MOC2PRE_b1	  	28
#define RCC_CFGR_MOC2PRE_b2	  	29
#define RCC_CFGR_MOC1PRE_b0	  	24
#define RCC_CFGR_MOC1PRE_b1	  	25
#define RCC_CFGR_MOC1PRE_b2	  	26
#define RCC_CFGR_I2SSRC 	  	23
#define RCC_CFGR_MOC1_b0	  	21
#define RCC_CFGR_MOC1_b1	  	22
#define RCC_CFGR_RTCPRE_b0 	  	16
#define RCC_CFGR_RTCPRE_b1 	  	17
#define RCC_CFGR_RTCPRE_b2 	  	18
#define RCC_CFGR_RTCPRE_b3 	  	19
#define RCC_CFGR_RTCPRE_b4 	  	20
#define RCC_CFGR_PPRE2_b0	  	13
#define RCC_CFGR_PPRE2_b1	  	14
#define RCC_CFGR_PPRE2_b2	  	15
#define RCC_CFGR_PPRE1_b0	  	10
#define RCC_CFGR_PPRE1_b1	  	11
#define RCC_CFGR_PPRE1_b2	  	12
#define RCC_CFGR_HPRE_b0	  	4
#define RCC_CFGR_HPRE_b1	  	5
#define RCC_CFGR_HPRE_b2	  	6
#define RCC_CFGR_HPRE_b3	  	7
#define RCC_CFGR_SWS_b0	  		2
#define RCC_CFGR_SWS_b1	  		3
#define RCC_CFGR_SW_b0	  		0
#define RCC_CFGR_SW_b1	  		1


#define RCC_AHB1ENR_DMA2EN	  22
#define RCC_AHB1ENR_DMA1EN	  21
#define RCC_AHB1ENR_CRCEN	  12
#define RCC_AHB1ENR_GPIOHEN	  7
#define RCC_AHB1ENR_GPIOEEN	  4
#define RCC_AHB1ENR_GPIODEN	  3
#define RCC_AHB1ENR_GPIOCEN	  2
#define RCC_AHB1ENR_GPIOBEN	  1
#define RCC_AHB1ENR_GPIOAEN	  0


#define RCC_AHB2ENR_OTGFSEN	  7


#define RCC_APB1ENR_PWREN		28
#define RCC_APB1ENR_I2C3EN		23
#define RCC_APB1ENR_I2C2EN		22
#define RCC_APB1ENR_I2C1EN		21
#define RCC_APB1ENR_USART2EN	17
#define RCC_APB1ENR_SPI3EN		15
#define RCC_APB1ENR_SPI2EN		14
#define RCC_APB1ENR_WWDGEN		11
#define RCC_APB1ENR_TIM5EN		3
#define RCC_APB1ENR_TIM4EN		2
#define RCC_APB1ENR_TIM3EN		1
#define RCC_APB1ENR_TIM2EN		0


#define RCC_APB2ENR_TIM11EN		18
#define RCC_APB2ENR_TIM10EN		17
#define RCC_APB2ENR_TIM9EN		16
#define RCC_APB2ENR_SYSCFGEN	14
#define RCC_APB2ENR_SPI4EN		13
#define RCC_APB2ENR_SPI1EN		12
#define RCC_APB2ENR_SDIOEN		11
#define RCC_APB2ENR_ADC1EN		8
#define RCC_APB2ENR_USART6EN	5
#define RCC_APB2ENR_USART1EN	4
#define RCC_APB2ENR_TIM1EN		0

#define RCC_AHB1LPENR_FLITFLPEN 15


/************************************************************************/
/*                        Config.h Macros                               */
/************************************************************************/

#define ENABLE  1
#define DISABLE 2

#define BYBASED 	1
#define NOTBYBASED	2

#define SYSCLK   	1
#define PLLI2SCLK	5
#define HSE      	3
#define PLLCLK   	4

#define NoDivision 	1
#define DivisionBy2	2
#define DivisionBy3	3
#define DivisionBy4	4
#define DivisionBy5	5


#define I2S_CKIN  2

#define HSI   	1
#define LSE   	2
#define PLLCLK	4

// AHB prescalers:
#define SYSCLKby2	2	//(0b1000)
#define SYSCLKby4	3	//(0b1001)
#define SYSCLKby8	4	//(0b1010)
#define SYSCLKby16	5	//(0b1011)
#define SYSCLKby64	6	//(0b1100)
#define SYSCLKby128 7	//(0b1101)
#define SYSCLKby256 8	//(0b1110)
#define SYSCLKby512	9	//(0b1111)


#define NoCLK0 	1
#define NoCLK1 	2
#define HSEby2 	3
#define HSEby3 	4
#define HSEby4 	5
#define HSEby5 	6
#define HSEby6 	7
#define HSEby7 	8
#define HSEby8 	9
#define HSEby9 	10
#define HSEby10	11
#define HSEby11	12
#define HSEby12	13
#define HSEby13	14
#define HSEby14	15
#define HSEby15	16
#define HSEby16	17
#define HSEby17	18
#define HSEby18	19
#define HSEby19	20
#define HSEby20	21
#define HSEby21	22
#define HSEby22	23
#define HSEby23	24
#define HSEby24	25
#define HSEby25	26
#define HSEby26	27
#define HSEby27	28
#define HSEby28	39
#define HSEby29	30
#define HSEby30	31
#define HSEby31	32


#define AHBby2	1
#define AHBby4 	2
#define AHBby8 	3
#define AHBby16	4


#define Equal_0 	0
#define Equal_1 	1
#define Equal_2 	2
#define Equal_3 	3
#define Equal_4 	4
#define Equal_5 	5
#define Equal_6 	6
#define Equal_7 	7
#define Equal_8 	8
#define Equal_9 	9
#define Equal_10	10
#define Equal_11	11
#define Equal_12	12
#define Equal_13	13
#define Equal_14	14
#define Equal_15	15
#define Equal_16	16
#define Equal_17	17
#define Equal_18	18
#define Equal_19    19
#define Equal_20    20
#define Equal_21    21
#define Equal_22    22
#define Equal_23    23
#define Equal_24    24
#define Equal_25    25
#define Equal_26    26
#define Equal_27    27
#define Equal_28    28
#define Equal_29    29
#define Equal_30    30
#define Equal_31    31
#define Equal_32    32
#define Equal_33    33
#define Equal_34    34
#define Equal_35    35
#define Equal_36    36
#define Equal_37    37
#define Equal_38    38
#define Equal_39    39
#define Equal_40    40
#define Equal_41    41
#define Equal_42    42
#define Equal_43    43
#define Equal_44    44
#define Equal_45    45
#define Equal_46    46
#define Equal_47    47
#define Equal_48    48
#define Equal_49    49
#define Equal_50    50
#define Equal_51    51
#define Equal_52    52
#define Equal_53    53
#define Equal_54    54
#define Equal_55    55
#define Equal_56    56
#define Equal_57    57
#define Equal_58    58
#define Equal_59    59
#define Equal_60    60
#define Equal_61    61
#define Equal_62    62
#define Equal_63    63





#endif /* MCAL_RCC_MRCC_PRIVATE_H_ */
