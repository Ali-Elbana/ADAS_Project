/* FILENAME: EX1_MotorStates_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Tue 05/09/2023
*/
#ifndef _EX1_MotorStates2_interface_H
#define _EX1_MotorStates2_interface_H


typedef enum
{
	MOTOR_OFF ,

	MOTOR_ON

} tMotor_enuRootStates ;

typedef enum
{
	RED_LED 	,

	YELLOW_LED 	,

	GREEN_LED

} tLED_enuSubStates ;

typedef struct
{
	tMotor_enuRootStates motor_state ;

	tLED_enuSubStates 	 led_state 	 ;

} HStateMachine ;


/************************************************************************/
/*                        Functions prototypes                          */
/************************************************************************/

void DPExecute_vHMotorStates( void ) ;







#endif //_EX1_MotorStates_interface_H
