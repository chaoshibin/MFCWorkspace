
// ChatDlg.h : ͷ�ļ�
//
#define WM_RECVDATA WM_USER+1
#pragma once


// CChatDlg �Ի���
class CChatDlg : public CDialogEx
{
// ����
public:
	CChatDlg(CWnd* pParent = NULL);	// ��׼���캯��
	//BOOL InitSocket();
	static DWORD WINAPI RecvProc(LPVOID  lpParameter);
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAT_DIALOG };
#endif

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