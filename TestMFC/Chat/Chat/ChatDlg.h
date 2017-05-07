
// ChatDlg.h : 头文件
//
#define WM_RECVDATA WM_USER+1
#pragma once


// CChatDlg 对话框
class CChatDlg : public CDialogEx
{
// 构造
public:
	CChatDlg(CWnd* pParent = NULL);	// 标准构造函数
	//BOOL InitSocket();
	static DWORD WINAPI RecvProc(LPVOID  lpParameter);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnRecvData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	SOCKET m_socket;
public:
	afx_msg void OnBnClickedBtnSend();
	BOOL InitSocket();
};
struct RECVPARAM
{
	SOCKET sock;
	HWND hwnd;
};