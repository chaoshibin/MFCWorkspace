#pragma once

// GrandDogWebPropPage.h : CGrandDogWebPropPage ����ҳ���������


// CGrandDogWebPropPage : �й�ʵ�ֵ���Ϣ������� GrandDogWebPropPage.cpp��

class CGrandDogWebPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CGrandDogWebPropPage)
	DECLARE_OLECREATE_EX(CGrandDogWebPropPage)

// ���캯��
public:
	CGrandDogWebPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_GRANDDOGWEB };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

