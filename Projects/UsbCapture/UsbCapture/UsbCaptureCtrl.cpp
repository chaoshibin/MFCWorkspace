// UsbCaptureCtrl.cpp : CUsbCaptureCtrl ActiveX �ؼ����ʵ�֡�

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

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CUsbCaptureCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CUsbCaptureCtrl, COleControl)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "takePhoto", dispidtakePhoto, takePhoto, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "Disconnect", dispidDisconnect, Disconnect, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "DELETE_FILE", dispidDELETE_FILE, DELETE_FILE, VT_UI1, VTS_BSTR)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "DLE_FILE", dispidDLE_FILE, DLE_FILE, VT_UI1, VTS_PI1)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "TAKE_PHOTO", dispidTAKE_PHOTO, TAKE_PHOTO, VT_UI1, VTS_BSTR)
	DISP_FUNCTION_ID(CUsbCaptureCtrl, "BASE64_Encode", dispidBASE64_Encode, BASE64_Encode, VT_BSTR, VTS_BSTR)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CUsbCaptureCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CUsbCaptureCtrl, 1)
	PROPPAGEID(CUsbCapturePropPage::guid)
END_PROPPAGEIDS(CUsbCaptureCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CUsbCaptureCtrl, "USBCAPTURE.UsbCaptureCtrl.1",
	0x6b66f9c4, 0x1da0, 0x4463, 0x96, 0x37, 0xac, 0, 0xa5, 0x74, 0xad, 0x7a)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CUsbCaptureCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DUsbCapture = { 0x337D8864, 0x9C89, 0x4335, { 0xA8, 0x8F, 0xBE, 0x2C, 0xDC, 0x89, 0xDA, 0x73 } };
const IID IID_DUsbCaptureEvents = { 0xE0903E55, 0x5DE1, 0x4BCF, { 0x8E, 0x65, 0xE1, 0x31, 0x9, 0x8B, 0x81, 0x70 } };

// �ؼ�������Ϣ

static const DWORD _dwUsbCaptureOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CUsbCaptureCtrl, IDS_USBCAPTURE, _dwUsbCaptureOleMisc)

// CUsbCaptureCtrl::CUsbCaptureCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CUsbCaptureCtrl ��ϵͳע�����

BOOL CUsbCaptureCtrl::CUsbCaptureCtrlFactory::UpdateRegistry(BOOL bRegister)
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


// CUsbCaptureCtrl::CUsbCaptureCtrl - ���캯��

CUsbCaptureCtrl::CUsbCaptureCtrl()
{
	InitializeIIDs(&IID_DUsbCapture, &IID_DUsbCaptureEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CUsbCaptureCtrl::~CUsbCaptureCtrl - ��������

CUsbCaptureCtrl::~CUsbCaptureCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CUsbCaptureCtrl::OnDraw - ��ͼ����

void CUsbCaptureCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
	m_mainDlg.MoveWindow(rcBounds, TRUE);
}

// CUsbCaptureCtrl::DoPropExchange - �־���֧��

void CUsbCaptureCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CUsbCaptureCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CUsbCaptureCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CUsbCaptureCtrl::AboutBox - ���û���ʾ�����ڡ���

void CUsbCaptureCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_USBCAPTURE);
	dlgAbout.DoModal();
}


// CUsbCaptureCtrl ��Ϣ�������


int CUsbCaptureCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_mainDlg.Create(IDD_PROPPAGE_USBCAPTURE, this);
	m_mainDlg.ShowWindow(SW_SHOW);
	return 0;
}


void CUsbCaptureCtrl::takePhoto(LPCTSTR filePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO:  �ڴ���ӵ��ȴ���������
	m_mainDlg.TakePhoto(filePath);
}


void CUsbCaptureCtrl::Disconnect()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_mainDlg.Disconnect();
	// TODO:  �ڴ���ӵ��ȴ���������
}


BYTE CUsbCaptureCtrl::DELETE_FILE(LPCTSTR filePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	MessageBox(filePath);
	char file[50]= { '\0' };
	//WideCharToMultiByte(CP_ACP, 0, filePath, -1, file, wcslen(filePath), NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, filePath, -1, file, wcslen(filePath), NULL, NULL);
	MessageBoxA(NULL, file, "��ʾ�Ի���һ", MB_OK);
	remove(file);
	// TODO:  �ڴ���ӵ��ȴ���������
	return 0;
}


BYTE CUsbCaptureCtrl::DLE_FILE(CHAR* fileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO:  �ڴ���ӵ��ȴ���������
	remove(fileName);
	return 0;
}


BYTE CUsbCaptureCtrl::TAKE_PHOTO(LPCTSTR fileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO:  �ڴ���ӵ��ȴ���������

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
	// TODO:  �ڴ���ӵ��ȴ���������
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
	//tc = (TCHAR *)malloc(slen); ����
	tc = new TCHAR[slen+1];
	slen = BASE64_Encoder(buffer, len, tc);
	CString result(tc);
	return result.AllocSysString();
}
