// loginPage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "������û.h"
#include "loginPage.h"


// loginPage

IMPLEMENT_DYNAMIC(loginPage, CPropertySheet)

loginPage::loginPage(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

loginPage::loginPage(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}
loginPage::loginPage()
{
	AddPage(&login);
}
loginPage::~loginPage()
{
}


BEGIN_MESSAGE_MAP(loginPage, CPropertySheet)
END_MESSAGE_MAP()


// loginPage �޽��� ó�����Դϴ�.
