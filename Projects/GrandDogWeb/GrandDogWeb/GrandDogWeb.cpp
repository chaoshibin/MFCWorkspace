// GrandDogWeb.cpp : CGrandDogWebApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "GrandDogWeb.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CGrandDogWebApp theApp;

const GUID CDECL _tlid = { 0x6ECFD4FB, 0x3277, 0x4596, { 0xAF, 0xF5, 0x51, 0x2, 0x5D, 0x3D, 0x74, 0xF0 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CGrandDogWebApp::InitInstance - DLL ��ʼ��

BOOL CGrandDogWebApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
		if (webAppCtrl.OnInitApp() != 0){
			AfxMessageBox(TEXT("Load RCGrandDogW32.dll failed."));
			exit(0);
		}
	}

	return bInit;
}



// CGrandDogWebApp::ExitInstance - DLL ��ֹ

int CGrandDogWebApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
