// MainDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AskTao.h"
#include "MainDialog.h"
#include "afxdialogex.h"


// CMainDialog �Ի���

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


// CMainDialog ��Ϣ�������
