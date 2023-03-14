
/************************************************************************/
/*                         Include headers                           	*/
/************************************************************************/

#include "COTS/LIB/LSTD_TYPES.h"
#include "COTS/LIB/LSTD_COMPILER.h"
#include "COTS/LIB/LSTD_VALUES.h"
#include "COTS/LIB/LSTD_BITMATH.h"

#include "COTS/MCAL/RCC/MRCC_interface.h"
#include "COTS/MCAL/GPIO/GPIO_interface.h"

#include "Drivers_Testing_Scripts/Testing_MCAL/Testing_GPIO/Testing_GPIO_interface.h"
#include "Drivers_Testing_Scripts/Testing_MCAL/Testing_EXTI/Testing_EXTI_interface.h"
#include "Drivers_Testing_Scripts/Testing_MCAL/Testing_SysTick/Testing_SysTick_interface.h"
#include "Drivers_Testing_Scripts/Testing_MCAL/Testing_ADC/Testing_ADC_interface.h"
#include "Drivers_Testing_Scripts/Testing_MCAL/Testing_UART/Testing_UART_interface.h"
#include "Drivers_Testing_Scripts/Testing_MCAL/Testing_SPI/Testing_SPI_interface.h"
#include "Drivers_Testing_Scripts/Testing_MCAL/Testing_TIM1/Testing_TIM1_interface.h"

#include "Drivers_Testing_Scripts/Testing_HAL/Testing_PushButtonSwitch/Testing_PushButtonSwitch_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_DC_Motor/Testing_DC_Motor_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_Motor_Driver/Testing_Motor_Driver_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_LDR/Testing_LDR_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_LCD/Testing_LCD_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_Bluetooth/Testing_Bluetooth_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_TFT/Testing_TFT_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_LED/Testing_LED_Driver_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_Buzzer/Testing_Buzzer_Driver_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_UltraSonic/Testing_UltraSonic_interface.h"

#include "Drivers_Testing_Scripts/Testing_Systems/Testing_ALC_Demo/Testing_ALC_Demo_interface.h"

/************************************************************************/
/*              	Testing Scripts Software Switches                   */
/************************************************************************/

#define TestingGPIO_OutputPushPull 		STOP
#define TestingGPIO_OutputOpenDrain 	STOP
#define TestingGPIO_Input 				STOP
#define TestingPushButton 				STOP
#define TestingEXTI_ToggleLED 			STOP
#define TestingDCMotor 					STOP
#define TestingSTK_ToggleLED_BusyWait 	STOP
#define TestingGPIO_Input  				STOP
#define TestingPushButton				STOP
#define TestingDCMotor					STOP
#define TestingEXTI_ToggleLED			STOP
#define TestingSTK_ToggleLED_BusyWait	STOP
#define TestingADC_ChnagingDelayTime	STOP
#define TestingLDR						STOP
#define TestingLCD						STOP
#define TestingGPIO_OutputPort			STOP
#define TestingALC						STOP
#define TestingUART						STOP
#define TestingBluetooth_RGBLED 	 	STOP
#define TestingSPI_SendChar				STOP
#define TestingTFT_ShowImage			STOP
#define TestingLED						STOP
#define TestingBUZZER					STOP
#define TestingLEDBlinking				STOP
#define TestingTIM1_PWM_Out				STOP
#define TestingTIM1_PWM_In				STOP
#define TestingTIM1_MeasurePulseTime	STOP
#define TestingUltraSonic				STOP
#define TestingMotorDriver 				RUN

/************************************************************************/
/*                          Application                        		   	*/
/************************************************************************/

int main(void)
{

	#if TestingGPIO_OutputPushPull == RUN

	TMGPIO_vPushPullOutputPins();

	#endif

	#if TestingGPIO_Input == RUN

	TMGPIO_vPullDownInputPins();

	#endif

	#if TestingPushButton == RUN

	THPushButton_vTogglePIN();

	#endif

	#if TestingDCMotor == RUN

	THDC_vMotor();

	#endif

	#if TestingGPIO_OutputOpenDrain == RUN

	TMGPIO_vOpenDrainOutputPIN();

	#endif

	#if TestingEXTI_ToggleLED == RUN

	TMEXTI_vToggleLED();

	#endif

	#if TestingSTK_ToggleLED_BusyWait == RUN

	TMSysTick_vToggleLED_BusyWait();

	#endif

	#if TestingMotorDriver == RUN

	THDC_vTestMotors();

	#endif

	#if TestingADC_ChnagingDelayTime == RUN

	TMADC_vChangeBlinkingLEDTime(  ) ;

	#endif

	#if TestingLDR == RUN

	TMLDR_vLightLEDsWithLevels(  ) ;

	#endif

	#if TestingGPIO_OutputPort == RUN

	TMGPIO_vOutputPortValue( ) ;

	#endif

	#if TestingLCD == RUN

	THLCD_vPrintString(  ) ;

	#endif

	#if TestingALC == RUN

	TSALC_vDispLux(  ) ;

	#endif

	#if TestingUART == RUN

	TMUART_vRGBLED(  ) ;

	#endif

	#if TestingBluetooth_RGBLED == RUN

	THBluetooth_vLEDColor(  ) ;

	#endif

	#if TestingSPI_SendChar == RUN

	TMSPI_vSendChar(  ) ;

	#endif

	#if TestingTFT_ShowImage == RUN

	THTFT_vDispImage( ) ;

	#endif


	#if TestingLED == RUN

	THLED_vTestLED( ) ;

	#endif

	#if TestingBUZZER == RUN

	THBuzzer_vTestBuzzer();

	#endif

	#if TestingLEDBlinking == RUN

	THLED_vBlinkLED( ) ;

	#endif

	#if TestingTIM1_PWM_Out == RUN

		TMTIM1_vGeneratePWM( ) ;

	#endif

	#if TestingTIM1_PWM_In == RUN

		TMTIM1_vMeasurePWM( ) ;

	#endif

	#if TestingTIM1_MeasurePulseTime == RUN

		TMTIM1_vMeasurePulseTime( ) ;

	#endif

	#if TestingUltraSonic == RUN

		TULTSNC_vMeasureDistance( ) ;

	#endif


	while (TRUE) ;

}





