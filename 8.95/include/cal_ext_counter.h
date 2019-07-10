
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



#ifndef __CAL_EXT_COUNTER_H__
#define __CAL_EXT_COUNTER_H__

#include "cal.h"
#include "cal_ext.h"

#ifdef __cplusplus
extern "C" {
#define CALAPI
#else
#define CALAPI extern
#endif

#ifndef CALAPIENTRYP
#define CALAPIENTRYP CALAPIENTRY *
#endif

typedef enum CALcountertypeEnum
{
    CAL_COUNTER_IDLE,
    CAL_COUNTER_INPUT_CACHE_HIT_RATE
} CALcountertype;

/*
 * Performance counter functions
 */
typedef CALuint CALcounter;


/*
 * Create a new performance counter object.
 *
 * counter (out) - Pointer to the returned counter object handle.
 * ctx (in) - Context in which to create the counter.
 * type (in) - Value to count.
 */
typedef CALresult (CALAPIENTRYP PFNCALCTXCREATECOUNTER)(CALcounter* counter, CALcontext ctx, CALcountertype type);

/*
 * Destroy a counter object.
 *
 * ctx (in) - Context that owns the counter.
 * counter (in) - Counter to destroy.
 */
typedef CALresult (CALAPIENTRYP PFNCALCTXDESTROYCOUNTER)(CALcontext ctx, CALcounter counter);

/*
 * Tell the specified counter object to begin counting.  This should be called
 * after calCtxConfigCounter and before the calls to calCtxRunProgram or
 * calMemCopy you are trying to profile.
 *
 * ctx (in) - Context that owns the counter.
 * counter (in) - Counter to start.
 */
typedef CALresult (CALAPIENTRYP PFNCALCTXBEGINCOUNTER)(CALcontext ctx, CALcounter counter);

/*
 * Tell the specified counter object to stop counting.  This should be called
 * after the calls to calCtxRunProgram or calMemCopy you are trying to profile
 * and before calCtxGetCounter.
 *
 * ctx (in) - Context that owns the counter.
 * counter (in) - Counter to stop.
 */
typedef CALresult (CALAPIENTRYP PFNCALCTXENDCOUNTER)(CALcontext ctx, CALcounter counter);

/*
 * Retrieve the results from a counter object.  This should be called after
 * calCtxEndCounter.
 *
 * result (out) - Pointer to a CALfloat that will store counter results.
 * ctx (in) - Context that owns the counter.
 * counter (in) - Counter from which to retrieve results.
 */
typedef CALresult (CALAPIENTRYP PFNCALCTXGETCOUNTER)(CALfloat* result, CALcontext ctx, CALcounter counter);

#ifdef __cplusplus
}      /* extern "C" { */
#endif

#endif


