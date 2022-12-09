/**
 * @file LSTD_COMPILER.h
 * @author Mohamed Alaa
 * @brief This file contains the compiler standard macros
 * @version 1.0
 * @date 11/04/2022
 */

#ifndef COTS_LIB_LSTD_COMPILER_H_
#define COTS_LIB_LSTD_COMPILER_H_

/**
 * @defgroup compiler Compiler standard macros
 *
 * @{
 */

/**
 * @def VAR(vartype)
 * Declare a variable with the specified type
 *
 */
#define VAR(vartype) vartype

/**
 * @def FUNC(vartype)
 * Declare a function's return type
 *
 */
#define FUNC(rettype) rettype

/**
 * @def P2VAR(vartype)
 * Declare a pointer-to-variable with the specified type
 *
 */
#define P2VAR(ptrtype) ptrtype *

/**
 * @def P2CONST(vartype)
 * Declare a constant pointer-to-variable with the specified type
 *
 */
#define P2CONST(ptrtype) const ptrtype *

/**
 * @def CONSTP2VAR(vartype)
 * Declare a pointer-to-variable constant with the specified type
 *
 */
#define CONSTP2VAR(ptrtype) ptrtype * const

/**
 * @def CONSTP2CONST(vartype)
 * Declare a constant pointer-to-variable constant with the specified type
 *
 */
#define CONSTP2CONST(ptrtype) const ptrtype * const

/**
 * @def P2FUNC(vartype)
 * Declare a pointer-to-function with the specified type
 *
 */
#define P2FUNC(rettype, fctname) rettype (*fctname)

/**
 * @def CONST(vartype)
 * Declare a standard constant variable with the specified type
 *
 */
#ifndef CONST
    #define CONST(consttype) const consttype
#endif

/**
 * @def STATIC
 * Declare a standard static variable
 *
 */
#ifndef STATIC
    #define STATIC static
#endif

/** @} */

#endif /* COTS_LIB_LSTD_COMPILER_H_ */
