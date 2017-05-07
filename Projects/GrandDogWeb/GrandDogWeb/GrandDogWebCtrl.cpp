// GrandDogWebCtrl.cpp : CGrandDogWebCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "GrandDogWeb.h"
#include "GrandDogWebCtrl.h"
#include "GrandDogWebPropPage.h"
#include "afxdialogex.h"
#include "GrandDogofDll.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CGrandDogWebCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CGrandDogWebCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CGrandDogWebCtrl, COleControl)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "RC_OPENDOG_EX", dispidRC_OPENDOG_EX, RC_OPENDOG_EX, VT_UI4, VTS_UI4 VTS_PI1 VTS_PUI4)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "WRC_OPENDOG", dispidWRC_OPENDOG, WRC_OPENDOG, VT_UI4, VTS_I4 VTS_BSTR)
	DISP_PROPERTY_NOTIFY_ID(CGrandDogWebCtrl, "lDogHandle", dispidlDogHandle, m_lDogHandle, OnlDogHandleChanged, VT_UI4)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "WRC_VerifyPassword", dispidWRC_VerifyPassword, WRC_VerifyPassword, VT_UI4, VTS_UI4 VTS_I1 VTS_BSTR)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "WRC_ChangePassword", dispidWRC_ChangePassword, WRC_ChangePassword, VT_UI4, VTS_UI4 VTS_I1 VTS_BSTR)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "WRC_CreateDir", dispidWRC_CreateDir, WRC_CreateDir, VT_UI4, VTS_UI4 VTS_UI2 VTS_UI4)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "WRC_CreateFile", dispidWRC_CreateFile, WRC_CreateFile, VT_UI4, VTS_UI4 VTS_UI2 VTS_UI2 VTS_I1 VTS_UI4)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "WRC_CheckDog", dispidWRC_CheckDog, WRC_CheckDog, VT_UI4, VTS_UI4)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "WRC_EncryptData", dispidWRC_EncryptData, WRC_EncryptData, VT_UI4, VTS_UI4 VTS_BSTR VTS_UI4 VTS_UI4)
	DISP_PROPERTY_NOTIFY_ID(CGrandDogWebCtrl, "EncryptData", dispidEncryptData, m_EncryptData, OnEncryptDataChanged, VT_BSTR)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "WRC_CloseDog", dispidWRC_CloseDog, WRC_CloseDog, VT_UI4, VTS_UI4)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "WriteDog", dispidWriteDog, WriteDog, VT_UI4, VTS_BSTR)
	DISP_FUNCTION_ID(CGrandDogWebCtrl, "ReadDog", dispidReadDog, ReadDog, VT_UI4, VTS_NONE)
	DISP_PROPERTY_NOTIFY_ID(CGrandDogWebCtrl, "ReadData", dispidReadData, m_ReadData, OnReadDataChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY_ID(CGrandDogWebCtrl, "DogSerial", dispidDogSerial, m_DogSerial, OnDogSerialChanged, VT_BSTR)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CGrandDogWebCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(CGrandDogWebCtrl, 1)
	PROPPAGEID(CGrandDogWebPropPage::guid)
END_PROPPAGEIDS(CGrandDogWebCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CGrandDogWebCtrl, "GRANDDOGWEB.GrandDogWebCtrl.1",
	0xa7e91c27, 0x2169, 0x4776, 0x93, 0x50, 0x3c, 0xc7, 0x63, 0x8, 0x2c, 0x56)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CGrandDogWebCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DGrandDogWeb = { 0x2ABB59CC, 0x9690, 0x4561, { 0xAE, 0x7B, 0xF9, 0xA4, 0x3A, 0x37, 0xB1, 0xFC } };
const IID IID_DGrandDogWebEvents = { 0xDBB05F08, 0x6AA4, 0x4357, { 0x95, 0x7D, 0x95, 0xAA, 0xCB, 0x2E, 0x82, 0x7A } };

// 控件类型信息

static const DWORD _dwGrandDogWebOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CGrandDogWebCtrl, IDS_GRANDDOGWEB, _dwGrandDogWebOleMisc)

// CGrandDogWebCtrl::CGrandDogWebCtrlFactory::UpdateRegistry -
// 添加或移除 CGrandDogWebCtrl 的系统注册表项

BOOL CGrandDogWebCtrl::CGrandDogWebCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_GRANDDOGWEB,
			IDB_GRANDDOGWEB,
			afxRegApartmentThreading,
			_dwGrandDogWebOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CGrandDogWebCtrl::CGrandDogWebCtrl - 构造函数

CGrandDogWebCtrl::CGrandDogWebCtrl()
{
	InitializeIIDs(&IID_DGrandDogWeb, &IID_DGrandDogWebEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CGrandDogWebCtrl::~CGrandDogWebCtrl - 析构函数

CGrandDogWebCtrl::~CGrandDogWebCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CGrandDogWebCtrl::OnDraw - 绘图函数

void CGrandDogWebCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CGrandDogWebCtrl::DoPropExchange - 持久性支持

void CGrandDogWebCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  为每个持久的自定义属性调用 PX_ 函数。
}


// CGrandDogWebCtrl::OnResetState - 将控件重置为默认状态

void CGrandDogWebCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CGrandDogWebCtrl::AboutBox - 向用户显示“关于”框

void CGrandDogWebCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_GRANDDOGWEB);
	dlgAbout.DoModal();
}


// CGrandDogWebCtrl 消息处理程序

int CGrandDogWebCtrl::OnInitApp(){
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
		return -1;
	}
	return 0;
}

ULONG CGrandDogWebCtrl::RC_OPENDOG_EX(ULONG ulFlag, CHAR* pszProductName, ULONG* pDogHandle)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	ULONG lhandle;
	char* m_cProductName = "GrandDog";
	return RC_OpenDog(ulFlag, m_cProductName, &lhandle);
}


ULONG CGrandDogWebCtrl::WRC_OPENDOG(LONG ulFlag, LPCTSTR pszProductName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	char productName[10] = { 0 };
	WideCharToMultiByte(CP_ACP, 0, pszProductName, -1, productName, _tcslen(pszProductName), NULL, NULL);
	return RC_OpenDog(ulFlag, productName, &m_lDogHandle);
}


void CGrandDogWebCtrl::OnlDogHandleChanged()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加属性处理程序代码

	SetModifiedFlag();
}


ULONG CGrandDogWebCtrl::WRC_VerifyPassword(ULONG DogHandle, CHAR ucPasswordType, LPCTSTR pszPassword)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	//验证开发商口令
	ULONG handle;
	if (DogHandle == 0)
	{
		handle = m_lDogHandle;
	}
	else{
		handle = DogHandle;
	}
	UCHAR pucDegree;
	char productName[20] = { 0 };
	WideCharToMultiByte(CP_ACP, 0, pszPassword, -1, productName, _tcslen(pszPassword), NULL, NULL);
	return RC_VerifyPassword(handle, ucPasswordType, productName, &pucDegree);
}


ULONG CGrandDogWebCtrl::WRC_ChangePassword(ULONG lDogHandle, CHAR ucPasswordType, LPCTSTR pszPassword)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	ULONG handle;
	if (lDogHandle == 0)
	{
		handle = m_lDogHandle;
	}
	else{
		handle = lDogHandle;
	}
	char userPwd[20] = { 0 };
	WideCharToMultiByte(CP_ACP, 0, pszPassword, -1, userPwd, _tcslen(pszPassword), NULL, NULL);
	return RC_ChangePassword(handle, ucPasswordType, userPwd);
}


ULONG CGrandDogWebCtrl::WRC_CreateDir(ULONG lDogHandle, USHORT dirId, ULONG dirSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	ULONG handle;
	if (lDogHandle == 0)
	{
		handle = m_lDogHandle;
	}
	else{
		handle = lDogHandle;
	}
	return RC_CreateDir(handle, dirId, dirSize);
}


ULONG CGrandDogWebCtrl::WRC_CreateFile(ULONG lDogHandle, USHORT usDirID, USHORT usFileID, CHAR ucFileType, ULONG ulFileLen)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	ULONG handle;
	if (lDogHandle == 0)
	{
		handle = m_lDogHandle;
	}
	else{
		handle = lDogHandle;
	}
	return RC_CreateFile(handle, usDirID, usFileID, ucFileType , ulFileLen);
}


ULONG CGrandDogWebCtrl::WRC_CheckDog(ULONG lDogHandle)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	ULONG handle;
	if (lDogHandle == 0)
	{
		handle = m_lDogHandle;
	}
	else{
		handle = lDogHandle;
	}
	return RC_CheckDog(handle);
}


ULONG CGrandDogWebCtrl::WRC_EncryptData(ULONG lDogHandle, LPCTSTR pucIn, ULONG ulInLen, ULONG pulOutLen)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	ULONG handle;
	if (lDogHandle == 0)
	{
		handle = m_lDogHandle;
	}
	else{
		handle = lDogHandle;
	}
	char buf[20] = { 0 };
	char ucResult1[16] = {0};
	WideCharToMultiByte(CP_ACP, 0, pucIn, -1, buf, _tcslen(pucIn), NULL, NULL);
	ULONG RET = RC_EncryptData(handle, (UCHAR*)buf, ulInLen, (UCHAR *)ucResult1, &pulOutLen);
	WCHAR tempData[16] = {0};
	MultiByteToWideChar(CP_ACP, 0, ucResult1, -1, tempData, strlen(ucResult1));
	m_EncryptData =  tempData;
	return RET;
}


void CGrandDogWebCtrl::OnEncryptDataChanged()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加属性处理程序代码

	SetModifiedFlag();
}


ULONG CGrandDogWebCtrl::WRC_CloseDog(ULONG lDogHandle)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	ULONG handle;
	if (lDogHandle == 0)
	{
		handle = m_lDogHandle;
	}
	else{
		handle = lDogHandle;
	}
	return RC_CloseDog(handle);
}


ULONG CGrandDogWebCtrl::WriteDog(LPCTSTR data)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO:  在此添加调度处理程序代码
	CString writeDate(data);
	ULONG lDogHandle;
	char* m_cProductName = "GrandDog";
	char* oldUserPwd = "12345678";
	char* oldDeveloperPwd = "abcdefgh";
	char* newUserPwd = "hzreformer";
	char* newDeveloperPwd = "lfzg2017";
	UCHAR pucDegree;
	LONG RET;
	RET = RC_OpenDog(RC_OPEN_FIRST_IN_LOCAL, m_cProductName, &lDogHandle);
	if (RET != 0)
	{
		//MessageBox(_T("打开宏狗失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	//验证开发商口令
	RET = RC_VerifyPassword(lDogHandle, DEVELOPER_TYPE, oldDeveloperPwd, &pucDegree);
	if (RET != 0)
	{
		RET = RC_VerifyPassword(lDogHandle, DEVELOPER_TYPE, newDeveloperPwd, &pucDegree);
	}
	if (RET != 0)
	{
		//MessageBox(_T("开发商口令验证失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	RET = RC_ChangePassword(lDogHandle, DEVELOPER_TYPE, newDeveloperPwd);
	if (RET != 0)
	{
		//MessageBox(_T("修改开发商口令失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	//验证用户口令
	RET = RC_VerifyPassword(lDogHandle, USER_TYPE, oldUserPwd, &pucDegree);
	if (RET != 0)
	{
		RET = RC_VerifyPassword(lDogHandle, USER_TYPE, newUserPwd, &pucDegree);
	}
	if (RET != 0)
	{
		//MessageBox(_T("用户口令验证失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	RET = RC_ChangePassword(lDogHandle, USER_TYPE, newUserPwd);
	if (RET != 0)
	{
		//MessageBox(_T("修改用户口令失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	RC_HARDWARE_INFO	HardwareInfo;
	ULONG				ulLen = sizeof(HardwareInfo);
	RET = RC_GetDogInfo(lDogHandle, &HardwareInfo, &ulLen);
	if (RET != 0){
		//MessageBox(_T("获取序列号失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	CString ProductCurrentNo;
	ProductCurrentNo.Format(TEXT("%d"), HardwareInfo.ulSerialNumber);
	m_DogSerial = ProductCurrentNo;
	USHORT dirId = 21;
	USHORT fileId = 30;
	ULONG dirSize = 200;
	ULONG fileSize = 100;
	RET = RC_CreateDir(lDogHandle, dirId, dirSize);
	if (RET == STORAGE_NOT_ENOUGH || RET == STORAGE_NOT_ENOUGH_TO)
	{
		//MessageBox(_T("宏狗存储不足，创建文件夹失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	if (RET != 0 && RET != FILE_EXISTT)
	{
		//MessageBox(_T("创建文件夹失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	RC_CreateFile(lDogHandle, dirId, fileId, (byte)1, fileSize);
	if (RET == STORAGE_NOT_ENOUGH || RET == STORAGE_NOT_ENOUGH_TO)
	{
		//MessageBox(_T("宏狗存储不足，创建文件失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	if (RET != 0 && RET != FILE_EXISTT)
	{
		//MessageBox(_T("创建文件失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	char tempData[48] = { 0 };
	WideCharToMultiByte(CP_ACP, 0, writeDate, -1, tempData, writeDate.GetLength(), NULL, NULL);
	UCHAR	ucKey[16] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50 };
	UCHAR TYPE = 1;
	ULONG LEN = 16;
	RET = RC_CheckDog(lDogHandle);
	/*if (RET != 0)
	{
	MessageBox(_T("检测失败！"), _T("提示"), MB_OK | MB_ICONERROR);
	return;
	}*/
	/*RET = RC_SetKey(lDogHandle, 1, ucKey, LEN);
	if (RET != 0)
	{
	MessageBox(_T("设置密钥失败！"), _T("提示"), MB_OK | MB_ICONERROR);
	return;
	}*/
	//UCHAR	ucRandomData[256];
	//UCHAR	ucLen = 100;
	//RET = RC_GetRandom(lDogHandle, ucRandomData, ucLen);
	//if (RET != 0)
	//{
	//	MessageBox(_T("获取随机数失败！"), _T("提示"), MB_OK | MB_ICONERROR);
	//	return;
	//}
	ULONG	ulEncryptLen = 16;
	UCHAR	ucResult1[16];
	UCHAR	ucResult2[16];
	UCHAR	ucResult3[16];
	ULONG	ulResultLen = 16;
	char data1[16] = { '\0' };
	char data2[16] = { '\0' };
	char data3[16] = { '\0' };
	memset(data1, 0, 16);
	memset(data2, 0, 16);
	memset(data3, '0', 16);
	memcpy(data1, tempData, 16);
	memcpy(data2, tempData + 16, 16);
	memcpy(data3, tempData + 32, 16);
	RET = RC_EncryptData(lDogHandle, (UCHAR*)data1, ulEncryptLen, ucResult1, &ulResultLen);
	if (RET != 0)
	{
		return RET;
	}
	RET = RC_EncryptData(lDogHandle, (UCHAR*)data2, ulEncryptLen, ucResult2, &ulResultLen);
	if (RET != 0)
	{
		return RET;
	}
	RET = RC_EncryptData(lDogHandle, (UCHAR*)data3, ulEncryptLen, ucResult3, &ulResultLen);
	if (RET != 0)
	{
		return RET;
	}
	char encryptData[50] = { '\0' };
	memset(encryptData, '0', 50);
	memcpy(encryptData, ucResult1, 16);
	memcpy(encryptData + 16, ucResult2, 16);
	memcpy(encryptData + 32, ucResult3, 16);
	//UCHAR aaap1[16];
	//UCHAR aaap2[16];
	//UCHAR aaap3[16];
	//RET = RC_DecryptData(lDogHandle, ucResult1, ulEncryptLen, aaap1, &ulResultLen);
	//RET = RC_DecryptData(lDogHandle, ucResult2, ulEncryptLen, aaap2, &ulResultLen);
	//RET = RC_DecryptData(lDogHandle, ucResult3, ulEncryptLen, aaap3, &ulResultLen);
	RET = RC_WriteFile(lDogHandle, dirId, fileId, 0, 50, (UCHAR*)encryptData);
	RC_CloseDog(lDogHandle);
	return RET;
}


ULONG CGrandDogWebCtrl::ReadDog()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
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
		//MessageBox(_T("打开宏狗失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	//验证开发商口令
	RET = RC_VerifyPassword(lDogHandle, DEVELOPER_TYPE, newDeveloperPwd, &pucDegree);
	if (RET != 0)
	{
		//MessageBox(_T("开发商口令验证失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	//验证用户口令
	RET = RC_VerifyPassword(lDogHandle, USER_TYPE, newUserPwd, &pucDegree);
	if (RET != 0)
	{
		//MessageBox(_T("用户口令验证失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	RET = RC_ReadFile(lDogHandle, dirId, fileId, 0, bufSize, bReadBuf);
	if (RET != 0)
	{
		//MessageBox(_T("文件读取失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	UCHAR encryptData1[16];
	UCHAR encryptData2[16];
	UCHAR encryptData3[16];
	UCHAR data[16];
	UCHAR decData[48];
	memset(decData, 0, 48);
	ULONG pOutSize = 16;
	memcpy(encryptData1, bReadBuf, 16);
	memcpy(encryptData2, bReadBuf + 16, 16);
	memcpy(encryptData3, bReadBuf + 32, 16);
	RET = RC_DecryptData(lDogHandle, encryptData1, 16, data, &pOutSize);
	if (RET != 0){
		//MessageBox(_T("数据解密失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	memcpy(decData, data, 16);
	RET = RC_DecryptData(lDogHandle, encryptData2, 16, data, &pOutSize);
	if (RET != 0){
		//MessageBox(_T("数据解密失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	memcpy(decData + 16, data, 16);
	RET = RC_DecryptData(lDogHandle, encryptData3, 16, data, &pOutSize);
	if (RET != 0){
		//MessageBox(_T("数据解密失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	RC_HARDWARE_INFO	HardwareInfo;
	ULONG				ulLen = sizeof(HardwareInfo);
	RET = RC_GetDogInfo(lDogHandle, &HardwareInfo, &ulLen);
	if (RET != 0){
		//MessageBox(_T("获取序列号失败！"), _T("提示"), MB_OK | MB_ICONERROR);
		return RET;
	}
	CString ProductCurrentNo;
	ProductCurrentNo.Format(TEXT("%d"), HardwareInfo.ulSerialNumber);
	m_DogSerial = ProductCurrentNo;
	RC_CloseDog(lDogHandle);
	memcpy(decData + 32, data, 16);
	WCHAR tempData[48] = { 0 };
	MultiByteToWideChar(CP_ACP, 0, (char *)decData, -1, tempData, strlen((char *)decData));
	m_ReadData = tempData;
	return RET;
}


void CGrandDogWebCtrl::OnReadDataChanged()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加属性处理程序代码

	SetModifiedFlag();
}


void CGrandDogWebCtrl::OnDogSerialChanged()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加属性处理程序代码

	SetModifiedFlag();
}
