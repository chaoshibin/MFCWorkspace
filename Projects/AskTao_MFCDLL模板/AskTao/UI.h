#pragma once


// UI �Ի���

class UI : public CDialog
{
	DECLARE_DYNAMIC(UI)

public:
	UI(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UI();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
