#pragma once

// UsbPrinterPropPage.h : CUsbPrinterPropPage ����ҳ���������


// CUsbPrinterPropPage : �й�ʵ�ֵ���Ϣ������� UsbPrinterPropPage.cpp��

class CUsbPrinterPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CUsbPrinterPropPage)
	DECLARE_OLECREATE_EX(CUsbPrinterPropPage)

// ���캯��
public:
	CUsbPrinterPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_USBPRINTER };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

