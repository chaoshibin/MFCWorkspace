// UsbPrinterCtrl.cpp : CUsbPrinterCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "UsbPrinter.h"
#include "UsbPrinterCtrl.h"
#include "UsbPrinterPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CUsbPrinterCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CUsbPrinterCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CUsbPrinterCtrl, COleControl)
	DISP_FUNCTION_ID(CUsbPrinterCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CUsbPrinterCtrl, "SendLocalFilePath", dispidSendLocalFilePath, SendLocalFilePath, VT_I4, VTS_BSTR)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CUsbPrinterCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CUsbPrinterCtrl, 1)
	PROPPAGEID(CUsbPrinterPropPage::guid)
END_PROPPAGEIDS(CUsbPrinterCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CUsbPrinterCtrl, "USBPRINTER.UsbPrinterCtrl.1",
	0x24d9a3f7, 0x6690, 0x41bb, 0xb0, 0xe, 0xc8, 0x92, 0x98, 0x73, 0xab, 0x34)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CUsbPrinterCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DUsbPrinter = { 0x7735B5C6, 0x4BD4, 0x4F5C, { 0xA5, 0xFC, 0x73, 0x38, 0x4F, 0x3F, 0x3A, 0xF7 } };
const IID IID_DUsbPrinterEvents = { 0x40317828, 0x19E3, 0x48FB, { 0xAB, 0xDF, 0x9F, 0x9A, 0x96, 0x4A, 0x88, 0xC8 } };

// �ؼ�������Ϣ

static const DWORD _dwUsbPrinterOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CUsbPrinterCtrl, IDS_USBPRINTER, _dwUsbPrinterOleMisc)

// CUsbPrinterCtrl::CUsbPrinterCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CUsbPrinterCtrl ��ϵͳע�����

BOOL CUsbPrinterCtrl::CUsbPrinterCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

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


// CUsbPrinterCtrl::CUsbPrinterCtrl - ���캯��

CUsbPrinterCtrl::CUsbPrinterCtrl()
{
	InitializeIIDs(&IID_DUsbPrinter, &IID_DUsbPrinterEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CUsbPrinterCtrl::~CUsbPrinterCtrl - ��������

CUsbPrinterCtrl::~CUsbPrinterCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CUsbPrinterCtrl::OnDraw - ��ͼ����

void CUsbPrinterCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CUsbPrinterCtrl::DoPropExchange - �־���֧��

void CUsbPrinterCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CUsbPrinterCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CUsbPrinterCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CUsbPrinterCtrl::AboutBox - ���û���ʾ�����ڡ���

void CUsbPrinterCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_USBPRINTER);
	dlgAbout.DoModal();
}


// CUsbPrinterCtrl ��Ϣ�������


LONG CUsbPrinterCtrl::SendLocalFilePath(LPCTSTR lpFilePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������
	LONG result = m_UsbPrinterApp->SendFilePath(lpFilePath);
	return result;
}
