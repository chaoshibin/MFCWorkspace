// AskTao.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "AskTao.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ��  ����ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CAskTaoApp

BEGIN_MESSAGE_MAP(CAskTaoApp, CWinApp)
END_MESSAGE_MAP()


// CAskTaoApp ����

CAskTaoApp::CAskTaoApp()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAskTaoApp ����

CAskTaoApp theApp;


// CAskTaoApp ��ʼ��

BOOL CAskTaoApp::InitInstance()
{
	CWinApp::InitInstance();
	//��dllע��֮����ʾ���Ի���
	m_pMainDialog = new CMainDialog();
	m_pFrame = new CFrameWnd();
	m_pMainWnd = m_pFrame;//�����Զ�������Ϣ��ʡȥ�ֶ�д��Ϣѭ�����Ӷ������ڶԻ���ճ��־͹ر�
	m_pMainWnd = m_pMainDialog;
	::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ShowDialog, (LPVOID)m_pMainDialog, NULL, NULL);
	return TRUE;
}
int CAskTaoApp::ExitInstance()
{
	SendMessage(m_pMainDialog->m_hWnd, WM_CLOSE, NULL, NULL);

	return CWinApp::ExitInstance();
}

void ShowDialog(CMainDialog *pMainDialog)
{
	pMainDialog->DoModal(); //��ʾ�Ի���
}