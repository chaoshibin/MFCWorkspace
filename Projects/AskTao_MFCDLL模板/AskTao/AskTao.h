// AskTao.h : AskTao DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "MainDialog.h"
// CAskTaoApp
// �йش���ʵ�ֵ���Ϣ������� AskTao.cpp
//

class CAskTaoApp : public CWinApp
{
public:
	CAskTaoApp();

// ��д
public:
	virtual BOOL InitInstance();
        virtual int ExitInstance();
        CMainDialog *m_pMainDialog;
        CFrameWnd *m_pFrame;
	DECLARE_MESSAGE_MAP()
};
void ShowDialog(CMainDialog *pMainDialog);//��ʾ���Ի����߳�