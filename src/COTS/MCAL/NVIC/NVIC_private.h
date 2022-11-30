/* FILENAME: NVIC_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 08/25/2022
*/
#ifndef _NVIC_private_H
#define _NVIC_private_H



#define NVIC_BASE_ADDRESS  0xE000E100

#define SCB_BASE_ADDRESS   0xE000ED00


typedef struct
{
   u32 ISERx[8];

   u32 RESERVED0x[24];

   u32 ICERx[8];

   u32 RSERVED1x[24];

   u32 ISPRx[8];

   u32 RESERVED2x[24];

   u32 ICPRx[8];

   u32 RESERVED3x[24];

   u32 IABRx[8];

   u32 RESERVED4x[56];

   u8  IPRx[240];

}  NVIC_MemoryMapType;


#define MNVIC  		( (volatile NVIC_MemoryMapType*) (NVIC_BASE_ADDRESS) )

#define MNVIC_STIR 	*( (volatile 32*) (0xE000EF00) )


typedef struct
{

    u32 CPUID;

    u32 ICSR;

    u32 VTOR;

    u32 AIRCR;

    u32 SCR;

    u32 CCR;

    u32 SHPR1;

    u32 SHPR2;

    u32 SHPR3;

    u32 SHCSR;

    u32 CFSR;

    u32 HFSR;

    u32 RESERVED;

    u32 MMFAR;

    u32 BFAR;

} SCB_MemoryMapType ;


#define MSCB	( (volatile SCB_MemoryMapType*) (SCB_BASE_ADDRESS) )






#define VECTKEY_Password	0x05FA0000


/////////////////////////
#define PEND_SV 		-6
#define SYSTICK 		-5
////////////////////////////
#define SV_CALL 		-4
/////////////////////////
#define MEMORY_MANAGE 	-3
#define BUS_FAULT 		-2
#define USAGE_FAULT 	-1
/////////////////////////






#endif //_NVIC_private_H
