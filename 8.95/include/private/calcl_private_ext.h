

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

#ifndef __CALCL_PRIVATE_EXT_H__
#define __CALCL_PRIVATE_EXT_H__

#include "calcl.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CALAPIENTRYP
#define CALAPIENTRYP CALAPIENTRY *
#endif

#define CAL_LANGUAGE_SC_ASM       ((CALlanguage)2)
#define CAL_LANGUAGE_SHADER_PARSE ((CALlanguage)3)

typedef enum calclPrivateExtidEnum
{
    CALCL_PRIVATE_EXT_COMPILER_CONFIG    = 0x9001,
    CALCL_PRIVATE_EXT_ISA_FUNCTIONS      = 0x9002,
} calclPrivateExtid;


#define CALCL_CONFIG_MIN_FETCH_CLAUSE_SIZE  "AMU_MIN_FETCH_CLAUSE_SIZE"
#define CALCL_CONFIG_NUM_CLAUSE_TEMPS       "AMU_NUM_CLAUSE_TEMPS"
#define CALCL_CONFIG_NUM_STACK_ENTRIES      "AMU_NUM_STACK_ENTRIES"
#define CALCL_CONFIG_NUM_GPRS               "AMU_NUM_GPRS"
#define CALCL_CONFIG_NUM_COPY_STACK_ENTRIES "AMU_NUM_COPY_STACK_ENTRIES"
#define CALCL_CONFIG_NUM_COPY_GPRS          "AMU_NUM_COPY_GPRS"
#define CALCL_CONFIG_DUMP_ILPARSEINFO       "AMU_DUMP_ILPARSEINFO"
#define CALCL_CONFIG_GLOBAL_RETURN_BUFFER   "AMU_GLOBAL_RETURN_BUFFER"

/**
 * Set the runtime configuration flags.
 *
 * key (in) - String of key to set value for
 * value (in) - string value for key
 */
typedef CALresult (CALAPIENTRYP PFNCALCLCONFIG)(const CALchar* key, const CALchar* value);

/**
 * Clear the runtime configuration flags
 */
typedef CALvoid (CALAPIENTRYP PFNCALCLCLEARCONFIG)(void);

/**
 * @fn calclAssemble(CALobject* obj,
 *                      CALlanguage language,
 *                      CALCLprogramType    programType,
 *                      const CALchar*      source,
 *                      CALtarget           target);
 *
 * @brief Assemble source of language type into an object
 *
 * CAL compiler function. Assemble a source language type string to the specified target device
 * and return a compiled object.
 *
 * @param obj (out) - created object
 * @param language (in) - language type to parse for assembly.
 * @param type (in) - source program type.
 * @param source (in) - string containing kernel source code.
 * @param target (in) - machine target.
 *
 * @return Returns CAL_RESULT_OK on success, CAL_RESULT_ERROR if there was an error.
 *
 * @sa calclLink calclFreeObject calclFreeImage
 */
typedef CALresult (CALAPIENTRYP PFNCALCLASSEMBLE)(CALobject* obj,
                                                     CALlanguage language,
                                                     CALCLprogramType    programType,
                                                     const CALchar*      source,
                                                     CALtarget           target);

/**
 * @fn calclDisassemble(const CALobject* obj,
 *                         CALlanguage language,
 *                         CALLogFunction logfunc)
 *
 * @brief Disassemble a CAL object source into an object
 *
 * CAL compiler function. Disassembles the CAL object, outputing on a line by line bases to the supplied log function.
 *
 * @param obj (in) - object to disassemble.
 * @param language (in) - language type to parse for assembly.
 * @param logfunc (in) - user supplied function to invoke for each line of disassembly.
 *
 * @return No return
 *
 * @sa calclAssemble calclLink
 */
typedef CALvoid (CALAPIENTRYP PFNCALCLDISASSEMBLE)(const CALobject* obj,
                                                   CALlanguage language,
                                                   CALLogFunction logfunc);

#ifdef __cplusplus
}
#endif
#endif // __CALCL_PRIVATE_EXT_H__



