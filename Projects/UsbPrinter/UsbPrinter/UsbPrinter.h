#pragma once

// UsbPrinter.h : UsbPrinter.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// CUsbPrinterApp : �й�ʵ�ֵ���Ϣ������� UsbPrinter.cpp��

class CUsbPrinterApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
	LONG SendFilePath(LPCTSTR lpFilePath);
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

