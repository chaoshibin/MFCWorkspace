
// RemoteThreadDll.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRemoteThreadDllApp: 
// �йش����ʵ�֣������ RemoteThreadDll.cpp
//

class CRemoteThreadDllApp : public CWinApp
{
public:
	CRemoteThreadDllApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRemoteThreadDllApp theApp;