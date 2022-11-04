/*
 * LSTD_VALUES.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Abo3a
 */

#ifndef COTS_LIB_LSTD_VALUES_H_
#define COTS_LIB_LSTD_VALUES_H_

/* Check whether the TRUE define is defined before */
#ifndef TRUE
    /* Type definition for TRUE */
    #define TRUE (1)
#endif  /* ifndef TRUE */

/* Check whether the FALSE define is defined before */
#ifndef FALSE
    /* Type definition for FALSE */
    #define FALSE (0)
#endif  /* ifndef FALSE */

/* Check whether the NULL define is defined before */
#ifndef NULL
	/* Type definition for NULL */
	#define NULL (P2VAR(void) 0)
#endif  /* ifndef NULL */

/* Check whether the INITIAL_ZERO define is defined before */
#ifndef INITIAL_ZERO
	/* Type definition for INITIAL_ZERO */
	#define INITIAL_ZERO (0)
#endif  /* ifndef INITIAL_ZERO */

/* Check whether the FLAG_SET define is defined before */
#ifndef FLAG_SET
	/* Type definition for FLAG_SET */
	#define FLAG_SET (1)
#endif  /* ifndef FLAG_SET */

/* Check whether the FLAG_CLEARED define is defined before */
#ifndef FLAG_CLEARED
	/* Type definition for FLAG_CLEARED */
	#define FLAG_CLEARED (0)
#endif  /* ifndef FLAG_CLEARED */

#endif /* COTS_LIB_LSTD_VALUES_H_ */
