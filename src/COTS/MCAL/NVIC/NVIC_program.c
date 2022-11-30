/* FILENAME: NVIC_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 08/25/2022
*/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBITMATH.h"


#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


static u32 GS_u32GroupConf = Initialized_by_Zero ;


/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vEnablePeriphral( u8 A_u8INTID )
{

	MNVIC->ISERx[ A_u8INTID / 32 ] = 1 << (A_u8INTID % 32) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vDisablePeriphral( u8 A_u8INTID )
{

	MNVIC->ICERx[ A_u8INTID / 32 ] = 1 << (A_u8INTID % 32) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vSetPendingFlag( u8 A_u8INTID )
{

	MNVIC->ISPRx[ A_u8INTID / 32 ] = 1 << (A_u8INTID % 32) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vClearPendingFlag( u8 A_u8INTID )
{

	MNVIC->ICPRx[ A_u8INTID / 32 ] = 1 << (A_u8INTID % 32) ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u8 MNVIC_u8GetActive( u8 A_u8INTID )
{

	u8 L_u8Active = Initialized_by_Zero ;

	 L_u8Active = GET_BIT( (MNVIC->IABRx[A_u8INTID / 32]), (A_u8INTID % 32) ) ;

	 return L_u8Active ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vSetPriorityConfig( u8 A_u8PriorityOption )
{

    GS_u32GroupConf = VECTKEY_Password | (A_u8PriorityOption << 8) ;

    MSCB->AIRCR = GS_u32GroupConf;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vSetPriority( s8 A_s8INTID, u8 A_u8GroupPriority, u8 A_u8SubPriority )
{

	u8 L_u8Priority = Initialized_by_Zero ;

    L_u8Priority = A_u8SubPriority | ( A_u8GroupPriority << ((GS_u32GroupConf - 0x05FA0300) / 0x100) ) ;

    // Core Peripheral
    if(A_s8INTID < 0)
    {
        if( A_s8INTID == MEMORY_MANAGE || A_s8INTID == BUS_FAULT || A_s8INTID == USAGE_FAULT )
        {
        	A_s8INTID += 3 ;

            MSCB->SHPR1 = (L_u8Priority) << ( (8 * A_s8INTID) + 4 ) ;
        }

        else if( A_s8INTID == SV_CALL )
        {
        	A_s8INTID += 7 ;

            MSCB->SHPR2 = (L_u8Priority) << ( (8 * A_s8INTID) + 4 ) ;
        }

        else if( A_s8INTID == PEND_SV || A_s8INTID == SYSTICK )
        {
        	A_s8INTID += 8 ;

            MSCB->SHPR3 = (L_u8Priority) << ( (8 * A_s8INTID) + 4 ) ;
        }
    }

    // External Peripheral
    else if( A_s8INTID >= 0 )
    {
        MNVIC->IPRx[A_s8INTID] = (L_u8Priority << 4) ;
    }


}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u32 NVIC_GetPriority( s8 A_s8INTID )
{

	//TODO:

	u32 L_u32ThePriorityIS = Initialized_by_Zero ;

    // Core Peripheral
    if(A_s8INTID < 0)
    {
        if( A_s8INTID == MEMORY_MANAGE || A_s8INTID == BUS_FAULT || A_s8INTID == USAGE_FAULT )
        {
        	A_s8INTID += 3 ;

        	L_u32ThePriorityIS = MSCB->SHPR1  >> ( (8 * A_s8INTID) + 4 ) ;
        }

        else if( A_s8INTID == SV_CALL )
        {
        	A_s8INTID += 7 ;

        	L_u32ThePriorityIS = MSCB->SHPR2 >> ( (8 * A_s8INTID) + 4 ) ;
        }

        else if( A_s8INTID == PEND_SV || A_s8INTID == SYSTICK )
        {
        	A_s8INTID += 8 ;

        	L_u32ThePriorityIS = MSCB->SHPR3 >> ( (8 * A_s8INTID) + 4 ) ;
        }
    }

    // External Peripheral
    else if( A_s8INTID >= 0 )
    {
    	L_u32ThePriorityIS = ( MNVIC->IPRx[A_s8INTID] >> 4 ) ;
    }


    return L_u32ThePriorityIS ;

}

/*******************************************************************************************************************/
/******************************************************************************************************************/








