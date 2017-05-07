// UsbPrinter.cpp : CUsbPrinterApp �� DLL ע���ʵ�֡�

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



// CUsbPrinterApp::InitInstance - DLL ��ʼ��

BOOL CUsbPrinterApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
		if (!LoadSDKLibrary())
		{
			MessageBox(NULL,TEXT("��ӡ��SDK�����ʧ�ܣ�"),TEXT("��ʾ"),MB_OK|MB_ICONERROR);
		}
	}

	return bInit;
}



// CUsbPrinterApp::ExitInstance - DLL ��ֹ

int CUsbPrinterApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣
	FreeSDKLibrary();
	return COleControlModule::ExitInstance();
}

LONG CUsbPrinterApp::SendFilePath(LPCTSTR lpFilePath)
{
	LONG result = 0;
	result = POS_Port_Open("SP-USB1", POS_PT_USB, FALSE, NULL);
	if (result == 0)
	{
		MessageBox(NULL, TEXT("�˿ڴ�ʧ�ܣ���ȷ���˿��Ƿ�ռ�ã�"), TEXT("��ʾ"), MB_OK | MB_ICONERROR);
		return result;
	}
	/*  CString s;
	  s.Format(_T("%ld"), result);
	  LPCWSTR path = (LPCWSTR)lpFilePath;*/
	  result = POS_Output_SendLocalFileW(result, lpFilePath);
	if (result == 0)
	{
		MessageBox(NULL, TEXT("�ļ���ȡʧ�ܣ�"), TEXT("��ʾ"), MB_OK | MB_ICONERROR);
		return result;
	}
	return result;
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
