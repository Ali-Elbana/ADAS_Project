/**
 * @file LSTD_VALUES.h
 * @author Ali El Bana
 * @brief This file contains the standard values
 * @version 1.0
 * @date 10/29/2022
 */

#ifndef COTS_LIB_LSTD_VALUES_H_
#define COTS_LIB_LSTD_VALUES_H_

/**
 * @defgroup standardvalues Standard values
 *
 * @{
 */

/**
 * @def TRUE
 * Type definition for TRUE
 *
 */
#ifndef TRUE
    #define TRUE (1)
#endif  /* ifndef TRUE */

/**
 * @def FALSE
 * Type definition for FALSE
 *
 */
#ifndef FALSE
    #define FALSE (0)
#endif  /* ifndef FALSE */

/**
 * @def NULL
 * Type definition for NULL
 *
 */
#ifndef NULL
	#define NULL (P2VAR(void) 0)
#endif  /* ifndef NULL */

/**
 * @def INITIAL_ZERO
 * Type definition for INITIAL_ZERO
 *
 */
#ifndef INITIAL_ZERO
	#define INITIAL_ZERO (0)
#endif  /* ifndef INITIAL_ZERO */

/**
 * @def FLAG_SET
 * Type definition for FLAG_SET
 *
 */
#ifndef FLAG_SET
	#define FLAG_SET (1)
#endif  /* ifndef FLAG_SET */

/**
 * @def FLAG_CLEARED
 * Type definition for FLAG_CLEARED
 *
 */
#ifndef FLAG_CLEARED
	#define FLAG_CLEARED (0)
#endif  /* ifndef FLAG_CLEARED */

/** @} */

#endif /* COTS_LIB_LSTD_VALUES_H_ */
