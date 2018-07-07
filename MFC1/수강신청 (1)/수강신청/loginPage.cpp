// loginPage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "수강신청.h"
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


// loginPage 메시지 처리기입니다.
