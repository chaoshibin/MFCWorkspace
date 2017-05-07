#pragma once

// UsbPrinterPropPage.h : CUsbPrinterPropPage 属性页类的声明。


// CUsbPrinterPropPage : 有关实现的信息，请参阅 UsbPrinterPropPage.cpp。

class CUsbPrinterPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CUsbPrinterPropPage)
	DECLARE_OLECREATE_EX(CUsbPrinterPropPage)

// 构造函数
public:
	CUsbPrinterPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_USBPRINTER };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

