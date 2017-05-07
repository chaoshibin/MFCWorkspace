
// GrandGogSetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GrandGogSet.h"
#include "GrandGogSetDlg.h"
#include "afxdialogex.h"
#include "GrandDogofDll.h"
#include "string.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define USER_TYPE 1 //�û�
#define DEVELOPER_TYPE 2   //������
#define STORAGE_NOT_ENOUGH 0xa8160011 //�洢���� 
#define STORAGE_NOT_ENOUGH_TO 0xA8160010 //�洢����
#define FILE_EXISTT 0xa816000a  //�ļ���Ŀ¼�Ѵ���
#define PWD_ERROR 0xa816000c //�������
#define PWD_LOCK //��������
RC_OPENDOG 							RC_OpenDog;
RC_CLOSEDOG 						RC_CloseDog;
RC_CHECKDOG							RC_CheckDog;
RC_GETDOGINFO						RC_GetDogInfo;
RC_GETPRODUCTCURRENTNO				RC_GetProductCurrentNo;
RC_VERIFYPASSWORD					RC_VerifyPassword;
RC_CHANGEPASSWORD					RC_ChangePassword;
RC_UPGRADE							RC_Upgrade;
RC_GETRANDOM						RC_GetRandom;
RC_ENCRYPTDATA						RC_EncryptData;
RC_DECRYPTDATA						RC_DecryptData;
RC_CONVERTDATA						RC_ConvertData;
RC_SETKEY							RC_SetKey;
RC_SIGNDATA							RC_SignData;
RC_EXECUTEFILE						RC_ExecuteFile;
RC_WRITEFILE						RC_WriteFile;
RC_VISITLICENSEFILE					RC_VisitLicenseFile;
RC_CREATEFILE						RC_CreateFile;
RC_DELETEFILE						RC_DeleteFile;
RC_CREATEDIR						RC_CreateDir;
RC_DELETEDIR						RC_DeleteDir;
RC_DEFRAGFILESYSTEM					RC_DefragFileSystem;
RC_READFILE							RC_ReadFile;
RC_GETUPGRADEREQUESTSTRING			RC_GetUpgradeRequestString;
RC_GETLICENSEINFO					RC_GetLicenseInfo;

HINSTANCE mlib;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CGrandGogSetDlg �Ի���



CGrandGogSetDlg::CGrandGogSetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGrandGogSetDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGrandGogSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_DATETIMEPICKER, m_validDate);
	DDX_Control(pDX, IDC_DATETIMEPICKER, m_myPickTime);
}

BEGIN_MESSAGE_MAP(CGrandGogSetDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO3, &CGrandGogSetDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BTN_SETGRANDDOG, &CGrandGogSetDlg::OnBnClickedBtnSetgranddog)
	ON_BN_CLICKED(IDC_BUTTON1, &CGrandGogSetDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_READ_SETTING, &CGrandGogSetDlg::OnBnClickedBtnReadSetting)
END_MESSAGE_MAP()


// CGrandGogSetDlg ��Ϣ�������

BOOL CGrandGogSetDlg::OnInitDialog()
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
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	mlib = LoadLibrary(TEXT("RCGrandDogW32.dll"));
	if (mlib != NULL)
	{
		RC_OpenDog = (RC_OPENDOG)GetProcAddress(mlib, "rc_OpenDog");
		RC_CloseDog = (RC_CLOSEDOG)GetProcAddress(mlib, "rc_CloseDog");
		RC_CheckDog = (RC_CHECKDOG)GetProcAddress(mlib, "rc_CheckDog");
		RC_GetDogInfo = (RC_GETDOGINFO)GetProcAddress(mlib, "rc_GetDogInfo");
		RC_GetProductCurrentNo = (RC_GETPRODUCTCURRENTNO)GetProcAddress(mlib, "rc_GetProductCurrentNo");
		RC_VerifyPassword = (RC_VERIFYPASSWORD)GetProcAddress(mlib, "rc_VerifyPassword");
		RC_ChangePassword = (RC_CHANGEPASSWORD)GetProcAddress(mlib, "rc_ChangePassword");
		RC_Upgrade = (RC_UPGRADE)GetProcAddress(mlib, "rc_Upgrade");
		RC_GetRandom = (RC_GETRANDOM)GetProcAddress(mlib, "rc_GetRandom");
		RC_EncryptData = (RC_ENCRYPTDATA)GetProcAddress(mlib, "rc_EncryptData");
		RC_DecryptData = (RC_DECRYPTDATA)GetProcAddress(mlib, "rc_DecryptData");
		RC_ConvertData = (RC_CONVERTDATA)GetProcAddress(mlib, "rc_ConvertData");
		RC_SetKey = (RC_SETKEY)GetProcAddress(mlib, "rc_SetKey");
		RC_SignData = (RC_SIGNDATA)GetProcAddress(mlib, "rc_SignData");
		RC_ExecuteFile = (RC_EXECUTEFILE)GetProcAddress(mlib, "rc_ExecuteFile");
		RC_WriteFile = (RC_WRITEFILE)GetProcAddress(mlib, "rc_WriteFile");
		RC_VisitLicenseFile = (RC_VISITLICENSEFILE)GetProcAddress(mlib, "rc_VisitLicenseFile");
		RC_CreateFile = (RC_CREATEFILE)GetProcAddress(mlib, "rc_CreateFile");
		RC_DeleteFile = (RC_DELETEFILE)GetProcAddress(mlib, "rc_DeleteFile");
		RC_CreateDir = (RC_CREATEDIR)GetProcAddress(mlib, "rc_CreateDir");
		RC_DeleteDir = (RC_DELETEDIR)GetProcAddress(mlib, "rc_DeleteDir");
		RC_DefragFileSystem = (RC_DEFRAGFILESYSTEM)GetProcAddress(mlib, "rc_DefragFileSystem");
		RC_ReadFile = (RC_READFILE)GetProcAddress(mlib, "rc_ReadFile");
		RC_GetUpgradeRequestString = (RC_GETUPGRADEREQUESTSTRING)GetProcAddress(mlib, "rc_GetUpgradeRequestString");
		RC_GetLicenseInfo = (RC_GETLICENSEINFO)GetProcAddress(mlib, "rc_GetLicenseInfo");
	}
	else
	{
		MessageBox(TEXT("Load RCGrandDogW32.dll failed."));
		exit(0);
	}
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGrandGogSetDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGrandGogSetDlg::OnPaint()
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
HCURSOR CGrandGogSetDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGrandGogSetDlg::OnBnClickedRadio3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

int SplitString(const CString str, char split, CStringArray &strArray)
{
	strArray.RemoveAll();
	CString strTemp = str;
	int iIndex = 0;
	while (1)
	{
		iIndex = strTemp.Find(split);
		if (iIndex >= 0)
		{
			strArray.Add(strTemp.Left(iIndex));
			strTemp = strTemp.Right(strTemp.GetLength() - iIndex - 1);
		}
		else
		{
			break;
		}
	}
	strArray.Add(strTemp);

	return strArray.GetSize();
}
void CGrandGogSetDlg::OnBnClickedBtnSetgranddog()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString writeDate= TEXT("");
	CString m_rflog; //��֤������ʶ
	CString m_keyfree; //keyfree����
	INT m_userCount; //�û�����
	INT m_deviceSum; //����������
	INT m_onlineUser;//ͬʱ�����˻�����
	INT m_accessContrtol; //�Ž�
	INT m_consuption; //����
	INT m_elevator; //�ݿ�
	INT m_attentend; //����
	INT m_water; //��֤������ʾ
	INT m_visitor_qr; //��ά��ÿ�
	INT m_visitor_card; //��ά�뿨Ƭ
	INT m_routing; //Ѳ��
	CString m_strValidDate;
	LPTSTR m_validDate = {}; //��Ч��
	if (((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck() == BST_CHECKED)
	{
		m_rflog = "0";
	}
	else
	{
		m_rflog = "1";
	}
	if (((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck() == BST_CHECKED)
	{
		m_keyfree = "1";
	}
	else
	{
		m_keyfree = "0";
	}
	m_userCount = GetDlgItemInt(IDC_EDIT_USERCOUNT);
	m_deviceSum = GetDlgItemInt(IDC_EDIT_DEVICESUM);
	m_onlineUser = GetDlgItemInt(IDC_EDIT_ONLINEUSER);
	if (m_userCount > 999999)
	{
		m_userCount = 999999;
	}
	if (m_deviceSum > 999999)
	{
		m_deviceSum = 999999;
	}
	if (m_onlineUser > 999999)
	{
		m_onlineUser = 999999;
	}
	m_accessContrtol = ((CButton*)GetDlgItem(IDC_CHECK_ACCESSCONTROL))->GetCheck();
	m_consuption = ((CButton*)GetDlgItem(IDC_CHECK_CONSUMPTION))->GetCheck();
	m_elevator = ((CButton*)GetDlgItem(IDC_CHECK_ELEVATOR))->GetCheck();
	m_attentend = ((CButton*)GetDlgItem(IDC_CHECK_ATTTENDTION))->GetCheck();
	m_water = ((CButton*)GetDlgItem(IDC_CHECK_WATER))->GetCheck();
	m_visitor_qr = ((CButton*)GetDlgItem(IDC_CHECK_VISITOR_QR))->GetCheck();
	m_visitor_card = ((CButton*)GetDlgItem(IDC_CHECK_VISITOR_CARD))->GetCheck();
	m_routing = ((CButton*)GetDlgItem(IDC_CHECK_ROUTING))->GetCheck();
	CString time;
	//GetDlgItem(IDC_DATETIMEPICKER)->GetWindowText(time);
	GetDlgItemText(IDC_DATETIMEPICKER, time);
	//MessageBox(time);
	/*
	CString stime = TEXT("2016/12/22");
	COleDateTime tempTime;
	tempTime.ParseDateTime(stime);
	AfxMessageBox(tempTime.Format(TEXT("%Y-%m-%d %H:%M:%S")));
	COleDateTimeSpan ts;
	ts = COleDateTime::GetCurrentTime() - tempTime;
	CString str;
	str.Format(TEXT("%d"), ts.GetDays());
	MessageBox(str);
	*/
	CStringArray strArr;
	SplitString(time, '/', strArr);
	if (strArr[1].GetLength() == 1)
	{
		strArr[1] = '0' + strArr[1];
	}
	if (strArr[2].GetLength() == 1)
	{
		strArr[2] = '0' + strArr[2];
	}
	strArr[2] = strArr[2].Left(2);
	COleDateTime tempTime;
	time = strArr[0] + "/" + strArr[1] + "/" + strArr[2];
	tempTime.ParseDateTime(time);
	//AfxMessageBox(tempTime.Format(TEXT("%Y-%m-%d %H:%M:%S")));
	COleDateTimeSpan ts = tempTime - COleDateTime::GetCurrentTime();
	CString strDays;
	LONG lDay = ts.GetDays() + 1;
	if (lDay > 9999)
	{
		lDay = 9999;
	}
	if (lDay < 0 )
	{
		lDay = 0;
	}
	strDays.Format(TEXT("%d"), lDay);
	//MessageBox(strDays);
	while (strDays.GetLength() < 4)
	{
		strDays = TEXT("0") + strDays;
	}
	writeDate += m_rflog;
	writeDate += m_keyfree;
	CString m_temp;
	m_temp.Format(TEXT("%d"), m_userCount);
		while (m_temp.GetLength() < 6)
		{
			m_temp = TEXT("0") + m_temp;

		}
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_deviceSum);
	while (m_temp.GetLength() < 6)
	{
		m_temp = TEXT("0") + m_temp;

	}
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_onlineUser);
	while (m_temp.GetLength() < 6)
	{
		m_temp = TEXT("0") + m_temp;

	}
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_accessContrtol);
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_consuption);
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_elevator);
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_attentend);
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_water);
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_visitor_qr);
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_visitor_card);
	writeDate += m_temp;
	m_temp.Format(TEXT("%d"), m_routing);
	writeDate += m_temp;
	time = strArr[0] + strArr[1] + strArr[2];
	writeDate += time + strDays;
	//MessageBox(writeDate);
	ULONG lDogHandle;
	char* m_cProductName = "GrandDog";
	char* oldUserPwd = "12345678";
	char* oldDeveloperPwd = "abcdefgh";
	char* newUserPwd = "hzreformer";
	char* newDeveloperPwd = "lfzg2017";
	UCHAR pucDegree;
	LONG RET;
	RET = RC_OpenDog(RC_OPEN_FIRST_IN_LOCAL, m_cProductName, &lDogHandle);
	if (RET != 0 )
	{
		MessageBox(_T("�򿪺깷ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	//��֤�����̿���
	RET = RC_VerifyPassword(lDogHandle, DEVELOPER_TYPE, oldDeveloperPwd, &pucDegree);
	if (RET != 0)
	{
		RET = RC_VerifyPassword(lDogHandle, DEVELOPER_TYPE, newDeveloperPwd, &pucDegree);
	}
	if (RET != 0)
	{
		MessageBox(_T("�����̿�����֤ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	RET = RC_ChangePassword(lDogHandle, DEVELOPER_TYPE, newDeveloperPwd);
	if (RET != 0)
	{
		MessageBox(_T("�޸Ŀ����̿���ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	//��֤�û�����
	RET = RC_VerifyPassword(lDogHandle, USER_TYPE, oldUserPwd, &pucDegree);
	if (RET != 0)
	{
		RET = RC_VerifyPassword(lDogHandle, USER_TYPE, newUserPwd, &pucDegree);
	}
	if (RET != 0)
	{
		MessageBox(_T("�û�������֤ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	RET = RC_ChangePassword(lDogHandle, USER_TYPE, newUserPwd);
	if (RET != 0)
	{
		MessageBox(_T("�޸��û�����ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	USHORT dirId = 21;
	USHORT fileId = 30;
	ULONG dirSize = 200;
	ULONG fileSize = 100;
	RET = RC_CreateDir(lDogHandle, dirId, dirSize);
		if (RET == STORAGE_NOT_ENOUGH || RET == STORAGE_NOT_ENOUGH_TO)
		{
			MessageBox(_T("�깷�洢���㣬�����ļ���ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
			return;
		}
		if (RET != 0 && RET != FILE_EXISTT)
		{
			MessageBox(_T("�����ļ���ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
			return;
		}
		 RC_CreateFile(lDogHandle, dirId, fileId, (byte)1, fileSize);
		if (RET == STORAGE_NOT_ENOUGH || RET == STORAGE_NOT_ENOUGH_TO)
		{
			MessageBox(_T("�깷�洢���㣬�����ļ�ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
			return;
		}
		if (RET != 0 && RET != FILE_EXISTT)
		{
			MessageBox(_T("�����ļ�ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
			return;
		}
	char data[48] = { 0 };
	WideCharToMultiByte(CP_ACP, 0, writeDate, -1, data, writeDate.GetLength(), NULL, NULL);
	UCHAR	ucKey[16] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50 };
	UCHAR TYPE = 1;
	ULONG LEN = 16;
	RET = RC_CheckDog(lDogHandle);
	/*if (RET != 0)
	{
		MessageBox(_T("���ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}*/
	/*RET = RC_SetKey(lDogHandle, 1, ucKey, LEN);
	if (RET != 0)
	{
		MessageBox(_T("������Կʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}*/
	//UCHAR	ucRandomData[256];
	//UCHAR	ucLen = 100;
	//RET = RC_GetRandom(lDogHandle, ucRandomData, ucLen);
	//if (RET != 0)
	//{
	//	MessageBox(_T("��ȡ�����ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
	//	return;
	//}
	ULONG	ulEncryptLen = 16;
	UCHAR	ucResult1[16];
	UCHAR	ucResult2[16];
	UCHAR	ucResult3[16];
	ULONG	ulResultLen = 16;
	char data1[16] = {'\0'};
	char data2[16] = { '\0' };
	char data3[16] = { '\0' };
	memset(data1, 0, 16);
	memset(data2, 0, 16);
	memset(data3, '0', 16);
	memcpy(data1, data, 16);
	memcpy(data2, data+16, 16);
	memcpy(data3, data+32, 16);
	RET = RC_EncryptData(lDogHandle, (UCHAR*)data1, ulEncryptLen, ucResult1, &ulResultLen);
	RET = RC_EncryptData(lDogHandle, (UCHAR*)data2, ulEncryptLen, ucResult2, &ulResultLen);
	RET = RC_EncryptData(lDogHandle, (UCHAR*)data3, ulEncryptLen, ucResult3, &ulResultLen);
	char encryptData[50] = { '\0' };
	memset(encryptData, '0', 50);
	memcpy(encryptData, ucResult1, 16);
	memcpy(encryptData+16, ucResult2, 16);
	memcpy(encryptData+32, ucResult3, 16);
	//UCHAR aaap1[16];
	//UCHAR aaap2[16];
	//UCHAR aaap3[16];
	//RET = RC_DecryptData(lDogHandle, ucResult1, ulEncryptLen, aaap1, &ulResultLen);
	//RET = RC_DecryptData(lDogHandle, ucResult2, ulEncryptLen, aaap2, &ulResultLen);
	//RET = RC_DecryptData(lDogHandle, ucResult3, ulEncryptLen, aaap3, &ulResultLen);
	RET = RC_WriteFile(lDogHandle, dirId, fileId, 0, 50, (UCHAR*)encryptData);
	if (RET != 0)
	{
		MessageBox(_T("����д��ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}else
	{
		MessageBox(_T("Ȩ��д��ɹ���"), _T("��ʾ"), MB_OK);
		RC_CloseDog(lDogHandle);
	}
 	return;
}


void CGrandGogSetDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ULONG lDogHandle;
	char *m_cProductName = "GrandDog";
	LONG RET;
	RET = RC_OpenDog(RC_OPEN_FIRST_IN_LOCAL, m_cProductName, &lDogHandle);
	if (RET != 0)
	{
		MessageBox(_T("δ��⵽�깷��"), _T("��ʾ"), MB_OK | MB_ICONERROR);
	}
	else
	{
		MessageBox(_T("�깷����"), _T("��ʾ"), MB_OK);
		RC_CloseDog(lDogHandle);
	}
}


void CGrandGogSetDlg::OnBnClickedBtnReadSetting()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//MessageBox(writeDate);
	ULONG lDogHandle;
	char* m_cProductName = "GrandDog";
	char* newUserPwd = "hzreformer";
	char* newDeveloperPwd = "lfzg2017";
	USHORT dirId = 21;
	USHORT fileId = 30;
	ULONG	bufSize = 100;
	UCHAR	bReadBuf[100];
	UCHAR pucDegree;
	LONG RET;
	RET = RC_OpenDog(RC_OPEN_FIRST_IN_LOCAL, m_cProductName, &lDogHandle);
	if (RET != 0)
	{
		MessageBox(_T("�򿪺깷ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	//��֤�����̿���
	RET = RC_VerifyPassword(lDogHandle, DEVELOPER_TYPE, newDeveloperPwd, &pucDegree);
	if (RET != 0)
	{
		MessageBox(_T("�����̿�����֤ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	//��֤�û�����
	RET = RC_VerifyPassword(lDogHandle, USER_TYPE, newUserPwd, &pucDegree);
	if (RET != 0)
	{
		MessageBox(_T("�û�������֤ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	RET = RC_ReadFile(lDogHandle, dirId, fileId, 0, bufSize, bReadBuf);
	if (RET != 0)
	{
		MessageBox(_T("�ļ���ȡʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	UCHAR encryptData1[16];
	UCHAR encryptData2[16];
	UCHAR encryptData3[16];
	UCHAR data[16];
	UCHAR decData[48];
	ULONG pOutSize = 16;
	memcpy(encryptData1, bReadBuf, 16);
	memcpy(encryptData2, bReadBuf+16, 16);
	memcpy(encryptData3, bReadBuf+32, 16);
	RET = RC_DecryptData(lDogHandle, encryptData1, 16, data, &pOutSize);
	if (RET != 0){
		MessageBox(_T("���ݽ���ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	memcpy(decData, data, 16);
	RET = RC_DecryptData(lDogHandle, encryptData2, 16, data, &pOutSize);
	if (RET != 0){
		MessageBox(_T("���ݽ���ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	memcpy(decData+16, data, 16);
	RET = RC_DecryptData(lDogHandle, encryptData3, 16, data, &pOutSize);
	if (RET != 0){
		MessageBox(_T("���ݽ���ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	memcpy(decData + 32, data, 16);
	if (decData[0] == '1')
	{
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(BST_CHECKED);
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_UNCHECKED);
	}
	if (decData[1] == '1')
	{
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(BST_UNCHECKED);
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(BST_CHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(BST_CHECKED);
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(BST_UNCHECKED);
	}
	UCHAR m_userCount[7] = { 0 }; //�û�����
	UCHAR m_deviceSum[7] = { 0 }; //����������
	UCHAR m_onlineUser[7] = { 0 };//ͬʱ�����˻�����
	UCHAR m_strValidDate[11] = { 0 };
	UCHAR m_validDate[5] = { 0 }; //��Ч��
	memcpy(m_userCount, decData + 2, 6);
	memcpy(m_deviceSum, decData + 8, 6);
	memcpy(m_onlineUser, decData + 14, 6);
	memcpy(m_strValidDate, decData + 28, 4);
	memcpy(m_strValidDate+4,"/", 1);
	memcpy(m_strValidDate+5, decData + 32, 2);
	memcpy(m_strValidDate + 7, "/", 1);
	memcpy(m_strValidDate + 8, decData+34, 2);
	/*INT userCount_Int = 0;
	CString userCount_Str(m_userCount);
	userCount_Str.Format(TEXT("%d"), userCount_Int);*/
	SetDlgItemInt(IDC_EDIT_USERCOUNT, _ttoi(CString(m_userCount)));
	SetDlgItemInt(IDC_EDIT_DEVICESUM, _ttoi(CString(m_deviceSum)));
	SetDlgItemInt(IDC_EDIT_ONLINEUSER, _ttoi(CString(m_onlineUser)));
	if (decData[20] == '1')
	{
		((CButton*)GetDlgItem(IDC_CHECK_ACCESSCONTROL))->SetCheck(BST_CHECKED);
	}else
	{
		((CButton*)GetDlgItem(IDC_CHECK_ACCESSCONTROL))->SetCheck(BST_UNCHECKED);
	}
	if (decData[21] == '1')
	{
		((CButton*)GetDlgItem(IDC_CHECK_CONSUMPTION))->SetCheck(BST_CHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_CONSUMPTION))->SetCheck(BST_UNCHECKED);
	}
	if (decData[22] == '1')
	{
		((CButton*)GetDlgItem(IDC_CHECK_ELEVATOR))->SetCheck(BST_CHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_ELEVATOR))->SetCheck(BST_UNCHECKED);
	}
	if (decData[23] == '1')
	{
		((CButton*)GetDlgItem(IDC_CHECK_ATTTENDTION))->SetCheck(BST_CHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_ATTTENDTION))->SetCheck(BST_UNCHECKED);
	}
	if (decData[24] == '1')
	{
		((CButton*)GetDlgItem(IDC_CHECK_WATER))->SetCheck(BST_CHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_WATER))->SetCheck(BST_UNCHECKED);
	}
	if (decData[25] == '1')
	{
		((CButton*)GetDlgItem(IDC_CHECK_VISITOR_QR))->SetCheck(BST_CHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_VISITOR_QR))->SetCheck(BST_UNCHECKED);
	}
	if (decData[26] == '1')
	{
		((CButton*)GetDlgItem(IDC_CHECK_VISITOR_CARD))->SetCheck(BST_CHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_VISITOR_CARD))->SetCheck(BST_UNCHECKED);
	}
	if (decData[27] == '1')
	{
		((CButton*)GetDlgItem(IDC_CHECK_ROUTING))->SetCheck(BST_CHECKED);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECK_ROUTING))->SetCheck(BST_UNCHECKED);
	}
	//m_myPickTime.SetFormat(CString(m_strValidDate));
	COleDateTime t;
	t.ParseDateTime(CString(m_strValidDate));
	m_myPickTime.SetTime(t);
	RC_HARDWARE_INFO	HardwareInfo;
	ULONG				ulLen = sizeof(HardwareInfo);
	RET = RC_GetDogInfo(lDogHandle, &HardwareInfo, &ulLen);
	if (RET != 0){
		MessageBox(_T("��ȡ���к�ʧ�ܣ�"), _T("��ʾ"), MB_OK | MB_ICONERROR);
		return;
	}
	CString ProductCurrentNo;
	ProductCurrentNo.Format(TEXT("%d"), HardwareInfo.ulSerialNumber);
	SetDlgItemText(IDC_EDIT_SN, TEXT("GRANDD")+ProductCurrentNo);
}
