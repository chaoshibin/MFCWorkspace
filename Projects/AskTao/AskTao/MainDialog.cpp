// MainDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "AskTao.h"
#include "MainDialog.h"
#include "afxdialogex.h"


// CMainDialog 对话框

IMPLEMENT_DYNAMIC(CMainDialog, CDialog)

CMainDialog::CMainDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MAINDIALOG, pParent)
	, m_Content(_T(""))
	, m_Talking(FALSE)
{

}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_Content);
	DDX_Check(pDX, IDC_CHECK_TALK, m_Talking);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialog)
	ON_BN_CLICKED(IDC_BTN_SEND, &CMainDialog::OnBnClickedBtnSend)
	ON_BN_CLICKED(IDC_CHECK_TALK, &CMainDialog::OnBnClickedCheckTalk)
END_MESSAGE_MAP()


// CMainDialog 消息处理程序	


void  __stdcall talkMachine(PTCHAR  buffer) {

	PVOID null_memory = malloc(0x100);
	ULONG bufferLen = _tcslen(buffer);
	memset(null_memory, 0, 0x100);
	_asm {
		pushfd;
		pushad;
		push  null_memory
			push null_memory
			push bufferLen
			push  buffer
			push 0
			push 1
			MOV ecx, 0x0d2E680
			MOV ECX, [ECX]
			MOV ECX, [ECX + 0x1F4]
			MOV eax, 0x0078F550
			CALL eax;
		popad;
		popfd;
	}
	free(null_memory);
}
TCHAR Buffer[MAX_PATH];
void CMainDialog::OnBnClickedBtnSend()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_CONTENT, Buffer, MAX_PATH);
	talkMachine(Buffer);
	if (m_Talking)
	   SetTimer(1, 5000, &TimerProc);
	
}
void CALLBACK TimerProc(
	HWND hwnd,
	UINT uMsg,
	UINT idEvent,
	DWORD dwTime
	){
	talkMachine(Buffer);
}




void CMainDialog::OnBnClickedCheckTalk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK_TALK))->GetCheck())
	{
		GetDlgItemText(IDC_EDIT_CONTENT, Buffer, MAX_PATH);
		SetTimer(1, 5000, &TimerProc);
	}else {
		KillTimer(1);
	}
}
