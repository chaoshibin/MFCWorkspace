
// TalkDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Talk.h"
#include "TalkDlg.h"
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


// CTalkDlg 对话框



CTalkDlg::CTalkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TALK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTalkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTalkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTalkDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTalkDlg 消息处理程序

BOOL CTalkDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTalkDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTalkDlg::OnPaint()
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
HCURSOR CTalkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
 void __declspec(naked) __stdcall personTalk()
{
	
	 
	_asm {
	       	push 0x002E0002         //空内存  这里的内存都是目标进程的内存
			push 0x002E0000       //空内存 这里的内存都是目标进程的内存
			push 40             //字符串长度
			push 0x002E0010     //喊话字符串  这里的内存都是目标进程的内存
			push 0               //未知
			push 1               //喊话类型  13喇叭
			mov ECX, 0x00CF4538
			mov ECX, [ECX]
			mov ECX, [ECX + 0x1F4]
			mov eax, 0x078EEB0
			call  eax
			ret;
	}
}
void RemoteCall()
{
	HWND hwnd;//窗口句柄
	//const  char title[50]="问道(1.571.1104)  [林海雪原十四线] [芷云]";
	//hwnd = ::FindWindow(NULL, (LPCWSTR)"问道(1.571.1104)  [林海雪原十线] [芷云]");//查找窗
	hwnd = ::FindWindowA("AskTao", NULL);	 
		if (hwnd == NULL)
	    {
			AfxMessageBox(_T("查找窗口失败"));
			return;
		}
		DWORD  id; //进程id

		LPDWORD Pid = &id;

		//取得指定窗口的进程ID存放在变量id里面
		::GetWindowThreadProcessId(hwnd, Pid);

		//获取访问进程权限，存放至hp
		HANDLE  hp = OpenProcess(PROCESS_ALL_ACCESS, false, id);
		//HANDLE  hp = OpenProcess(PROCESS_ALL_ACCESS, false, 6264);
		if (hp == NULL)
		{
			AfxMessageBox(_T("获取访问权限失败"));
			return;
		}
		//分配远程内存  以写入自己的代码
		LPVOID callbase = VirtualAllocEx(hp, NULL, 0x3000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		//LPVOID callbase =VirtualAlloc(NULL, 0x3000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		if (callbase == NULL)
		{
			AfxMessageBox(_T("申请内存失败！"));
			return;
		}
		//写入远程进程代码
		//PVOID  pTalk = (PULONG)(*(PULONG) ((ULONG)personTalk + 1) + (ULONG)personTalk + 5);
		//if (!::WriteProcessMemory(hp, callbase, pTalk, 0x3000, NULL))
		//{
		//	AfxMessageBox(_T("写入代码失败!"));
		//	return;
		//}
		//远程调用代码
		//DWORD tid;

		//CreateRemoteThread(hp, NULL, 0, (LPTHREAD_START_ROUTINE)callbase, 0, 0, &tid);

	}
void CTalkDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	RemoteCall();
}

