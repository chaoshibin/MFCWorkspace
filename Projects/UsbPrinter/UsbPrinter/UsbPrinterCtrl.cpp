// UsbPrinterCtrl.cpp : CUsbPrinterCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "UsbPrinter.h"
#include "UsbPrinterCtrl.h"
#include "UsbPrinterPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CUsbPrinterCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CUsbPrinterCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CUsbPrinterCtrl, COleControl)
	DISP_FUNCTION_ID(CUsbPrinterCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CUsbPrinterCtrl, "SendLocalFilePath", dispidSendLocalFilePath, SendLocalFilePath, VT_I4, VTS_BSTR)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CUsbPrinterCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(CUsbPrinterCtrl, 1)
	PROPPAGEID(CUsbPrinterPropPage::guid)
END_PROPPAGEIDS(CUsbPrinterCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CUsbPrinterCtrl, "USBPRINTER.UsbPrinterCtrl.1",
	0x24d9a3f7, 0x6690, 0x41bb, 0xb0, 0xe, 0xc8, 0x92, 0x98, 0x73, 0xab, 0x34)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CUsbPrinterCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DUsbPrinter = { 0x7735B5C6, 0x4BD4, 0x4F5C, { 0xA5, 0xFC, 0x73, 0x38, 0x4F, 0x3F, 0x3A, 0xF7 } };
const IID IID_DUsbPrinterEvents = { 0x40317828, 0x19E3, 0x48FB, { 0xAB, 0xDF, 0x9F, 0x9A, 0x96, 0x4A, 0x88, 0xC8 } };

// 控件类型信息

static const DWORD _dwUsbPrinterOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CUsbPrinterCtrl, IDS_USBPRINTER, _dwUsbPrinterOleMisc)

// CUsbPrinterCtrl::CUsbPrinterCtrlFactory::UpdateRegistry -
// 添加或移除 CUsbPrinterCtrl 的系统注册表项

BOOL CUsbPrinterCtrl::CUsbPrinterCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_USBPRINTER,
			IDB_USBPRINTER,
			afxRegApartmentThreading,
			_dwUsbPrinterOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CUsbPrinterCtrl::CUsbPrinterCtrl - 构造函数

CUsbPrinterCtrl::CUsbPrinterCtrl()
{
	InitializeIIDs(&IID_DUsbPrinter, &IID_DUsbPrinterEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CUsbPrinterCtrl::~CUsbPrinterCtrl - 析构函数

CUsbPrinterCtrl::~CUsbPrinterCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CUsbPrinterCtrl::OnDraw - 绘图函数

void CUsbPrinterCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CUsbPrinterCtrl::DoPropExchange - 持久性支持

void CUsbPrinterCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  为每个持久的自定义属性调用 PX_ 函数。
}


// CUsbPrinterCtrl::OnResetState - 将控件重置为默认状态

void CUsbPrinterCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CUsbPrinterCtrl::AboutBox - 向用户显示“关于”框

void CUsbPrinterCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_USBPRINTER);
	dlgAbout.DoModal();
}


// CUsbPrinterCtrl 消息处理程序


LONG CUsbPrinterCtrl::SendLocalFilePath(LPCTSTR lpFilePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  在此添加调度处理程序代码
	LONG result = m_UsbPrinterApp->SendFilePath(lpFilePath);
	return result;
}
