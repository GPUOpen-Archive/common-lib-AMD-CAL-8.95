/**
 *  @file     cal_private.h
 *  @brief    Private CAL Interface Header
 *  @version  1.00.0 Beta
 */


/* ============================================================

Copyright (c) 2016-2019 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

============================================================ */



#ifndef __CAL_PRIVATE_H__
#define __CAL_PRIVATE_H__

#include "cal.h"

#ifdef __cplusplus
extern "C" {
#define CALAPI
#else
#define CALAPI extern
#endif

#ifdef _WIN32
#define CALAPIENTRY  __stdcall
#else
#define CALAPIENTRY
#endif
#ifndef CALAPIENTRYP
#define CALAPIENTRYP CALAPIENTRY *
#endif

// Private parts of enums that will eventually move into public

/*============================================================================
 * CAL Runtime Interface
 *============================================================================*/

/** CAL resource map flags **/
typedef enum CALresmapflagsEnum {
    CAL_RESMAP_READWRITE  = 0, /**< used for read and write */
    CAL_RESMAP_READ       = 1, /**< used for readonly */
    CAL_RESMAP_WRITE      = 2, /**< used for writeonly */
} CALresmapflags;

/** CAL resource allocation flags **/
typedef enum CALresallocflagsPrivateEnum {
    CAL_RESALLOC_PERSISTENT     = (1 << 31), /**< direct mappable memory */
} CALresallocflagsPrivate;

typedef enum CALresultPrivateEnum {
    CAL_RESULT_INVALID_THREAD    = 11, /**< Runtime context is not in the same thread as creation */
} CALresultPrivate;

typedef enum CALmemcopyflagsEnum
{
    CAL_MEMCOPY_DEFAULT = 0, /**< default CAL behavior of partial sync */
    CAL_MEMCOPY_SYNC    = 1, /**< used to synchronize with the specified CAL context */
    CAL_MEMCOPY_ASYNC   = 2, /**< used to indicate completely asynchronous behavior */
} CALmemcopyflags;

typedef struct CALfuncExtendedInfoRec
{
    CALuint     struct_size;         /**< Client filled out size of CALdeviceattribs struct */
    CALfuncInfo funcInfo;            /**< calFuncInfo*/
    CALboolean  bLDSisUsed;          /**< LDS is used in func */
} CALfuncExtendedInfo;

/*----------------------------------------------------------------------------
 * CAL Context Functions
 *----------------------------------------------------------------------------*/



#ifdef __cplusplus
}      /* extern "C" { */
#endif


#endif /* __CAL_PRIVATE_H__ */



