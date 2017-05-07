#pragma once
#include "afxwin.h"

#define  TIMEER

// CMainDialog �Ի���

class CMainDialog : public CDialog
{
	DECLARE_DYNAMIC(CMainDialog)

public:
	CMainDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAINDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSend();
	CString m_Content;
	afx_msg void OnBnClickedCheckTalk();
	BOOL m_Talking;
};
void CALLBACK TimerProc(
	HWND hwnd,
	UINT uMsg,
	UINT idEvent,
	DWORD dwTime
	);

//UINT SetTimer(
//	HWND hWnd,
//	UINT nIDEvent,
//	UINT uElapse,
//	TIMERPROC lpTimerFunc
//	);