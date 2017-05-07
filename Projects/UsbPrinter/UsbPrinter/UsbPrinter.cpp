// UsbPrinter.cpp : CUsbPrinterApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "UsbPrinter.h"
#include "LoadDll.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CUsbPrinterApp theApp;

const GUID CDECL _tlid = { 0xDD44A22D, 0x2F44, 0x4E35, { 0xA9, 0xB4, 0xCF, 0x4F, 0x5D, 0xE0, 0xF1, 0x4 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CUsbPrinterApp::InitInstance - DLL 初始化

BOOL CUsbPrinterApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
		if (!LoadSDKLibrary())
		{
			MessageBox(NULL,TEXT("打印机SDK库加载失败！"),TEXT("提示"),MB_OK|MB_ICONERROR);
		}
	}

	return bInit;
}



// CUsbPrinterApp::ExitInstance - DLL 终止

int CUsbPrinterApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。
	FreeSDKLibrary();
	return COleControlModule::ExitInstance();
}

LONG CUsbPrinterApp::SendFilePath(LPCTSTR lpFilePath)
{
	LONG result = 0;
	result = POS_Port_Open("SP-USB1", POS_PT_USB, FALSE, NULL);
	if (result == 0)
	{
		MessageBox(NULL, TEXT("端口打开失败，请确定端口是否被占用！"), TEXT("提示"), MB_OK | MB_ICONERROR);
		return result;
	}
	/*  CString s;
	  s.Format(_T("%ld"), result);
	  LPCWSTR path = (LPCWSTR)lpFilePath;*/
	  result = POS_Output_SendLocalFileW(result, lpFilePath);
	if (result == 0)
	{
		MessageBox(NULL, TEXT("文件读取失败！"), TEXT("提示"), MB_OK | MB_ICONERROR);
		return result;
	}
	return result;
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
