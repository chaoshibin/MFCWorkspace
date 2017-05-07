// UsbCapturePropPage.cpp : CUsbCapturePropPage 属性页类的实现。

#include "stdafx.h"
#include "UsbCapture.h"
#include "UsbCapturePropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CUsbCapturePropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CUsbCapturePropPage, COlePropertyPage)
	ON_BN_CLICKED(IDC_BTN_TAKEPHOTO, &CUsbCapturePropPage::OnBnClickedBtnTakephoto)
	ON_STN_CLICKED(IDC_TAKE_PHOTO, &CUsbCapturePropPage::OnStnClickedTakePhoto)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CUsbCapturePropPage, "USBCAPTURE.UsbCapturePropPage.1",
	0x1675d513, 0xb783, 0x40c0, 0xbe, 0xf3, 0x67, 0xbc, 0x4a, 0xa9, 0xa8, 0x8d)

// CUsbCapturePropPage::CUsbCapturePropPageFactory::UpdateRegistry -
// 添加或移除 CUsbCapturePropPage 的系统注册表项

BOOL CUsbCapturePropPage::CUsbCapturePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_USBCAPTURE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CUsbCapturePropPage::CUsbCapturePropPage - 构造函数

CUsbCapturePropPage::CUsbCapturePropPage() :
	COlePropertyPage(IDD, IDS_USBCAPTURE_PPG_CAPTION)
{
}

// CUsbCapturePropPage::DoDataExchange - 在页和属性间移动数据

void CUsbCapturePropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CUsbCapturePropPage 消息处理程序


void CUsbCapturePropPage::OnBnClickedBtnTakephoto()
{
	// TODO:  在此添加控件通知处理程序代码
	//TCHAR szNewFile[256] = {0};
	//GetDlgItemText(IDC_EDIT_PHOTONAME, szNewFile,256);
	
	LPCTSTR a = TEXT("E:\\UUUUUU.jpg");
	TakePhoto(a);
}


BOOL CUsbCapturePropPage::OnInitDialog()
{
	COlePropertyPage::OnInitDialog();

	// TODO:  在此处添加消息处理程序代码
	m_bInit = FALSE;
	CWnd *pWnd = GetDlgItem(IDC_TAKE_PHOTO);//得到预示窗口指针
	//CWnd *p = GetDlgItem(IDD_PROPPAGE_USBCAPTURE);//显示大小
	CRect rect;
	pWnd->GetWindowRect(&rect); // 得到窗口大小
	//CString str;
	//str.Format(_T("%d"), rect.Width());
	//MessageBox(str);

	//BITMAPINFO bmpInfo;
	//设置
	//bmpInfo.bmiHeader.biWidth = rect.Width();
	//bmpInfo.bmiHeader.biHeight = rect.Height();
	//bmpInfo.bmiHeader.biBitCount=g_iBits;
	//bmpInfo.bmiHeader.biSizeImage=g_iWidth*g_iHeight*g_iBits;

	//写入
	/*if (!capSetVideoFormat(m_hCapWnd, &bmpInfo, sizeof(BITMAPINFO)))
	{
		MessageBox(TEXT("capSetVideoFormat False!"));
	}*/

	m_hCapWnd = capCreateCaptureWindow((LPTSTR)TEXT("视频捕捉"),
		WS_CHILD | WS_VISIBLE | WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME,
		0, 0, rect.Width(), rect.Height(),
		pWnd->GetSafeHwnd(), 0); // 设置预示窗口 
	ASSERT(m_hCapWnd);
	for (size_t i = 0; i < 5; i++)
	{
		if (capDriverConnect(m_hCapWnd, 0))
		{
			// 连接第0 号驱动器
			m_bInit = TRUE;
			//得到驱动器的性能
			capDriverGetCaps(m_hCapWnd, &m_CapDrvCap, sizeof(CAPDRIVERCAPS));
			if (m_CapDrvCap.fCaptureInitialized)
			{
				// 初始化成功
				capGetStatus(m_hCapWnd, &m_CapStatus, sizeof(m_CapStatus)); // 得到驱动器状态
				capPreviewRate(m_hCapWnd, 30); // 设置预示帧频
				capPreview(m_hCapWnd, TRUE); // 设置预示方式
				break;
			}
			else{
				// 初始化失败
				MessageBoxW(TEXT("视频捕捉卡初始化失败!"), TEXT("提示"), MB_OK);
				AfxGetMainWnd()->PostMessage(WM_CLOSE);
			}
		}
	}

	     //else{// 未能连接到驱动器
		 //MessageBoxW(TEXT("与视频捕捉卡连接失败!"), TEXT("提示"), MB_OK);
		 // MessageBoxW(TEXT("请确认USB摄像头正确连接!"), TEXT("提示"), MB_OK);
		 //	AfxGetMainWnd()->PostMessage(WM_CLOSE);
	     //}
	return FALSE;
}


void CUsbCapturePropPage::OnStnClickedTakePhoto()
{
	// TODO:  在此添加控件通知处理程序代码
}

void CUsbCapturePropPage::TakePhoto(LPCTSTR filePath)
{
	// TODO:  在此添加控件通知处理程序代码
	//TCHAR szNewFile[256] = {0};
	//GetDlgItemText(IDC_EDIT_PHOTONAME, szNewFile,256);
	capCaptureSingleFrame(m_hCapWnd);
	capFileSaveDIB(m_hCapWnd, filePath);
}

BYTE CUsbCapturePropPage::TakePhotoEx(LPCTSTR filePath)
{
	// TODO:  在此添加控件通知处理程序代码
	//TCHAR szNewFile[256] = {0};
	//GetDlgItemText(IDC_EDIT_PHOTONAME, szNewFile,256);
	capCaptureSingleFrame(m_hCapWnd);
	return capFileSaveDIB(m_hCapWnd, filePath);
}

void CUsbCapturePropPage::Disconnect()
{
	// TODO:  在此添加控件通知处理程序代码
	capDriverDisconnect(m_hCapWnd);
}