#pragma once

// UsbCaptureCtrl.h : CUsbCaptureCtrl ActiveX �ؼ����������


// CUsbCaptureCtrl : �й�ʵ�ֵ���Ϣ������� UsbCaptureCtrl.cpp��
#include"UsbCapturePropPage.h"
class CUsbCaptureCtrl : public COleControl
{
	DECLARE_DYNCREATE(CUsbCaptureCtrl)

// ���캯��
public:
	CUsbCaptureCtrl();
	CUsbCapturePropPage m_mainDlg;
// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CUsbCaptureCtrl();

	DECLARE_OLECREATE_EX(CUsbCaptureCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CUsbCaptureCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CUsbCaptureCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CUsbCaptureCtrl)		// �������ƺ�����״̬

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

