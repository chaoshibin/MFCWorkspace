#pragma once

// UsbCaptureCtrl.h : CUsbCaptureCtrl ActiveX 控件类的声明。


// CUsbCaptureCtrl : 有关实现的信息，请参阅 UsbCaptureCtrl.cpp。
#include"UsbCapturePropPage.h"
class CUsbCaptureCtrl : public COleControl
{
	DECLARE_DYNCREATE(CUsbCaptureCtrl)

// 构造函数
public:
	CUsbCaptureCtrl();
	CUsbCapturePropPage m_mainDlg;
// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CUsbCaptureCtrl();

	DECLARE_OLECREATE_EX(CUsbCaptureCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CUsbCaptureCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CUsbCaptureCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CUsbCaptureCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		dispidBASE64_Encode = 6L,
		dispidTAKE_PHOTO = 5L,
		dispidDLE_FILE = 4L,
		dispidDELETE_FILE = 3L,
		dispidDisconnect = 2L,
		dispidtakePhoto = 1L
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	void takePhoto(LPCTSTR filePath);
	void Disconnect();
	BYTE DELETE_FILE(LPCTSTR filePath);
	BYTE DLE_FILE(CHAR* fileName);
	BYTE TAKE_PHOTO(LPCTSTR fileName);
	BSTR BASE64_Encode(LPCTSTR fileName);
};

