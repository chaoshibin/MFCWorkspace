
// TestLogDll.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "StaticLogger.h"
// CTestLogDllApp: 
// �йش����ʵ�֣������ TestLogDll.cpp
//

class CTestLogDllApp : public CWinApp
{
public:
	CTestLogDllApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
private:
	int m_iPrintFlag;
	ILogger::LogLevel m_logLevel = (ILogger::LogLevel)1;//��־����
};

extern CTestLogDllApp theApp;
extern CStaticLogger Logger;