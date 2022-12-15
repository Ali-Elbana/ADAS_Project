/* FILENAME: ADC_config  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 12/14/2022
*/
#ifndef _ADC_config_H
#define _ADC_config_H


/**********************************************************************************/
/*							  ADC_CR1 configurations 							  */
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define OVERRUN_INT DISABLE

/**********************************************************************************/

/*options:
 *_12_BITS
 *_10_BITS
 *_8_BITS
 *_6_BITS
 */
#define RESOLUTION _12_BITS

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define ANALOG_WDT DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define INJ_ANALOG_WDT NOTBYBASED

/**********************************************************************************/

/*options:
 *_1_CHANNEL
 *_2_CHANNELS
 *_3_CHANNELS
 *_4_CHANNELS
 *_5_CHANNELS
 *_6_CHANNELS
 *_7_CHANNELS
 *_8_CHANNELS
 */
#define DISC_CHANNEL_NUM _1_CHANNEL

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define INJ_DISC_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define DISC_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define INJ_AUTO_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define AWDSGL_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define SCAN_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define JEOCIE_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define AWDIE_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define EOCIE_MODE DISABLE

/**********************************************************************************/

/*options:
 *ZERO
 *ONE
 *THREE
 *FOUR
 *FIVE
 *SIX
 *SEVEN
 *EIGHT
 *NINE
 *TEN
 *ELEVEN
 *TWELVE
 *THERTEEN
 *FOURTEEN
 *FIFTEEN
 *SIXTEEN
 *SEVENTEEN
 *EIGHTEEN
 */
#define AWD_CHANNEL ZERO

/**********************************************************************************/
/*							  ADC_CR2 configurations 							  */
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define REG_START_CONV ENABLE

/**********************************************************************************/

/*options:
 *DISABLE
 *RISING
 *FALLING
 *ON_CHANGE
 */
#define REG_EXTERNAL_TRIGGER DISABLE

/**********************************************************************************/

/*options:
 *T1_CC1
 *T1_CC2
 *T1_CC3
 *T2_CC2
 *T2_CC3
 *T2_CC4
 *REG_T2_TRGO
 *T3_CC1
 *T3_TRGO
 *T4_CC4
 *T5_CC1
 *T5_CC2
 *T5_CC3
 *EXTI_LINE11
 */
#define REG_EXT_EVENT_SRC EXTI_LINE11

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define INJ_START_CONV DISABLE

/**********************************************************************************/

/*options:
 *DISABLE
 *RISING
 *FALLING
 *ON_CHANGE
 */
#define INJ_EXTERNAL_TRIGGER DISABLE

/**********************************************************************************/

/*options:
 *T1_CC4
 *T1_TRGO
 *T2_CC1
 *INJ_T2_TRGO
 *T3_CC2
 *T3_CC4
 *T4_CC1
 *T4_CC2
 *T4_CC3
 *T4_TRGO
 *T5_CC4
 *T5_TRGO
 *EXTI_LINE15
 */
#define INJ_EXT_EVENT_SRC EXTI_LINE15

/**********************************************************************************/

/*options:
 *RIGHT
 *LEFT
 */
#define DATA_ALIGN RIGHT

/**********************************************************************************/

/*options:
 *SEQUENCE
 *REG_CONV
 */
#define EOC_SELECTION REG_CONV

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define DMA_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define DMA_DIS_SELECTION DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CONT_CONV ENABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define ADC_ON ENABLE

/**********************************************************************************/
/*							  ADC_SMPR1 configurations 							  */
/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP10 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP11 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP12 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP13 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP14 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP15 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP16 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP17 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP18 _3_CYCLES

/**********************************************************************************/
/*							  ADC_SMPR2 configurations 							  */
/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP0 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP1 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP2 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP3 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP4 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP5 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP6 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP7 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP8 _3_CYCLES

/**********************************************************************************/

/*options:
 *_3_CYCLES
 *_15_CYCLES
 *_28_CYCLES
 *_56_CYCLES
 *_84_CYCLES
 *_112_CYCLES
 *_144_CYCLES
 *_480_CYCLES
 */
#define SMP9 _3_CYCLES

/**********************************************************************************/
/*							  ADC_SQR1 configurations 							  */
/**********************************************************************************/

/*options:
 *_1_CONV
 *_2_CONV
 *_3_CONV
 *_4_CONV
 *_5_CONV
 *_6_CONV
 *_7_CONV
 *_8_CONV
 *_9_CONV
 *_10_CONV
 *_11_CONV
 *_15_CONV
 *_16_CONV
 */
#define REG_SQ_LENGTH _1_CONV

/**********************************************************************************/
/*							  ADC_CCR configurations 							  */
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TEMP_SENSOR_AND_VREF DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define V_BATTERY DISABLE

/**********************************************************************************/

/*options:
 *DIV_BY_2
 *DIV_BY_4
 *DIV_BY_6
 *DIV_BY_8
 */
#define ADC_PRESCALER DIV_BY_2

/**********************************************************************************/
/*							  Bit Manipulation Macros 							  */
/**********************************************************************************/

#define SQ1_BIT_MANIPULATION 0xFFFFFFE0






#endif //_ADC_config_H
