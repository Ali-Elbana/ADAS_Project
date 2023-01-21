/* FILENAME: TFT_config  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 10/13/2022
*/
#ifndef _TFT_config_H
#define _TFT_config_H


#define A0_PORT 			GPIO_PORTA
#define RST_PORT 			GPIO_PORTA

#define A0_PIN				GPIOx_PIN1
#define RST_PIN				GPIOx_PIN0

#define SPI_SRC				SPI1
#define SPI_RELATION		SPIx_MSTR
#define SPI_DATA_DIRECTION 	SPIx_FULL_DUPLEX

#define SLPOUT_CMD 			0x11
#define DISPON_CMD			0x29
#define XPOSITION_CMD		0x2A
#define YPOSITION_CMD		0x2B
#define COLOR_MODE_CMD 		0x3A
#define MEMORY_WRITE_CMD 	0x2C
#define RGB565_CMD	   		0x05
#define RGB444				0x03
#define RGB666				0x06


#endif //_TFT_config_H
