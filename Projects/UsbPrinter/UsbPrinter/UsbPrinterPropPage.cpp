// UsbPrinterPropPage.cpp : CUsbPrinterPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "UsbPrinter.h"
#include "UsbPrinterPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CUsbPrinterPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CUsbPrinterPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CUsbPrinterPropPage, "USBPRINTER.UsbPrinterPropPage.1",
	0x66f7a9e0, 0xcc12, 0x4819, 0xa6, 0x89, 0xa8, 0x6b, 0x61, 0xb, 0x17, 0x72)

// CUsbPrinterPropPage::CUsbPrinterPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CUsbPrinterPropPage ��ϵͳע�����

BOOL CUsbPrinterPropPage::CUsbPrinterPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_USBPRINTER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CUsbPrinterPropPage::CUsbPrinterPropPage - ���캯��

CUsbPrinterPropPage::CUsbPrinterPropPage() :
	COlePropertyPage(IDD, IDS_USBPRINTER_PPG_CAPTION)
{
}

// CUsbPrinterPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CUsbPrinterPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CUsbPrinterPropPage ��Ϣ�������
