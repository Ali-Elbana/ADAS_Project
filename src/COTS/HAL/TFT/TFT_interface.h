/* FILENAME: TFT_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 10/13/2022
*/
#ifndef _TFT_interface_H
#define _TFT_interface_H


void HTFT_vInit( void ) ;

void HTFT_vShowImage( u16_t const *A_u16Image, u32_t A_u32ImageSize ) ;

void HTFT_vSetXPosition( u16_t A_u16XStart, u16_t A_u16XEnd ) ;

void HTFT_vSetYPosition( u16_t A_u16YStart, u16_t A_u16YEnd ) ;

void HTFT_vFillRectangle( u16_t A_u16Color ) ;

void HTFT_vFillBackground( u16_t A_u16Color ) ;

void HTFT_vDrawLine( u16_t A_u16X1, u16_t A_u16X2, u16_t A_u16Y1, u16_t A_u16Y2 ) ;

















#endif //_TFT_interface_H
