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


#ifndef __CAL_EXT_GL_H__
#define __CAL_EXT_GL_H__
#include "cal.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CALAPIENTRYP
#define CALAPIENTRYP CALAPIENTRY *
#endif

typedef enum CALResGLBufferTypeEnum{
	CAL_RES_GL_BUFFER_TYPE_TEXTURE      = 0,
	CAL_RES_GL_BUFFER_TYPE_FRAMEBUFFER  = 1,
	CAL_RES_GL_BUFFER_TYPE_RENDERBUFFER = 2,
    CAL_RES_GL_BUFFER_TYPE_VERTEXBUFFER = 3
}CALResGLBufferType;


typedef  struct CALDeviceGLParamsRec {
    CALdevice          dev;
	CALvoid            *GLplatformContext;
	CALvoid            *GLdeviceContext;
	CALuint            flags;
}CALDeviceGLParams;

typedef enum CALDeviceGLParamsFlagsEnum {
    CAL_DEVICE_GL_PARAMS_FLAG_VALIDATEONLY = 1
}CALDeviceGLParamsFlags;

/*
 * calGLAssociate
 * Enables CAL to share resources with the GL context on the specified device.
 * params specfies the GL context, CAL device, GL dc & flags
 * GLplatformContext is a platform neutral GL context handle.
 * Flags is for future usage.
 * On success, CAL_RESULT_OK is returned.
 * On error, CAL_RESULT_BAD_HANDLE is returned.
 */
typedef CALresult (CALAPIENTRYP PFNCALGLASSOCIATE) (const CALDeviceGLParams *params);

/*
 * calGLDissociate
 * Ends resource sharing with GL context
 * params specfies the GL context, CAL device, GL dc & flags
 * GLplatformContext is a platform neutral GL context handle.
 * Flags is for future usage.
 * On success, CAL_RESULT_OK is returned.
 * If buffers are still being shared CAL_RESULT_ERROR will be returned
 */
typedef CALresult (CALAPIENTRYP PFNCALGLDISSOCIATE) (const CALDeviceGLParams *params);

/*
 * calResGLAssociate
 * Creates a CAL resource from a named GL buffer
 * params specfies the GL context, GL dc, CAL device
 * On success, CAL_RESULT_OK is returned.
 * If the specified GL buffer cannot be located, CAL_RESULT_ERROR will be returned.
 */
typedef CALresult (CALAPIENTRYP PFNCALRESGLASSOCIATE) (const CALDeviceGLParams *params, CALuint name, CALResGLBufferType type, CALresource *res);

#ifdef __cplusplus
}
#endif
#endif // __CAL_EXT_GL_H__

