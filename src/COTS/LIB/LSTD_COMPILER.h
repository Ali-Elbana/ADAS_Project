/*
 * LSTD_COMPILER.h
 *
 *  Created on: Nov 4, 2022
 */

#ifndef COTS_LIB_LSTD_COMPILER_H_
#define COTS_LIB_LSTD_COMPILER_H_

#define VAR(vartype) vartype

#define FUNC(rettype) rettype

#define P2VAR(ptrtype) ptrtype *

#define P2CONST(ptrtype) const ptrtype *

#define CONSTP2VAR(ptrtype) ptrtype * const

#define CONSTP2CONST(ptrtype) const ptrtype * const

#define P2FUNC(rettype, fctname) rettype (* fctname)

#ifndef CONST
    #define CONST(consttype) const consttype
#endif

#ifndef STATIC
    #define STATIC static
#endif

#endif /* COTS_LIB_LSTD_COMPILER_H_ */
