
// DllTese.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDllTeseApp: 
// �йش����ʵ�֣������ DllTese.cpp
//

class CDllTeseApp : public CWinApp
{
public:
	CDllTeseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDllTeseApp theApp;