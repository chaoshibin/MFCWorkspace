
// RemoteThreadInjectDLL.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRemoteThreadInjectDLLApp:
// �йش����ʵ�֣������ RemoteThreadInjectDLL.cpp
//

class CRemoteThreadInjectDLLApp : public CWinApp
{
public:
	CRemoteThreadInjectDLLApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRemoteThreadInjectDLLApp theApp;