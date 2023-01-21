/* FILENAME: SPI_config  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Wed 10/12/2022
*/
#ifndef _SPI_config_H
#define _SPI_config_H


/**********************************************************************************/
							// SPI_CR1 configurations //
/**********************************************************************************/

/*options:
 *FIRST_CLK_Captured
 *SECOND_CLK_Captured
 */
#define CPHA_MODE SECOND_CLK_Captured

/**********************************************************************************/

/*options:
 *CLK_IdleAt0
 *CLK_IdleAt1
 */
#define CPOL_MODE CLK_IdleAt1

/**********************************************************************************/

/*options:
 *SLAVE
 *MASTER
 */
#define MSTR_MODE MASTER

/**********************************************************************************/

/*options:
 *CLK_By2
 *CLK_By4
 *CLK_By8
 *CLK_By16
 *CLK_By32
 *CLK_By64
 *CLK_By128
 *CLK_By256
 */
#define BR_MODE CLK_By2

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define SPE_MODE ENABLE

/**********************************************************************************/

/*options:
 *MSB_First
 *LSB_First
 */
#define LSBFIRST_MODE MSB_First

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define SSM_MODE DISABLE

/**********************************************************************************/

/*options:
 *FULL_DUPLEX
 *RX_ONLY
 */
#define RXONLY_MODE FULL_DUPLEX

/**********************************************************************************/

/*options:
 *EIGHT_BITS
 *SIXTEEN_BITS
 */
#define DFF_MODE EIGHT_BITS

/**********************************************************************************/

/*options:
 *CRC_PHASE
 *NO_CRC_PHASE
 */
#define CRCNEXT_MODE NO_CRC_PHASE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define CRCEN_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define BIDIOE_MODE DISABLE

/**********************************************************************************/

/*options:
 *OneLine
 *TwoLines
 */
#define BIDMODE_MODE OneLine

/**********************************************************************************/

/*options:
 *HALF_DUPLEX_TX
 *HALF_DUPLEX_RX
 */
#define HALF_DUPLEX_MODE HALF_DUPLEX_TX

/**********************************************************************************/

/*options:
 *SIMPLEX_TX
 *SIMPLEX_RX
 */
#define SIMPLEX_MODE SIMPLEX_TX

/**********************************************************************************/
							// SPI_CR2 configurations //
/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define RXDMAEN_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TXDMAEN_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define MULTI_MSTR_MODE DISABLE

/**********************************************************************************/

/*options:
 *MOTOROLA
 *TI
 */
#define FRF_MODE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define ERRIE_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define RXNEIE_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TXNEIE_MODE DISABLE


/**********************************************************************************/
							// SPI_SR configurations //
/**********************************************************************************/

/*options:
 *ERROR
 *NO_ERROR
 */
#define FRE_MODE DISABLE

/**********************************************************************************/

/*options:
 *BUSY
 *NOT_BUSY
 */
#define BSY_MODE DISABLE

/**********************************************************************************/

/*options:
 *OCCURRED
 *NOT_OCCURRED
 */
#define OVR_MODE DISABLE

/**********************************************************************************/

/*options:
 *FAULT_OCCURRED
 *NO_FAULT_OCCURRED
 */
#define MODF_MODE DISABLE

/**********************************************************************************/

/*options:
 *OCCURRED
 *NOT_OCCURRED
 */
#define UDR_MODE

/**********************************************************************************/

/*options:
 *MATCHED
 *NOT_MATCHED
 */
#define CRCERR_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define RXNEIE_MODE DISABLE

/**********************************************************************************/

/*options:
 *ENABLE
 *DISABLE
 */
#define TXNEIE_MODE DISABLE

/**********************************************************************************/












#endif //_SPI_config_H
