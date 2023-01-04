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

#ifndef TRUE
/**
 * @def TRUE
 * Type definition for TRUE
 *
 */
#define TRUE (1)
#endif /* ifndef TRUE */

#ifndef FALSE
/**
 * @def FALSE
 * Type definition for FALSE
 *
 */
#define FALSE (0)
#endif /* ifndef FALSE */

#ifndef NULL
/**
 * @def NULL
 * Type definition for NULL
 *
 */
#define NULL ( (void*)0 )
#endif /* ifndef NULL */

#ifndef NULL
#define NULL ((P2VAR(void))0)
#endif  /* ifndef NULL */


#ifndef INITIAL_ZERO
/**
 * @def INITIAL_ZERO
 * Type definition for INITIAL_ZERO
 *
 */
#define INITIAL_ZERO (0)
#endif /* ifndef INITIAL_ZERO */

#ifndef FLAG_SET
/**
 * @def FLAG_SET
 * Type definition for FLAG_SET
 *
 */
#define FLAG_SET (1)
#endif /* ifndef FLAG_SET */

#ifndef FLAG_CLEARED
/**
 * @def FLAG_CLEARED
 * Type definition for FLAG_CLEARED
 *
 */
#define FLAG_CLEARED (0)
#endif /* ifndef FLAG_CLEARED */

/**
 * @def RUN
 * Type definition for RUN
 *
 */
#ifndef RUN
	#define RUN (1)
#endif  /* ifndef RUN */


/**
 * @def STOP
 * Type definition for STOP
 *
 */
#ifndef STOP
	#define STOP (0)
#endif  /* ifndef STOP */

/**
 * @def PRESSED
 * Type definition for PRESSED
 *
 */
#ifndef PRESSED
	#define PRESSED (1)
#endif  /* ifndef PRESSED */

/**
 * @def RELEASED
 * Type definition for RELEASED
 *
 */
#ifndef RELEASED
	#define RELEASED (0)
#endif  /* ifndef RELEASED */

/**
 * @def SAME_STRING
 * Type definition for SAME_STRING
 *
 */
#ifndef SAME_STRING
	#define SAME_STRING (0)
#endif  /* ifndef SAME_STRING */

/**
 * @def DIFFERENT_STRING
 * Type definition for DIFFERENT_STRING
 *
 */
#ifndef DIFFERENT_STRING
	#define DIFFERENT_STRING (1)
#endif  /* ifndef DIFFERENT_STRING */



/** @} */

#endif /* COTS_LIB_LSTD_VALUES_H_ */
