#pragma once

// UsbCapturePropPage.h : CUsbCapturePropPage ����ҳ���������


// CUsbCapturePropPage : �й�ʵ�ֵ���Ϣ������� UsbCapturePropPage.cpp��
#include <vfw.h>
#pragma comment(lib,"vfw32.lib")

class CUsbCapturePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CUsbCapturePropPage)
	DECLARE_OLECREATE_EX(CUsbCapturePropPage)

// ���캯��
public:
	CUsbCapturePropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_USBCAPTURE };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnTakephoto();
	virtual BOOL OnInitDialog();

public:
	//�Զ���
	HWND m_hCapWnd;// Ԥʾ����
	BOOL m_bInit;// ��׽����ʼ��
	
	CAPDRIVERCAPS m_CapDrvCap; // CAPDRIVERCAPS �ṹ����������������
	CAPSTATUS m_CapStatus; // CAPSTATUS �ṹ�����岶׽���ڵ�ǰ״̬
	CAPTUREPARMS m_Parms;  // CAPTURE PARMS �ṹ�����岶׽����
	CString m_CapFileName; // ��׽�ļ�����
	afx_msg void OnStnClickedTakePhoto();

public:
	//�Զ���
	void TakePhoto(LPCTSTR filePath);
	BYTE TakePhotoEx(LPCTSTR filePath);
	void Disconnect();
	LPCTSTR filePathStr;
};

