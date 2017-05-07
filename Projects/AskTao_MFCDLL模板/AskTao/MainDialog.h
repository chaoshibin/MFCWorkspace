#pragma once


// CMainDialog 对话框

class CMainDialog : public CDialog
{
	DECLARE_DYNAMIC(CMainDialog)

public:
	CMainDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainDialog();

// 对话框数据
	enum { IDD = IDD_MAINDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
