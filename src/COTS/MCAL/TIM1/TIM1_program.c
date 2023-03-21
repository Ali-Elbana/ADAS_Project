/* FILENAME: TIM1_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 01/24/2023
*/

/************************************************************************/
/*                         Include headers                           	*/
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "../RCC/MRCC_interface.h"
#include "../GPIO/GPIO_interface.h"

#include "TIM1_interface.h"
#include "TIM1_private.h"
#include "TIM1_config.h"

/************************************************************************/
/*                     Functions  implementations                      	*/
/************************************************************************/

void MTIM1_vInit( void )
{

	// EN TIM1 CLK:
	MRCC_vEnablePeriphralCLK( RCC_APB2, APB2ENR_TIM1EN ) ;

	/*_______________________CR1________________________*/

	// EN/DIS update:
	#if	UPDATE_CNTRL == ENABLE

	CLR_BIT( TIM1->CR1, UDIS ) ;

	#elif  UPDATE_CNTRL == DISABLE

	SET_BIT( TIM1->CR1, UDIS ) ;

	#endif

	// Update request source:
	#if	UPDATE_SRC == OVF_UDF

	SET_BIT( TIM1->CR1, URS ) ;

	#elif UPDATE_SRC == ANY_EVENT

	CLR_BIT( TIM1->CR1, URS ) ;

	#endif

	// One pulse mode:
	#if	OP_MODE == ENABLE

	SET_BIT( TIM1->CR1, OPM ) ;

	#elif OP_MODE == DISABLE

	CLR_BIT( TIM1->CR1, OPM ) ;

	#endif

	// Counting Direction:
	#if	CNT_DIR == UP

	CLR_BIT( TIM1->CR1, DIR ) ;

	#elif CNT_DIR == DOWN

	SET_BIT( TIM1->CR1, DIR ) ;

	#endif

	// Center-aligned mode selection:
	#if	CMS == EDGE

	CLR_BIT( TIM1->CR1, CMS0 ) ;
	CLR_BIT( TIM1->CR1, CMS1 ) ;

	#elif CMS == CENTER1

	SET_BIT( TIM1->CR1, CMS0 ) ;
	CLR_BIT( TIM1->CR1, CMS1 ) ;

	#elif CMS == CENTER2

	CLR_BIT( TIM1->CR1, CMS0 ) ;
	SET_BIT( TIM1->CR1, CMS1 ) ;

	#elif CMS == CENTER3

	SET_BIT( TIM1->CR1, CMS0 ) ;
	SET_BIT( TIM1->CR1, CMS1 ) ;

	#endif

	// Auto-reload preload enable:
	#if	ARP_EN == NOT_BUFFERED

	CLR_BIT( TIM1->CR1, ARPE ) ;

	#elif ARP_EN == BUFFERED

	SET_BIT( TIM1->CR1, ARPE ) ;

	#endif

	// Clock division:
	#if	CKD == ONE_TCK

	CLR_BIT( TIM1->CR1, CKD0 ) ;
	CLR_BIT( TIM1->CR1, CKD1 ) ;

	#elif CKD == TWO_TCK

	SET_BIT( TIM1->CR1, CKD0 ) ;
	CLR_BIT( TIM1->CR1, CKD1 ) ;

	#elif CKD == FOUR_TCK

	CLR_BIT( TIM1->CR1, CKD0 ) ;
	SET_BIT( TIM1->CR1, CKD1 ) ;

	#endif

	/*_______________________CR2________________________*/

	// Capture/compare preloaded control:
	#if	CCP_CTRL == NOT_PRELOADED

	CLR_BIT( TIM1->CR2, CCPC ) ;

	#elif CCP_CTRL == PRELOADED

	SET_BIT( TIM1->CR2, CCPC ) ;

	#endif

	// Capture/compare control update selection:
	#if	CCU_SLCT == COMG_ONLY

	CLR_BIT( TIM1->CR2, CCUS ) ;

	#elif CCU_SLCT == ANY_EVENT

	SET_BIT( TIM1->CR2, CCUS ) ;

	#endif

	// Capture/compare DMA selection:
	#if	CCD_SLCT == CCx_EVENT

	CLR_BIT( TIM1->CR2, CCDS ) ;

	#elif CCD_SLCT == UPDATE_EVENT

	SET_BIT( TIM1->CR2, CCDS ) ;

	#endif

	// Master mode selection:
	#if	MMS == RST

	CLR_BIT( TIM1->CR2, MMS0 ) ;
	CLR_BIT( TIM1->CR2, MMS1 ) ;
	CLR_BIT( TIM1->CR2, MMS2 ) ;

	#elif MMS == ENABLE

	SET_BIT( TIM1->CR2, MMS0 ) ;
	CLR_BIT( TIM1->CR2, MMS1 ) ;
	CLR_BIT( TIM1->CR2, MMS2 ) ;

	#elif MMS == UPDATE

	CLR_BIT( TIM1->CR2, MMS0 ) ;
	SET_BIT( TIM1->CR2, MMS1 ) ;
	CLR_BIT( TIM1->CR2, MMS2 ) ;

	#elif MMS == COMP_PULSE

	SET_BIT( TIM1->CR2, MMS0 ) ;
	SET_BIT( TIM1->CR2, MMS1 ) ;
	CLR_BIT( TIM1->CR2, MMS2 ) ;

	#elif MMS == COMP1

	CLR_BIT( TIM1->CR2, MMS0 ) ;
	CLR_BIT( TIM1->CR2, MMS1 ) ;
	SET_BIT( TIM1->CR2, MMS2 ) ;

	#elif MMS == COMP2

	SET_BIT( TIM1->CR2, MMS0 ) ;
	CLR_BIT( TIM1->CR2, MMS1 ) ;
	SET_BIT( TIM1->CR2, MMS2 ) ;

	#elif MMS == COMP3

	CLR_BIT( TIM1->CR2, MMS0 ) ;
	SET_BIT( TIM1->CR2, MMS1 ) ;
	SET_BIT( TIM1->CR2, MMS2 ) ;

	#elif MMS == COMP4

	SET_BIT( TIM1->CR2, MMS0 ) ;
	SET_BIT( TIM1->CR2, MMS1 ) ;
	SET_BIT( TIM1->CR2, MMS2 ) ;

	#endif

	// TI1 selection:
	#if	TI1_SLCT == CH1

	CLR_BIT( TIM1->CR2, TI1S ) ;

	#elif TI1_SLCT == CH1_2_3

	SET_BIT( TIM1->CR2, TI1S ) ;

	#endif

	// Output Idle state 1 (OC1 output):
	#if	OC1_IDLE_STATE == LOW

	CLR_BIT( TIM1->CR2, OIS1 ) ;

	#elif OC1_IDLE_STATE == HIGH

	SET_BIT( TIM1->CR2, OIS1 ) ;

	#endif

	// Output Idle state 1 (OC1N output):
	#if	OC1N_IDLE_STATE == LOW

	CLR_BIT( TIM1->CR2, OIS1N ) ;

	#elif OC1N_IDLE_STATE == HIGH

	SET_BIT( TIM1->CR2, OIS1N ) ;

	#endif

	// Output Idle state 2 (OC2 output):
	#if	OC2_IDLE_STATE == LOW

	CLR_BIT( TIM1->CR2, OIS2 ) ;

	#elif OC2_IDLE_STATE == HIGH

	SET_BIT( TIM1->CR2, OIS2 ) ;

	#endif

	// Output Idle state 2 (OC2N output):
	#if	OC2N_IDLE_STATE == LOW

	CLR_BIT( TIM1->CR2, OIS2N ) ;

	#elif OC2N_IDLE_STATE == HIGH

	SET_BIT( TIM1->CR2, OIS2N ) ;

	#endif

	// Output Idle state 3 (OC3 output):
	#if	OC3_IDLE_STATE == LOW

	CLR_BIT( TIM1->CR2, OIS3 ) ;

	#elif OC3_IDLE_STATE == HIGH

	SET_BIT( TIM1->CR2, OIS3 ) ;

	#endif

	// Output Idle state 3 (OC3N output):
	#if	OC3N_IDLE_STATE == LOW

	CLR_BIT( TIM1->CR2, OIS3N ) ;

	#elif OC3N_IDLE_STATE == HIGH

	SET_BIT( TIM1->CR2, OIS3N ) ;

	#endif

	// Output Idle state 4 (OC4 output):
	#if	OC3_IDLE_STATE == LOW

	CLR_BIT( TIM1->CR2, OIS4 ) ;

	#elif OC3_IDLE_STATE == HIGH

	SET_BIT( TIM1->CR2, OIS4 ) ;

	#endif

	/*_______________________SMCR________________________*/

	// Slave mode selection:
	#if	SMS == DISABLE

	CLR_BIT( TIM1->SMCR, SMS0 ) ;
	CLR_BIT( TIM1->SMCR, SMS1 ) ;
	CLR_BIT( TIM1->SMCR, SMS2 ) ;

	#elif SMS == ENCODER1

	SET_BIT( TIM1->SMCR, SMS0 ) ;
	CLR_BIT( TIM1->SMCR, SMS1 ) ;
	CLR_BIT( TIM1->SMCR, SMS2 ) ;

	#elif SMS == ENCODER2

	CLR_BIT( TIM1->SMCR, SMS0 ) ;
	SET_BIT( TIM1->SMCR, SMS1 ) ;
	CLR_BIT( TIM1->SMCR, SMS2 ) ;

	#elif SMS == ENCODER3

	SET_BIT( TIM1->SMCR, SMS0 ) ;
	SET_BIT( TIM1->SMCR, SMS1 ) ;
	CLR_BIT( TIM1->SMCR, SMS2 ) ;

	#elif SMS == RST

	CLR_BIT( TIM1->SMCR, SMS0 ) ;
	CLR_BIT( TIM1->SMCR, SMS1 ) ;
	SET_BIT( TIM1->SMCR, SMS2 ) ;

	#elif SMS == GATED

	SET_BIT( TIM1->SMCR, SMS0 ) ;
	CLR_BIT( TIM1->SMCR, SMS1 ) ;
	SET_BIT( TIM1->SMCR, SMS2 ) ;

	#elif SMS == TRIGGER

	CLR_BIT( TIM1->SMCR, SMS0 ) ;
	SET_BIT( TIM1->SMCR, SMS1 ) ;
	SET_BIT( TIM1->SMCR, SMS2 ) ;

	#elif SMS == EXT_CLK

	SET_BIT( TIM1->SMCR, SMS0 ) ;
	SET_BIT( TIM1->SMCR, SMS1 ) ;
	SET_BIT( TIM1->SMCR, SMS2 ) ;

	#endif

	// Trigger selection:
	#if	TS == ITR0

	CLR_BIT( TIM1->SMCR, TS0 ) ;
	CLR_BIT( TIM1->SMCR, TS1 ) ;
	CLR_BIT( TIM1->SMCR, TS2 ) ;

	#elif TS == ITR1

	SET_BIT( TIM1->SMCR, TS0 ) ;
	CLR_BIT( TIM1->SMCR, TS1 ) ;
	CLR_BIT( TIM1->SMCR, TS2 ) ;

	#elif TS == ITR2

	CLR_BIT( TIM1->SMCR, TS0 ) ;
	SET_BIT( TIM1->SMCR, TS1 ) ;
	CLR_BIT( TIM1->SMCR, TS2 ) ;

	#elif TS == ITR3

	SET_BIT( TIM1->SMCR, TS0 ) ;
	SET_BIT( TIM1->SMCR, TS1 ) ;
	CLR_BIT( TIM1->SMCR, TS2 ) ;

	#elif TS == TI1F_ED

	CLR_BIT( TIM1->SMCR, TS0 ) ;
	CLR_BIT( TIM1->SMCR, TS1 ) ;
	SET_BIT( TIM1->SMCR, TS2 ) ;

	#elif TS == TI1FP1

	SET_BIT( TIM1->SMCR, TS0 ) ;
	CLR_BIT( TIM1->SMCR, TS1 ) ;
	SET_BIT( TIM1->SMCR, TS2 ) ;

	#elif TS == TI1FP2

	CLR_BIT( TIM1->SMCR, TS0 ) ;
	SET_BIT( TIM1->SMCR, TS1 ) ;
	SET_BIT( TIM1->SMCR, TS2 ) ;

	#elif TS == ETRF

	SET_BIT( TIM1->SMCR, TS0 ) ;
	SET_BIT( TIM1->SMCR, TS1 ) ;
	SET_BIT( TIM1->SMCR, TS2 ) ;

	#endif

	// Master/slave mode:
	#if	MSTR_SLAVE_MODE == NO_ACTION

	CLR_BIT( TIM1->SMCR, MSM ) ;

	#elif MSTR_SLAVE_MODE == TRGI

	SET_BIT( TIM1->SMCR, MSM ) ;

	#endif

	// External trigger prescaler:
	#if	ETPS == OFF

	CLR_BIT( TIM1->SMCR, ETPS0 ) ;
	CLR_BIT( TIM1->SMCR, ETPS1 ) ;

	#elif ETPS == BY2

	SET_BIT( TIM1->SMCR, ETPS0 ) ;
	CLR_BIT( TIM1->SMCR, ETPS1 ) ;

	#elif ETPS == BY4

	CLR_BIT( TIM1->SMCR, ETPS0 ) ;
	SET_BIT( TIM1->SMCR, ETPS1 ) ;

	#elif ETPS == BY8

	SET_BIT( TIM1->SMCR, ETPS0 ) ;
	SET_BIT( TIM1->SMCR, ETPS1 ) ;

	#endif

	// External clock enable:
	#if	EXT_CLK_EN == ENABLE

	SET_BIT( TIM1->SMCR, ECE ) ;

	#elif EXT_CLK_EN == DISABLE

	CLR_BIT( TIM1->SMCR, ECE ) ;

	#endif

	// External trigger polarity:
	#if	EXTP == INVERTED

	SET_BIT( TIM1->SMCR, ETP ) ;

	#elif EXTP == NON_INVERTED

	CLR_BIT( TIM1->SMCR, ETP ) ;

	#endif

	/*_______________________EGR________________________*/

	// Update generation:
	#if	UP_GEN == RE_INIT

	SET_BIT( TIM1->EGR, UG ) ;

	#elif UP_GEN == NO_ACTION

	CLR_BIT( TIM1->EGR, UG ) ;

	#endif

	// Capture/Compare 1 generation:
	#if	CC1_GEN == CC_GENERATED

	SET_BIT( TIM1->EGR, CC1G ) ;

	#elif CC1_GEN == NO_ACTION

	CLR_BIT( TIM1->EGR, CC1G ) ;

	#endif

	// Capture/Compare 2 generation:
	#if	CC2_GEN == CC_GENERATED

	SET_BIT( TIM1->EGR, CC2G ) ;

	#elif CC2_GEN == NO_ACTION

	CLR_BIT( TIM1->EGR, CC2G ) ;

	#endif

	// Capture/Compare 3 generation:
	#if	CC3_GEN == CC_GENERATED

	SET_BIT( TIM1->EGR, CC3G ) ;

	#elif CC3_GEN == NO_ACTION

	CLR_BIT( TIM1->EGR, CC3G ) ;

	#endif

	// Capture/Compare 4 generation:
	#if	CC4_GEN == CC_GENERATED

	SET_BIT( TIM1->EGR, CC4G ) ;

	#elif CC4_GEN == NO_ACTION

	CLR_BIT( TIM1->EGR, CC4G ) ;

	#endif

	// Capture/Compare control update generation:
	#if	COM_GEN == CC_UPDATED

	SET_BIT( TIM1->EGR, COMG ) ;

	#elif COM_GEN == NO_ACTION

	CLR_BIT( TIM1->EGR, COMG ) ;

	#endif

	// Trigger generation:
	#if	TRG_GEN == TRG_ENABLED

	SET_BIT( TIM1->EGR, TG ) ;

	#elif TRG_GEN == NO_ACTION

	CLR_BIT( TIM1->EGR, TG ) ;

	#endif

	// Break generation:
	#if	BRK_GEN == BRK_GENERATED

	SET_BIT( TIM1->EGR, BG ) ;

	#elif BRK_GEN == NO_ACTION

	CLR_BIT( TIM1->EGR, BG ) ;

	#endif

	/*_______________________CCMR1________________________*/

	// Capture/Compare 1 Selection:
	#if	CC1S == CC1_OUTPUT

	CLR_BIT( TIM1->CCMR1, CC1S0 ) ;
	CLR_BIT( TIM1->CCMR1, CC1S1 ) ;

	#elif CC1S == CC1_INPUT_TI1

	SET_BIT( TIM1->CCMR1, CC1S0 ) ;
	CLR_BIT( TIM1->CCMR1, CC1S1 ) ;

	#elif CC1S == CC1_INPUT_TI2

	CLR_BIT( TIM1->CCMR1, CC1S0 ) ;
	SET_BIT( TIM1->CCMR1, CC1S1 ) ;

	#elif CC1S == CC1_INPUT_TRC

	SET_BIT( TIM1->CCMR1, CC1S0 ) ;
	SET_BIT( TIM1->CCMR1, CC1S1 ) ;

	#endif

	// Capture/Compare 2 Selection:
	#if	CC2S == CC2_OUTPUT

	CLR_BIT( TIM1->CCMR1, CC2S0 ) ;
	CLR_BIT( TIM1->CCMR1, CC2S1 ) ;

	#elif CC2S == CC2_INPUT_TI1

	SET_BIT( TIM1->CCMR1, CC2S0 ) ;
	CLR_BIT( TIM1->CCMR1, CC2S1 ) ;

	#elif CC2S == CC2_INPUT_TI2

	CLR_BIT( TIM1->CCMR1, CC2S0 ) ;
	SET_BIT( TIM1->CCMR1, CC2S1 ) ;

	#elif CC2S == CC2_INPUT_TRC

	SET_BIT( TIM1->CCMR1, CC2S0 ) ;
	SET_BIT( TIM1->CCMR1, CC2S1 ) ;

	#endif

	// Input capture 1 prescaler:
	#if	IC1PSC == NO_PRESCALER

	CLR_BIT( TIM1->CCMR1, IC1PSC0 ) ;
	CLR_BIT( TIM1->CCMR1, IC1PSC1 ) ;

	#elif IC1PSC == EVERY_2_EVENTS

	SET_BIT( TIM1->CCMR1, IC1PSC0 ) ;
	CLR_BIT( TIM1->CCMR1, IC1PSC1 ) ;

	#elif IC1PSC == EVERY_4_EVENTS

	CLR_BIT( TIM1->CCMR1, IC1PSC0 ) ;
	SET_BIT( TIM1->CCMR1, IC1PSC1 ) ;

	#elif IC1PSC == EVERY_8_EVENTS

	SET_BIT( TIM1->CCMR1, IC1PSC0 ) ;
	SET_BIT( TIM1->CCMR1, IC1PSC1 ) ;

	#endif


	// Input capture 2 prescaler:
	#if	IC2PSC == NO_PRESCALER

	CLR_BIT( TIM1->CCMR1, IC2PSC0 ) ;
	CLR_BIT( TIM1->CCMR1, IC2PSC1 ) ;

	#elif IC2PSC == EVERY_2_EVENTS

	SET_BIT( TIM1->CCMR1, IC2PSC0 ) ;
	CLR_BIT( TIM1->CCMR1, IC2PSC1 ) ;

	#elif IC2PSC == EVERY_4_EVENTS

	CLR_BIT( TIM1->CCMR1, IC2PSC0 ) ;
	SET_BIT( TIM1->CCMR1, IC2PSC1 ) ;

	#elif IC2PSC == EVERY_8_EVENTS

	SET_BIT( TIM1->CCMR1, IC2PSC0 ) ;
	SET_BIT( TIM1->CCMR1, IC2PSC1 ) ;

	#endif

	// Output Compare 1 fast enable:
	#if	OC1F_EN == NORMALLY

	CLR_BIT( TIM1->CCMR1, OC1FE ) ;

	#elif OC1F_EN == INPUT_TRIGGER

	SET_BIT( TIM1->CCMR1, OC1FE ) ;

	#endif

	// Output Compare 1 preload enable:
	#if	OC1P_EN == ENABLE

	SET_BIT( TIM1->CCMR1, OC1PE ) ;

	#elif OC1P_EN == DISABLE

	CLR_BIT( TIM1->CCMR1, OC1PE ) ;

	#endif

	// Output Compare 1 mode:
	#if	OC1M == FROZEN

	CLR_BIT( TIM1->CCMR1, OC1M0 ) ;
	CLR_BIT( TIM1->CCMR1, OC1M1 ) ;
	CLR_BIT( TIM1->CCMR1, OC1M2 ) ;

	#elif OC1M == OC1REF_HIGH

	SET_BIT( TIM1->CCMR1, OC1M0 ) ;
	CLR_BIT( TIM1->CCMR1, OC1M1 ) ;
	CLR_BIT( TIM1->CCMR1, OC1M2 ) ;

	#elif OC1M == OC1REF_LOW

	CLR_BIT( TIM1->CCMR1, OC1M0 ) ;
	SET_BIT( TIM1->CCMR1, OC1M1 ) ;
	CLR_BIT( TIM1->CCMR1, OC1M2 ) ;

	#elif OC1M == OC1REF_TOGGLE

	SET_BIT( TIM1->CCMR1, OC1M0 ) ;
	SET_BIT( TIM1->CCMR1, OC1M1 ) ;
	CLR_BIT( TIM1->CCMR1, OC1M2 ) ;

	#elif OC1M == OC1REF_FORCED_LOW

	CLR_BIT( TIM1->CCMR1, OC1M0 ) ;
	CLR_BIT( TIM1->CCMR1, OC1M1 ) ;
	SET_BIT( TIM1->CCMR1, OC1M2 ) ;

	#elif OC1M == OC1REF_FORCED_HIGH

	SET_BIT( TIM1->CCMR1, OC1M0 ) ;
	CLR_BIT( TIM1->CCMR1, OC1M1 ) ;
	SET_BIT( TIM1->CCMR1, OC1M2 ) ;

	#elif OC1M == PWM1

	CLR_BIT( TIM1->CCMR1, OC1M0 ) ;
	SET_BIT( TIM1->CCMR1, OC1M1 ) ;
	SET_BIT( TIM1->CCMR1, OC1M2 ) ;

	#elif OC1M == PWM2

	SET_BIT( TIM1->CCMR1, OC1M0 ) ;
	SET_BIT( TIM1->CCMR1, OC1M1 ) ;
	SET_BIT( TIM1->CCMR1, OC1M2 ) ;

	#endif

	// Output Compare 1 clear enable:
	#if	OC1C_EN == OC1Ref_NOTEFFECTED

	CLR_BIT( TIM1->CCMR1, OC1CE ) ;

	#elif OC1C_EN == OC1Ref_CLEARED

	SET_BIT( TIM1->CCMR1, OC1CE ) ;

	#endif

	// Output Compare 2 fast enable:
	#if	OC2F_EN == NORMALLY

	CLR_BIT( TIM1->CCMR1, OC2FE ) ;

	#elif OC2F_EN == INPUT_TRIGGER

	SET_BIT( TIM1->CCMR1, OC2FE ) ;

	#endif

	// Output Compare 2 preload enable:
	#if	OC2P_EN == ENABLE

	SET_BIT( TIM1->CCMR1, OC2PE ) ;

	#elif OC2P_EN == DISABLE

	CLR_BIT( TIM1->CCMR1, OC2PE ) ;

	#endif

	// Output Compare 2 mode:
	#if	OC2M == FROZEN

	CLR_BIT( TIM1->CCMR1, OC2M0 ) ;
	CLR_BIT( TIM1->CCMR1, OC2M1 ) ;
	CLR_BIT( TIM1->CCMR1, OC2M2 ) ;

	#elif OC2M == OC2REF_HIGH

	SET_BIT( TIM1->CCMR1, OC2M0 ) ;
	CLR_BIT( TIM1->CCMR1, OC2M1 ) ;
	CLR_BIT( TIM1->CCMR1, OC2M2 ) ;

	#elif OC2M == OC2REF_LOW

	CLR_BIT( TIM1->CCMR1, OC2M0 ) ;
	SET_BIT( TIM1->CCMR1, OC2M1 ) ;
	CLR_BIT( TIM1->CCMR1, OC2M2 ) ;

	#elif OC2M == OC2REF_TOGGLE

	SET_BIT( TIM1->CCMR1, OC2M0 ) ;
	SET_BIT( TIM1->CCMR1, OC2M1 ) ;
	CLR_BIT( TIM1->CCMR1, OC2M2 ) ;

	#elif OC2M == OC2REF_FORCED_LOW

	CLR_BIT( TIM1->CCMR1, OC2M0 ) ;
	CLR_BIT( TIM1->CCMR1, OC2M1 ) ;
	SET_BIT( TIM1->CCMR1, OC2M2 ) ;

	#elif OC2M == OC2REF_FORCED_HIGH

	SET_BIT( TIM1->CCMR1, OC2M0 ) ;
	CLR_BIT( TIM1->CCMR1, OC2M1 ) ;
	SET_BIT( TIM1->CCMR1, OC2M2 ) ;

	#elif OC2M == PWM1

	CLR_BIT( TIM1->CCMR1, OC2M0 ) ;
	SET_BIT( TIM1->CCMR1, OC2M1 ) ;
	SET_BIT( TIM1->CCMR1, OC2M2 ) ;

	#elif OC2M == PWM2

	SET_BIT( TIM1->CCMR1, OC2M0 ) ;
	SET_BIT( TIM1->CCMR1, OC2M1 ) ;
	SET_BIT( TIM1->CCMR1, OC2M2 ) ;

	#endif

	// Output Compare 2 clear enable:
	#if	OC2C_EN == OC2Ref_NOTEFFECTED

	CLR_BIT( TIM1->CCMR1, OC2CE ) ;

	#elif OC2C_EN == OC2Ref_CLEARED

	SET_BIT( TIM1->CCMR1, OC2CE ) ;

	#endif

	/*_______________________CCMR2________________________*/

	// Capture/Compare 3 Selection:
	#if	CC3S == CC3_OUTPUT

	CLR_BIT( TIM1->CCMR2, CC3S0 ) ;
	CLR_BIT( TIM1->CCMR2, CC3S1 ) ;

	#elif CC3S == CC3_INPUT_TI1

	SET_BIT( TIM1->CCMR2, CC3S0 ) ;
	CLR_BIT( TIM1->CCMR2, CC3S1 ) ;

	#elif CC3S == CC3_INPUT_TI2

	CLR_BIT( TIM1->CCMR2, CC3S0 ) ;
	SET_BIT( TIM1->CCMR2, CC3S1 ) ;

	#elif CC3S == CC3_INPUT_TRC

	SET_BIT( TIM1->CCMR2, CC3S0 ) ;
	SET_BIT( TIM1->CCMR2, CC3S1 ) ;

	#endif

	// Capture/Compare 4 Selection:
	#if	CC4S == CC4_OUTPUT

	CLR_BIT( TIM1->CCMR2, CC4S0 ) ;
	CLR_BIT( TIM1->CCMR2, CC4S1 ) ;

	#elif CC4S == CC4_INPUT_TI1

	SET_BIT( TIM1->CCMR2, CC4S0 ) ;
	CLR_BIT( TIM1->CCMR2, CC4S1 ) ;

	#elif CC4S == CC4_INPUT_TI2

	CLR_BIT( TIM1->CCMR2, CC4S0 ) ;
	SET_BIT( TIM1->CCMR2, CC4S1 ) ;

	#elif CC4S == CC4_INPUT_TRC

	SET_BIT( TIM1->CCMR2, CC4S0 ) ;
	SET_BIT( TIM1->CCMR2, CC4S1 ) ;

	#endif

	// Input capture 3 prescaler:
	#if	IC3PSC == NO_PRESCALER

	CLR_BIT( TIM1->CCMR2, IC3PSC0 ) ;
	CLR_BIT( TIM1->CCMR2, IC3PSC1 ) ;

	#elif IC3PSC == EVERY_2_EVENTS

	SET_BIT( TIM1->CCMR2, IC3PSC0 ) ;
	CLR_BIT( TIM1->CCMR2, IC3PSC1 ) ;

	#elif IC3PSC == EVERY_4_EVENTS

	CLR_BIT( TIM1->CCMR2, IC3PSC0 ) ;
	SET_BIT( TIM1->CCMR2, IC3PSC1 ) ;

	#elif IC3PSC == EVERY_8_EVENTS

	SET_BIT( TIM1->CCMR2, IC3PSC0 ) ;
	SET_BIT( TIM1->CCMR2, IC3PSC1 ) ;

	#endif

	// Input capture 4 prescaler:
	#if	IC4PSC == NO_PRESCALER

	CLR_BIT( TIM1->CCMR2, IC4PSC0 ) ;
	CLR_BIT( TIM1->CCMR2, IC4PSC1 ) ;

	#elif IC4PSC == EVERY_2_EVENTS

	SET_BIT( TIM1->CCMR2, IC4PSC0 ) ;
	CLR_BIT( TIM1->CCMR2, IC4PSC1 ) ;

	#elif IC4PSC == EVERY_4_EVENTS

	CLR_BIT( TIM1->CCMR2, IC4PSC0 ) ;
	SET_BIT( TIM1->CCMR2, IC4PSC1 ) ;

	#elif IC4PSC == EVERY_8_EVENTS

	SET_BIT( TIM1->CCMR2, IC4PSC0 ) ;
	SET_BIT( TIM1->CCMR2, IC4PSC1 ) ;

	#endif

	// Output Compare 3 fast enable:
	#if	OC3F_EN == NORMALLY

	CLR_BIT( TIM1->CCMR2, OC3FE ) ;

	#elif OC3F_EN == INPUT_TRIGGER

	SET_BIT( TIM1->CCMR2, OC3FE ) ;

	#endif

	// Output Compare 3 preload enable:
	#if	OC1P_EN == ENABLE

	SET_BIT( TIM1->CCMR2, OC3PE ) ;

	#elif OC1P_EN == DISABLE

	CLR_BIT( TIM1->CCMR2, OC3PE ) ;

	#endif

	// Output Compare 3 mode:
	#if	OC3M == FROZEN

	CLR_BIT( TIM1->CCMR2, OC3M0 ) ;
	CLR_BIT( TIM1->CCMR2, OC3M1 ) ;
	CLR_BIT( TIM1->CCMR2, OC3M2 ) ;

	#elif OC3M == OC3REF_HIGH

	SET_BIT( TIM1->CCMR2, OC3M0 ) ;
	CLR_BIT( TIM1->CCMR2, OC3M1 ) ;
	CLR_BIT( TIM1->CCMR2, OC3M2 ) ;

	#elif OC3M == OC3REF_LOW

	CLR_BIT( TIM1->CCMR2, OC3M0 ) ;
	SET_BIT( TIM1->CCMR2, OC3M1 ) ;
	CLR_BIT( TIM1->CCMR2, OC3M2 ) ;

	#elif OC3M == OC3REF_TOGGLE

	SET_BIT( TIM1->CCMR2, OC3M0 ) ;
	SET_BIT( TIM1->CCMR2, OC3M1 ) ;
	CLR_BIT( TIM1->CCMR2, OC3M2 ) ;

	#elif OC3M == OC3REF_FORCED_LOW

	CLR_BIT( TIM1->CCMR2, OC3M0 ) ;
	CLR_BIT( TIM1->CCMR2, OC3M1 ) ;
	SET_BIT( TIM1->CCMR2, OC3M2 ) ;

	#elif OC3M == OC3REF_FORCED_HIGH

	SET_BIT( TIM1->CCMR2, OC3M0 ) ;
	CLR_BIT( TIM1->CCMR2, OC3M1 ) ;
	SET_BIT( TIM1->CCMR2, OC3M2 ) ;

	#elif OC3M == PWM1

	CLR_BIT( TIM1->CCMR2, OC3M0 ) ;
	SET_BIT( TIM1->CCMR2, OC3M1 ) ;
	SET_BIT( TIM1->CCMR2, OC3M2 ) ;

	#elif OC3M == PWM2

	SET_BIT( TIM1->CCMR2, OC3M0 ) ;
	SET_BIT( TIM1->CCMR2, OC3M1 ) ;
	SET_BIT( TIM1->CCMR2, OC3M2 ) ;

	#endif

	// Output Compare 3 clear enable:
	#if	OC3C_EN == OC3Ref_NOTEFFECTED

	CLR_BIT( TIM1->CCMR2, OC3CE ) ;

	#elif OC3C_EN == OC3Ref_CLEARED

	SET_BIT( TIM1->CCMR2, OC3CE ) ;

	#endif

	// Output Compare 4 fast enable:
	#if	OC4F_EN == NORMALLY

	CLR_BIT( TIM1->CCMR2, OC4FE ) ;

	#elif OC4F_EN == INPUT_TRIGGER

	SET_BIT( TIM1->CCMR2, OC4FE ) ;

	#endif

	// Output Compare 4 preload enable:
	#if	OC4P_EN == ENABLE

	SET_BIT( TIM1->CCMR2, OC4PE ) ;

	#elif OC4P_EN == DISABLE

	CLR_BIT( TIM1->CCMR2, OC4PE ) ;

	#endif

	// Output Compare 4 mode:
	#if	OC4M == FROZEN

	CLR_BIT( TIM1->CCMR2, OC4M0 ) ;
	CLR_BIT( TIM1->CCMR2, OC4M1 ) ;
	CLR_BIT( TIM1->CCMR2, OC4M2 ) ;

	#elif OC4M == OC4REF_HIGH

	SET_BIT( TIM1->CCMR2, OC4M0 ) ;
	CLR_BIT( TIM1->CCMR2, OC4M1 ) ;
	CLR_BIT( TIM1->CCMR2, OC4M2 ) ;

	#elif OC4M == OC4REF_LOW

	CLR_BIT( TIM1->CCMR2, OC4M0 ) ;
	SET_BIT( TIM1->CCMR2, OC4M1 ) ;
	CLR_BIT( TIM1->CCMR2, OC4M2 ) ;

	#elif OC4M == OC4REF_TOGGLE

	SET_BIT( TIM1->CCMR2, OC4M0 ) ;
	SET_BIT( TIM1->CCMR2, OC4M1 ) ;
	CLR_BIT( TIM1->CCMR2, OC4M2 ) ;

	#elif OC4M == OC4REF_FORCED_LOW

	CLR_BIT( TIM1->CCMR2, OC4M0 ) ;
	CLR_BIT( TIM1->CCMR2, OC4M1 ) ;
	SET_BIT( TIM1->CCMR2, OC4M2 ) ;

	#elif OC4M == OC4REF_FORCED_HIGH

	SET_BIT( TIM1->CCMR2, OC4M0 ) ;
	CLR_BIT( TIM1->CCMR2, OC4M1 ) ;
	SET_BIT( TIM1->CCMR2, OC4M2 ) ;

	#elif OC4M == PWM1

	CLR_BIT( TIM1->CCMR2, OC4M0 ) ;
	SET_BIT( TIM1->CCMR2, OC4M1 ) ;
	SET_BIT( TIM1->CCMR2, OC4M2 ) ;

	#elif OC4M == PWM2

	SET_BIT( TIM1->CCMR2, OC4M0 ) ;
	SET_BIT( TIM1->CCMR2, OC4M1 ) ;
	SET_BIT( TIM1->CCMR2, OC4M2 ) ;

	#endif

	// Output Compare 4 clear enable:
	#if	OC4C_EN == OC4Ref_NOTEFFECTED

	CLR_BIT( TIM1->CCMR2, OC4CE ) ;

	#elif OC4C_EN == OC4Ref_CLEARED

	SET_BIT( TIM1->CCMR2, OC4CE ) ;

	#endif

	/*_______________________CCER________________________*/

	// Capture/Compare 1 output enable:
	#if	CC1_EN == ENABLE

	SET_BIT( TIM1->CCER, CC1E ) ;

	#elif CC1_EN == DISABLE

	CLR_BIT( TIM1->CCER, CC1E ) ;

	#endif

	// Capture/Compare 1 output polarity:
	#if	CC1_POLARITY == ACTIVE_HIGH

	CLR_BIT( TIM1->CCER, CC1P ) ;

	#elif CC1_POLARITY == ACTIVE_LOW

	SET_BIT( TIM1->CCER, CC1P ) ;

	#endif

	// Capture/Compare 1 complementary output enable:
	#if	CC1N_EN == ENABLE

	SET_BIT( TIM1->CCER, CC1NE ) ;

	#elif CC1N_EN == DISABLE

	CLR_BIT( TIM1->CCER, CC1NE ) ;

	#endif

	// Capture/Compare 1 complementary output polarity:
	#if	CC1N_POLARITY == ACTIVE_HIGH

	CLR_BIT( TIM1->CCER, CC1NP ) ;

	#elif CC1N_POLARITY == ACTIVE_LOW

	SET_BIT( TIM1->CCER, CC1NP ) ;

	#endif

	// Capture/Compare 2 output enable:
	#if	CC2_EN == ENABLE

	SET_BIT( TIM1->CCER, CC2E ) ;

	#elif CC2_EN == DISABLE

	CLR_BIT( TIM1->CCER, CC2E ) ;

	#endif

	// Capture/Compare 2 output polarity:
	#if	CC2_POLARITY == ACTIVE_HIGH

	CLR_BIT( TIM1->CCER, CC2P ) ;

	#elif CC2_POLARITY == ACTIVE_LOW

	SET_BIT( TIM1->CCER, CC2P ) ;

	#endif

	// Capture/Compare 2 complementary output enable:
	#if	CC2N_EN == ENABLE

	SET_BIT( TIM1->CCER, CC2NE ) ;

	#elif CC2N_EN == DISABLE

	CLR_BIT( TIM1->CCER, CC2NE ) ;

	#endif

	// Capture/Compare 2 complementary output polarity:
	#if	CC2N_POLARITY == ACTIVE_HIGH

	CLR_BIT( TIM1->CCER, CC2NP ) ;

	#elif CC2N_POLARITY == ACTIVE_LOW

	SET_BIT( TIM1->CCER, CC2NP ) ;

	#endif

	// Capture/Compare 3 output enable:
	#if	CC3_EN == ENABLE

	SET_BIT( TIM1->CCER, CC3E ) ;

	#elif CC3_EN == DISABLE

	CLR_BIT( TIM1->CCER, CC3E ) ;

	#endif

	// Capture/Compare 3 output polarity:
	#if	CC1_POLARITY == ACTIVE_HIGH

	CLR_BIT( TIM1->CCER, CC3P ) ;

	#elif CC1_POLARITY == ACTIVE_LOW

	SET_BIT( TIM1->CCER, CC3P ) ;

	#endif

	// Capture/Compare 3 complementary output enable:
	#if	CC3N_EN == ENABLE

	SET_BIT( TIM1->CCER, CC3NE ) ;

	#elif CC3N_EN == DISABLE

	CLR_BIT( TIM1->CCER, CC3NE ) ;

	#endif

	// Capture/Compare 3 complementary output polarity:
	#if	CC3N_POLARITY == ACTIVE_HIGH

	CLR_BIT( TIM1->CCER, CC3NP ) ;

	#elif CC3N_POLARITY == ACTIVE_LOW

	SET_BIT( TIM1->CCER, CC3NP ) ;

	#endif

	// Capture/Compare 4 output enable:
	#if	CC4_EN == ENABLE

	SET_BIT( TIM1->CCER, CC4E ) ;

	#elif CC4_EN == DISABLE

	CLR_BIT( TIM1->CCER, CC4E ) ;

	#endif

	// Capture/Compare 4 output polarity:
	#if	CC4_POLARITY == ACTIVE_HIGH

	CLR_BIT( TIM1->CCER, CC4P ) ;

	#elif CC4_POLARITY == ACTIVE_LOW

	SET_BIT( TIM1->CCER, CC4P ) ;

	#endif

	/*_______________________BDTR________________________*/

	// Off-state selection for Idle mode:
	#if	OSSI_MODE == OC_ENABLE

	SET_BIT( TIM1->BDTR, OSSI ) ;

	#elif OSSI_MODE == OC_DISABLE

	CLR_BIT( TIM1->BDTR, OSSI ) ;

	#endif

	// Off-state selection for Run mode:
	#if	OSSR_MODE == OC_ENABLE

	SET_BIT( TIM1->BDTR, OSSR ) ;

	#elif OSSR_MODE == OC_DISABLE

	CLR_BIT( TIM1->BDTR, OSSR ) ;

	#endif

	// Automatic output enable:
	#if	AO_EN == AUTO

	SET_BIT( TIM1->BDTR, AOE ) ;

	#elif AO_EN == SW

	CLR_BIT( TIM1->BDTR, AOE ) ;

	#endif

	// Main output enable:
	#if	MO_EN == OC_ENABLE

	SET_BIT( TIM1->BDTR, MOE ) ;

	#elif MO_EN == OC_DISABLE

	CLR_BIT( TIM1->BDTR, MOE ) ;

	#endif

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vSetCounterValue( u16_t A_u16CNT_Value )
{

	TIM1->CNT = A_u16CNT_Value ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vSetPrescalerValue( u16_t A_u16PSC_Value )
{

	TIM1->PSC = A_u16PSC_Value ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vSetAutoReloadValue( u16_t A_u16ARR_Value )
{

	TIM1->ARR = A_u16ARR_Value ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vSetRepetitionValue( u8_t A_u8RCR_Value )
{

	TIM1->RCR = A_u8RCR_Value ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vSetCompareReg1Value( u16_t A_u16CCR1_Value )
{

	TIM1->CCR1 = A_u16CCR1_Value ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

u16_t MTIM1_u16GetCaptureReg1Value( void )
{

	return TIM1->CCR1 ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vSetCompareReg2Value( u16_t A_u16CCR2_Value )
{

	TIM1->CCR2 = A_u16CCR2_Value ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

u16_t MTIM1_u16GetCaptureReg2Value( void )
{

	return TIM1->CCR2 ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vSetCompareReg3Value( u16_t A_u16CCR3_Value )
{

	TIM1->CCR3 = A_u16CCR3_Value ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

u16_t MTIM1_u16GetCaptureReg3Value( void )
{

	return TIM1->CCR3 ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vSetCompareReg4Value( u16_t A_u16CCR4_Value )
{

	TIM1->CCR4 = A_u16CCR4_Value ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

u16_t MTIM1_u16GetCaptureReg4Value( void )
{

	return TIM1->CCR4 ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vGeneratePWM( u8_t A_u8T1CHx, u8_t A_u8PWM_Mode, u8_t A_u8CenterMode,
					u16_t A_u16PSC_Value, u16_t A_u16ARR_Value, u16_t A_u16CCRx_Value )
{

	// Auto-reload preload enable:
	SET_BIT( TIM1->CR1, ARPE ) ;

	// Set counter direction as up-counter:
	CLR_BIT( TIM1->CR1, DIR ) ;

	// Compare - OC1REF signal is used as trigger output (TRGO):
	CLR_BIT( TIM1->CR2, MMS0 ) ;
	CLR_BIT( TIM1->CR2, MMS1 ) ;
	SET_BIT( TIM1->CR2, MMS2 ) ;

	// Select master mode Compare:
	SET_BIT( TIM1->SMCR, MSM ) ;

	// Set timer Prescaler, bus clock = 8 MHz, fCK_PSC / (PSC[15:0] + 1)
	// CK_CNT = F / (PSC+1) -> FREQ Hz -> time base = 1/FREQ
	TIM1->PSC = A_u16PSC_Value ;

	// Set timer auto reload value:
	TIM1->ARR = A_u16ARR_Value ;

	// Set timer compare value:
	switch( A_u8T1CHx )
	{
		case TIM1_CH1: TIM1->CCR1 = A_u16CCRx_Value ; break ;

		case TIM1_CH2: TIM1->CCR2 = A_u16CCRx_Value ; break ;

		case TIM1_CH3: TIM1->CCR3 = A_u16CCRx_Value ; break ;

		case TIM1_CH4: TIM1->CCR4 = A_u16CCRx_Value ; break ;
	}

	// Set Capture/Compare CHx as output & preload enable:
	switch( A_u8T1CHx )
	{
		case TIM1_CH1:
		{
			CLR_BIT( TIM1->CCMR1, CC1S0 ) ;
			CLR_BIT( TIM1->CCMR1, CC1S1 ) ;

			SET_BIT( TIM1->CCMR1, OC1PE ) ;
		}
		break ;

		case TIM1_CH2:
		{
			CLR_BIT( TIM1->CCMR1, CC2S0 ) ;
			CLR_BIT( TIM1->CCMR1, CC2S1 ) ;

			SET_BIT( TIM1->CCMR1, OC2PE ) ;
		}
		break ;

		case TIM1_CH3:
		{
			CLR_BIT( TIM1->CCMR2, CC3S0 ) ;
			CLR_BIT( TIM1->CCMR2, CC3S1 ) ;

			SET_BIT( TIM1->CCMR2, OC3PE ) ;
		}
		break ;

		case TIM1_CH4:
		{
			CLR_BIT( TIM1->CCMR2, CC4S0 ) ;
			CLR_BIT( TIM1->CCMR2, CC4S1 ) ;

			SET_BIT( TIM1->CCMR2, OC4PE ) ;
		}
		break ;

	}

	// Select Output Compare PWM mode:
	switch( A_u8T1CHx )
	{
		case TIM1_CH1:
		{
			switch( A_u8PWM_Mode )
			{

				case FROZEN:
				{
					CLR_BIT( TIM1->CCMR1, OC1M0 ) ;
					CLR_BIT( TIM1->CCMR1, OC1M1 ) ;
					CLR_BIT( TIM1->CCMR1, OC1M2 ) ;
				}
				break ;

				case OC1REF_HIGH:
				{
					SET_BIT( TIM1->CCMR1, OC1M0 ) ;
					CLR_BIT( TIM1->CCMR1, OC1M1 ) ;
					CLR_BIT( TIM1->CCMR1, OC1M2 ) ;
				}
				break ;

				case OC1REF_LOW:
				{
					CLR_BIT( TIM1->CCMR1, OC1M0 ) ;
					SET_BIT( TIM1->CCMR1, OC1M1 ) ;
					CLR_BIT( TIM1->CCMR1, OC1M2 ) ;
				}
				break ;

				case OC1REF_TOGGLE:
				{
					SET_BIT( TIM1->CCMR1, OC1M0 ) ;
					SET_BIT( TIM1->CCMR1, OC1M1 ) ;
					CLR_BIT( TIM1->CCMR1, OC1M2 ) ;
				}
				break ;

				case OC1REF_FORCED_LOW:
				{
					CLR_BIT( TIM1->CCMR1, OC1M0 ) ;
					CLR_BIT( TIM1->CCMR1, OC1M1 ) ;
					SET_BIT( TIM1->CCMR1, OC1M2 ) ;
				}
				break ;

				case OC1REF_FORCED_HIGH:
				{
					SET_BIT( TIM1->CCMR1, OC1M0 ) ;
					CLR_BIT( TIM1->CCMR1, OC1M1 ) ;
					SET_BIT( TIM1->CCMR1, OC1M2 ) ;
				}
				break ;

				case PWM1:
				{
					CLR_BIT( TIM1->CCMR1, OC1M0 ) ;
					SET_BIT( TIM1->CCMR1, OC1M1 ) ;
					SET_BIT( TIM1->CCMR1, OC1M2 ) ;
				}
				break ;

				case PWM2:
				{
					SET_BIT( TIM1->CCMR1, OC1M0 ) ;
					SET_BIT( TIM1->CCMR1, OC1M1 ) ;
					SET_BIT( TIM1->CCMR1, OC1M2 ) ;
				}
				break ;
			}
		}
		break ;

		case TIM1_CH2:
		{
			switch( A_u8PWM_Mode )
			{

				case FROZEN:
				{
					CLR_BIT( TIM1->CCMR1, OC2M0 ) ;
					CLR_BIT( TIM1->CCMR1, OC2M1 ) ;
					CLR_BIT( TIM1->CCMR1, OC2M2 ) ;
				}
				break ;

				case OC1REF_HIGH:
				{
					SET_BIT( TIM1->CCMR1, OC2M0 ) ;
					CLR_BIT( TIM1->CCMR1, OC2M1 ) ;
					CLR_BIT( TIM1->CCMR1, OC2M2 ) ;
				}
				break ;

				case OC1REF_LOW:
				{
					CLR_BIT( TIM1->CCMR1, OC2M0 ) ;
					SET_BIT( TIM1->CCMR1, OC2M1 ) ;
					CLR_BIT( TIM1->CCMR1, OC2M2 ) ;
				}
				break ;

				case OC1REF_TOGGLE:
				{
					SET_BIT( TIM1->CCMR1, OC2M0 ) ;
					SET_BIT( TIM1->CCMR1, OC2M1 ) ;
					CLR_BIT( TIM1->CCMR1, OC2M2 ) ;
				}
				break ;

				case OC1REF_FORCED_LOW:
				{
					CLR_BIT( TIM1->CCMR1, OC2M0 ) ;
					CLR_BIT( TIM1->CCMR1, OC2M1 ) ;
					SET_BIT( TIM1->CCMR1, OC2M2 ) ;
				}
				break ;

				case OC1REF_FORCED_HIGH:
				{
					SET_BIT( TIM1->CCMR1, OC2M0 ) ;
					CLR_BIT( TIM1->CCMR1, OC2M1 ) ;
					SET_BIT( TIM1->CCMR1, OC2M2 ) ;
				}
				break ;

				case PWM1:
				{
					CLR_BIT( TIM1->CCMR1, OC2M0 ) ;
					SET_BIT( TIM1->CCMR1, OC2M1 ) ;
					SET_BIT( TIM1->CCMR1, OC2M2 ) ;
				}
				break ;

				case PWM2:
				{
					SET_BIT( TIM1->CCMR1, OC2M0 ) ;
					SET_BIT( TIM1->CCMR1, OC2M1 ) ;
					SET_BIT( TIM1->CCMR1, OC2M2 ) ;
				}
				break ;
			}
		}
		break ;

		case TIM1_CH3:
		{
			switch( A_u8PWM_Mode )
			{

				case FROZEN:
				{
					CLR_BIT( TIM1->CCMR2, OC3M0 ) ;
					CLR_BIT( TIM1->CCMR2, OC3M1 ) ;
					CLR_BIT( TIM1->CCMR2, OC3M2 ) ;
				}
				break ;

				case OC1REF_HIGH:
				{
					SET_BIT( TIM1->CCMR2, OC3M0 ) ;
					CLR_BIT( TIM1->CCMR2, OC3M1 ) ;
					CLR_BIT( TIM1->CCMR2, OC3M2 ) ;
				}
				break ;

				case OC1REF_LOW:
				{
					CLR_BIT( TIM1->CCMR2, OC3M0 ) ;
					SET_BIT( TIM1->CCMR2, OC3M1 ) ;
					CLR_BIT( TIM1->CCMR2, OC3M2 ) ;
				}
				break ;

				case OC1REF_TOGGLE:
				{
					SET_BIT( TIM1->CCMR2, OC3M0 ) ;
					SET_BIT( TIM1->CCMR2, OC3M1 ) ;
					CLR_BIT( TIM1->CCMR2, OC3M2 ) ;
				}
				break ;

				case OC1REF_FORCED_LOW:
				{
					CLR_BIT( TIM1->CCMR2, OC3M0 ) ;
					CLR_BIT( TIM1->CCMR2, OC3M1 ) ;
					SET_BIT( TIM1->CCMR2, OC3M2 ) ;
				}
				break ;

				case OC1REF_FORCED_HIGH:
				{
					SET_BIT( TIM1->CCMR2, OC3M0 ) ;
					CLR_BIT( TIM1->CCMR2, OC3M1 ) ;
					SET_BIT( TIM1->CCMR2, OC3M2 ) ;
				}
				break ;

				case PWM1:
				{
					CLR_BIT( TIM1->CCMR2, OC3M0 ) ;
					SET_BIT( TIM1->CCMR2, OC3M1 ) ;
					SET_BIT( TIM1->CCMR2, OC3M2 ) ;
				}
				break ;

				case PWM2:
				{
					SET_BIT( TIM1->CCMR2, OC3M0 ) ;
					SET_BIT( TIM1->CCMR2, OC3M1 ) ;
					SET_BIT( TIM1->CCMR2, OC3M2 ) ;
				}
				break ;
			}
		}
		break ;

		case TIM1_CH4:
		{
			switch( A_u8PWM_Mode )
			{

				case FROZEN:
				{
					CLR_BIT( TIM1->CCMR2, OC4M0 ) ;
					CLR_BIT( TIM1->CCMR2, OC4M1 ) ;
					CLR_BIT( TIM1->CCMR2, OC4M2 ) ;
				}
				break ;

				case OC1REF_HIGH:
				{
					SET_BIT( TIM1->CCMR2, OC4M0 ) ;
					CLR_BIT( TIM1->CCMR2, OC4M1 ) ;
					CLR_BIT( TIM1->CCMR2, OC4M2 ) ;
				}
				break ;

				case OC1REF_LOW:
				{
					CLR_BIT( TIM1->CCMR2, OC4M0 ) ;
					SET_BIT( TIM1->CCMR2, OC4M1 ) ;
					CLR_BIT( TIM1->CCMR2, OC4M2 ) ;
				}
				break ;

				case OC1REF_TOGGLE:
				{
					SET_BIT( TIM1->CCMR2, OC4M0 ) ;
					SET_BIT( TIM1->CCMR2, OC4M1 ) ;
					CLR_BIT( TIM1->CCMR2, OC4M2 ) ;
				}
				break ;

				case OC1REF_FORCED_LOW:
				{
					CLR_BIT( TIM1->CCMR2, OC4M0 ) ;
					CLR_BIT( TIM1->CCMR2, OC4M1 ) ;
					SET_BIT( TIM1->CCMR2, OC4M2 ) ;
				}
				break ;

				case OC1REF_FORCED_HIGH:
				{
					SET_BIT( TIM1->CCMR2, OC4M0 ) ;
					CLR_BIT( TIM1->CCMR2, OC4M1 ) ;
					SET_BIT( TIM1->CCMR2, OC4M2 ) ;
				}
				break ;

				case PWM1:
				{
					CLR_BIT( TIM1->CCMR2, OC4M0 ) ;
					SET_BIT( TIM1->CCMR2, OC4M1 ) ;
					SET_BIT( TIM1->CCMR2, OC4M2 ) ;
				}
				break ;

				case PWM2:
				{
					SET_BIT( TIM1->CCMR2, OC4M0 ) ;
					SET_BIT( TIM1->CCMR2, OC4M1 ) ;
					SET_BIT( TIM1->CCMR2, OC4M2 ) ;
				}
				break ;
			}
		}
		break ;
	}

	// Center-aligned mode selection:
	switch( A_u8CenterMode )
	{
		case EDGE:
		{
			CLR_BIT( TIM1->CR1, CMS0 ) ;
			CLR_BIT( TIM1->CR1, CMS1 ) ;
		}
		break ;

		case CENTER1:
		{
			SET_BIT( TIM1->CR1, CMS0 ) ;
			CLR_BIT( TIM1->CR1, CMS1 ) ;
		}
		break ;

		case CENTER2:
		{
			CLR_BIT( TIM1->CR1, CMS0 ) ;
			SET_BIT( TIM1->CR1, CMS1 ) ;
		}
		break ;

		case CENTER3:
		{
			SET_BIT( TIM1->CR1, CMS0 ) ;
			SET_BIT( TIM1->CR1, CMS1 ) ;
		}
		break ;
	}

    // Initialize all the registers:
    SET_BIT( TIM1->EGR, UG ) ;

	// Enable Capture/Compare output:
	if( A_u8T1CHx == TIM1_CH1 )
	{
		CLR_BIT( TIM1->CCER, CC1P ) ;

		SET_BIT( TIM1->CCER, CC1E ) ;

		MGPIOx_ConfigType T1_CH1 =
		{
			.Port 			= T1CHx_PORT 			, 	.Pin 		= T1CH1_PIN 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_LowSpeed		, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF1
		} ;

		MGPIOx_vInit( &T1_CH1 ) ;
	}
    else
    {
		CLR_BIT( TIM1->CCER, CC1E ) ;
    }

	if( A_u8T1CHx == TIM1_CH2 )
	{
		CLR_BIT( TIM1->CCER, CC2P ) ;

		SET_BIT( TIM1->CCER, CC2E ) ;

		MGPIOx_ConfigType T1_CH2 =
		{
			.Port 			= T1CHx_PORT 			, 	.Pin 		= T1CH2_PIN 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_LowSpeed		, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF1
		} ;

		MGPIOx_vInit( &T1_CH2 ) ;
	}
    else
    {
    	CLR_BIT( TIM1->CCER, CC2E ) ;
    }

  	if( A_u8T1CHx == TIM1_CH3 )
  	{
		CLR_BIT( TIM1->CCER, CC3P ) ;

		SET_BIT( TIM1->CCER, CC3E ) ;

		MGPIOx_ConfigType T1_CH3 =
		{
			.Port 			= T1CHx_PORT 			, 	.Pin 		= T1CH3_PIN 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_LowSpeed		, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF1
		} ;

		MGPIOx_vInit( &T1_CH3 ) ;
  	}
    else
    {
    	CLR_BIT( TIM1->CCER, CC3E ) ;
    }

  	if( A_u8T1CHx == TIM1_CH4 )
  	{
		CLR_BIT( TIM1->CCER, CC4P ) ;

		SET_BIT( TIM1->CCER, CC4E ) ;

		MGPIOx_ConfigType T1_CH4 =
		{
			.Port 			= T1CHx_PORT 			, 	.Pin 		= T1CH4_PIN 		,
			.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
			.OutputSpeed 	= GPIOx_LowSpeed		, 	.InputType 	= GPIOx_NoPull		,
			.AF_Type 		= GPIOx_AF1
		} ;

		MGPIOx_vInit( &T1_CH4 ) ;
  	}
    else
    {
    	CLR_BIT( TIM1->CCER, CC4E ) ;
    }

    // Enable timer main output:
    SET_BIT( TIM1->BDTR, MOE ) ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vReadPWM( void )
{

	// Enable ICU PINs:
	MGPIOx_ConfigType T1_CH1 =
	{
		.Port 			= T1CHx_PORT 			, 	.Pin 		= T1CH1_PIN 		,
		.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
		.OutputSpeed 	= GPIOx_LowSpeed		, 	.InputType 	= GPIOx_NoPull		,
		.AF_Type 		= GPIOx_AF1
	} ;

	MGPIOx_ConfigType T1_CH2 =
	{
		.Port 			= T1CHx_PORT 			, 	.Pin 		= T1CH2_PIN 		,
		.Mode 			= GPIOx_MODE_AF 		, 	.OutputType = GPIOx_PUSHPULL 	,
		.OutputSpeed 	= GPIOx_LowSpeed		, 	.InputType 	= GPIOx_NoPull		,
		.AF_Type 		= GPIOx_AF1
	} ;

	MGPIOx_vInit( &T1_CH1 ) ;
	MGPIOx_vInit( &T1_CH2 ) ;

	// TIM1 IC1 Configurations:
	// Select TI1 for CCR1:
	SET_BIT( TIM1->CCMR1, CC1S0 ) ;
	CLR_BIT( TIM1->CCMR1, CC1S1 ) ;

	// Select active Rising edge for TI1FP1:
	CLR_BIT( TIM1->CCER, CC1P 	) ;
	CLR_BIT( TIM1->CCER, CC1NP 	) ;

	// TIM1 IC2 Configurations:
	// Select TI1 for CCR2:
	CLR_BIT( TIM1->CCMR1, CC2S0 ) ;
	SET_BIT( TIM1->CCMR1, CC2S1 ) ;

	// Select active Falling edge for TI1FP2:
	SET_BIT( TIM1->CCER, CC2P 	) ;
	SET_BIT( TIM1->CCER, CC2NP 	) ;

	// TIM1 Trigger Configurations:
	// Select TI1FP1 as trigger input:
	SET_BIT( TIM1->SMCR, TS0 ) ;
	CLR_BIT( TIM1->SMCR, TS1 ) ;
	SET_BIT( TIM1->SMCR, TS2 ) ;

	// Configure Slave mode in reset mode:
	CLR_BIT( TIM1->SMCR, SMS0 ) ;
	CLR_BIT( TIM1->SMCR, SMS1 ) ;
	SET_BIT( TIM1->SMCR, SMS2 ) ;

	// Enable the Captures:
	// Enable CC1:
	SET_BIT( TIM1->CCER, CC1E ) ;

	// Enable CC2:
	SET_BIT( TIM1->CCER, CC2E ) ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vEnableCounter( void )
{

	// Enable the counter:
	SET_BIT( TIM1->CR1, CEN ) ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

void MTIM1_vDisableCounter( void )
{

	// Disable the counter:
	CLR_BIT( TIM1->CR1, CEN ) ;

}

/********************************************************************************************************************/
/*******************************************************************************************************************/

























