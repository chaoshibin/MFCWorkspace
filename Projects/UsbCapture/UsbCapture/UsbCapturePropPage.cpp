// UsbCapturePropPage.cpp : CUsbCapturePropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "UsbCapture.h"
#include "UsbCapturePropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CUsbCapturePropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CUsbCapturePropPage, COlePropertyPage)
	ON_BN_CLICKED(IDC_BTN_TAKEPHOTO, &CUsbCapturePropPage::OnBnClickedBtnTakephoto)
	ON_STN_CLICKED(IDC_TAKE_PHOTO, &CUsbCapturePropPage::OnStnClickedTakePhoto)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CUsbCapturePropPage, "USBCAPTURE.UsbCapturePropPage.1",
	0x1675d513, 0xb783, 0x40c0, 0xbe, 0xf3, 0x67, 0xbc, 0x4a, 0xa9, 0xa8, 0x8d)

// CUsbCapturePropPage::CUsbCapturePropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CUsbCapturePropPage ��ϵͳע�����

BOOL CUsbCapturePropPage::CUsbCapturePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_USBCAPTURE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CUsbCapturePropPage::CUsbCapturePropPage - ���캯��

CUsbCapturePropPage::CUsbCapturePropPage() :
	COlePropertyPage(IDD, IDS_USBCAPTURE_PPG_CAPTION)
{
}

// CUsbCapturePropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CUsbCapturePropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CUsbCapturePropPage ��Ϣ�������


void CUsbCapturePropPage::OnBnClickedBtnTakephoto()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//TCHAR szNewFile[256] = {0};
	//GetDlgItemText(IDC_EDIT_PHOTONAME, szNewFile,256);
	
	LPCTSTR a = TEXT("E:\\UUUUUU.jpg");
	TakePhoto(a);
}


BOOL CUsbCapturePropPage::OnInitDialog()
{
	COlePropertyPage::OnInitDialog();

	// TODO:  �ڴ˴������Ϣ����������
	m_bInit = FALSE;
	CWnd *pWnd = GetDlgItem(IDC_TAKE_PHOTO);//�õ�Ԥʾ����ָ��
	//CWnd *p = GetDlgItem(IDD_PROPPAGE_USBCAPTURE);//��ʾ��С
	CRect rect;
	pWnd->GetWindowRect(&rect); // �õ����ڴ�С
	//CString str;
	//str.Format(_T("%d"), rect.Width());
	//MessageBox(str);

	//BITMAPINFO bmpInfo;
	//����
	//bmpInfo.bmiHeader.biWidth = rect.Width();
	//bmpInfo.bmiHeader.biHeight = rect.Height();
	//bmpInfo.bmiHeader.biBitCount=g_iBits;
	//bmpInfo.bmiHeader.biSizeImage=g_iWidth*g_iHeight*g_iBits;

	//д��
	/*if (!capSetVideoFormat(m_hCapWnd, &bmpInfo, sizeof(BITMAPINFO)))
	{
		MessageBox(TEXT("capSetVideoFormat False!"));
	}*/

	m_hCapWnd = capCreateCaptureWindow((LPTSTR)TEXT("��Ƶ��׽"),
		WS_CHILD | WS_VISIBLE | WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME,
		0, 0, rect.Width(), rect.Height(),
		pWnd->GetSafeHwnd(), 0); // ����Ԥʾ���� 
	ASSERT(m_hCapWnd);
	for (size_t i = 0; i < 5; i++)
	{
		if (capDriverConnect(m_hCapWnd, 0))
		{
			// ���ӵ�0 ��������
			m_bInit = TRUE;
			//�õ�������������
			capDriverGetCaps(m_hCapWnd, &m_CapDrvCap, sizeof(CAPDRIVERCAPS));
			if (m_CapDrvCap.fCaptureInitialized)
			{
				// ��ʼ���ɹ�
				capGetStatus(m_hCapWnd, &m_CapStatus, sizeof(m_CapStatus)); // �õ�������״̬
				capPreviewRate(m_hCapWnd, 30); // ����Ԥʾ֡Ƶ
				capPreview(m_hCapWnd, TRUE); // ����Ԥʾ��ʽ
				break;
			}
			else{
				// ��ʼ��ʧ��
				MessageBoxW(TEXT("��Ƶ��׽����ʼ��ʧ��!"), TEXT("��ʾ"), MB_OK);
				AfxGetMainWnd()->PostMessage(WM_CLOSE);
			}
		}
	}

	     //else{// δ�����ӵ�������
		 //MessageBoxW(TEXT("����Ƶ��׽������ʧ��!"), TEXT("��ʾ"), MB_OK);
		 // MessageBoxW(TEXT("��ȷ��USB����ͷ��ȷ����!"), TEXT("��ʾ"), MB_OK);
		 //	AfxGetMainWnd()->PostMessage(WM_CLOSE);
	     //}
	return FALSE;
}


void CUsbCapturePropPage::OnStnClickedTakePhoto()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CUsbCapturePropPage::TakePhoto(LPCTSTR filePath)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//TCHAR szNewFile[256] = {0};
	//GetDlgItemText(IDC_EDIT_PHOTONAME, szNewFile,256);
	capCaptureSingleFrame(m_hCapWnd);
	capFileSaveDIB(m_hCapWnd, filePath);
}

BYTE CUsbCapturePropPage::TakePhotoEx(LPCTSTR filePath)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//TCHAR szNewFile[256] = {0};
	//GetDlgItemText(IDC_EDIT_PHOTONAME, szNewFile,256);
	capCaptureSingleFrame(m_hCapWnd);
	return capFileSaveDIB(m_hCapWnd, filePath);
}

void CUsbCapturePropPage::Disconnect()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	capDriverDisconnect(m_hCapWnd);
}