#pragma once
// GrandDogWeb.h : GrandDogWeb.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������
#include"GrandDogWebCtrl.h"

// CGrandDogWebApp : �й�ʵ�ֵ���Ϣ������� GrandDogWeb.cpp��

class CGrandDogWebApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
	CGrandDogWebCtrl webAppCtrl;
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;
