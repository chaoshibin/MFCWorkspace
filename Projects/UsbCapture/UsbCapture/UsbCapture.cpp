// UsbCapture.cpp : CUsbCaptureApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "UsbCapture.h"
#include "stdio.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CUsbCaptureApp theApp;

const GUID CDECL _tlid = { 0x16767E43, 0x974A, 0x40CF, { 0x8C, 0x56, 0x1A, 0xB8, 0xC, 0xE1, 0xB, 0x5F } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CUsbCaptureApp::InitInstance - DLL ��ʼ��

BOOL CUsbCaptureApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}
	return bInit;
}



// CUsbCaptureApp::ExitInstance - DLL ��ֹ

int CUsbCaptureApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣
	capDriverDisconnect(m_UsbCapturePropPage.m_hCapWnd);
	LPCTSTR filePath = m_UsbCapturePropPage.filePathStr;
	//MessageBox(NULL,filePath,TEXT("432"),MB_OK);
	//char *filename = "D:\\ReformerVisitor.jpg";;
	//WideCharToMultiByte(CP_ACP, 0, filePath, -1, filename, wcslen(filePath), NULL, NULL);
	//MessageBoxA(NULL, filename, "��ʾ�Ի���һ", MB_OK);
	//remove(filename);
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
