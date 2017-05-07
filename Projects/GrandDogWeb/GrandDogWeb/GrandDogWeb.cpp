// GrandDogWeb.cpp : CGrandDogWebApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "GrandDogWeb.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CGrandDogWebApp theApp;

const GUID CDECL _tlid = { 0x6ECFD4FB, 0x3277, 0x4596, { 0xAF, 0xF5, 0x51, 0x2, 0x5D, 0x3D, 0x74, 0xF0 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CGrandDogWebApp::InitInstance - DLL 初始化

BOOL CGrandDogWebApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
		if (webAppCtrl.OnInitApp() != 0){
			AfxMessageBox(TEXT("Load RCGrandDogW32.dll failed."));
			exit(0);
		}
	}

	return bInit;
}



// CGrandDogWebApp::ExitInstance - DLL 终止

int CGrandDogWebApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
