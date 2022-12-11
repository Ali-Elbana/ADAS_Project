

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

#include "Drivers_Testing_Scripts/Testing_HAL/Testing_PushButtonSwitch/Testing_PushButtonSwitch_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_DC_Motor/Testing_DC_Motor_interface.h"
#include "Drivers_Testing_Scripts/Testing_HAL/Testing_Motor_Driver/Testing_Motor_Driver_interface.h"

/************************************************************************/
/*              	Testing Scripts Software Switches                   */
/************************************************************************/

#define TestingGPIO_OutputPushPull STOP
#define TestingGPIO_OutputOpenDrain STOP
#define TestingGPIO_Input STOP
#define TestingPushButton STOP
#define TestingEXTI_ToggleLED STOP
#define TestingDCMotor STOP
#define TestingSTK_ToggleLED_BusyWait STOP
#define TestingMotorDriver RUN

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

#if TestingMotorDriver == RUN

	THDC_vTestMotors();

#endif

#if TestingEXTI_ToggleLED == RUN

	TMEXTI_vToggleLED();

#endif

#if TestingSTK_ToggleLED_BusyWait == RUN

	TMSysTick_vToggleLED_BusyWait();

#endif

	while (TRUE)
		;
}
