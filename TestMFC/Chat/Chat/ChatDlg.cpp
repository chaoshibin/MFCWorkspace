
// ChatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChatDlg 对话框



CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHAT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

BOOL CChatDlg::InitSocket()
{
	m_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET ==m_socket)
	{
		AfxMessageBox(_T("套接字创建失败!"), MB_OKCANCEL | MB_ICONQUESTION);
		return FALSE;
	}
	SOCKADDR_IN addrSock;
	addrSock.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSock.sin_family = AF_INET;
	addrSock.sin_port = htons(6000);
	int retval;

	retval = bind(m_socket, (SOCKADDR*)&addrSock, sizeof(SOCKADDR));
	if (SOCKET_ERROR == retval)
	{
		closesocket(m_socket);
		//MessageBox("");
		AfxMessageBox(_T("绑定失败"), MB_OK);
		return FALSE;
	}
	return TRUE;
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_RECVDATA,OnRecvData)
	ON_BN_CLICKED(IDC_BTN_SEND, &CChatDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()


LRESULT CChatDlg::OnRecvData(WPARAM wParam, LPARAM lParam) {

	CString str;
	str= (char*)lParam;
	CString strTemp;
	GetDlgItemText(IDC_EDIT_RECV, strTemp);
	str += "\r\n";
	str += strTemp;
	SetDlgItemText(IDC_EDIT_RECV, str);
	return 0;
}

// CChatDlg 消息处理程序

BOOL CChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	InitSocket();
	RECVPARAM *pRecvParam = new RECVPARAM;
	pRecvParam->sock = m_socket;
	pRecvParam->hwnd = m_hWnd;
	HANDLE hThread = CreateThread(NULL, 0, RecvProc, (LPVOID)pRecvParam, 0, NULL);

	CloseHandle(hThread);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
DWORD WINAPI CChatDlg::RecvProc(LPVOID  lpParameter) {
	SOCKET sock = ((RECVPARAM*)lpParameter)->sock;
	HWND hwnd = ((RECVPARAM*)lpParameter)->hwnd;

	delete lpParameter;

	SOCKADDR_IN addrFrom;
	int len = sizeof(SOCKADDR);
	char recvBuf[200];
	char tempBuf[300];
	int retval;
	while (true)
	{
		retval = recvfrom(sock, recvBuf, 200, 0, (SOCKADDR*)&addrFrom, &len);
		if (SOCKET_ERROR == retval)
			break;
			sprintf_s(tempBuf, "%s说:%s", inet_ntoa(addrFrom.sin_addr), recvBuf);
			//CString temp;
			//temp= (char*)tempBuf;
			//AfxMessageBox(temp);
			::SendMessage(hwnd,WM_RECVDATA, 0, (LPARAM)tempBuf);
		return 0;
	}
}



void CChatDlg::OnBnClickedBtnSend()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD dwIP;
	((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);
	SOCKADDR_IN addrTo;
	addrTo.sin_addr.S_un.S_addr = htonl(dwIP);
	addrTo.sin_family = AF_INET;
	addrTo.sin_port = htons(6000);


	CString strSend;
	GetDlgItemText(IDC_EDIT_SEND, strSend);
	//AfxMessageBox(strSend);
	sendto(m_socket, (LPSTR)(LPCTSTR)strSend,strSend.GetLength() + 1, 0, (SOCKADDR*)&addrTo, sizeof(SOCKADDR));
	SetDlgItemText(IDC_EDIT_SEND,(LPCTSTR)"");
}
