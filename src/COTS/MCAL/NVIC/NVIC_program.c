/**
 * @file NVIC_program.c
 * @author Ali El Bana
 * @brief This file contains the source code of the interfacing for the NVIC modules
 * @version 2.0
 * @date 08/25/2022
 */

/************************************************************************/
/*                        Include headers                        	    */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LSTD_COMPILER.h"
#include "../../LIB/LSTD_VALUES.h"
#include "../../LIB/LSTD_BITMATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/************************************************************************/
/*                              Global functions                      	*/
/************************************************************************/

STATIC VAR(u32_t) GS_u32GroupConf = INITIAL_ZERO;

#define REGISTER_SIZE (32)

/************************************************************************/
/*                     Functions' implementations                      	*/
/************************************************************************/

void MNVIC_vEnablePeriphral(u8_t A_u8INTID)
{
    MNVIC->ISERx[A_u8INTID / REGISTER_SIZE] = (1 << (A_u8INTID % REGISTER_SIZE));
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vDisablePeriphral(u8_t A_u8INTID)
{
    MNVIC->ICERx[A_u8INTID / REGISTER_SIZE] = (1 << (A_u8INTID % REGISTER_SIZE));
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vSetPendingFlag(u8_t A_u8INTID)
{
    MNVIC->ISPRx[A_u8INTID / REGISTER_SIZE] = (1 << (A_u8INTID % REGISTER_SIZE));
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vClearPendingFlag(u8_t A_u8INTID)
{
    MNVIC->ICPRx[A_u8INTID / REGISTER_SIZE] = (1 << (A_u8INTID % REGISTER_SIZE));
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u8_t MNVIC_u8GetActive(u8_t A_u8INTID)
{
    u8_t L_u8Active = INITIAL_ZERO;
    L_u8Active = GET_BIT((MNVIC->IABRx[A_u8INTID / REGISTER_SIZE]), (A_u8INTID % REGISTER_SIZE));
    return L_u8Active;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vSetPriorityConfig(u8_t A_u8PriorityOption)
{
    GS_u32GroupConf = (VECTKEY_PASSWORD | (A_u8PriorityOption << 8));
    MSCB->AIRCR = GS_u32GroupConf;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

void MNVIC_vSetPriority(s8_t A_s8INTID, u8_t A_u8GroupPriority, u8_t A_u8SubPriority)
{
    u8_t L_u8Priority = INITIAL_ZERO;
    L_u8Priority = A_u8SubPriority | (A_u8GroupPriority << ((GS_u32GroupConf - 0x05FA0300) / 0x100));

    // Core Peripheral
    if (A_s8INTID < 0)
    {
        if ((A_s8INTID == MEMORY_MANAGE) || (A_s8INTID == BUS_FAULT) || (A_s8INTID == USAGE_FAULT))
        {
            A_s8INTID += 3;
            MSCB->SHPR1 = (L_u8Priority) << ((8 * A_s8INTID) + 4);
        }
        else if (A_s8INTID == SV_CALL)
        {
            A_s8INTID += 7;
            MSCB->SHPR2 = (L_u8Priority) << ((8 * A_s8INTID) + 4);
        }
        else if (A_s8INTID == PEND_SV || A_s8INTID == SYSTICK)
        {
            A_s8INTID += 8;
            MSCB->SHPR3 = (L_u8Priority) << ((8 * A_s8INTID) + 4);
        }
        else
        {
            /* Do nothing */
        }
    }
    // External Peripheral
    else if (A_s8INTID >= 0)
    {
        MNVIC->IPRx[A_s8INTID] = (L_u8Priority << 4);
    }
    else
    {
        /* Do nothing */
    }
}

/*******************************************************************************************************************/
/******************************************************************************************************************/

u32_t NVIC_GetPriority(s8_t A_s8INTID)
{
    u32_t L_u32ThePriorityIS = INITIAL_ZERO;

    // Core Peripheral
    if (A_s8INTID < 0)
    {
        if ((A_s8INTID == MEMORY_MANAGE) || (A_s8INTID == BUS_FAULT) || (A_s8INTID == USAGE_FAULT))
        {
            A_s8INTID += 3;
            L_u32ThePriorityIS = MSCB->SHPR1 >> ((8 * A_s8INTID) + 4);
        }
        else if (A_s8INTID == SV_CALL)
        {
            A_s8INTID += 7;
            L_u32ThePriorityIS = MSCB->SHPR2 >> ((8 * A_s8INTID) + 4);
        }
        else if (A_s8INTID == PEND_SV || A_s8INTID == SYSTICK)
        {
            A_s8INTID += 8;
            L_u32ThePriorityIS = MSCB->SHPR3 >> ((8 * A_s8INTID) + 4);
        }
        else
        {
            /* Do nothing */
        }
    }
    // External Peripheral
    else if (A_s8INTID >= 0)
    {
        L_u32ThePriorityIS = (MNVIC->IPRx[A_s8INTID] >> 4);
    }
    else
    {
        /* Do nothing */
    }

    return L_u32ThePriorityIS;
}

/*******************************************************************************************************************/
/******************************************************************************************************************/
