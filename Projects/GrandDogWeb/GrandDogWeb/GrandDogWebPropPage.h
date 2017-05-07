#pragma once

// GrandDogWebPropPage.h : CGrandDogWebPropPage 属性页类的声明。


// CGrandDogWebPropPage : 有关实现的信息，请参阅 GrandDogWebPropPage.cpp。

class CGrandDogWebPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CGrandDogWebPropPage)
	DECLARE_OLECREATE_EX(CGrandDogWebPropPage)

// 构造函数
public:
	CGrandDogWebPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_GRANDDOGWEB };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

