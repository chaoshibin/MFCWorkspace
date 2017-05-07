#pragma once

// UsbPrinterCtrl.h : CUsbPrinterCtrl ActiveX 控件类的声明。


// CUsbPrinterCtrl : 有关实现的信息，请参阅 UsbPrinterCtrl.cpp。

class CUsbPrinterCtrl : public COleControl
{
	DECLARE_DYNCREATE(CUsbPrinterCtrl)

// 构造函数
public:
	CUsbPrinterCtrl();
	CUsbPrinterApp *m_UsbPrinterApp;
// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CUsbPrinterCtrl();

	DECLARE_OLECREATE_EX(CUsbPrinterCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CUsbPrinterCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CUsbPrinterCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CUsbPrinterCtrl)		// 类型名称和杂项状态

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
		dispidSendLocalFilePath = 1L
	};
protected:
	LONG SendLocalFilePath(LPCTSTR lpFilePath);
};

