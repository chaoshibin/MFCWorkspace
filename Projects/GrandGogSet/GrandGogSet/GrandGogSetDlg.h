
// GrandGogSetDlg.h : ͷ�ļ�
//

#pragma once
#include "afxdtctl.h"


// CGrandGogSetDlg �Ի���
class CGrandGogSetDlg : public CDialogEx
{
// ����
public:
	CGrandGogSetDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GRANDGOGSET_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedBtnSetgranddog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtnReadSetting();
//	CDateTimeCtrl m_validDate;
	CDateTimeCtrl m_myPickTime;
};