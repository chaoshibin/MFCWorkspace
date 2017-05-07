#pragma once

// UsbPrinterCtrl.h : CUsbPrinterCtrl ActiveX �ؼ����������


// CUsbPrinterCtrl : �й�ʵ�ֵ���Ϣ������� UsbPrinterCtrl.cpp��

class CUsbPrinterCtrl : public COleControl
{
	DECLARE_DYNCREATE(CUsbPrinterCtrl)

// ���캯��
public:
	CUsbPrinterCtrl();
	CUsbPrinterApp *m_UsbPrinterApp;
// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CUsbPrinterCtrl();

	DECLARE_OLECREATE_EX(CUsbPrinterCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CUsbPrinterCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CUsbPrinterCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CUsbPrinterCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidSendLocalFilePath = 1L
	};
protected:
	LONG SendLocalFilePath(LPCTSTR lpFilePath);
};

