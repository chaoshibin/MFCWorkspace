#pragma once

// UsbCapturePropPage.h : CUsbCapturePropPage 属性页类的声明。


// CUsbCapturePropPage : 有关实现的信息，请参阅 UsbCapturePropPage.cpp。
#include <vfw.h>
#pragma comment(lib,"vfw32.lib")

class CUsbCapturePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CUsbCapturePropPage)
	DECLARE_OLECREATE_EX(CUsbCapturePropPage)

// 构造函数
public:
	CUsbCapturePropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_USBCAPTURE };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnTakephoto();
	virtual BOOL OnInitDialog();

public:
	//自定义
	HWND m_hCapWnd;// 预示窗口
	BOOL m_bInit;// 捕捉器初始化
	
	CAPDRIVERCAPS m_CapDrvCap; // CAPDRIVERCAPS 结构，定义驱动器性能
	CAPSTATUS m_CapStatus; // CAPSTATUS 结构，定义捕捉窗口当前状态
	CAPTUREPARMS m_Parms;  // CAPTURE PARMS 结构，定义捕捉参数
	CString m_CapFileName; // 捕捉文件名称
	afx_msg void OnStnClickedTakePhoto();

public:
	//自定义
	void TakePhoto(LPCTSTR filePath);
	BYTE TakePhotoEx(LPCTSTR filePath);
	void Disconnect();
	LPCTSTR filePathStr;
};

