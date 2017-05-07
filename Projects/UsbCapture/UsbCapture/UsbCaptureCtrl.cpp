// UsbCaptureCtrl.cpp : CUsbCaptureCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "UsbCapture.h"
#include "UsbCaptureCtrl.h"
#include "UsbCapturePropPage.h"
#include "afxdialogex.h"
#include "BASE64_API.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CUsbCaptureCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CUsbCaptureCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CUsbCaptureCtrl, COleControl)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "takePhoto", dispidtakePhoto, takePhoto, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "Disconnect", dispidDisconnect, Disconnect, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "DELETE_FILE", dispidDELETE_FILE, DELETE_FILE, VT_UI1, VTS_BSTR)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "DLE_FILE", dispidDLE_FILE, DLE_FILE, VT_UI1, VTS_PI1)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "TAKE_PHOTO", dispidTAKE_PHOTO, TAKE_PHOTO, VT_UI1, VTS_BSTR)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "BASE64_Encode", dispidBASE64_Encode, BASE64_Encode, VT_BSTR, VTS_BSTR)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CUsbCaptureCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(CUsbCaptureCtrl, 1)
	PROPPAGEID(CUsbCapturePropPage::guid)
END_PROPPAGEIDS(CUsbCaptureCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CUsbCaptureCtrl, "USBCAPTURE.UsbCaptureCtrl.1",
	0x6b66f9c4, 0x1da0, 0x4463, 0x96, 0x37, 0xac, 0, 0xa5, 0x74, 0xad, 0x7a)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CUsbCaptureCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DUsbCapture = { 0x337D8864, 0x9C89, 0x4335, { 0xA8, 0x8F, 0xBE, 0x2C, 0xDC, 0x89, 0xDA, 0x73 } };
const IID IID_DUsbCaptureEvents = { 0xE0903E55, 0x5DE1, 0x4BCF, { 0x8E, 0x65, 0xE1, 0x31, 0x9, 0x8B, 0x81, 0x70 } };

// 控件类型信息

static const DWORD _dwUsbCaptureOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CUsbCaptureCtrl, IDS_USBCAPTURE, _dwUsbCaptureOleMisc)

// CUsbCaptureCtrl::CUsbCaptureCtrlFactory::UpdateRegistry -
// 添加或移除 CUsbCaptureCtrl 的系统注册表项

BOOL CUsbCaptureCtrl::CUsbCaptureCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_USBCAPTURE,
			IDB_USBCAPTURE,
			afxRegApartmentThreading,
			_dwUsbCaptureOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CUsbCaptureCtrl::CUsbCaptureCtrl - 构造函数

CUsbCaptureCtrl::CUsbCaptureCtrl()
{
	InitializeIIDs(&IID_DUsbCapture, &IID_DUsbCaptureEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CUsbCaptureCtrl::~CUsbCaptureCtrl - 析构函数

CUsbCaptureCtrl::~CUsbCaptureCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CUsbCaptureCtrl::OnDraw - 绘图函数

void CUsbCaptureCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
	m_mainDlg.MoveWindow(rcBounds, TRUE);
}

// CUsbCaptureCtrl::DoPropExchange - 持久性支持

void CUsbCaptureCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  为每个持久的自定义属性调用 PX_ 函数。
}


// CUsbCaptureCtrl::OnResetState - 将控件重置为默认状态

void CUsbCaptureCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CUsbCaptureCtrl::AboutBox - 向用户显示“关于”框

void CUsbCaptureCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_USBCAPTURE);
	dlgAbout.DoModal();
}


// CUsbCaptureCtrl 消息处理程序


int CUsbCaptureCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_mainDlg.Create(IDD_PROPPAGE_USBCAPTURE, this);
	m_mainDlg.ShowWindow(SW_SHOW);
	return 0;
}


void CUsbCaptureCtrl::takePhoto(LPCTSTR filePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO:  在此添加调度处理程序代码
	m_mainDlg.TakePhoto(filePath);
}


void CUsbCaptureCtrl::Disconnect()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_mainDlg.Disconnect();
	// TODO:  在此添加调度处理程序代码
}


BYTE CUsbCaptureCtrl::DELETE_FILE(LPCTSTR filePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	MessageBox(filePath);
	char file[50]= { '\0' };
	//WideCharToMultiByte(CP_ACP, 0, filePath, -1, file, wcslen(filePath), NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, filePath, -1, file, wcslen(filePath), NULL, NULL);
	MessageBoxA(NULL, file, "提示对话框一", MB_OK);
	remove(file);
	// TODO:  在此添加调度处理程序代码
	return 0;
}


BYTE CUsbCaptureCtrl::DLE_FILE(CHAR* fileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO:  在此添加调度处理程序代码
	remove(fileName);
	return 0;
}


BYTE CUsbCaptureCtrl::TAKE_PHOTO(LPCTSTR fileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码

	return m_mainDlg.TakePhotoEx(fileName);
}


BSTR CUsbCaptureCtrl::BASE64_Encode(LPCTSTR fileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	/*
	CFile   imageFile; 
    imageFile.Open(imageFileName,CFile::modeRead); 
    BYTE*   imageBuffer; 
    long   nlength   =   imageFile.GetLength(); 
    imageBuffer   =   new   BYTE[nlength+2]; 
    imageFile.Read(imageBuffer,nlength); 
	*/
	// TODO:  在此添加调度处理程序代码
	CFile imageFile;
	CFileException ex;
	INT RET = imageFile.Open(fileName, CFile::modeRead | CFile::shareDenyNone, &ex);
	if (RET == 0)
	{
		TCHAR   szCause[255];
		CString strFormatted;
		ex.GetErrorMessage(szCause, 255);
		strFormatted = _T("The data file could not be opened because of this error: ");
		strFormatted += szCause;
		AfxMessageBox(strFormatted);
	}
	ULONG len = imageFile.GetLength();
	BYTE *buffer;
	buffer = new BYTE[len + 2];
	//buffer = (BYTE *)malloc(len*sizeof(BYTE));
	imageFile.Read(buffer, len);
	imageFile.Close();
	int slen = (len / 3) * 4;
	slen += 10;
	TCHAR * tc;
	//tc = (TCHAR *)malloc(slen); 报错
	tc = new TCHAR[slen+1];
	slen = BASE64_Encoder(buffer, len, tc);
	CString result(tc);
	return result.AllocSysString();
}
