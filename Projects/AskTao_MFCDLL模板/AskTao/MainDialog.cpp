// MainDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "AskTao.h"
#include "MainDialog.h"
#include "afxdialogex.h"


// CMainDialog 对话框

IMPLEMENT_DYNAMIC(CMainDialog, CDialog)

CMainDialog::CMainDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDialog::IDD, pParent)
{

}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialog)
END_MESSAGE_MAP()


// CMainDialog 消息处理程序
