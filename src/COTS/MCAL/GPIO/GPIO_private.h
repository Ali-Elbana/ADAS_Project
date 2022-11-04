/* FILENAME: GPIO_private  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Mon 08/22/2022
*/
#ifndef _GPIO_private_H
#define _GPIO_private_H

#define GPIOA_BASE_ADDRESS	(0x40020000)
#define GPIOB_BASE_ADDRESS 	(0x40020400)
#define GPIOC_BASE_ADDRESS  (0x40020800)


typedef struct
{
	VAR(u32_t) MODERx;
	VAR(u32_t) OTYPERx;
	VAR(u32_t) OSPEEDRx;
	VAR(u32_t) PUPDRx;
	VAR(u32_t) IDRx;
	VAR(u32_t) ODRx;
	VAR(u32_t) BSRRx;
	VAR(u32_t) LCKRx;
	VAR(u32_t) AFRLx;
	VAR(u32_t) AFRHx;
} GPIOx_MemoryMapType;

#define GPIOA ((volatile P2VAR(GPIOx_MemoryMapType)) (GPIOA_BASE_ADDRESS))
#define GPIOB ((volatile P2VAR(GPIOx_MemoryMapType)) (GPIOB_BASE_ADDRESS))
#define GPIOC ((volatile P2VAR(GPIOx_MemoryMapType)) (GPIOB_BASE_ADDRESS))



#endif //_GPIO_private_H
