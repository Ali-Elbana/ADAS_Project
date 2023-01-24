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

	u32_t CR1 		;

	u32_t CR2 		;

	u32_t SMCR 		;

	u32_t DIER 		;

	u32_t SR 		;

	u32_t EGR 		;

	u32_t CCMR1_OC 	;

	u32_t CCMR1_IC 	;

	u32_t CCMR2_OC 	;

	u32_t CCMR2_IC 	;

	u32_t CCER 		;

	u32_t CNT 		;

	u32_t PSC 		;

	u32_t ARR 		;

	u32_t RCR 		;

	u32_t CCR1 		;

	u32_t CCR2 		;

	u32_t CCR3 		;

	u32_t CCR4 		;

	u32_t BDTR 		;

	u32_t DCR		;

	u32_t DMAR		;

} TIM1_MemoryMapType ;


#define TIM1_BASE_ADDRESS 0x40010000

#define TIM1 ( ( volatile P2VAR(TIM1_MemoryMapType) ) (TIM1_BASE_ADDRESS) )

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

#define OC2CE	15
#define OC2M2	14
#define OC2M1	13
#define OC2M0	12
#define OC2PE	11
#define OC2FE	10
#define CC2S1	9
#define CC2S0	8
#define OC1CE	7
#define OC1M2	6
#define OC1M1	5
#define OC1M0	4
#define OC1PE	3
#define OC1FE	2
#define CC1S1	1
#define CC1S0	0

/************************************************************************/
/*                     TIM1_CCMR2 register bits                         */
/************************************************************************/

// For Output compare mode:
#define OC4CE	15
#define OC4M2	14
#define OC4M1	13
#define OC4M0	12
#define OC4PE	11
#define OC4FE	10
#define CC2S1	9
#define CC4S0	8
#define OC3CE	7
#define OC3M2	6
#define OC3M1	5
#define OC3M0	4
#define OC3PE	3
#define OC3FE	2
#define CC3S1	1
#define CC3S0	0

// For Input capture mode:
#define IC4F3	15
#define IC4F2	14
#define IC4F1	13
#define IC4F0	12
#define IC4PSC1	11
#define IC4PSC0	10
#define CC2S1	9
#define CC4S0	8
#define IC3F3	7
#define IC3F2	6
#define IC3F1	5
#define IC3F0	4
#define IC3PSC1	3
#define IC3PSC0	2
#define CC3S1	1
#define CC3S0	0

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
/*                     TIM1_CCER2 register bits                         */
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

#define ENABLE  1
#define DISABLE 0











#endif //_TIM1_private_H
