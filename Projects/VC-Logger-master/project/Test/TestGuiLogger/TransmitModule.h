// TransmitModule.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������

#include "..\..\LoggerDLL\StaticLogger.h"

// CTransmitModuleApp:
// �йش����ʵ�֣������ TransmitModule.cpp
//

class CTransmitModuleApp : public CWinApp
{
public:
	CTransmitModuleApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CTransmitModuleApp theApp;
extern CStaticLogger Logger;
