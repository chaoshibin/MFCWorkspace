// GrandDogWebPropPage.cpp : CGrandDogWebPropPage 属性页类的实现。

#include "stdafx.h"
#include "GrandDogWeb.h"
#include "GrandDogWebPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CGrandDogWebPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CGrandDogWebPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CGrandDogWebPropPage, "GRANDDOGWEB.GrandDogWebPropPage.1",
	0x36969f7a, 0x63d3, 0x4b7c, 0xa2, 0x8e, 0x3, 0xe7, 0x18, 0xde, 0x92, 0xb7)

// CGrandDogWebPropPage::CGrandDogWebPropPageFactory::UpdateRegistry -
// 添加或移除 CGrandDogWebPropPage 的系统注册表项

BOOL CGrandDogWebPropPage::CGrandDogWebPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_GRANDDOGWEB_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CGrandDogWebPropPage::CGrandDogWebPropPage - 构造函数

CGrandDogWebPropPage::CGrandDogWebPropPage() :
	COlePropertyPage(IDD, IDS_GRANDDOGWEB_PPG_CAPTION)
{
}

// CGrandDogWebPropPage::DoDataExchange - 在页和属性间移动数据

void CGrandDogWebPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CGrandDogWebPropPage 消息处理程序
