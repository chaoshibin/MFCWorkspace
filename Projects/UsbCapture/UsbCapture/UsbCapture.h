#pragma once

// UsbCapture.h : UsbCapture.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������
#include "UsbCapturePropPage.h"
#include "UsbCaptureCtrl.h"
// CUsbCaptureApp : �й�ʵ�ֵ���Ϣ������� UsbCapture.cpp��

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

