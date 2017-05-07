

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Feb 10 16:00:34 2017
 */
/* Compiler settings for GrandDogWeb.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_GrandDogWebLib,0x6ECFD4FB,0x3277,0x4596,0xAF,0xF5,0x51,0x02,0x5D,0x3D,0x74,0xF0);


MIDL_DEFINE_GUID(IID, DIID__DGrandDogWeb,0x2ABB59CC,0x9690,0x4561,0xAE,0x7B,0xF9,0xA4,0x3A,0x37,0xB1,0xFC);


MIDL_DEFINE_GUID(IID, DIID__DGrandDogWebEvents,0xDBB05F08,0x6AA4,0x4357,0x95,0x7D,0x95,0xAA,0xCB,0x2E,0x82,0x7A);


MIDL_DEFINE_GUID(CLSID, CLSID_GrandDogWeb,0xA7E91C27,0x2169,0x4776,0x93,0x50,0x3C,0xC7,0x63,0x08,0x2C,0x56);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



