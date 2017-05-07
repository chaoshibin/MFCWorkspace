#pragma once

// UsbCapture.h : UsbCapture.DLL 的主头文件

#if !defined( __AFXCTL_H__ )
#error "在包括此文件之前包括“afxctl.h”"
#endif

#include "resource.h"       // 主符号
#include "UsbCapturePropPage.h"
#include "UsbCaptureCtrl.h"
// CUsbCaptureApp : 有关实现的信息，请参阅 UsbCapture.cpp。

class CUsbCaptureApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
	CUsbCapturePropPage m_UsbCapturePropPage;
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

