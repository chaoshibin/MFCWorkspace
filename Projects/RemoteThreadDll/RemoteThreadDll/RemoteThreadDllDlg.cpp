
// RemoteThreadDllDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RemoteThreadDll.h"
#include "RemoteThreadDllDlg.h"
#include "afxdialogex.h"
#include <tlhelp32.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CRemoteThreadDllDlg �Ի���



CRemoteThreadDllDlg::CRemoteThreadDllDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_REMOTETHREADDLL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRemoteThreadDllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRemoteThreadDllDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRemoteThreadDllDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRemoteThreadDllDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CRemoteThreadDllDlg ��Ϣ�������

BOOL CRemoteThreadDllDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRemoteThreadDllDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRemoteThreadDllDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRemoteThreadDllDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL WINAPI InjectLibW(DWORD dwProcessId, PCWSTR pszLibFile) {

	BOOL bOk = FALSE; // Assume that the function fails
	HANDLE hProcess = NULL, hThread = NULL;
	LPVOID pszLibFileRemote = NULL;

	__try {
		// Get a handle for the target process.
		//��ȡ���ʽ���Ȩ�ޣ������hProcess
		hProcess = OpenProcess(
			PROCESS_QUERY_INFORMATION |   // Required by Alpha
			PROCESS_CREATE_THREAD |   // For CreateRemoteThread
			PROCESS_VM_OPERATION |   // For VirtualAllocEx/VirtualFreeEx
			PROCESS_VM_WRITE,             // For WriteProcessMemory
			FALSE, dwProcessId);
		if (hProcess == NULL) {
				AfxMessageBox(_T("��ȡ����Ȩ��ʧ��"));
				return FALSE;
		};

		// Calculate the number of bytes needed for the DLL's pathname
		int cch = 1 + lstrlenW(pszLibFile);
		//�����ڴ��С
		int cb = cch * sizeof(wchar_t);

		// Allocate space in the remote process for the pathname
		////����Զ���ڴ�  ��д���Լ��Ĵ���
		//pszLibFileRemote = (PWSTR)VirtualAllocEx(hProcess, NULL, cb, MEM_COMMIT, PAGE_READWRITE);
		//����Զ���ڴ�  ��д���Լ��Ĵ���
		pszLibFileRemote = VirtualAllocEx(hProcess, NULL, 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (pszLibFileRemote == NULL) {
		
			AfxMessageBox(_T("�ڴ�����ʧ��"));
			return FALSE;
		};

		// Copy the DLL's pathname to the remote process' address space
		//д��Զ�̽��̴���
		if (!WriteProcessMemory(hProcess, pszLibFileRemote,
			(PVOID)pszLibFile, cb, NULL)) {
			AfxMessageBox(_T("�ڴ�д��ʧ��"));
			return FALSE;
		}

		// Get the real address of LoadLibraryW in Kernel32.dll
		PTHREAD_START_ROUTINE pfnThreadRtn = (PTHREAD_START_ROUTINE)
			GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");
		if (pfnThreadRtn == NULL) {
			AfxMessageBox(_T("��ȡ���̵�ַʧ��"));
			return FALSE;
		}

		// Create a remote thread that calls LoadLibraryW(DLLPathname)
		////Զ�̵��ô���
		hThread = CreateRemoteThread(hProcess, NULL, 0,
			pfnThreadRtn, pszLibFileRemote, 0, NULL);
		if (hThread == NULL)
		{
			AfxMessageBox(_T("Զ���̴߳���ʧ��"));
			return FALSE;
		}

		// Wait for the remote thread to terminate
		//�ȴ��������߳���ֹ
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
inline CString WINAPI GetAppPath()
{
	CString strPathBuffer;
	TCHAR PathBuffer[MAX_PATH];
	GetModuleFileName(AfxGetInstanceHandle(), PathBuffer, MAX_PATH);
	strPathBuffer.Format(_T("%s"), PathBuffer);
	CString strAppPath = strPathBuffer.Mid(0, strPathBuffer.ReverseFind(_T('\\')) + 1);
	return strAppPath;
};

void CRemoteThreadDllDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd;//���ھ��
	hwnd = ::FindWindowA("AskTao", NULL);
	if (hwnd == NULL)
	{
		AfxMessageBox(_T("���Ҵ���ʧ��"));
		return;
	}
	DWORD  id; //����id

	LPDWORD Pid = &id;

	//ȡ��ָ�����ڵĽ���ID����ڱ���id����
	::GetWindowThreadProcessId(hwnd, Pid);
	//char * path = "I:\\Project\\AskTao\\Debug\\AskTao.dll";
	//CString str = CString(path);
	CString strDllFile = GetAppPath() + _T("AskTao.dll");
	CString str = strDllFile;
	USES_CONVERSION;
	LPCWSTR wszClassName = new WCHAR[str.GetLength() + 1];
	_tcscpy_s((LPTSTR)wszClassName, _tcslen(wszClassName), (LPTSTR)str.GetBuffer(NULL));
	str.ReleaseBuffer();
	CString b;
	b.Format(TEXT("ע�����%d"), id);
	MessageBox(b);
	InjectLibW(id,wszClassName);
	
	/*if (gameForm= NULL)
	{
		gameForm = new GameForm();
		gameForm->create("");
	}
	gameForm->ShowWindow(SW_SHOW);*/

}

//��������Ȩ��
bool EnablePrivilege(TCHAR* PrivilegeName, BOOL IsEnable)
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tp;
	LUID luid;

	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY | TOKEN_READ, &hToken))
	{
		return false;
	}
	if (!LookupPrivilegeValue(NULL, PrivilegeName, &luid))
	{
		return false;
	}
	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = (IsEnable) ? SE_PRIVILEGE_ENABLED : 0;
	BOOL bSucc = AdjustTokenPrivileges(hToken, FALSE, &tp, NULL, NULL, NULL);
	CloseHandle(hToken);
	return (GetLastError() == ERROR_SUCCESS);
}
//����dllʵ�����
HMODULE GetProcessModuleByName(DWORD dwProcessId, CString lpStrName)
{
	HANDLE hModuleSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessId);

	//������ص�DLL
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
//ж��ע���DLL
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
	//��dll�����ַ���Ѿ���dwProcessId�еĵ�ַ�����в���Ҫд��
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
	// �ȴ��߳̽���
	if (hRemoteThread)
	{
		WaitForSingleObject(hRemoteThread, INFINITE);
	}
	CloseHandle(hRemoteProcess);
	return true;
}

void CRemoteThreadDllDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		CString strDllFile = GetAppPath() + _T("AskTao.dll");
		HWND hwnd;//���ھ��
		hwnd = ::FindWindowA("AskTao", NULL);
		if (hwnd == NULL)
		{
			AfxMessageBox(_T("���Ҵ���ʧ��"));
			return;
		}
		DWORD  id; //����id

		LPDWORD Pid = &id;

		//ȡ��ָ�����ڵĽ���ID����ڱ���id����
		::GetWindowThreadProcessId(hwnd, Pid);
		if (UnhookProcess(id,strDllFile) == false)
		{
			AfxMessageBox(_T("ж��ʧ�ܣ�"));
		}
}
