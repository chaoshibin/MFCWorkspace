

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sat Oct 15 18:24:04 2016
 */
/* Compiler settings for UsbPrinter.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_UsbPrinterLib,0xDD44A22D,0x2F44,0x4E35,0xA9,0xB4,0xCF,0x4F,0x5D,0xE0,0xF1,0x04);


MIDL_DEFINE_GUID(IID, DIID__DUsbPrinter,0x7735B5C6,0x4BD4,0x4F5C,0xA5,0xFC,0x73,0x38,0x4F,0x3F,0x3A,0xF7);


MIDL_DEFINE_GUID(IID, DIID__DUsbPrinterEvents,0x40317828,0x19E3,0x48FB,0xAB,0xDF,0x9F,0x9A,0x96,0x4A,0x88,0xC8);


MIDL_DEFINE_GUID(CLSID, CLSID_UsbPrinter,0x24D9A3F7,0x6690,0x41BB,0xB0,0x0E,0xC8,0x92,0x98,0x73,0xAB,0x34);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



