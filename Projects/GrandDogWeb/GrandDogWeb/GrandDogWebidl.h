

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __GrandDogWebidl_h__
#define __GrandDogWebidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DGrandDogWeb_FWD_DEFINED__
#define ___DGrandDogWeb_FWD_DEFINED__
typedef interface _DGrandDogWeb _DGrandDogWeb;

#endif 	/* ___DGrandDogWeb_FWD_DEFINED__ */


#ifndef ___DGrandDogWebEvents_FWD_DEFINED__
#define ___DGrandDogWebEvents_FWD_DEFINED__
typedef interface _DGrandDogWebEvents _DGrandDogWebEvents;

#endif 	/* ___DGrandDogWebEvents_FWD_DEFINED__ */


#ifndef __GrandDogWeb_FWD_DEFINED__
#define __GrandDogWeb_FWD_DEFINED__

#ifdef __cplusplus
typedef class GrandDogWeb GrandDogWeb;
#else
typedef struct GrandDogWeb GrandDogWeb;
#endif /* __cplusplus */

#endif 	/* __GrandDogWeb_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_GrandDogWeb_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_GrandDogWeb_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GrandDogWeb_0000_0000_v0_0_s_ifspec;


#ifndef __GrandDogWebLib_LIBRARY_DEFINED__
#define __GrandDogWebLib_LIBRARY_DEFINED__

/* library GrandDogWebLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_GrandDogWebLib;

#ifndef ___DGrandDogWeb_DISPINTERFACE_DEFINED__
#define ___DGrandDogWeb_DISPINTERFACE_DEFINED__

/* dispinterface _DGrandDogWeb */
/* [uuid] */ 


EXTERN_C const IID DIID__DGrandDogWeb;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2ABB59CC-9690-4561-AE7B-F9A43A37B1FC")
    _DGrandDogWeb : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DGrandDogWebVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DGrandDogWeb * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DGrandDogWeb * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DGrandDogWeb * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DGrandDogWeb * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DGrandDogWeb * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DGrandDogWeb * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DGrandDogWeb * This,
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
    } _DGrandDogWebVtbl;

    interface _DGrandDogWeb
    {
        CONST_VTBL struct _DGrandDogWebVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DGrandDogWeb_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DGrandDogWeb_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DGrandDogWeb_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DGrandDogWeb_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DGrandDogWeb_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DGrandDogWeb_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DGrandDogWeb_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DGrandDogWeb_DISPINTERFACE_DEFINED__ */


#ifndef ___DGrandDogWebEvents_DISPINTERFACE_DEFINED__
#define ___DGrandDogWebEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DGrandDogWebEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DGrandDogWebEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DBB05F08-6AA4-4357-957D-95AACB2E827A")
    _DGrandDogWebEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DGrandDogWebEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DGrandDogWebEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DGrandDogWebEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DGrandDogWebEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DGrandDogWebEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DGrandDogWebEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DGrandDogWebEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DGrandDogWebEvents * This,
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
    } _DGrandDogWebEventsVtbl;

    interface _DGrandDogWebEvents
    {
        CONST_VTBL struct _DGrandDogWebEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DGrandDogWebEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DGrandDogWebEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DGrandDogWebEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DGrandDogWebEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DGrandDogWebEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DGrandDogWebEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DGrandDogWebEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DGrandDogWebEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_GrandDogWeb;

#ifdef __cplusplus

class DECLSPEC_UUID("A7E91C27-2169-4776-9350-3CC763082C56")
GrandDogWeb;
#endif
#endif /* __GrandDogWebLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


