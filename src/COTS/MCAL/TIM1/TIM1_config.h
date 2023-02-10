/* FILENAME: TIM1_config  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 01/24/2023
*/
#ifndef _TIM1_config_H
#define _TIM1_config_H

/**********************************************************************************/
/*							  TIM1_CR1 configurations  							  */
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define UPDATE_CNTRL ENABLE

/**********************************************************************************/

/*options:
 *ANY_EVENT
 *OVF_UDF
 */
#define UPDATE_SRC ANY_EVENT

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define OP_MODE DISABLE

/**********************************************************************************/

/*options:
 *UP
 *DOWN
 */
#define CNT_DIR UP

/**********************************************************************************/

/*options:
 *EDGE
 *CENTER1
 *CENTER2
 *CENTER3
 */
#define CMS CENTER3

/**********************************************************************************/

/*options:
 *NOT_BUFFERED
 *BUFFERED
 */
#define ARP_EN BUFFERED

/**********************************************************************************/

/*options:
 *ONE_TCK
 *TWO_TCK
 *FOUR_TCK
 */
#define CKD ONE_TCK

/**********************************************************************************/
/*							  TIM1_CR2 configurations  							  */
/**********************************************************************************/

/*options:
 *NOT_PRELOADED
 *PRELOADED
 */
#define CCP_CTRL NOT_PRELOADED

/**********************************************************************************/

/*options:
 *COMG_ONLY
 *ANY_EVENT
 */
#define CCU_SLCT COMG_ONLY

/**********************************************************************************/

/*options:
 *CCx_EVENT
 *UPDATE_EVENT
 */
#define CCD_SLCT CCx_EVENT

/**********************************************************************************/

/*options:
 *RST
 *ENABLE
 *UPDATE
 *COMP_PULSE
 *COMP1
 *COMP2
 *COMP3
 *COMP4
 */
#define MMS COMP1

/**********************************************************************************/

/*options:
 *CH1
 *CH1_2_3
 */
#define TI1_SLCT CH1

/**********************************************************************************/

/*options:
 *LOW
 *HIGH
 */
#define OC1_IDLE_STATE LOW

/**********************************************************************************/

/*options:
 *LOW
 *HIGH
 */
#define OC1N_IDLE_STATE LOW

/**********************************************************************************/

/*options:
 *LOW
 *HIGH
 */
#define OC2_IDLE_STATE LOW

/**********************************************************************************/

/*options:
 *LOW
 *HIGH
 */
#define OC2N_IDLE_STATE LOW

/**********************************************************************************/

/*options:
 *LOW
 *HIGH
 */
#define OC3_IDLE_STATE LOW

/**********************************************************************************/

/*options:
 *LOW
 *HIGH
 */
#define OC3N_IDLE_STATE LOW

/**********************************************************************************/

/*options:
 *LOW
 *HIGH
 */
#define OC4_IDLE_STATE LOW

/**********************************************************************************/
/*							  TIM1_SMCR configurations  						  */
/**********************************************************************************/

/*options:
 *DISABLE
 *ENCODER1
 *ENCODER2
 *ENCODER3
 *RST
 *GATED
 *TRIGGER
 *EXT_CLK
 */
#define SMS DISABLE

/**********************************************************************************/

/*options:
 *ITR0
 *ITR1
 *ITR2
 *ITR3
 *TI1F_ED
 *TI1FP1
 *TI1FP2
 *ETRF
 */
#define TS ITR0

/**********************************************************************************/

/*options:
 *NO_ACTION
 *TRGI
 */
#define MSTR_SLAVE_MODE TRGI

/**********************************************************************************/

/*options:
 *NO_FLTR
 *FCK_N2
 *FCK_N4
 *FCK_N8
 *FDTS2_N6
 *FDTS2_N8
 *FDTS4_N6
 *FDTS4_N8
 *FDTS8_N6
 *FDTS8_N8
 *FDTS16_N5
 *FDTS16_N6
 *FDTS16_N8
 *FDTS32_N5
 *FDTS32_N6
 *FDTS32_N8
 */
#define EXT_FLTR NO_FLTR

/**********************************************************************************/

/*options:
 *OFF
 *BY2
 *BY4
 *BY8
 */
#define ETPS OFF

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define EXT_CLK_EN DISABLE

/**********************************************************************************/

/*options:
 *NON_INVERTED
 *INVERTED
 */
#define EXTP NON_INVERTED

/**********************************************************************************/
/*							  TIM1_EGR configurations  						 	  */
/**********************************************************************************/

/*options:
 *NO_ACTION
 *RE_INIT
 */
#define UP_GEN RE_INIT

/**********************************************************************************/

/*options:
 *NO_ACTION
 *CC_GENERATED
 */
#define CC1_GEN NO_ACTION

/**********************************************************************************/

/*options:
 *NO_ACTION
 *CC_GENERATED
 */
#define CC2_GEN NO_ACTION

/**********************************************************************************/

/*options:
 *NO_ACTION
 *CC_GENERATED
 */
#define CC3_GEN NO_ACTION

/**********************************************************************************/

/*options:
 *NO_ACTION
 *CC_GENERATED
 */
#define CC4_GEN NO_ACTION

/**********************************************************************************/

/*options:
 *NO_ACTION
 *CC_UPDATED
 */
#define COM_GEN NO_ACTION

/**********************************************************************************/

/*options:
 *NO_ACTION
 *TRG_ENABLED
 */
#define TRG_GEN NO_ACTION

/**********************************************************************************/

/*options:
 *NO_ACTION
 *BRK_GENERATED
 */
#define BRK_GEN NO_ACTION

/**********************************************************************************/
/*							TIM1_CCMR1 configurations  						 	  */
/**********************************************************************************/

/*options:
 *CC1_OUTPUT
 *CC1_INPUT_TI1
 *CC1_INPUT_TI2
 *CC1_INPUT_TRC
 */
#define CC1S CC1_OUTPUT

/**********************************************************************************/

/*options:
 *NO_PRESCALER
 *EVERY_2_EVENTS
 *EVERY_4_EVENTS
 *EVERY_8_EVENTS
 */
#define IC1PSC NO_PRESCALER

/**********************************************************************************/

/*options:
 *CC2_OUTPUT
 *CC2_INPUT_TI1
 *CC2_INPUT_TI2
 *CC2_INPUT_TRC
 */
#define CC2S CC2_OUTPUT

/**********************************************************************************/

/*options:
 *NO_PRESCALER
 *EVERY_2_EVENTS
 *EVERY_4_EVENTS
 *EVERY_8_EVENTS
 */
#define IC2PSC NO_PRESCALER

/**********************************************************************************/

/*options:
 *NORMALLY
 *INPUT_TRIGGER
 */
#define OC1F_EN NORMALLY

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define OC1P_EN ENABLE

/**********************************************************************************/

/*options:
 *FROZEN
 *OC1REF_HIGH
 *OC1REF_LOW
 *OC1REF_TOGGLE
 *OC1REF_FORCED_LOW
 *OC1REF_FORCED_HIGH
 *PWM1
 *PWM2
 */
#define OC1M PWM1

/**********************************************************************************/

/*options:
 *OC1Ref_NOTEFFECTED
 *OC1Ref_CLEARED
 */
#define OC1C_EN OC1Ref_NOTEFFECTED

/**********************************************************************************/

/*options:
 *NORMALLY
 *INPUT_TRIGGER
 */
#define OC2F_EN NO_ACTION

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define OC2P_EN DISABLE

/**********************************************************************************/

/*options:
 *FROZEN
 *OC2REF_HIGH
 *OC2REF_LOW
 *OC2REF_TOGGLE
 *OC2REF_FORCED_LOW
 *OC2REF_FORCED_HIGH
 *PWM1
 *PWM2
 */
#define OC2M FROZEN

/**********************************************************************************/

/*options:
 *OC2Ref_NOTEFFECTED
 *OC2Ref_CLEARED
 */
#define OC2C_EN OC2Ref_NOTEFFECTED

/**********************************************************************************/
/*							TIM1_CCMR2 configurations  						 	  */
/**********************************************************************************/

/*options:
 *CC3_OUTPUT
 *CC3_INPUT_TI3
 *CC3_INPUT_TI4
 *CC3_INPUT_TRC
 */
#define CC3S CC3_OUTPUT

/**********************************************************************************/

/*options:
 *NO_PRESCALER
 *EVERY_2_EVENTS
 *EVERY_4_EVENTS
 *EVERY_8_EVENTS
 */
#define IC3PSC NO_PRESCALER

/**********************************************************************************/

/*options:
 *CC4_OUTPUT
 *CC4_INPUT_TI4
 *CC4_INPUT_TI3
 *CC4_INPUT_TRC
 */
#define CC4S CC4_OUTPUT

/**********************************************************************************/

/*options:
 *NO_PRESCALER
 *EVERY_2_EVENTS
 *EVERY_4_EVENTS
 *EVERY_8_EVENTS
 */
#define IC4PSC NO_PRESCALER

/**********************************************************************************/

/*options:
 *NORMALLY
 *INPUT_TRIGGER
 */
#define OC3F_EN NORMALLY

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define OC3P_EN DISABLE

/**********************************************************************************/

/*options:
 *FROZEN
 *OC3REF_HIGH
 *OC3REF_LOW
 *OC3REF_TOGGLE
 *OC3REF_FORCED_LOW
 *OC3REF_FORCED_HIGH
 *PWM1
 *PWM2
 */
#define OC3M FROZEN

/**********************************************************************************/

/*options:
 *OC3Ref_NOTEFFECTED
 *OC3Ref_CLEARED
 */
#define OC3C_EN OC3Ref_NOTEFFECTED

/**********************************************************************************/

/*options:
 *NORMALLY
 *INPUT_TRIGGER
 */
#define OC4F_EN NORMALLY

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define OC4P_EN DISABLE

/**********************************************************************************/

/*options:
 *FROZEN
 *OC4REF_HIGH
 *OC4REF_LOW
 *OC4REF_TOGGLE
 *OC4REF_FORCED_LOW
 *OC4REF_FORCED_HIGH
 *PWM1
 *PWM2
 */
#define OC4M FROZEN

/**********************************************************************************/

/*options:
 *OC4Ref_NOTEFFECTED
 *OC4Ref_CLEARED
 */
#define OC4C_EN OC4Ref_NOTEFFECTED

/**********************************************************************************/
/*							TIM1_CCER configurations  						 	  */
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CC1_EN ENABLE

/**********************************************************************************/

/*options:
 *ACTIVE_HIGH
 *ACTIVE_LOW
 */
#define CC1_POLARITY ACTIVE_HIGH

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CC1N_EN ENABLE

/**********************************************************************************/

/*options:
 *ACTIVE_HIGH
 *ACTIVE_LOW
 */
#define CC1N_POLARITY ACTIVE_HIGH

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CC2_EN DISABLE

/**********************************************************************************/

/*options:
 *ACTIVE_HIGH
 *ACTIVE_LOW
 */
#define CC2_POLARITY ACTIVE_HIGH

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CC2N_EN DISABLE

/**********************************************************************************/

/*options:
 *ACTIVE_HIGH
 *ACTIVE_LOW
 */
#define CC2N_POLARITY ACTIVE_HIGH

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CC3_EN DISABLE

/**********************************************************************************/

/*options:
 *ACTIVE_HIGH
 *ACTIVE_LOW
 */
#define CC3_POLARITY ACTIVE_HIGH

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CC3N_EN DISABLE

/**********************************************************************************/

/*options:
 *ACTIVE_HIGH
 *ACTIVE_LOW
 */
#define CC3N_POLARITY ACTIVE_HIGH

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CC4_EN DISABLE

/**********************************************************************************/

/*options:
 *ACTIVE_HIGH
 *ACTIVE_LOW
 */
#define CC4_POLARITY ACTIVE_HIGH

/**********************************************************************************/
/*							TIM1_BDTR configurations  						 	  */
/**********************************************************************************/

/*options:
 *OC_DISABLE
 *OC_ENABLE
 */
#define OSSI_MODE OC_ENABLE

/**********************************************************************************/

/*options:
 *OC_DISABLE
 *OC_ENABLE
 */
#define OSSR_MODE OC_ENABLE

/**********************************************************************************/

/*options:
 *SW
 *AUTO
 */
#define AO_EN SW

/**********************************************************************************/

/*options:
 *OC_DISABLE
 *OC_ENABLE
 */
#define MO_EN OC_ENABLE

/**********************************************************************************/








































































#endif //_TIM1_config_H
