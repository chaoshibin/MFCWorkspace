#pragma once

// GrandDogWebCtrl.h : CGrandDogWebCtrl ActiveX 控件类的声明。


// CGrandDogWebCtrl : 有关实现的信息，请参阅 GrandDogWebCtrl.cpp。

class CGrandDogWebCtrl : public COleControl
{
	DECLARE_DYNCREATE(CGrandDogWebCtrl)

// 构造函数
public:
	CGrandDogWebCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
	~CGrandDogWebCtrl();
protected:
	

	DECLARE_OLECREATE_EX(CGrandDogWebCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CGrandDogWebCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CGrandDogWebCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CGrandDogWebCtrl)		// 类型名称和杂项状态

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

