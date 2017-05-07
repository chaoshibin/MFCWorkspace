

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Jan 16 10:35:53 2017
 */
/* Compiler settings for UsbCapture.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_UsbCaptureLib,0x16767E43,0x974A,0x40CF,0x8C,0x56,0x1A,0xB8,0x0C,0xE1,0x0B,0x5F);


MIDL_DEFINE_GUID(IID, DIID__DUsbCapture,0x337D8864,0x9C89,0x4335,0xA8,0x8F,0xBE,0x2C,0xDC,0x89,0xDA,0x73);


MIDL_DEFINE_GUID(IID, DIID__DUsbCaptureEvents,0xE0903E55,0x5DE1,0x4BCF,0x8E,0x65,0xE1,0x31,0x09,0x8B,0x81,0x70);


MIDL_DEFINE_GUID(CLSID, CLSID_UsbCapture,0x6B66F9C4,0x1DA0,0x4463,0x96,0x37,0xAC,0x00,0xA5,0x74,0xAD,0x7A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



