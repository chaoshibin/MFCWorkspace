

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __UsbPrinteridl_h__
#define __UsbPrinteridl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DUsbPrinter_FWD_DEFINED__
#define ___DUsbPrinter_FWD_DEFINED__
typedef interface _DUsbPrinter _DUsbPrinter;

#endif 	/* ___DUsbPrinter_FWD_DEFINED__ */


#ifndef ___DUsbPrinterEvents_FWD_DEFINED__
#define ___DUsbPrinterEvents_FWD_DEFINED__
typedef interface _DUsbPrinterEvents _DUsbPrinterEvents;

#endif 	/* ___DUsbPrinterEvents_FWD_DEFINED__ */


#ifndef __UsbPrinter_FWD_DEFINED__
#define __UsbPrinter_FWD_DEFINED__

#ifdef __cplusplus
typedef class UsbPrinter UsbPrinter;
#else
typedef struct UsbPrinter UsbPrinter;
#endif /* __cplusplus */

#endif 	/* __UsbPrinter_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_UsbPrinter_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_UsbPrinter_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UsbPrinter_0000_0000_v0_0_s_ifspec;


#ifndef __UsbPrinterLib_LIBRARY_DEFINED__
#define __UsbPrinterLib_LIBRARY_DEFINED__

/* library UsbPrinterLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_UsbPrinterLib;

#ifndef ___DUsbPrinter_DISPINTERFACE_DEFINED__
#define ___DUsbPrinter_DISPINTERFACE_DEFINED__

/* dispinterface _DUsbPrinter */
/* [uuid] */ 


EXTERN_C const IID DIID__DUsbPrinter;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7735B5C6-4BD4-4F5C-A5FC-73384F3F3AF7")
    _DUsbPrinter : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DUsbPrinterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DUsbPrinter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DUsbPrinter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DUsbPrinter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DUsbPrinter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DUsbPrinter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DUsbPrinter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DUsbPrinter * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DUsbPrinterVtbl;

    interface _DUsbPrinter
    {
        CONST_VTBL struct _DUsbPrinterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DUsbPrinter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DUsbPrinter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DUsbPrinter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DUsbPrinter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DUsbPrinter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DUsbPrinter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DUsbPrinter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DUsbPrinter_DISPINTERFACE_DEFINED__ */


#ifndef ___DUsbPrinterEvents_DISPINTERFACE_DEFINED__
#define ___DUsbPrinterEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DUsbPrinterEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DUsbPrinterEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("40317828-19E3-48FB-ABDF-9F9A964A88C8")
    _DUsbPrinterEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DUsbPrinterEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DUsbPrinterEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DUsbPrinterEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DUsbPrinterEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DUsbPrinterEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DUsbPrinterEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DUsbPrinterEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DUsbPrinterEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DUsbPrinterEventsVtbl;

    interface _DUsbPrinterEvents
    {
        CONST_VTBL struct _DUsbPrinterEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DUsbPrinterEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DUsbPrinterEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DUsbPrinterEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DUsbPrinterEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DUsbPrinterEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DUsbPrinterEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DUsbPrinterEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DUsbPrinterEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_UsbPrinter;

#ifdef __cplusplus

class DECLSPEC_UUID("24D9A3F7-6690-41BB-B00E-C8929873AB34")
UsbPrinter;
#endif
#endif /* __UsbPrinterLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


