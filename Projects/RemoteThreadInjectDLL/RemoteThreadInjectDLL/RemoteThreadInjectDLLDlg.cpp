
// RemoteThreadInjectDLLDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RemoteThreadInjectDLL.h"
#include "RemoteThreadInjectDLLDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define DLLNAME _T("AskTao.dll")
#define CLSNAME _T("AskTao")
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


// CRemoteThreadInjectDLLDlg 对话框




CRemoteThreadInjectDLLDlg::CRemoteThreadInjectDLLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRemoteThreadInjectDLLDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRemoteThreadInjectDLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PROCESSLIST, m_ProcessList);
}

BEGIN_MESSAGE_MAP(CRemoteThreadInjectDLLDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_INJECT, &CRemoteThreadInjectDLLDlg::OnBnClickedBtnInject)
	ON_BN_CLICKED(IDC_BTN_UNLOAD, &CRemoteThreadInjectDLLDlg::OnBnClickedBtnUnload)
	ON_CBN_DROPDOWN(IDC_COMBO_PROCESSLIST, &CRemoteThreadInjectDLLDlg::OnDropdownComboProcesslist)
END_MESSAGE_MAP()


// CRemoteThreadInjectDLLDlg 消息处理程序

BOOL CRemoteThreadInjectDLLDlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRemoteThreadInjectDLLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRemoteThreadInjectDLLDlg::OnPaint()
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
HCURSOR CRemoteThreadInjectDLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRemoteThreadInjectDLLDlg::OnBnClickedBtnInject()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_ProcessList.GetCurSel() == -1)
	{
		MessageBox(_T("请选择目标进程！"), _T("提示"),MB_OK|MB_ICONEXCLAMATION);
	} 
	else
	{
		CString strDllFile = pathfileFun::GetAppPath() + DLLNAME;
		if (!InjectLibW(m_ProcessList.GetItemData(m_ProcessList.GetCurSel()), strDllFile.LockBuffer()))
		{
			MessageBox(_T("注入失败！"), _T("提示"), MB_OK|MB_ICONERROR);
		}
		strDllFile.UnlockBuffer();
	}
}


void CRemoteThreadInjectDLLDlg::OnBnClickedBtnUnload()
{
	// TODO: 在此添加控件通知处理程序代码
		// TODO: 在此添加控件通知处理程序代码
	if (m_ProcessList.GetCurSel() == -1)
	{
		MessageBox(_T("请选择目标进程！"), _T("提示"), MB_OK | MB_ICONEXCLAMATION);
	} 
	else
	{
		HWND hwnd = ::FindWindow(NULL, _T("问道"));
		if (NULL != hwnd){
			if (IDCANCEL == MessageBox(TEXT("确认卸载？"), TEXT("提示"), MB_OKCANCEL | MB_ICONQUESTION))
			    return;
		}
		::SendMessage(hwnd, WM_CLOSE, NULL, NULL);
		CString strDllFile = pathfileFun::GetAppPath() + DLLNAME;
		if (!UnhookProcess(m_ProcessList.GetItemData(m_ProcessList.GetCurSel()), strDllFile))
		{
			MessageBox(_T("卸载失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		}
	}
}


//调整进程权限
bool EnablePrivilege(TCHAR* PrivilegeName,BOOL IsEnable)
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tp;
	LUID luid;

	if(!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY | TOKEN_READ,&hToken))
	{
		return false;
	}
	if(!LookupPrivilegeValue(NULL, PrivilegeName, &luid))
	{
		return false;
	}
	tp.PrivilegeCount           = 1;
	tp.Privileges[0].Luid       = luid;
	tp.Privileges[0].Attributes = (IsEnable) ? SE_PRIVILEGE_ENABLED : 0;
	BOOL bSucc = AdjustTokenPrivileges(hToken,FALSE,&tp,NULL,NULL,NULL);
	CloseHandle(hToken);
	return (GetLastError() == ERROR_SUCCESS);
}
BOOL WINAPI InjectLibW(DWORD dwProcessId, PCWSTR pszLibFile) {

	BOOL bOk = FALSE; // Assume that the function fails
	HANDLE hProcess = NULL, hThread = NULL;
	LPVOID pszLibFileRemote = NULL;

	__try {
		// Get a handle for the target process.
		//获取访问进程权限，存放至hProcess
		hProcess = OpenProcess(
			PROCESS_QUERY_INFORMATION |   // Required by Alpha
			PROCESS_CREATE_THREAD |   // For CreateRemoteThread
			PROCESS_VM_OPERATION |   // For VirtualAllocEx/VirtualFreeEx
			PROCESS_VM_WRITE,             // For WriteProcessMemory
			FALSE, dwProcessId);
		if (hProcess == NULL) {
			AfxMessageBox(_T("获取访问权限失败"));
			return FALSE;
		};

		// Calculate the number of bytes needed for the DLL's pathname
		int cch = 1 + lstrlenW(pszLibFile);
		//申请内存大小
		int cb = cch * sizeof(wchar_t);

		// Allocate space in the remote process for the pathname
		////分配远程内存  以写入自己的代码
		//pszLibFileRemote = (PWSTR)VirtualAllocEx(hProcess, NULL, cb, MEM_COMMIT, PAGE_READWRITE);
		//分配远程内存  以写入自己的代码
		pszLibFileRemote = VirtualAllocEx(hProcess, NULL, 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (pszLibFileRemote == NULL) {

			AfxMessageBox(_T("内存申请失败"));
			return FALSE;
		};

		// Copy the DLL's pathname to the remote process' address space
		//写入远程进程代码
		if (!WriteProcessMemory(hProcess, pszLibFileRemote,
			(PVOID)pszLibFile, cb, NULL)) {
			AfxMessageBox(_T("内存写入失败"));
			return FALSE;
		}

		// Get the real address of LoadLibraryW in Kernel32.dll
		PTHREAD_START_ROUTINE pfnThreadRtn = (PTHREAD_START_ROUTINE)
			GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");
		if (pfnThreadRtn == NULL) {
			AfxMessageBox(_T("获取进程地址失败"));
			return FALSE;
		}

		// Create a remote thread that calls LoadLibraryW(DLLPathname)
		////远程调用代码
		hThread = CreateRemoteThread(hProcess, NULL, 0,
			pfnThreadRtn, pszLibFileRemote, 0, NULL);
		if (hThread == NULL)
		{
			AfxMessageBox(_T("远程线程创建失败"));
			return FALSE;
		}

		// Wait for the remote thread to terminate
		//等待创建的线程终止
		WaitForSingleObject(hThread, INFINITE);

		bOk = TRUE; // Everything executed successfully
	}
	__finally { // Now, we can clean everything up

		// Free the remote memory that contained the DLL's pathname
		if (pszLibFileRemote != NULL)
			VirtualFreeEx(hProcess, pszLibFileRemote, 0, MEM_RELEASE);

		if (hThread != NULL)
			CloseHandle(hThread);

		if (hProcess != NULL)
			CloseHandle(hProcess);
	}

	return(bOk);
}
//将指定dll注入指定进程
bool HookProcess(DWORD dwProcessId,CStringA szDllPath)
{

	HANDLE hRemoteProcess    = NULL;
	HANDLE hRemoteThread     = NULL;
	HANDLE hRemoteFunc        = NULL;
	PVOID  pRemoteParam              = NULL;
	DWORD  dwWriten                   = 0;
	BOOL   bRet                      = FALSE;

	char   szDllPathCopy[256] = {0};
	lstrcpyA(szDllPathCopy,szDllPath);

	EnablePrivilege(SE_DEBUG_NAME,true);
	hRemoteProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwProcessId);
	/*hRemoteProcess = OpenProcess(
		PROCESS_QUERY_INFORMATION |   // Required by Alpha
		PROCESS_CREATE_THREAD |   // For CreateRemoteThread
		PROCESS_VM_OPERATION |   // For VirtualAllocEx/VirtualFreeEx
		PROCESS_VM_WRITE,             // For WriteProcessMemory
		FALSE, dwProcessId);*/
	if(hRemoteProcess == NULL)
	{
		EnablePrivilege(SE_DEBUG_NAME,false);
		return false;
	}
	int iSize = (int)strlen(szDllPath);
	pRemoteParam = VirtualAllocEx(hRemoteProcess,NULL,iSize,MEM_COMMIT,PAGE_READWRITE);
	if(pRemoteParam == NULL)
	{
		EnablePrivilege(SE_DEBUG_NAME,false);
		return false;
	}
	bRet = WriteProcessMemory(hRemoteProcess,pRemoteParam,(LPVOID)szDllPathCopy,iSize,&dwWriten);
	if(!bRet)
	{
		if (pRemoteParam)
			VirtualFreeEx(hRemoteProcess,pRemoteParam,0,MEM_RELEASE);
		EnablePrivilege(SE_DEBUG_NAME,false);
		return false; 
	}
	 #ifdef UNICODE
	 	hRemoteFunc = GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "LoadLibraryW");
	 #else
	 	hRemoteFunc = GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
	 #endif
	hRemoteThread = CreateRemoteThread(hRemoteProcess,0,0,(LPTHREAD_START_ROUTINE)hRemoteFunc,pRemoteParam,0,&dwWriten);

	EnablePrivilege(SE_DEBUG_NAME,false);
	// 等待线程结束
	if (hRemoteThread)
	{
		WaitForSingleObject(hRemoteThread,INFINITE);
		HMODULE g_hRemoteHandle;
		GetExitCodeThread(hRemoteThread,(DWORD*)&g_hRemoteHandle);
	}

	// 清理工作
	if(pRemoteParam)
		VirtualFreeEx(hRemoteProcess, pRemoteParam,0,MEM_RELEASE);
	CloseHandle(hRemoteProcess);
	return true;
}
//查找dll实例句柄
HMODULE GetProcessModuleByName(DWORD dwProcessId, CString lpStrName)
{
	HANDLE hModuleSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessId);

	//查找相关的DLL
	MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };
	for (BOOL fok = ::Module32First(hModuleSnap, &me32); fok; fok = ::Module32Next(hModuleSnap, &me32))
	{
		if (lstrcmpi(me32.szExePath, lpStrName) == 0 || lstrcmpi(me32.szModule, lpStrName) == 0)
		{
			return me32.hModule;
		}
	}
	return 0;
}
//卸载注入的DLL
bool UnhookProcess(DWORD dwProcessId, CString szDllPath)
{
	HANDLE hRemoteProcess = NULL;
	HANDLE hRemoteThread = NULL;
	HANDLE hRemoteFunc = NULL;
	PVOID  pRemoteParam = NULL;
	DWORD  dwWriten = 0;
	BOOL   bRet = FALSE;
	//char   szDllPathCopy[256] = {0};
	//lstrcpyA(szDllPathCopy,szDllPath);
	EnablePrivilege(SE_DEBUG_NAME, true);
	hRemoteProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
	if (hRemoteProcess == NULL)
	{
		EnablePrivilege(SE_DEBUG_NAME, false);
		return false;
	}
	//此dll句柄地址就已经是dwProcessId中的地址，所有不需要写入
	HMODULE hDllModule = GetProcessModuleByName(dwProcessId, szDllPath);
	if (!hDllModule)
	{
		EnablePrivilege(SE_DEBUG_NAME, false);
		return false;
	}
	pRemoteParam = hDllModule;
	hRemoteFunc = GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "FreeLibrary");
	hRemoteThread = CreateRemoteThread(hRemoteProcess, 0, 0, (LPTHREAD_START_ROUTINE)hRemoteFunc, pRemoteParam, 0, &dwWriten);
	EnablePrivilege(SE_DEBUG_NAME, false);
	// 等待线程结束
	if (hRemoteThread)
	{
		WaitForSingleObject(hRemoteThread, INFINITE);
	}
	CloseHandle(hRemoteProcess);
	return true;
}
//获取进程列表
void GetProcessList(CArray<PROCESSENTRY32>& arrProcess)
{
	arrProcess.RemoveAll();
	PROCESSENTRY32    stProcess;
	HANDLE     hSnapShot;
	BOOL b;

	RtlZeroMemory(&stProcess, sizeof(stProcess));
	stProcess.dwSize = sizeof(stProcess);
	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	b = Process32First(hSnapShot, &stProcess);
	while ( b )
	{
		arrProcess.Add(stProcess);
		b = Process32Next(hSnapShot, &stProcess);
	}        
	CloseHandle(hSnapShot);
}

typedef struct
{
	HWND hWnd;
	DWORD dwPid;
}WNDINFO;

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	WNDINFO* pInfo = (WNDINFO*)lParam;
	DWORD dwProcessId = 0;
	GetWindowThreadProcessId(hWnd, &dwProcessId);

	if (dwProcessId == pInfo->dwPid)
	{
		pInfo->hWnd = hWnd;
		return FALSE;
	}
	return TRUE;
}
HWND GetHwndByProcessId(DWORD dwProcessId)
{
	WNDINFO info = { 0 };
	info.hWnd = NULL;
	info.dwPid = dwProcessId;
	EnumWindows(EnumWindowsProc, (LPARAM)&info);
	return info.hWnd;
}
void CRemoteThreadInjectDLLDlg::OnDropdownComboProcesslist()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ProcessList.ResetContent();//清空列表
	HWND hwnd;
	hwnd = ::FindWindow(CLSNAME, NULL);
	if (NULL != hwnd)
	{
		WCHAR szTitle[MAX_PATH];
		::GetWindowText(hwnd, szTitle, sizeof(szTitle));
		DWORD processId;
		::GetWindowThreadProcessId(hwnd, &processId);
		m_ProcessList.SetItemData(m_ProcessList.AddString(szTitle),processId);
	}
	while (hwnd != NULL)
	{
		hwnd = ::FindWindowEx(NULL, hwnd, CLSNAME, NULL);
		if (NULL != hwnd)
		{
			WCHAR szTitle[MAX_PATH];
			::GetWindowText(hwnd, szTitle, MAX_PATH);
			DWORD threadId, processId;
			threadId = GetWindowThreadProcessId(hwnd, &processId);
			if (threadId)
			{
				m_ProcessList.SetItemData(m_ProcessList.AddString(szTitle), processId);
			}
		}
	}

	//CArray<PROCESSENTRY32> arrProcess;
	//GetProcessList(arrProcess);
	//CString strProcessInfo;
	//for (int i=arrProcess.GetCount()-1; i>=0; i--)
	//{
	//	strProcessInfo=_T("");
	//	m_ProcessList.AddString(pathfileFun::GetFileNameFromFilePath(arrProcess[i].szExeFile));
	//	strProcessInfo.Format(_T("[%d]%s"), arrProcess[i].th32ProcessID, pathfileFun::GetFileNameFromFilePath(arrProcess[i].szExeFile));
	//	m_ProcessList.SetItemData( m_ProcessList.AddString(strProcessInfo), arrProcess[i].th32ProcessID );
	//}
}
