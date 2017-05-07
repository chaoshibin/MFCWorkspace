
// RemoteThreadInjectDLLDlg.h : 头文件
//
#include <tlhelp32.h>
#include "afxwin.h"
#pragma once


// CRemoteThreadInjectDLLDlg 对话框
class CRemoteThreadInjectDLLDlg : public CDialogEx
{
// 构造
public:
	CRemoteThreadInjectDLLDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_REMOTETHREADINJECTDLL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
//调整进程权限
bool EnablePrivilege(TCHAR* PrivilegeName,BOOL IsEnable);
//将指定dll注入指定进程
bool HookProcess(DWORD dwProcessId,CStringA szDllPath);
BOOL WINAPI InjectLibW(DWORD dwProcessId, PCWSTR pszLibFile);
//查找dll实例句柄
HMODULE GetProcessModuleByName(DWORD dwProcessId,CString lpStrName);
//卸载注入的DLL
bool UnhookProcess(DWORD dwProcessId,CString szDllPath);

//获取进程列表
void GetProcessList(CArray<PROCESSENTRY32>& arrProcess);

namespace pathfileFun
{
	//**************************************************************  
	//*  GetCurrentDirectory得到的不一定是应用程序所在的目录！要得到应用程序所在的目录，这里有一个函数： 
	//*函数名：     GetAppPath()  
	//*  
	//*  
	//*返回值         CString                     -   返回路径的形式是   C:\temp\      
	//功能               -   得到应用程序所在的路径，保存到strPathBuffer中  
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
	//格式化路径，使得路径统一成以“\”结尾
	inline CString FormatPath(CString strPath)
	{
		if ( strPath.Right(1) != _T("\\") )
			strPath += _T("\\");
		return strPath;
	};
	//从文件的全路径中获取文件所在的文件夹路径，返回的路径以“\”结尾
	inline CString GetPathFromFile(CString FilePath)
	{
		return FilePath.Mid(0,FilePath.ReverseFind(_T('\\'))+1);
	};
	//从文件的全路径中获取文件名（含后缀）
	inline CString GetFileNameFromFilePath(CString FilePath)
	{
		return FilePath.Right(FilePath.GetLength() - FilePath.ReverseFind(_T('\\'))+1);
	};
}