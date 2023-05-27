/**
 * @file GPIO_program.c
 * @author Ali El Bana & Mo Alaa
 * @brief This file contains the source code of the interfacing for the GPIO modules
 * @version 2.0
 * @date 08/22/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

void MGPIOx_vLockedPins(void)
{

	VAR(volatile u32_t) L_u32LockGPIOA = INITIAL_ZERO ;

	/* Lock key write sequence */

	/* WR LCKR[16] = '1' + LCKR[13,14,15] = �1� */
	L_u32LockGPIOA = ( (1UL << LCKK_BIT_POS) | (GPIOA_PIN_POS) ) ;

	GPIOA->LCKRx = L_u32LockGPIOA ;

	/* WR LCKR[16] = '0' + LCKR[13,14,15] should not change*/
	GPIOA->LCKRx = (GPIOA_PIN_POS) ;

	/* WR LCKR[16] = '1'+ LCKR[13,14,15] should not change*/
	GPIOA->LCKRx = L_u32LockGPIOA ;

	/* RD LCKR */
	L_u32LockGPIOA = GPIOA->LCKRx ;

	/////////////////////////////////////////////////////////////////////////

	VAR(volatile u32_t) L_u32LockGPIOB = INITIAL_ZERO ;

	/* Lock key write sequence */

	/* WR LCKR[16] = '1' + LCKR[2,3,4,11] = �1� */
	L_u32LockGPIOB = ( (1UL << LCKK_BIT_POS) | (GPIOB_PIN_POS) ) ;

	GPIOB->LCKRx = L_u32LockGPIOB ;

	/* WR LCKR[16] = '0' + LCKR[2,3,4,11] should not change*/
	GPIOB->LCKRx = (GPIOB_PIN_POS) ;

	/* WR LCKR[16] = '1' + LCKR[2,3,4,11] should not change*/
	GPIOB->LCKRx = L_u32LockGPIOB ;

	/* RD LCKR */
	L_u32LockGPIOB = GPIOB->LCKRx ;

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinMode(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8Mode)
{

	switch (A_u8PortID)
	{
		case GPIO_PORTA:
			CLR_BITs(GPIOA->MODERx, 0b11, A_u8PinID, 2);
			SET_BITs(GPIOA->MODERx, A_u8Mode, A_u8PinID, 2);
			break;

		case GPIO_PORTB:
			CLR_BITs(GPIOB->MODERx, 0b11, A_u8PinID, 2);
			SET_BITs(GPIOB->MODERx, A_u8Mode, A_u8PinID, 2);
			break;

		case GPIO_PORTC:
			CLR_BITs(GPIOC->MODERx, 0b11, A_u8PinID, 2);
			SET_BITs(GPIOC->MODERx, A_u8Mode, A_u8PinID, 2);
			break;
	}

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinOutputType(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8OutputType)
{

	switch (A_u8OutputType)
	{
		case GPIOx_OPENDRAIN:
			switch (A_u8PortID)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA->OTYPERx, A_u8PinID);
				break;

			case GPIO_PORTB:
				SET_BIT(GPIOB->OTYPERx, A_u8PinID);
				break;

			case GPIO_PORTC:
				SET_BIT(GPIOC->OTYPERx, A_u8PinID);
				break;
			}
			break;
			
		case GPIOx_PUSHPULL:
			switch(A_u8PortID)
			{
			case GPIO_PORTA:
				CLR_BIT(GPIOA->OTYPERx, A_u8PinID);
				break;

			case GPIO_PORTB:
				CLR_BIT(GPIOB->OTYPERx, A_u8PinID);
				break;

			case GPIO_PORTC:
				CLR_BIT(GPIOC->OTYPERx, A_u8PinID);
				break;
			}
			break;
	}

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinOutputSpeed(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8OutputSpeed)
{

	switch(A_u8PortID)
	{
		case GPIO_PORTA:
			CLR_BITs(GPIOA->OSPEEDRx, 0b11, A_u8PinID, 2);
			SET_BITs(GPIOA->OSPEEDRx, A_u8OutputSpeed, A_u8PinID, 2);
			break;

		case GPIO_PORTB:
			CLR_BITs(GPIOB->OSPEEDRx, 0b11, A_u8PinID, 2);
			SET_BITs(GPIOB->OSPEEDRx, A_u8OutputSpeed, A_u8PinID, 2);
			break;

		case GPIO_PORTC:
			CLR_BITs(GPIOC->OSPEEDRx, 0b11, A_u8PinID, 2);
			SET_BITs(GPIOC->OSPEEDRx, A_u8OutputSpeed, A_u8PinID, 2);
			break;
	}

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinInputPullType(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8InputPullType)
{

	switch (A_u8PortID)
	{
		case GPIO_PORTA:
			CLR_BITs(GPIOA->PUPDRx, 0b11, A_u8PinID, 2);
			SET_BITs(GPIOA->PUPDRx, A_u8InputPullType, A_u8PinID, 2);
			break;

		case GPIO_PORTB:
			CLR_BITs(GPIOB->PUPDRx, 0b11, A_u8PinID, 2);
			SET_BITs(GPIOB->PUPDRx, A_u8InputPullType, A_u8PinID, 2);
			break;

		case GPIO_PORTC:
			CLR_BITs(GPIOC->PUPDRx, 0b11, A_u8PinID, 2);
			SET_BITs(GPIOC->PUPDRx, A_u8InputPullType, A_u8PinID, 2);
			break;
	}

}

/**************************************************************************************/
/**************************************************************************************/

u8_t MGPIOx_u8GetPinValue(u8_t A_u8PortID, u8_t A_u8PinID)
{

	u8_t L_u8PinValue = INITIAL_ZERO;

	switch (A_u8PortID)
	{
		case GPIO_PORTA:
			L_u8PinValue = GET_BIT(GPIOA->IDRx, A_u8PinID);
			break;

		case GPIO_PORTB:
			L_u8PinValue = GET_BIT(GPIOB->IDRx, A_u8PinID);
			break;

		case GPIO_PORTC:
			L_u8PinValue = GET_BIT(GPIOC->IDRx, A_u8PinID);
			break;
	}

	return L_u8PinValue;

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetPinValue(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8PinValue)
{

	switch (A_u8PinValue)
	{
		case GPIOx_HIGH:
			switch (A_u8PortID)
			{
				case GPIO_PORTA:
					SET_BIT(GPIOA->ODRx, A_u8PinID);
					break;

				case GPIO_PORTB:
					SET_BIT(GPIOB->ODRx, A_u8PinID);
					break;

				case GPIO_PORTC:
					SET_BIT(GPIOC->ODRx, A_u8PinID);
					break;
			}
			break;

		case GPIOx_LOW:
			switch( A_u8PortID )
			{
				case GPIO_PORTA:
					CLR_BIT(GPIOA->ODRx, A_u8PinID);
					break;

				case GPIO_PORTB:
					CLR_BIT(GPIOB->ODRx, A_u8PinID);
					break;

				case GPIO_PORTC:
					CLR_BIT(GPIOC->ODRx, A_u8PinID);
					break;
			}
			break;
	}

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetResetAtomic(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8SetResetPinValue)
{

	switch (A_u8PortID)
	{

		case GPIO_PORTA:

		switch (A_u8SetResetPinValue)
		{
			case GPIOx_HIGH:
			GPIOA->BSRRx = (1 << A_u8PinID);
			break;

			case GPIOx_LOW:
			GPIOA->BSRRx = (1 << (A_u8PinID + 16));
			break;
		}

		break;

		case GPIO_PORTB:

			switch (A_u8SetResetPinValue)
			{
				case GPIOx_HIGH:
				GPIOB->BSRRx = (1 << A_u8PinID);
				break;

				case GPIOx_LOW:
				GPIOB->BSRRx = (1 << (A_u8PinID + 16));
				break;
			}

			break;

		case GPIO_PORTC:

				switch (A_u8SetResetPinValue)
				{
					case GPIOx_HIGH:
					GPIOC->BSRRx = (1 << A_u8PinID);
					break;

					case GPIOx_LOW:
					GPIOC->BSRRx = (1 << (A_u8PinID + 16));
					break;
				}

				break;
	}

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vSetAlternateFunctionON(u8_t A_u8PortID, u8_t A_u8PinID, u8_t A_u8AFID)
{

	switch (A_u8PortID)
	{
		case GPIO_PORTA:
			switch (A_u8PinID)
			{
				case GPIOx_PIN0:
				case GPIOx_PIN1:
				case GPIOx_PIN2:
				case GPIOx_PIN3:
				case GPIOx_PIN4:
				case GPIOx_PIN5:
				case GPIOx_PIN6:
				case GPIOx_PIN7:
					CLR_BITs(GPIOA->AFRLx, 0b1111, A_u8PinID, 4);
					SET_BITs(GPIOA->AFRLx, A_u8AFID, A_u8PinID, 4);
					break;

				case GPIOx_PIN8:
				case GPIOx_PIN9:
				case GPIOx_PIN10:
				case GPIOx_PIN11:
				case GPIOx_PIN12:
				case GPIOx_PIN13:
				case GPIOx_PIN14:
				case GPIOx_PIN15:
					CLR_BITs(GPIOA->AFRHx, 0b1111, (A_u8PinID - 8), 4);
					SET_BITs(GPIOA->AFRHx, A_u8AFID, (A_u8PinID - 8), 4);
					break;
			}
			break;

		case GPIO_PORTB:
			switch (A_u8PinID)
			{
				case GPIOx_PIN0:
				case GPIOx_PIN1:
				case GPIOx_PIN2:
				case GPIOx_PIN3:
				case GPIOx_PIN4:
				case GPIOx_PIN5:
				case GPIOx_PIN6:
				case GPIOx_PIN7:
					CLR_BITs(GPIOB->AFRLx, 0b1111, A_u8PinID, 4);
					SET_BITs(GPIOB->AFRLx, A_u8AFID, A_u8PinID, 4);
					break;

				case GPIOx_PIN8:
				case GPIOx_PIN9:
				case GPIOx_PIN10:
				case GPIOx_PIN11:
				case GPIOx_PIN12:
				case GPIOx_PIN13:
				case GPIOx_PIN14:
				case GPIOx_PIN15:
					CLR_BITs(GPIOB->AFRHx, 0b1111, (A_u8PinID - 8), 4);
					SET_BITs(GPIOB->AFRHx, A_u8AFID, (A_u8PinID - 8), 4);
					break;
			}
			break;

		case GPIO_PORTC:
			switch (A_u8PinID)
			{
				case GPIOx_PIN0:
				case GPIOx_PIN1:
				case GPIOx_PIN2:
				case GPIOx_PIN3:
				case GPIOx_PIN4:
				case GPIOx_PIN5:
				case GPIOx_PIN6:
				case GPIOx_PIN7:
					CLR_BITs(GPIOC->AFRLx, 0b1111, A_u8PinID, 4);
					SET_BITs(GPIOC->AFRLx, A_u8AFID, A_u8PinID, 4);
					break;

				case GPIOx_PIN8:
				case GPIOx_PIN9:
				case GPIOx_PIN10:
				case GPIOx_PIN11:
				case GPIOx_PIN12:
				case GPIOx_PIN13:
				case GPIOx_PIN14:
				case GPIOx_PIN15:
					CLR_BITs(GPIOC->AFRHx, 0b1111, (A_u8PinID - 8), 4);
					SET_BITs(GPIOC->AFRHx, A_u8AFID, (A_u8PinID - 8), 4);
					break;
			}
			break;
	}

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vInit(MGPIOx_ConfigType * A_xPinConfig)
{

	MGPIOx_vSetPinMode				(A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->Mode			);
	MGPIOx_vSetPinOutputType		(A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->OutputType	);
	MGPIOx_vSetPinOutputSpeed		(A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->OutputSpeed	);
	MGPIOx_vSetPinInputPullType		(A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->InputType		);
	MGPIOx_vSetAlternateFunctionON	(A_xPinConfig->Port, A_xPinConfig->Pin, A_xPinConfig->AF_Type		);

}

/**************************************************************************************/
/**************************************************************************************/

void MGPIOx_vTogglePinValue(u8_t A_u8PortID, u8_t A_u8PinID)
{

	switch (A_u8PortID)
	{
		case GPIO_PORTA:
			TOGGLE_BIT(GPIOA->ODRx, A_u8PinID);
			break;

		case GPIO_PORTB:
			TOGGLE_BIT(GPIOB->ODRx, A_u8PinID);
			break;

		case GPIO_PORTC:
			TOGGLE_BIT(GPIOC->ODRx, A_u8PinID);
			break;
	}

}

/**************************************************************************************/
/**************************************************************************************/

void GPIO_vSetNibbleLowValue( u8_t A_u8PortID, u16_t A_u16PortValue )
{

    switch(A_u8PortID)
    {

        case GPIO_PORTA : GPIOA->ODRx = ( ((GPIOA->ODRx & PORTA_BIT_MANIPULATION) | (A_u16PortValue)) << 0 ) ; break; //Start writing from PIN0 to PIN7.

        case GPIO_PORTB : GPIOB->ODRx = ( ((GPIOB->ODRx & PORTB_BIT_MANIPULATION) | (A_u16PortValue)) << 5 ) ; break; //Start writing from PIN5 to PIN12.

        case GPIO_PORTC : GPIOC->ODRx ; break; // You shouldn't write on this port.

        default :  break;
    }

}

/**************************************************************************************/
/**************************************************************************************/



