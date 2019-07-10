
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



#ifndef __CAL_EXT_H__
#define __CAL_EXT_H__

#include "cal.h"

#ifdef __cplusplus
extern "C" {
#define CALAPI
#else
#define CALAPI extern
#endif

#ifndef CALAPIENTRYP
#define CALAPIENTRYP CALAPIENTRY *
#endif

typedef enum CALextidEnum {
    CAL_EXT_D3D9            = 0x1001,   /* CAL/D3D9 interaction extension    */
    CAL_EXT_RESERVED        = 0x1002,   /* Place Holder  */
    CAL_EXT_D3D10           = 0x1003,   /* CAL/D3D10 interaction extension */
    CAL_EXT_COUNTERS        = 0x1004,   /* CAL counter extension */
    CAL_EXT_DOMAIN_PARAMS   = 0x1005,   /* CAL Domain Param extension */
    CAL_EXT_RES_CREATE      = 0x1006,   /* CAL Create resource extension */
    CAL_EXT_COMPUTE_SHADER  = 0x1007,   /* CAL compute shader extension */
    CAL_EXT_SAMPLER_PARAM   = 0x1008,   /* CAL Sampler extension */
} CALextid;

typedef CALvoid* CALextproc;


CALAPI CALresult CALAPIENTRY calExtSupported(CALextid extid);
CALAPI CALresult CALAPIENTRY calExtGetVersion(CALuint* major, CALuint* minor, CALextid extid);
CALAPI CALresult CALAPIENTRY calExtGetProc(CALextproc* proc, CALextid extid, const CALchar* procname);

/*
 * CAL Domain Parameters extension
 */
typedef struct CALvec4fRec {
    CALfloat x;
    CALfloat y;
    CALfloat z;
    CALfloat w;
} CALvec4f;

typedef struct CALparamRec {
    CALvec4f ul;            /* upper left domain parameter value */
    CALvec4f ll;            /* lower left domain parameter value */
    CALvec4f lr;            /* lower right domain parameter value */
} CALparam;

typedef struct CALdomainparamRec {
    CALparam  param0;
    CALparam  param1;
    CALparam  param2;
    CALparam  param3;
    CALparam  param4;
    CALparam  param5;
    CALparam  param6;
    CALparam  param7;
} CALdomainparam;


typedef CALresult (CALAPIENTRYP PFNCALCTXRUNPROGRAMPARAMS)(CALevent *event, CALcontext ctx, CALfunc func, const CALdomain* domain, const CALdomainparam* params);

/**
 * @fn calCtxRunProgramGrid(CALevent* event,
 *                          CALcontext ctx,
 *                          CALprogramGrid* pProgramGrid)
 *
 * @brief Invoke the kernel over the specified domain.
 *
 *
 * issues a task to invoke the computation of the kernel identified by
 * <i>func</i> within a region <i>domain</i> on the context <i>ctx</i> and
 * returns an associated event token in <i>*event</i> with this task. This
 * method returns CAL_RESULT_ERROR if <i>func</i> is not found in the currently
 * loaded module. This method returns CAL_RESULT_ERROR, if any of the inputs,
 * input references, outputs and constant buffers associated with the kernel
 * are not setup. Completion of this event can be queried by the master process
 * using <i>calIsEventDone</i>
 *
 * Extended contextual information regarding a calCtxRunProgram failure
 * can be obtained with the calGetErrorString function.
 *
 * @param event (out) - event associated with RunProgram instance. On error, event will be zero.
 * @param ctx (in) - context.
 * @param programGrid (in) - description of program information to get kernel and thread counts.
 *
 * @return Returns CAL_RESULT_OK on success, CAL_RESULT_ERROR if there was an error.
 *
 * @sa calCtxIsEventDone
 */
typedef CALresult (CALAPIENTRYP PFNCALCTXRUNPROGRAMGRID)(CALevent* event,
                                                  CALcontext ctx,
                                                  CALprogramGrid* pProgramGrid);

/**
 * @fn calModuleGetFuncInfo(CALfuncInfo* info, CALcontext ctx, CALmodule module, CALfunc func)
 *
 * @brief Retrieve information regarding the named func in the
 * named module.
 *
 * returns in <i>*info</i> the information regarding the func.
 * This method returns CAL_RESULT_NOT_INITIALIZED if CAL is not
 * initialied.
 * This method returns CAL_RESULT_INVALID_PARAMETER if info is
 * NULL.
 * This method returns CAL_RESULT_BAD_HANDLE if ctx is invalid
 * or module is not loaded or func is not found.
 * This method returns CAL_RESULT_ERROR if there was an error
 *
 * @param pInfo (out) - pointer to CALmoduleInfo output
 *              structure.
 * @param ctx (in) - context.
 * @param module (in) - handle to the loaded image.
 * @param func (in) - name of the function.
 *
 * @return Returns CAL_RESULT_OK on success,
 *         CAL_RESULT_NOT_INITIALIZED,
 *         CAL_RESULT_INVALID_PARAMETER, CAL_RESULT_BAD_HANDLE,
 *         or CAL_RESULT_ERROR if there was an error.
 *
 */
typedef CALresult (CALAPIENTRYP PFNCALMODULEGETFUNCINFO)(CALfuncInfo* pInfo,
                     CALcontext   ctx,
                     CALmodule    module,
                     CALfunc      func);

/**
 * @fn calCtxRunProgramGridArray(CALevent* event,
 *                               CALcontext ctx,
 *                               CALprogramGridArray* pProgramGridArray)
 *
 * @brief Invoke the kernel array over the specified domain(s).
 *
 *
 * issues a task to invoke the computation of the kernel arrays identified by
 * <i>func</i> within a region <i>domain</i> on the context <i>ctx</i> and
 * returns an associated event token in <i>*event</i> with this task. This
 * method returns CAL_RESULT_ERROR if <i>func</i> is not found in the currently
 * loaded module. This method returns CAL_RESULT_ERROR, if any of the inputs,
 * input references, outputs and constant buffers associated with the kernel
 * are not setup. Completion of this event can be queried by the master process
 * using <i>calIsEventDone</i>
 *
 * Extended contextual information regarding a calCtxRunProgram failure
 * can be obtained with the calGetErrorString function.
 *
 * @param event (out) - event associated with RunProgram instance. On error, event will be zero.
 * @param ctx (in) - context.
 * @param programGridArray (in) - array containing kernel programs and grid information.
 *
 * @return Returns CAL_RESULT_OK on success, CAL_RESULT_ERROR if there was an error.
 *
 * @sa calCtxIsEventDone
 */
typedef CALresult (CALAPIENTRYP PFNCALCTXRUNPROGRAMGRIDARRAY)(CALevent* event,
                                                  CALcontext ctx,
                                                  CALprogramGridArray* pGridArray);


/**
 * @fn calResCreate2D(CALresource* res, CALdevice dev, CALvoid* mem, CALuint width, CALuint height, CALformat format, CALuint size, CALuint flags)
 *
 * @brief Create a resource based on memory allocated by the application
 *
 * @param res (out)   - returned resource handle. On error, res will be zero.
 * @param dev (in)    - device the resource should be local.
 * @param mem (in)    - pointer to allocated memory
 * @param width (in)  - width of resource (in elements).
 * @param height (in) - height of resource
 * @param format (in) - format/type of each element of the resource.
 * @param size (in)   - Size of allocation (in bytes)
 * @param flags (in) - currently unused.
 *
 * @return Returns CAL_RESULT_OK on success
 */



typedef CALresult (CALAPIENTRYP PFNCALRESCREATE2D)(CALresource* res,
               CALdevice dev,
               CALvoid* mem,
               CALuint width,
               CALuint height,
               CALformat format,
               CALuint size,
               CALuint flags);
/**
 * @fn calResCreate1D(CALresource* res, CALdevice dev, CALvoid* mem, CALuint width, CALuint height, CALformat format, CALuint size, CALuint flags)
 *
 * @brief Create a resource based on memory allocated by the application
 *
 * @param res (out)   - returned resource handle. On error, res will be zero.
 * @param dev (in)    - device the resource should be local.
 * @param mem (in)    - pointer to allocated memory
 * @param width (in)  - width of resource (in elements).
 * @param format (in) - format/type of each element of the resource.
 * @param size (in)   - Size of allocation (in bytes)
 * @param flags (in) - currently unused.
 *
 * @return Returns CAL_RESULT_OK on success
 */

typedef CALresult (CALAPIENTRYP PFNCALRESCREATE1D)(CALresource* res,
               CALdevice dev,
               CALvoid* mem,
               CALuint width,
               CALformat format,
               CALuint size,
               CALuint flags);

//
// calCtxSetSamplerParams typedefs
//
typedef enum calSamplerParameterEnum {
    CAL_SAMPLER_PARAM_FETCH4 = 0, //DEPRECATED.  should set min/mag filter.
    CAL_SAMPLER_PARAM_DEFAULT = 0,
    CAL_SAMPLER_PARAM_MIN_FILTER,
    CAL_SAMPLER_PARAM_MAG_FILTER,
    CAL_SAMPLER_PARAM_WRAP_S,
    CAL_SAMPLER_PARAM_WRAP_T,
    CAL_SAMPLER_PARAM_WRAP_R,
    CAL_SAMPLER_PARAM_BORDER_COLOR,
    CAL_SAMPLER_PARAM_LAST
} CALsamplerParameter;

typedef enum calSamplerParamMinFilter {
    CAL_SAMPLER_MIN_LINEAR,
    CAL_SAMPLER_MIN_NEAREST,
    CAL_SAMPLER_MIN_NEAREST_MIPMAP_NEAREST,
    CAL_SAMPLER_MIN_NEAREST_MIPMAP_LINEAR,
    CAL_SAMPLER_MIN_LINEAR_MIPMAP_NEAREST,
    CAL_SAMPLER_MIN_LINEAR_MIPMAP_LINEAR,
    reserved_min0,
    CAL_SAMPLER_MIN_LINEAR_FOUR_SAMPLE,
    CAL_SAMPLER_MIN_LINEAR_FOUR_SAMPLE_MIPMAP_NEAREST,
    reserved_min1,
    reserved_min2,
} CALsamplerParamMinFilter;

typedef enum calSamplerParamMagFilter {
    CAL_SAMPLER_MAG_NEAREST,
    CAL_SAMPLER_MAG_LINEAR,
    reserved_mag0,
    reserved_mag1,
    CAL_SAMPLER_MAG_LINEAR_FOUR_SAMPLE
} CALsamplerParamMagFilter;

typedef enum calSamplerParamWrapMode {
    CAL_SAMPLER_WRAP_REPEAT,
    CAL_SAMPLER_WRAP_MIRRORED_REPEAT,
    CAL_SAMPLER_WRAP_CLAMP_TO_EDGE,
    CAL_SAMPLER_WRAP_MIRROR_CLAMP_TO_EDGE_EXT,
    CAL_SAMPLER_WRAP_CLAMP,
    CAL_SAMPLER_WRAP_MIRROR_CLAMP_EXT,
    CAL_SAMPLER_WRAP_CLAMP_TO_BORDER,
    CAL_SAMPLER_WRAP_MIRROR_CLAMP_TO_BORDER_EXT
} CALsamplerParamWrapMode;

/**
 * @fn calCtxSetSamplerParameter(CALcontext ctx, CALname name, CALsamplerParameter param, CALvoid* vals)
 *
 * @brief Set sampler state for the given sampler name.
 *
 * This method returns CAL_RESULT_BAD_HANDLE if ctx or name is invalid
 * or if name is not a sampler type name.
 * This method returns CAL_RESULT_INVALID_PARAMETER if vals is NULL and param
 * is not CAL_SAMPLER_PARAM_DEFAULT.
 * This method returns CAL_RESULT_ERROR if there was an error trying to set
 * the sampler paramter.
 *
 * @param ctx (in) - context.
 * @param name (in) - name.
 * @param param (in) - sampler parameter to change.
 * @param vals (in) - typeless list of values to update the sampler parameter.
 *
 * @return Returns CAL_RESULT_OK on success,
 *         CAL_RESULT_INVALID_PARAMETER, CAL_RESULT_BAD_HANDLE,
 *         or CAL_RESULT_ERROR if there was an error.
 *
 */
typedef CALresult (CALAPIENTRYP PFNCALSETSAMPLERPARAMS) (CALcontext ctx,
                                                         CALname name,
                                                         CALsamplerParameter param,
                                                         CALvoid* vals);

/**
 * @fn calCtxGetSamplerParameter(CALcontext ctx, CALname name, CALsamplerParameter param, CALvoid* vals)
 *
 * @brief Get sampler state for the given sampler name.
 *
 * This method returns CAL_RESULT_BAD_HANDLE if ctx or name is invalid
 * or if name is not a sampler type name.
 * This method returns CAL_RESULT_INVALID_PARAMETER if vals is NULL.
 * This method returns CAL_RESULT_ERROR if there was an error trying to get
 * the sampler paramter.
 *
 * @param ctx (in) - context.
 * @param name (in) - name.
 * @param param (in) - sampler parameter to change.
 * @param vals (out) - typeless list of values for the sampler parameter.
 *
 * @return Returns CAL_RESULT_OK on success,
 *         CAL_RESULT_INVALID_PARAMETER, CAL_RESULT_BAD_HANDLE,
 *         or CAL_RESULT_ERROR if there was an error.
 *
 */
typedef CALresult (CALAPIENTRYP PFNCALGETSAMPLERPARAMS) (CALcontext ctx,
                                                        CALname name,
                                                        CALsamplerParameter param,
                                                        CALvoid* vals);


#ifdef __cplusplus
}      /* extern "C" { */
#endif

#endif


