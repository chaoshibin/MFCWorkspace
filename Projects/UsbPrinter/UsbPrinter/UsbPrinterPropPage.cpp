// UsbPrinterPropPage.cpp : CUsbPrinterPropPage 属性页类的实现。

#include "stdafx.h"
#include "UsbPrinter.h"
#include "UsbPrinterPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CUsbPrinterPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CUsbPrinterPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CUsbPrinterPropPage, "USBPRINTER.UsbPrinterPropPage.1",
	0x66f7a9e0, 0xcc12, 0x4819, 0xa6, 0x89, 0xa8, 0x6b, 0x61, 0xb, 0x17, 0x72)

// CUsbPrinterPropPage::CUsbPrinterPropPageFactory::UpdateRegistry -
// 添加或移除 CUsbPrinterPropPage 的系统注册表项

BOOL CUsbPrinterPropPage::CUsbPrinterPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_USBPRINTER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CUsbPrinterPropPage::CUsbPrinterPropPage - 构造函数

CUsbPrinterPropPage::CUsbPrinterPropPage() :
	COlePropertyPage(IDD, IDS_USBPRINTER_PPG_CAPTION)
{
}

// CUsbPrinterPropPage::DoDataExchange - 在页和属性间移动数据

void CUsbPrinterPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CUsbPrinterPropPage 消息处理程序
