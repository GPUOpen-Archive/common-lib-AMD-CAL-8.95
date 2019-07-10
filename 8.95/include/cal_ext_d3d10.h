
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


#ifndef __CAL_EXT_D3D10_H__
#define __CAL_EXT_D3D10_H__

#include "cal.h"
#include <windows.h>
#include <D3D10.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CALAPIENTRYP
#define CALAPIENTRYP CALAPIENTRY *
#endif

/*
 * calD3D10Associate
 *
 * @brief Associate d3dDevice with CAL device dev for D3D10 interoperability
 *
 *
 */
typedef CALresult (CALAPIENTRYP PFNCALD3D10ASSOCIATEFUNC) (CALdevice dev, ID3D10Device* d3dDevice);


/*
 * calD3D10MapResource
 *
 * On success, CAL_RESULT_OK is returned.
 * On error, CAL_RESULT_BAD_HANDLE is returned if res is an invalid handle.
 * CAL_RESULT_INVALID_PARAMETER is returned if d3dRes or d3dDevice is null,
 * CAL_RESULT_ERROR is returned if the memory resource res  is not accessible
 * by the physical adapter associated with the D3D Device d3DDevice.
 */
typedef CALresult (CALAPIENTRYP PFNCALD3D10MAPRESOURCEFUNC) (CALresource* res, CALdevice dev, ID3D10Resource* d3dRes, HANDLE shareHandle);

#ifdef __cplusplus
}
#endif
#endif // __CAL_EXT_D3D10_H__
