// GrandDogWebPropPage.cpp : CGrandDogWebPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "GrandDogWeb.h"
#include "GrandDogWebPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CGrandDogWebPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CGrandDogWebPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CGrandDogWebPropPage, "GRANDDOGWEB.GrandDogWebPropPage.1",
	0x36969f7a, 0x63d3, 0x4b7c, 0xa2, 0x8e, 0x3, 0xe7, 0x18, 0xde, 0x92, 0xb7)

// CGrandDogWebPropPage::CGrandDogWebPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CGrandDogWebPropPage ��ϵͳע�����

BOOL CGrandDogWebPropPage::CGrandDogWebPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_GRANDDOGWEB_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CGrandDogWebPropPage::CGrandDogWebPropPage - ���캯��

CGrandDogWebPropPage::CGrandDogWebPropPage() :
	COlePropertyPage(IDD, IDS_GRANDDOGWEB_PPG_CAPTION)
{
}

// CGrandDogWebPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CGrandDogWebPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CGrandDogWebPropPage ��Ϣ�������
