// UI.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AskTao.h"
#include "UI.h"
#include "afxdialogex.h"


// UI �Ի���

IMPLEMENT_DYNAMIC(UI, CDialog)

UI::UI(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_UI, pParent)
{

}

UI::~UI()
{
}

void UI::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UI, CDialog)
END_MESSAGE_MAP()


// UI ��Ϣ�������
