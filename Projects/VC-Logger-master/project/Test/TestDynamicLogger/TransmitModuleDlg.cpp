// TransmitModuleDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TransmitModule.h"
#include ".\transmitmoduledlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTransmitModuleDlg �Ի���



CTransmitModuleDlg::CTransmitModuleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTransmitModuleDlg::IDD, pParent)
	, m_enModuleState(MS_INIT)
	, m_iPrintFlag(ILogger::DEFAULT_PRINT_FLAG)
	, m_logLevel(ILogger::DEFAULT_LOG_LEVEL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTransmitModuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_START_STOP, m_btnStartStop);
	DDX_Control(pDX, IDC_LOG_LEVEL, m_btnLogLevel);
	DDX_Control(pDX, IDC_PRINT_FLAG, m_btnPrintFlag);
	DDX_Control(pDX, IDC_INFO, m_edtInfo);
	DDX_Control(pDX, IDC_SEND_MAIN, m_btnSendMain);
	DDX_Control(pDX, IDC_SEND_OTHER, m_btnSendOther);
}

BEGIN_MESSAGE_MAP(CTransmitModuleDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_START_STOP, OnBnClickedStartStop)
	ON_BN_CLICKED(IDC_LOG_LEVEL, OnBnClickedLogLevel)
	ON_BN_CLICKED(IDC_PRINT_FLAG, OnBnClickedPrintFlag)
	ON_WM_CLOSE()
	//ON_WM_COPYDATA()
	ON_MESSAGE(ILogger::LOG_MESSAGE, OnLoggerMsg)
	ON_BN_CLICKED(IDC_SEND_MAIN, OnBnClickedSendMain)
	ON_BN_CLICKED(IDC_SEND_OTHER, OnBnClickedSendOther)
END_MESSAGE_MAP()

// CTransmitModuleDlg ��Ϣ�������

BOOL CTransmitModuleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_NORMAL);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	SetModuleState(MS_INIT);
	UpdateBtnLogLevelText();
	UpdatePrintFlagText();

	srand((UINT)time(NULL));
	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTransmitModuleDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
HCURSOR CTransmitModuleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTransmitModuleDlg::UpdateDlgUI()
{
	switch(GetModuleState())
	{
	case MS_INIT:
	case MS_START_ERROR:
	case MS_STOP_OK:
	case MS_STOP_ERROR:
		m_btnStartStop.EnableWindow(TRUE);
		m_btnPrintFlag.EnableWindow(TRUE);
		break;
	case MS_STARTING:
	case MS_STOPING:
		m_btnStartStop.EnableWindow(FALSE);
		m_btnPrintFlag.EnableWindow(FALSE);
		break;
	case MS_START_OK:
		m_btnStartStop.EnableWindow(TRUE);
		m_btnPrintFlag.EnableWindow(FALSE);
		break;
	default:
		;
	}
	m_btnLogLevel.EnableWindow(m_btnPrintFlag.IsWindowEnabled());
}

void CTransmitModuleDlg::OnBnClickedStartStop()
{
	if(!Logger->HasInited())
	{
		// Init
		SetModuleState(MS_STARTING);
		if(Logger->Init(NULL, m_logLevel, m_iPrintFlag))
		{
			SetModuleState(MS_START_OK);
			Logger->SetGUIWindow(GetSafeHwnd());
			Logger->Info(_T("��־�����ʼ���ɹ� ^_^"));
		}
		else
		{
			LPCTSTR desc = Logger.ILogger_GetErrorDesc(Logger->GetLastError());
			MessageBox(desc, _T("��ʾ"), MB_OK | MB_ICONEXCLAMATION);
			SetModuleState(MS_START_ERROR);
		}
	}
	else
	{
		// UnInit
		SetModuleState(MS_STOPING);
		if(Logger->UnInit())
		{
			SetModuleState(MS_STOP_OK);
			MessageBox(_T("��־����رճɹ� ^_^"), _T("��ʾ"), MB_OK | MB_ICONINFORMATION);
		}
		else
		{
			SetModuleState(MS_STOP_ERROR);
			MessageBox(_T("��־����ر�ʧ�� ����"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		}
	}
	m_btnStartStop.SetWindowText(Logger->HasInited() ? _T("�ر���־") : _T("����־"));
}

void CTransmitModuleDlg::OnBnClickedLogLevel()
{
	int level = (m_logLevel + 1);
	if(level > ILogger::LL_FATAL)
		level = level % ILogger::LL_FATAL;
	m_logLevel = (ILogger::LogLevel)(level);
	UpdateBtnLogLevelText();
}

void CTransmitModuleDlg::OnBnClickedPrintFlag()
{
	switch(m_iPrintFlag)
	{
	case 0:
		m_iPrintFlag = ILogger::PRINT_FLAG_FILE;
		break;
	case ILogger::PRINT_FLAG_FILE:
		m_iPrintFlag = ILogger::PRINT_FLAG_SCREEN;;
		break;
	case ILogger::PRINT_FLAG_SCREEN:
		m_iPrintFlag = ILogger::PRINT_FLAG_FILE | ILogger::PRINT_FLAG_SCREEN;
		break;
	case ILogger::PRINT_FLAG_FILE | ILogger::PRINT_FLAG_SCREEN:
		m_iPrintFlag = 0;
		break;
	default:
		m_iPrintFlag = ILogger::PRINT_FLAG_FILE | ILogger::PRINT_FLAG_SCREEN;
	}
	UpdatePrintFlagText();
}

void CTransmitModuleDlg::OnBnClickedSendMain()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i = 0; i < 1; i++)
	{
		MakeLogInfoFunc(0);
	}
}

void CTransmitModuleDlg::OnBnClickedSendOther()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i = 0; i < 1; i++)
	{
		AfxBeginThread(MakeLogInfoFunc, (PVOID)1);
	}
}

void CTransmitModuleDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	Logger->SetGUIWindow(NULL);
	CDialog::OnClose();
}

LRESULT CTransmitModuleDlg::OnLoggerMsg(WPARAM wp, LPARAM lp)
{
	// WPARAM�� ILoggger ����ָ��
	ILogger* pLogger		= (ILogger*)(wp);
	// LPARAM�� TLogMsg ����ָ��
	ILogger::TLogMsg* plm	= (ILogger::TLogMsg*)(lp);

	SYSTEMTIME& st			= plm->m_stMsgTime;
	
	CString msg;
	msg.Format	(	_T("%02d-%02d %02d:%02d:%02d.%03d\t%6d\t[%-5s]\t%s\r\n"), 
					st.wMonth, st.wDay, st.wHour, 
					st.wMinute, st.wSecond, st.wMilliseconds, 
					plm->m_uiThreadID, 
					Logger.ILogger_GetLogLevelDesc(plm->m_logLevel), plm->m_psMsg
				);

	if(m_edtInfo.GetWindowTextLength() > MAX_INFO_TEXT_LENGT)
		m_edtInfo.SetWindowText(_T(""));

	CString oriMsg;
	m_edtInfo.GetWindowText(oriMsg);
	m_edtInfo.SetWindowText(msg + oriMsg);

	// ���� TLogMsg ����
	Logger->FreeLogMsg(plm);

	return 0;
}

UINT CTransmitModuleDlg::MakeLogInfoFunc(LPVOID  pParam)
{
	if(pParam)
		srand((UINT)::GetCurrentThreadId());

	ILogger::LogLevel ll = (ILogger::LogLevel)(rand() % ILogger::LL_FATAL + 1);

	if(pParam)
		Logger->TryLog(ll, _T("�߳� 0x%08X д����־��Ϣ��������������������������������������������������������������������������������������"), ::GetCurrentThreadId());
	else
		Logger->Log_0(ll, _T("���߳�д����־��Ϣ�����������������������������������������������"));

	return 0;
}

void CTransmitModuleDlg::UpdateBtnLogLevelText(void)
{
	CString text;
	text.Format(_T("��־���� [%s]"), Logger.ILogger_GetLogLevelDesc(m_logLevel));
	m_btnLogLevel.SetWindowText(text);
}

void CTransmitModuleDlg::UpdatePrintFlagText(void)
{
	CString pf;
	switch(m_iPrintFlag)
	{
	case 0:
		pf = _T("����ӡ��־");
		break;
	case ILogger::PRINT_FLAG_FILE:
		pf = _T("ֻ��ӡ���ļ�");
		break;
	case ILogger::PRINT_FLAG_SCREEN:
		pf = _T("ֻ��ӡ����Ļ");
		break;
	case ILogger::PRINT_FLAG_FILE | ILogger::PRINT_FLAG_SCREEN:
		pf = _T("��ӡ���ļ�����Ļ");
		break;
	default:
		pf = _T("----------");
	}
	m_btnPrintFlag.SetWindowText(pf);
}

BOOL CTransmitModuleDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (
		pMsg->message == WM_KEYDOWN		
		&&(	pMsg->wParam == VK_ESCAPE	 
		||	pMsg->wParam == VK_CANCEL	
		||	pMsg->wParam == VK_RETURN	
		))
		return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}
