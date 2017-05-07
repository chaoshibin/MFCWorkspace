
// TalkDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Talk.h"
#include "TalkDlg.h"
#include "afxdialogex.h"

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


// CTalkDlg �Ի���



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


// CTalkDlg ��Ϣ�������

BOOL CTalkDlg::OnInitDialog()
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTalkDlg::OnPaint()
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
HCURSOR CTalkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
 void __declspec(naked) __stdcall personTalk()
{
	
	 
	_asm {
	       	push 0x002E0002         //���ڴ�  ������ڴ涼��Ŀ����̵��ڴ�
			push 0x002E0000       //���ڴ� ������ڴ涼��Ŀ����̵��ڴ�
			push 40             //�ַ�������
			push 0x002E0010     //�����ַ���  ������ڴ涼��Ŀ����̵��ڴ�
			push 0               //δ֪
			push 1               //��������  13����
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
	HWND hwnd;//���ھ��
	//const  char title[50]="�ʵ�(1.571.1104)  [�ֺ�ѩԭʮ����] [����]";
	//hwnd = ::FindWindow(NULL, (LPCWSTR)"�ʵ�(1.571.1104)  [�ֺ�ѩԭʮ��] [����]");//���Ҵ�
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

		//��ȡ���ʽ���Ȩ�ޣ������hp
		HANDLE  hp = OpenProcess(PROCESS_ALL_ACCESS, false, id);
		//HANDLE  hp = OpenProcess(PROCESS_ALL_ACCESS, false, 6264);
		if (hp == NULL)
		{
			AfxMessageBox(_T("��ȡ����Ȩ��ʧ��"));
			return;
		}
		//����Զ���ڴ�  ��д���Լ��Ĵ���
		LPVOID callbase = VirtualAllocEx(hp, NULL, 0x3000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		//LPVOID callbase =VirtualAlloc(NULL, 0x3000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		if (callbase == NULL)
		{
			AfxMessageBox(_T("�����ڴ�ʧ�ܣ�"));
			return;
		}
		//д��Զ�̽��̴���
		//PVOID  pTalk = (PULONG)(*(PULONG) ((ULONG)personTalk + 1) + (ULONG)personTalk + 5);
		//if (!::WriteProcessMemory(hp, callbase, pTalk, 0x3000, NULL))
		//{
		//	AfxMessageBox(_T("д�����ʧ��!"));
		//	return;
		//}
		//Զ�̵��ô���
		//DWORD tid;

		//CreateRemoteThread(hp, NULL, 0, (LPTHREAD_START_ROUTINE)callbase, 0, 0, &tid);

	}
void CTalkDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	RemoteCall();
}

