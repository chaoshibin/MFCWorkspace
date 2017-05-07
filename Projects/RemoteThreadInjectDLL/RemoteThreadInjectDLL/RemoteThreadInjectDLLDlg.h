
// RemoteThreadInjectDLLDlg.h : ͷ�ļ�
//
#include <tlhelp32.h>
#include "afxwin.h"
#pragma once


// CRemoteThreadInjectDLLDlg �Ի���
class CRemoteThreadInjectDLLDlg : public CDialogEx
{
// ����
public:
	CRemoteThreadInjectDLLDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_REMOTETHREADINJECTDLL_DIALOG };

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
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnInject();
	afx_msg void OnBnClickedBtnUnload();
	afx_msg void OnCbnSelchangeComboProcesslist();
	afx_msg void OnDropdownComboProcesslist();
	CComboBox m_ProcessList;
};
//��������Ȩ��
bool EnablePrivilege(TCHAR* PrivilegeName,BOOL IsEnable);
//��ָ��dllע��ָ������
bool HookProcess(DWORD dwProcessId,CStringA szDllPath);
BOOL WINAPI InjectLibW(DWORD dwProcessId, PCWSTR pszLibFile);
//����dllʵ�����
HMODULE GetProcessModuleByName(DWORD dwProcessId,CString lpStrName);
//ж��ע���DLL
bool UnhookProcess(DWORD dwProcessId,CString szDllPath);

//��ȡ�����б�
void GetProcessList(CArray<PROCESSENTRY32>& arrProcess);

namespace pathfileFun
{
	//**************************************************************  
	//*  GetCurrentDirectory�õ��Ĳ�һ����Ӧ�ó������ڵ�Ŀ¼��Ҫ�õ�Ӧ�ó������ڵ�Ŀ¼��������һ�������� 
	//*��������     GetAppPath()  
	//*  
	//*  
	//*����ֵ         CString                     -   ����·������ʽ��   C:\temp\      
	//����               -   �õ�Ӧ�ó������ڵ�·�������浽strPathBuffer��  
	//*  
	//**************************************************************  
	inline CString WINAPI GetAppPath()
	{
		CString strPathBuffer;
		TCHAR PathBuffer[MAX_PATH];
		GetModuleFileName(AfxGetInstanceHandle(), PathBuffer, MAX_PATH);
		strPathBuffer.Format(_T("%s"),PathBuffer);
		CString strAppPath=strPathBuffer.Mid(0,strPathBuffer.ReverseFind(_T('\\'))+1);
		return strAppPath;
	};
	//��ʽ��·����ʹ��·��ͳһ���ԡ�\����β
	inline CString FormatPath(CString strPath)
	{
		if ( strPath.Right(1) != _T("\\") )
			strPath += _T("\\");
		return strPath;
	};
	//���ļ���ȫ·���л�ȡ�ļ����ڵ��ļ���·�������ص�·���ԡ�\����β
	inline CString GetPathFromFile(CString FilePath)
	{
		return FilePath.Mid(0,FilePath.ReverseFind(_T('\\'))+1);
	};
	//���ļ���ȫ·���л�ȡ�ļ���������׺��
	inline CString GetFileNameFromFilePath(CString FilePath)
	{
		return FilePath.Right(FilePath.GetLength() - FilePath.ReverseFind(_T('\\'))+1);
	};
}