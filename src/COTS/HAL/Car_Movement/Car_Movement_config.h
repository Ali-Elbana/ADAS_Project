/* FILENAME: Car_Movement_config  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 03/14/2023
*/
#ifndef _Car_Movement_config_H
#define _Car_Movement_config_H


#define MOTOR1_PORT	GPIO_PORTA
#define MOTOR2_PORT GPIO_PORTA

#define IN1_PIN		GPIOx_PIN3
#define IN2_PIN		GPIOx_PIN4

#define IN3_PIN		GPIOx_PIN5
#define IN4_PIN		GPIOx_PIN6


// Initialize motor 1
VAR(DCM_MotorConfiguration) Motor1 =
{
    .u8Port			= MOTOR1_PORT	,
    .u8Pin1 		= IN1_PIN		,
    .u8Pin2 		= IN2_PIN		,
    .u8Direction 	= FORWARD		,
	.u8SpeedPin		= TIM1_CH3		,
	.u8SpeedRatio	= SPEED_0_PERCENT
};

// Initialize motor 3
VAR(DCM_MotorConfiguration) Motor3 =
{
    .u8Port			= MOTOR2_PORT	,
    .u8Pin1 		= IN3_PIN		,
    .u8Pin2 		= IN4_PIN		,
    .u8Direction 	= FORWARD		,
	.u8SpeedPin		= TIM1_CH3		,
	.u8SpeedRatio	= SPEED_0_PERCENT
};


#endif //_Car_Movement_config_H
