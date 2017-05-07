// AskTao.h : AskTao DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "MainDialog.h"
// CAskTaoApp
// 有关此类实现的信息，请参阅 AskTao.cpp
//

class CAskTaoApp : public CWinApp
{
public:
	CAskTaoApp();

// 重写
public:
	virtual BOOL InitInstance();
        virtual int ExitInstance();
        CMainDialog *m_pMainDialog;
        CFrameWnd *m_pFrame;
	DECLARE_MESSAGE_MAP()
};
void ShowDialog(CMainDialog *pMainDialog);//显示主对话框线程