
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


#ifndef __CAL_EXT_D3D9_H__
#define __CAL_EXT_D3D9_H__

#include "cal.h"
#include <windows.h>
#include <d3d9.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CALAPIENTRYP
#define CALAPIENTRYP CALAPIENTRY *
#endif

/*
 * calD3D9Associate
 * Enable a CAL device and a D3D device to share resources.
 * The CALdevice specified by device must be open.
 * The D3D device specified by d3dDevice must be created.
 * A D3D device must be associated with a CAL device prior to any resource sharing.
 *
 * On success, CAL_RESULT_OK is returned.
 * On error, CAL_RESULT_BAD_HANDLE is returned if device is an invalid handle.
 */
typedef CALresult (CALAPIENTRYP PFNCALD3D9ASSOCIATE) (CALdevice device, IDirect3DDevice9* d3dDevice);

/*
 * calD3D9MapTexture
 * Return,  in d3dTex, a pointer to a created IDirect3DTexture9 interface for the supplied CAL resource res.
 * The IDirect3DTexture9 is created on the supplied D3D device specified by d3dDevice.
 * Use IDirect3DTexture9::GetLevelDesc() to get the description of the vertex buffer created.
 *
 * On success, CAL_RESULT_OK is returned.
 * On error, CAL_RESULT_BAD_HANDLE is returned if res is an invalid handle.
 * CAL_RESULT_INVALID_PARAMETER is returned if d3dTex or d3dDevice is null,
 * CAL_RESULT_ERROR is returned if the memory resource res  is not accessible
 * by the physical adapter associated with the D3D Device d3DDevice.
 */
typedef CALresult (CALAPIENTRYP PFNCALD3D9MAPTEXTUREFUNC) (IDirect3DTexture9 **d3dTex, IDirect3DDevice9* d3dDevice, CALresource res);

/*
 * calD3D9MapSurface
 *
 * On success, CAL_RESULT_OK is returned.
 * On error, CAL_RESULT_BAD_HANDLE is returned if res is an invalid handle.
 * CAL_RESULT_INVALID_PARAMETER is returned if d3dTex or d3dDevice is null,
 * CAL_RESULT_ERROR is returned if the memory resource res  is not accessible
 * by the physical adapter associated with the D3D Device d3DDevice.
 */
typedef CALresult (CALAPIENTRYP PFNCALD3D9MAPSURFACEFUNC) (CALresource* res, CALdevice dev, IDirect3DSurface9* tex, HANDLE shareHandle);

/*
 * calD3D9UnmapTexture
 * Destroy the created Direct3D texture.
 * calD3D9UnmapTexture should only be called on textures created with calD3D9MapTexture.
 *
 * On success, CAL_RESULT_OK is returned.
 * On error, CAL_RESULT_BAD_HANDLE is returned if res is an invalid handle,
 * CAL_RESULT_ERROR is returned if d3dTex wasn’t created by calD3D9CreateTexture.
 */
typedef CALresult (CALAPIENTRYP PFNCALD3D9UNMAPTEXTUREFUNC) (IDirect3DTexture9 *d3dTex);

/*
 * calD3D9MapVertexBuffer
 *
 * On success, CAL_RESULT_OK is returned.
 * On error, CAL_RESULT_BAD_HANDLE is returned if res is an invalid handle.
 * CAL_RESULT_INVALID_PARAMETER is returned if d3dVB or d3dDevice is null,
 * CAL_RESULT_ERROR is returned if the memory resource res  is not accessible
 * by the physical adapter associated with the D3D Device d3DDevice.
 */
typedef CALresult (CALAPIENTRYP PFNCALD3D9MAPVERTEXBUFFERFUNC) (CALresource* res, CALdevice dev, IDirect3DVertexBuffer9* d3dVB, HANDLE shareHandle);

/*
 * calD3D9MapIndexBuffer
 *
 * On success, CAL_RESULT_OK is returned.
 * On error, CAL_RESULT_BAD_HANDLE is returned if res is an invalid handle.
 * CAL_RESULT_INVALID_PARAMETER is returned if d3dIB or d3dDevice is null,
 * CAL_RESULT_ERROR is returned if the memory resource res  is not accessible
 * by the physical adapter associated with the D3D Device d3DDevice.
 */
typedef CALresult (CALAPIENTRYP PFNCALD3D9MAPINDEXBUFFERFUNC) (CALresource* res, CALdevice dev, IDirect3DIndexBuffer9* d3dIB, HANDLE shareHandle);

#ifdef __cplusplus
}
#endif
#endif // __CAL_EXT_D3D9_H__
