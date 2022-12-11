/**
 * @file MRCC_config.h
 * @author Ali El Bana & Mo Alaa
 * @brief This file contains the RCC configurations
 * @version 2.0
 * @date 11/9/2022
 */

#ifndef MCAL_RCC_MRCC_CONFIG_H_
#define MCAL_RCC_MRCC_CONFIG_H_


/**********************************************************************************/
/*							  RCC_CR configurations 							  */
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define PLLI2S DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define PLL DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CSS DISABLE

/**********************************************************************************/

/*options:
 *BYBASED
 *NOTBYBASED
 */
#define HSEBYP NOTBYBASED

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define HSE_EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define HSI_EN ENABLE


/**********************************************************************************/
							// RCC_PLLCFGR configurations //
/**********************************************************************************/

/*options:
 *Equal_2
 *Equal_3
 *Equal_4
 *Equal_5
 *Equal_6
 *Equal_7
 *Equal_8
 *Equal_9
 *Equal_10
 *Equal_11
 *Equal_12
 *Equal_13
 *Equal_14
 *Equal_15
 */
#define PLLQ Equal_2

/**********************************************************************************/

/*options:
 *HSI
 *HSE
 */
#define PLLSRC HSE

/**********************************************************************************/

/*options:
 *Equal_2
 *Equal_4
 *Equal_6
 *Equal_8
 */
#define PLLP PLLCLK

/**********************************************************************************/

/*options:
 *Equal_192
 *Equal_193
 *Equal_194
 *Equal_195
 *Equal_196
 *Equal_197
 *Equal_198
 *Equal_199
 *Equal_200
 *Equal_201
 *Equal_202
 *Equal_203
 *Equal_204
 *Equal_205
 *Equal_206
 *Equal_207
 *Equal_208
 *Equal_209
 *Equal_210

 *Equal_300
 *Equal_301
 *Equal_302
 *Equal_303
 *Equal_304
 *Equal_305
 *Equal_306
 *Equal_307
 *Equal_308
 *Equal_309
 *Equal_310

 *Equal_400
 *Equal_401
 *Equal_402
 *Equal_403
 *Equal_404
 *Equal_405
 *Equal_406
 *Equal_407
 *Equal_408
 *Equal_409
 *Equal_410
 *Equal_411
 *Equal_412
 *Equal_413
 *Equal_414
 *Equal_415
 *Equal_416
 *Equal_417
 *Equal_418
 *Equal_419
 *Equal_420
 *Equal_421
 *Equal_422
 *Equal_423
 *Equal_424
 *Equal_425
 *Equal_426
 *Equal_427
 *Equal_428
 *Equal_429
 *Equal_430
 *Equal_431
 *Equal_432
 */
#define PLLN Equal_200

/**********************************************************************************/

/*options:
 *Equal_2
 *Equal_4
 *Equal_5
 *Equal_6
 *Equal_7
 *Equal_8
 *Equal_9
 *Equal_10
 *Equal_11
 *Equal_12
 *Equal_13
 *Equal_14
 *Equal_15
 *Equal_16
 *Equal_17
 *Equal_18
 *Equal_19
 *Equal_20
 *Equal_21
 *Equal_22
 *Equal_23
 *Equal_24
 *Equal_25
 *Equal_26
 *Equal_27
 *Equal_28
 *Equal_29
 *Equal_30
 *Equal_31
 *Equal_32
 *Equal_33
 *Equal_34
 *Equal_35
 *Equal_36
 *Equal_37
 *Equal_38
 *Equal_39
 *Equal_40
 *Equal_41
 *Equal_42
 *Equal_43
 *Equal_44
 *Equal_45
 *Equal_46
 *Equal_47
 *Equal_48
 *Equal_49
 *Equal_50
 *Equal_51
 *Equal_52
 *Equal_53
 *Equal_54
 *Equal_55
 *Equal_56
 *Equal_57
 *Equal_58
 *Equal_59
 *Equal_60
 *Equal_61
 *Equal_62
 *Equal_63
 */
#define PLLM Equal_2


/**********************************************************************************/
							// RCC_CFGR configurations //
/**********************************************************************************/

/*options:
 *SYSCLK
 *PLLI2SCLK
 *HSE
 *PLLCLK
 */
#define MCO2 SYSCLK

/**********************************************************************************/

/*options:
 *NoDivision
 *DivisionBy2
 *DivisionBy3
 *DivisionBy4
 *DivisionBy5
 */
#define MCO2PRE NoDivision

/**********************************************************************************/

/*options:
 *NoDivision
 *DivisionBy2
 *DivisionBy3
 *DivisionBy4
 *DivisionBy5
 */
#define MCO1PRE NoDivision

/**********************************************************************************/

/*options:
 *PLLI2SCLK
 *I2S_CKIN
 */
#define I2SSRC PLLI2SCLK

/**********************************************************************************/

/*options:
 *HSI
 *LSE
 *HSE
 *PLLCLK
 */
#define MCO1 HSE

/**********************************************************************************/

/*options:
 *NoCLK0
 *NoCLK1
 *HSEby2
 *HSEby3
 *HSEby4
 *HSEby5
 *HSEby6
 *HSEby7
 *HSEby8
 *HSEby9
 *HSEby10
 *HSEby11
 *HSEby12
 *HSEby13
 *HSEby14
 *HSEby15
 *HSEby16
 *HSEby17
 *HSEby18
 *HSEby19
 *HSEby20
 *HSEby21
 *HSEby22
 *HSEby22
 *HSEby23
 *HSEby24
 *HSEby25
 *HSEby26
 *HSEby27
 *HSEby28
 *HSEby29
 *HSEby30
 *HSEby31
 */
#define RTCPRE HSEby2

/**********************************************************************************/

/*options:
 *NoDivision
 *AHBby2
 *AHBby4
 *AHBBby8
 *AHBby16
 */
#define PPRE2 NoDivision

/**********************************************************************************/

/*options:
 *NoDivision
 *AHBby2
 *AHBby4
 *AHBby8
 *AHBby16
 */
#define PPRE1 NoDivision

/**********************************************************************************/

/*options:
 *NoDivision
 *SYSCLKby2
 *SYSCLKby4
 *SYSCLKby8
 *SYSCLKby16
 *SYSCLKby64
 *SYSCLKby128
 *SYSCLKby256
 *SYSCLKby512
 */
#define HPRE SYSCLKby2

/**********************************************************************************/

/*options:
 *HSI
 *HSE
 *PLLCLK
 */
#define SWS HSI

/**********************************************************************************/

/*options:
 *HSI
 *HSE
 *PLLCLK
 */
#define SW HSI


/**********************************************************************************/
							// RCC_AHB1ENR configurations //
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define DMA2CLK DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define DMA1CLK DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CRCCLK DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define GPIOHCLK DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define GPIOECLK DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define GPIODCLK DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define GPIOCCLK DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define GPIOBCLK DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define GPIOACLK DISABLE


/**********************************************************************************/
							// RCC_AHB2ENR configurations //
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define OTGFS DISABLE


/**********************************************************************************/
							// RCC_APB1ENR configurations //
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define PWREN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define I2C3EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define I2C2EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define I2C1EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define USART2EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define SPI3EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define SPI2EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define WWDGEN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TIM5EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TIM4EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TIM3EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TIM2EN DISABLE


/**********************************************************************************/
							// RCC_APB2ENR configurations //
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TIM11EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TIM10EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TIM9EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define SYSCFGEN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define SPI4EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define SPI1EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define SDIOEN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define ADC1EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define USART6EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define USART1EN DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TIM1EN DISABLE

/**********************************************************************************/
















#endif /* MCAL_RCC_MRCC_CONFIG_H_ */
