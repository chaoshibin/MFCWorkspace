

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __UsbCaptureidl_h__
#define __UsbCaptureidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DUsbCapture_FWD_DEFINED__
#define ___DUsbCapture_FWD_DEFINED__
typedef interface _DUsbCapture _DUsbCapture;

#endif 	/* ___DUsbCapture_FWD_DEFINED__ */


#ifndef ___DUsbCaptureEvents_FWD_DEFINED__
#define ___DUsbCaptureEvents_FWD_DEFINED__
typedef interface _DUsbCaptureEvents _DUsbCaptureEvents;

#endif 	/* ___DUsbCaptureEvents_FWD_DEFINED__ */


#ifndef __UsbCapture_FWD_DEFINED__
#define __UsbCapture_FWD_DEFINED__

#ifdef __cplusplus
typedef class UsbCapture UsbCapture;
#else
typedef struct UsbCapture UsbCapture;
#endif /* __cplusplus */

#endif 	/* __UsbCapture_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_UsbCapture_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_UsbCapture_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_UsbCapture_0000_0000_v0_0_s_ifspec;


#ifndef __UsbCaptureLib_LIBRARY_DEFINED__
#define __UsbCaptureLib_LIBRARY_DEFINED__

/* library UsbCaptureLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_UsbCaptureLib;

#ifndef ___DUsbCapture_DISPINTERFACE_DEFINED__
#define ___DUsbCapture_DISPINTERFACE_DEFINED__

/* dispinterface _DUsbCapture */
/* [uuid] */ 


EXTERN_C const IID DIID__DUsbCapture;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("337D8864-9C89-4335-A88F-BE2CDC89DA73")
    _DUsbCapture : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DUsbCaptureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DUsbCapture * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DUsbCapture * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DUsbCapture * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DUsbCapture * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DUsbCapture * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DUsbCapture * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DUsbCapture * This,
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
    } _DUsbCaptureVtbl;

    interface _DUsbCapture
    {
        CONST_VTBL struct _DUsbCaptureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DUsbCapture_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DUsbCapture_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DUsbCapture_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DUsbCapture_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DUsbCapture_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DUsbCapture_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DUsbCapture_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DUsbCapture_DISPINTERFACE_DEFINED__ */


#ifndef ___DUsbCaptureEvents_DISPINTERFACE_DEFINED__
#define ___DUsbCaptureEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DUsbCaptureEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DUsbCaptureEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E0903E55-5DE1-4BCF-8E65-E131098B8170")
    _DUsbCaptureEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DUsbCaptureEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DUsbCaptureEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DUsbCaptureEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DUsbCaptureEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DUsbCaptureEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DUsbCaptureEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DUsbCaptureEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DUsbCaptureEvents * This,
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
    } _DUsbCaptureEventsVtbl;

    interface _DUsbCaptureEvents
    {
        CONST_VTBL struct _DUsbCaptureEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DUsbCaptureEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DUsbCaptureEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DUsbCaptureEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DUsbCaptureEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DUsbCaptureEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DUsbCaptureEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DUsbCaptureEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DUsbCaptureEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_UsbCapture;

#ifdef __cplusplus

class DECLSPEC_UUID("6B66F9C4-1DA0-4463-9637-AC00A574AD7A")
UsbCapture;
#endif
#endif /* __UsbCaptureLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


