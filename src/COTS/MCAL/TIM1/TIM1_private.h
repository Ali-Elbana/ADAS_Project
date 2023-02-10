/* FILENAME: TIM1_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 01/24/2023
*/
#ifndef _TIM1_private_H
#define _TIM1_private_H

/************************************************************************/
/*                        Peripherals declaration                       */
/************************************************************************/

/**
 * @brief TIM1 declaration structure for its registers
 * @struct TIM1_MemoryMapType
 *
 */
typedef struct
{

	volatile u32_t CR1 		;

	volatile u32_t CR2 		;

	volatile u32_t SMCR 	;

	volatile u32_t DIER 	;

	volatile u32_t SR 		;

	volatile u32_t EGR 		;

	volatile u32_t CCMR1 	;

	volatile u32_t CCMR2 	;

	volatile u32_t CCER 	;

	volatile u32_t CNT 		;

	volatile u32_t PSC 		;

	volatile u32_t ARR 		;

	volatile u32_t RCR 		;

	volatile u32_t CCR1 	;

	volatile u32_t CCR2 	;

	volatile u32_t CCR3 	;

	volatile u32_t CCR4 	;

	volatile u32_t BDTR 	;

	volatile u32_t DCR		;

	volatile u32_t DMAR		;

} TIM1_MemoryMapType ;


#define TIM1_BASE_ADDRESS 0x40010000

#define TIM1 ( ( volatile TIM1_MemoryMapType* ) (TIM1_BASE_ADDRESS) )

/************************************************************************/
/*                      TIM1_CR1 register bits                          */
/************************************************************************/

#define CKD1	9
#define CKD0	8
#define ARPE	7
#define CMS1	6
#define CMS0	5
#define DIR		4
#define OPM		3
#define URS		2
#define UDIS	1
#define CEN		0

/************************************************************************/
/*                      TIM1_CR2 register bits                          */
/************************************************************************/

#define OIS4	14
#define OIS3N	13
#define OIS3	12
#define OIS2N	11
#define OIS2	10
#define OIS1N	9
#define OIS1	8
#define TI1S	7
#define MMS2	6
#define MMS1	5
#define MMS0	4
#define CCDS	3
#define CCUS	2
#define CCPC	0

/************************************************************************/
/*                     TIM1_SMCR register bits                          */
/************************************************************************/

#define ETP		15
#define ECE		14
#define ETPS1	13
#define ETPS0	12
#define ETF3	11
#define ETF2	10
#define ETF1	9
#define ETF0	8
#define MSM		7
#define TS2		6
#define TS1		5
#define TS0		4
#define SMS2	2
#define SMS1	1
#define SMS0	0

/************************************************************************/
/*                     TIM1_DIER register bits                          */
/************************************************************************/

#define TDE		14
#define COMDE	13
#define CC4DE	12
#define CC3DE	11
#define CC2DE	10
#define CC1DE	9
#define UDE		8
#define BIE		7
#define TIE		6
#define COMIE	5
#define CC4IE	4
#define CC3IE	3
#define CC2IE	2
#define CC1IE	1
#define UIE		0

/************************************************************************/
/*                     TIM1_SR register bits                          	*/
/************************************************************************/

#define CC4OF	12
#define CC3OF	11
#define CC2OF	10
#define CC1OF	9
#define BIF		7
#define TIF		6
#define COMIF	5
#define CC4IF	4
#define CC3IF	3
#define CC2IF	2
#define CC1IF	1
#define UIF		0

/************************************************************************/
/*                     TIM1_EGR register bits                          	*/
/************************************************************************/

#define BG		7
#define TG		6
#define COMG	5
#define CC4G	4
#define CC3G	3
#define CC2G	2
#define CC1G	1
#define UG		0

/************************************************************************/
/*                     TIM1_CCMR1 register bits                         */
/************************************************************************/

// General:
#define CC2S1	9
#define CC2S0	8
#define CC1S1	1
#define CC1S0	0

// Output Capture mode:
#define OC2CE	15
#define OC2M2	14
#define OC2M1	13
#define OC2M0	12
#define OC2PE	11
#define OC2FE	10
#define OC1CE	7
#define OC1M2	6
#define OC1M1	5
#define OC1M0	4
#define OC1PE	3
#define OC1FE	2

// Input Capture mode:
#define	IC2F3 	15
#define	IC2F2 	14
#define	IC2F1 	13
#define	IC2F0 	12
#define IC2PSC1	11
#define IC2PSC0	10
#define	IC1F3 	7
#define	IC1F2 	6
#define	IC1F1 	5
#define	IC1F0 	4
#define IC1PSC1	3
#define IC1PSC0	2

/************************************************************************/
/*                     TIM1_CCMR2 register bits                         */
/************************************************************************/

// General:
#define CC4S1	9
#define CC4S0	8
#define CC3S1	1
#define CC3S0	0

// For Output compare mode:
#define OC4CE	15
#define OC4M2	14
#define OC4M1	13
#define OC4M0	12
#define OC4PE	11
#define OC4FE	10
#define OC3CE	7
#define OC3M2	6
#define OC3M1	5
#define OC3M0	4
#define OC3PE	3
#define OC3FE	2

// For Input capture mode:
#define IC4F3	15
#define IC4F2	14
#define IC4F1	13
#define IC4F0	12
#define IC4PSC1	11
#define IC4PSC0	10
#define IC3F3	7
#define IC3F2	6
#define IC3F1	5
#define IC3F0	4
#define IC3PSC1	3
#define IC3PSC0	2

/************************************************************************/
/*                     TIM1_CCER2 register bits                         */
/************************************************************************/

#define CC4P	13
#define CC4E	12
#define CC3NP	11
#define CC3NE	10
#define CC3P	9
#define CC3E	8
#define CC2NP	7
#define CC2NE	6
#define CC2P	5
#define CC2E	4
#define CC1NP	3
#define CC1NE	2
#define CC1P	1
#define CC1E	0

/************************************************************************/
/*                     TIM1_BDTR register bits                          */
/************************************************************************/

#define MOE		15
#define AOE		14
#define BKP		13
#define BKE		12
#define OSSR	11
#define OSSI	10
#define LOCK1	9
#define LOCK0	8
#define DTG7	7
#define DTG6	6
#define DTG5	5
#define DTG4	4
#define DTG3	3
#define DTG2	2
#define DTG1	1
#define DTG0	0

/************************************************************************/
/*                     TIM1_DCR register bits                           */
/************************************************************************/

#define DBL4	12
#define DBL3	11
#define DBL2	10
#define DBL1	9
#define DBL0	8
#define DBA4	4
#define DBA3	3
#define DBA2	2
#define DBA1	1
#define DBA0	0

/************************************************************************/
/*                        Config.h Macros                               */
/************************************************************************/

#define ENABLE  				2
#define DISABLE 				1

#define ANY_EVENT 				1
#define OVF_UDF  				2

#define UP  					1
#define DOWN					2

#define EDGE                    1
#define CENTER1                 2
#define CENTER2                 3
#define CENTER3                 4


#define NOT_BUFFERED  			1
#define BUFFERED				2

#define ONE_TCK					1
#define TWO_TCK					2
#define FOUR_TCK				3

#define	NOT_PRELOADED			1
#define	PRELOADED    			2

#define	COMG_ONLY				2

#define	CCx_EVENT   			1
#define UPDATE_EVENT			2

#define RST						1
#define UPDATE          		3
#define COMP_PULSE      		4
#define COMP1           		5
#define COMP2           		6
#define COMP3           		7
#define COMP4           		8

#define	CH1						1
#define	CH1_2_3					2

#define LOW 					1
#define HIGH					2

#define ENCODER1				3
#define ENCODER2				4
#define ENCODER3				5
#define GATED  					6
#define TRIGGER					7
#define EXT_CLK					8

#define ITR0            		1
#define ITR1            		2
#define ITR2            		3
#define ITR3            		4
#define TI1F_ED         		5
#define TI1FP1          		6
#define TI1FP2          		7
#define ETRF            		8

#define NO_ACTION				1
#define TRGI					2

#define	NO_FLTR         		1
#define FCK_N2          		2
#define	FCK_N4          		3
#define	FCK_N8          		4
#define	FDTS2_N6        		5
#define	FDTS2_N8        		6
#define	FDTS4_N6        		7
#define	FDTS4_N8        		8
#define	FDTS8_N6        		9
#define	FDTS8_N8        		10
#define	FDTS16_N5       		11
#define	FDTS16_N6       		12
#define FDTS16_N8       		13
#define FDTS32_N5       		14
#define FDTS32_N6       		15
#define FDTS32_N8       		16

#define	OFF             		1
#define BY2             		2
#define	BY4             		3
#define	BY8             		4

#define NON_INVERTED			1
#define INVERTED    			2

#define RE_INIT					2

#define	CC_GENERATED			2

#define CC_UPDATED				2

#define	TRG_ENABLED				2

#define BRK_GENERATED			2

#define CC1_OUTPUT      		1
#define CC1_INPUT_TI1   		2
#define CC1_INPUT_TI2   		3
#define CC1_INPUT_TRC   		4

#define NO_PRESCALER    		1
#define EVERY_2_EVENTS  		2
#define EVERY_4_EVENTS  		3
#define EVERY_8_EVENTS  		4

#define CC2_OUTPUT      		1
#define CC2_INPUT_TI1   		2
#define CC2_INPUT_TI2   		3
#define CC2_INPUT_TRC   		4

#define NORMALLY				1
#define INPUT_TRIGGER			2

#define  FROZEN             	1
#define  OC1REF_HIGH         	2
#define  OC1REF_LOW          	3
#define  OC1REF_TOGGLE       	4
#define  OC1REF_FORCED_LOW   	5
#define  OC1REF_FORCED_HIGH  	6
#define  PWM1                	7
#define  PWM2                	8

#define OC1Ref_NOTEFFECTED		1
#define OC1Ref_CLEARED    		2

#define OC2Ref_NOTEFFECTED		1
#define OC2Ref_CLEARED    		2

#define OC2REF_HIGH             2
#define OC2REF_LOW              3
#define OC2REF_TOGGLE           4
#define OC2REF_FORCED_LOW       5
#define OC2REF_FORCED_HIGH      6

#define CC3_OUTPUT              1
#define CC3_INPUT_TI3           2
#define CC3_INPUT_TI4           3
#define CC3_INPUT_TRC           4

#define CC4_OUTPUT              1
#define CC4_INPUT_TI4           2
#define CC4_INPUT_TI3           3
#define CC4_INPUT_TRC           4

#define OC3REF_HIGH             2
#define OC3REF_LOW              3
#define OC3REF_TOGGLE           4
#define OC3REF_FORCED_LOW       5
#define OC3REF_FORCED_HIGH      6

#define OC4REF_HIGH             2
#define OC4REF_LOW              3
#define OC4REF_TOGGLE           4
#define OC4REF_FORCED_LOW       5
#define OC4REF_FORCED_HIGH      6

#define OC3Ref_NOTEFFECTED		1
#define OC3Ref_CLEARED    		2

#define OC4Ref_NOTEFFECTED		1
#define OC4Ref_CLEARED    		2

#define ACTIVE_HIGH             1
#define ACTIVE_LOW              2

#define OC_DISABLE				1
#define OC_ENABLE 				2

#define SW                      1
#define AUTO                    2


#endif //_TIM1_private_H
