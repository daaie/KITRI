// PersonnelPage.cpp : implementation file
//

#include "stdafx.h"
#include "������û.h"
#include "PersonnelPage.h"


// CPersonnelPage

IMPLEMENT_DYNAMIC(CPersonnelPage, CPropertySheet)

CPersonnelPage::CPersonnelPage(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CPersonnelPage::CPersonnelPage(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	: CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}
CPersonnelPage::CPersonnelPage()
{
	AddPage(&personnel);
}
CPersonnelPage::~CPersonnelPage()
{
}


BEGIN_MESSAGE_MAP(CPersonnelPage, CPropertySheet)
END_MESSAGE_MAP()


// CPersonnelPage message handlers
