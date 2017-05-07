
// TestLogDllDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestLogDll.h"
#include "TestLogDllDlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestLogDllDlg 对话框



CTestLogDllDlg::CTestLogDllDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestLogDllDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestLogDllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestLogDllDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTestLogDllDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestLogDllDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTestLogDllDlg 消息处理程序

BOOL CTestLogDllDlg::OnInitDialog()
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

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestLogDllDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestLogDllDlg::OnPaint()
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
HCURSOR CTestLogDllDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestLogDllDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	ILogger::LogLevel logLevel = (ILogger::LogLevel)(rand() % ILogger::LL_FATAL + 1);
	//LPSTR log = { 0 };
	//LPCTSTR logW = TEXT("我是谁！");

	//INT iSize = WideCharToMultiByte(CP_ACP, 0, szIp, -1, NULL, 0, NULL, NULL);
	//WideCharToMultiByte(CP_ACP, 0, szIp, -1, ip, 32, NULL, NULL);

	//WideCharToMultiByte(CP_ACP, 0, logW, _tcslen(logW), log, (INT)_tcslen(logW), NULL, NULL); //_tcslen 视项目字符集设置而定 同 wcslen宽字节
	//Logger->Debug_0(LPCTSTR("我是谁"), ::GetCurrentThreadId());
	Logger->TryLog(logLevel, LPCTSTR("线程 0x%08X 写的日志信息～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～"), ::GetCurrentThreadId());
	Logger->Debug(LPCTSTR("你你你"));
		return;
}


void CTestLogDllDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	if (!Logger->HasInited())
	{
		MessageBox(TEXT("未初始化 ～～"), TEXT("提示"), MB_OK | MB_ICONERROR);
	}
	else{
		MessageBox(TEXT("已初始化 ～～"), TEXT("提示"), MB_OK|MB_ICONASTERISK);
	}
}
