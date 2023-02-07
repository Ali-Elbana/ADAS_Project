/* FILENAME: ADC_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 12/14/2022
*/
#ifndef _ADC_private_H
#define _ADC_private_H

// TODO: Review the comments and modify them.

/************************************************************************/
/*                        Peripherals declaration                       */
/************************************************************************/

/**
 * @brief ADC declaration structure for its registers
 * @struct ADC_MemoryMapType
 *
 */
typedef struct
{

	/**
	 * @brief clock control register
	 */
	u32_t SR 			;

	/**
	 * @brief PLL configuration register
	 */
	u32_t CR1 			;

	/**
	 * @brief clock configuration register
	 */
	u32_t CR2 			;

	/**
	 * @brief clock interrupt register
	 */
	u32_t SMPR1     	;

	/**
	 * @brief AHB1 peripheral reset register
	 */
	u32_t SMPR2 		;

	/**
	 * @brief AHB2 peripheral reset register
	 */
	u32_t JOFR1 		;

	/**
	 * @brief Reserved register
	 */
	u32_t JOFR2 		;

	/**
	 * @brief Reserved register
	 */
	u32_t JOFR3 		;

	/**
	 * @brief APB1 peripheral reset register
	 */
	u32_t JOFR4 		;

	/**
	 * @brief APB2 peripheral reset register
	 */
	u32_t HTR 			;

	/**
	 * @brief Reserved register
	 */
	u32_t LTR 			;

	/**
	 * @brief Reserved register
	 */
	u32_t SQR1 			;

	/**
	 * @brief AHB1 peripheral clock enable register
	 */
	u32_t SQR2 			;

	/**
	 * @brief AHB2 peripheral clock enable register
	 */
	u32_t SQR3 			;

	/**
	 * @brief Reserved register
	 */
	u32_t JSQR 			;

	/**
	 * @brief Reserved register
	 */
	u32_t JDR1 			;

	/**
	 * @brief APB1 peripheral clock enable register
	 */
	u32_t JDR2 			;

	/**
	 * @brief APB2 peripheral clock enable register
	 */
	u32_t JDR3 			;

	/**
	 * @brief Reserved register
	 */
	u32_t JDR4 			;

	/**
	 * @brief Reserved register
	 */
	u32_t DR 			;

	/**
	 * @brief AHB1 peripheral clock enable in low power mode register
	 */
	u32_t CCR			;


} ADC_MemoryMapType ;


/**
 * @def ADC_BASE_ADDRESS
 * ADC Base Address
 *
 */
#define ADC_BASE_ADDRESS 0x40012000

/**
 * @def ADC
 * ADC register
 *
 */
#define ADC ( (volatile P2VAR(ADC_MemoryMapType) ) (ADC_BASE_ADDRESS) ) // Is a pointer to the struct.


/************************************************************************/
/*                        ADC_SR register bits                          */
/************************************************************************/

#define OVR		5
#define STRT	4
#define JSTRT	3
#define JEOC	2
#define EOC		1
#define AWD		0

/************************************************************************/
/*                        ADC_CR1 register bits                         */
/************************************************************************/

#define OVRIE		26
#define RES0		24
#define RES1		25
#define AWDEN		23
#define JAWDEN		22
#define DISCNUM0	13
#define DISCNUM1	14
#define DISCNUM2	15
#define JDISCEN		13
#define DISCEN		11
#define JAUTO		10
#define AWDSGL		9
#define SCAN		8
#define JEOCIE		7
#define AWDIE		6
#define EOCIE		5
#define AWDCH0		0
#define AWDCH1		1
#define AWDCH2		2
#define AWDCH3		3
#define AWDCH4		4

/************************************************************************/
/*                        ADC_CR2 register bits                         */
/************************************************************************/

#define SWSTART		30
#define EXTEN0		28
#define EXTEN1		29
#define EXTSEL0		24
#define EXTSEL1		25
#define EXTSEL2		26
#define EXTSEL3		27
#define JSWSTART	22
#define JEXTEN0		20
#define JEXTEN1		21
#define JEXTSEL0	16
#define JEXTSEL1	17
#define JEXTSEL2	18
#define JEXTSEL3	19
#define ALIGN		11
#define EOCS		10
#define DDS			9
#define DMA			8
#define CONT		1
#define ADON		0

/************************************************************************/
/*                        ADC_SMPR1 register bits                       */
/************************************************************************/

#define SMP10_b0	0
#define SMP10_b1	1
#define SMP10_b2	2

#define SMP11_b0	3
#define SMP11_b1	4
#define SMP11_b2	5

#define SMP12_b0	6
#define SMP12_b1	7
#define SMP12_b2	8

#define SMP13_b0	9
#define SMP13_b1	10
#define SMP13_b2	11

#define SMP14_b0	12
#define SMP14_b1	13
#define SMP14_b2	14

#define SMP15_b0	15
#define SMP15_b1	16
#define SMP15_b2	17

#define SMP15_b0	15
#define SMP15_b1	16
#define SMP15_b2	17

#define SMP16_b0	18
#define SMP16_b1	19
#define SMP16_b2	20

#define SMP17_b0	21
#define SMP17_b1	22
#define SMP17_b2	23

#define SMP18_b0	24
#define SMP18_b1	25
#define SMP18_b2	26

/************************************************************************/
/*                        ADC_SMPR2 register bits                       */
/************************************************************************/

#define SMP0_b0	0
#define SMP0_b1	1
#define SMP0_b2	2

#define SMP1_b0	3
#define SMP1_b1	4
#define SMP1_b2	5

#define SMP2_b0	6
#define SMP2_b1	7
#define SMP2_b2	8

#define SMP3_b0	9
#define SMP3_b1	10
#define SMP3_b2	11

#define SMP4_b0	12
#define SMP4_b1	13
#define SMP4_b2	14

#define SMP5_b0	15
#define SMP5_b1	16
#define SMP5_b2	17

#define SMP5_b0	15
#define SMP5_b1	16
#define SMP5_b2	17

#define SMP6_b0	18
#define SMP6_b1	19
#define SMP6_b2	20

#define SMP7_b0	21
#define SMP7_b1	22
#define SMP7_b2	23

#define SMP8_b0	24
#define SMP8_b1	25
#define SMP8_b2	26

#define SMP9_b0	27
#define SMP9_b1	28
#define SMP9_b2	29

/************************************************************************/
/*                        ADC_SQR1 register bits                       */
/************************************************************************/

#define L0		20
#define L1		21
#define L2		22
#define L3		23

#define SQ16_b0	15
#define SQ16_b1	16
#define SQ16_b2	17
#define SQ16_b3	18
#define SQ16_b4	19

#define SQ15_b0	10
#define SQ15_b1	11
#define SQ15_b2	12
#define SQ15_b3	13
#define SQ15_b4	14

#define SQ14_b0	5
#define SQ14_b1	6
#define SQ14_b2	7
#define SQ14_b3	8
#define SQ14_b4	9

#define SQ13_b0	0
#define SQ13_b1	1
#define SQ13_b2	2
#define SQ13_b3	3
#define SQ13_b4	4

/************************************************************************/
/*                        ADC_SQR2 register bits                       */
/************************************************************************/

#define SQ12_b0	25
#define SQ12_b1	26
#define SQ12_b2	27
#define SQ12_b3	28
#define SQ12_b4	29

#define SQ11_b0	20
#define SQ11_b1	21
#define SQ11_b2	22
#define SQ11_b3	23
#define SQ11_b4	24

#define SQ10_b0	15
#define SQ10_b1	16
#define SQ10_b2	17
#define SQ10_b3	18
#define SQ10_b4	19

#define SQ9_b0	10
#define SQ9_b1	11
#define SQ9_b2	12
#define SQ9_b3	13
#define SQ9_b4	14

#define SQ8_b0	5
#define SQ8_b1	6
#define SQ8_b2	7
#define SQ8_b3	8
#define SQ8_b4	9

#define SQ7_b0	0
#define SQ7_b1	1
#define SQ7_b2	2
#define SQ7_b3	3
#define SQ7_b4	4

/************************************************************************/
/*                        ADC_SQR3 register bits                       */
/************************************************************************/

#define SQ6_b0	25
#define SQ6_b1	26
#define SQ6_b2	27
#define SQ6_b3	28
#define SQ6_b4	29

#define SQ5_b0	20
#define SQ5_b1	21
#define SQ5_b2	22
#define SQ5_b3	23
#define SQ5_b4	24

#define SQ4_b0	15
#define SQ4_b1	16
#define SQ4_b2	17
#define SQ4_b3	18
#define SQ4_b4	19

#define SQ3_b0	10
#define SQ3_b1	11
#define SQ3_b2	12
#define SQ3_b3	13
#define SQ3_b4	14

#define SQ2_b0	5
#define SQ2_b1	6
#define SQ2_b2	7
#define SQ2_b3	8
#define SQ2_b4	9

#define SQ1_b0	0
#define SQ1_b1	1
#define SQ1_b2	2
#define SQ1_b3	3
#define SQ1_b4	4

/************************************************************************/
/*                        ADC_CCR register bits                         */
/************************************************************************/

#define TSVREFE	23
#define VBATE	22
#define ADCPRE0	16
#define ADCPRE1	17

/************************************************************************/
/*                        Config.h Macros                               */
/************************************************************************/

#define ENABLE  1
#define DISABLE 2

#define _12_BITS  0
#define _10_BITS  1
#define _8_BITS   2
#define _6_BITS   3

#define _1_CHANNEL   0
#define _2_CHANNELS  1
#define _3_CHANNELS  2
#define _4_CHANNELS  3
#define _5_CHANNELS  4
#define _6_CHANNELS  5
#define _7_CHANNELS  6
#define _8_CHANNELS  7

#define ZERO	 	0
#define ONE      	1
#define THREE    	2
#define FOUR     	3
#define FIVE     	4
#define SIX      	5
#define SEVEN    	6
#define EIGHT    	7
#define NINE		8
#define TEN			9
#define ELEVEN		10
#define TWELVE		11
#define THERTEEN	12
#define FOURTEEN	13
#define FIFTEEN		14
#define SIXTEEN		15
#define SEVENTEEN	16
#define EIGHTEEN	17

#define T1_CC1     		0
#define T1_CC2          1
#define T1_CC3          2
#define T2_CC2          3
#define T2_CC3          4
#define T2_CC4          5
#define REG_T2_TRGO     6
#define T3_CC1          7
#define T3_TRGO         8
#define T4_CC4          9
#define T5_CC1          10
#define T5_CC2          11
#define T5_CC3          12
#define EXTI_LINE11     15

#define RISING          1
#define FALLING         2
#define ON_CHANGE       3

#define T1_CC4			0
#define T1_TRGO         1
#define T2_CC1          2
#define INJ_T2_TRGO     3
#define T3_CC2          4
#define T3_CC4          5
#define T4_CC1          6
#define T4_CC2          7
#define T4_CC3          8
#define T4_TRGO         9
#define T5_CC4          10
#define T5_TRGO         11
#define EXTI_LINE15     15

#define RIGHT  0
#define LEFT   1

#define _3_CYCLES     0
#define _15_CYCLES    1
#define _28_CYCLES    2
#define _56_CYCLES    3
#define _84_CYCLES    4
#define _112_CYCLES   5
#define _144_CYCLES   6
#define _480_CYCLES   7

#define _1_CONV 	0
#define _2_CONV     1
#define _3_CONV     2
#define _4_CONV     3
#define _5_CONV     4
#define _6_CONV     5
#define _7_CONV     6
#define _8_CONV     7
#define _9_CONV     8
#define _10_CONV    9
#define _11_CONV    10
#define _15_CONV    11
#define _16_CONV    15


#define DIV_BY_2    0
#define DIV_BY_4    1
#define DIV_BY_6    2
#define DIV_BY_8    3







#endif //_ADC_private_H
