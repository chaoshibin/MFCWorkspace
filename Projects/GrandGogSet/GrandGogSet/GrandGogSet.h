
// GrandGogSet.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGrandGogSetApp: 
// �йش����ʵ�֣������ GrandGogSet.cpp
//

class CGrandGogSetApp : public CWinApp
{
public:
	CGrandGogSetApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGrandGogSetApp theApp;