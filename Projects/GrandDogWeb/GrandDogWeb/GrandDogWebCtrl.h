#pragma once

// GrandDogWebCtrl.h : CGrandDogWebCtrl ActiveX �ؼ����������


// CGrandDogWebCtrl : �й�ʵ�ֵ���Ϣ������� GrandDogWebCtrl.cpp��

class CGrandDogWebCtrl : public COleControl
{
	DECLARE_DYNCREATE(CGrandDogWebCtrl)

// ���캯��
public:
	CGrandDogWebCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
	~CGrandDogWebCtrl();
protected:
	

	DECLARE_OLECREATE_EX(CGrandDogWebCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CGrandDogWebCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CGrandDogWebCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CGrandDogWebCtrl)		// �������ƺ�����״̬

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
		dispidDogSerial = 15,
		dispidReadData = 14,
		dispidReadDog = 13L,
		dispidWriteDog = 12L,
		dispidWRC_CloseDog = 11L,
		dispidEncryptData = 10,
		dispidWRC_EncryptData = 9L,
		dispidWRC_CheckDog = 8L,
		dispidWRC_CreateFile = 7L,
		dispidWRC_CreateDir = 6L,
		dispidWRC_ChangePassword = 5L,
		dispidWRC_VerifyPassword = 4L,
		dispidlDogHandle = 3,
		dispidWRC_OPENDOG = 2L,
		dispidRC_OPENDOG_EX = 1L

	};

public:
	int OnInitApp();
protected:
	ULONG RC_OPENDOG_EX(ULONG ulFlag, CHAR* pszProductName, ULONG* pDogHandle);
	ULONG WRC_OPENDOG(LONG ulFlag, LPCTSTR pszProductName);
	void OnlDogHandleChanged();
	ULONG m_lDogHandle;
	ULONG WRC_VerifyPassword(ULONG DogHandle, CHAR ucPasswordType, LPCTSTR pszPassword);
	ULONG WRC_ChangePassword(ULONG lDogHandle, CHAR ucPasswordType, LPCTSTR pszPassword);
	ULONG WRC_CreateDir(ULONG lDogHandle, USHORT dirId, ULONG dirSize);
	ULONG WRC_CreateFile(ULONG lDogHandle, USHORT usDirID, USHORT usFileID, CHAR ucFileType, ULONG ulFileLen);
	ULONG WRC_CheckDog(ULONG lDogHandle);
	ULONG WRC_EncryptData(ULONG lDogHandle, LPCTSTR pucIn, ULONG ulInLen, ULONG pulOutLen);
	void OnEncryptDataChanged();
	CString m_EncryptData;
	ULONG WRC_CloseDog(ULONG lDogHandle);
	ULONG WriteDog(LPCTSTR data);
	ULONG ReadDog();
	void OnReadDataChanged();
	CString m_ReadData;
	void OnDogSerialChanged();
	CString m_DogSerial;
};

