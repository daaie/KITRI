// StudentPage.cpp : implementation file
//

#include "stdafx.h"
#include "������û.h"
#include "StudentPage.h"


// CStudentPage

IMPLEMENT_DYNAMIC(CStudentPage, CPropertySheet)

CStudentPage::CStudentPage(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CStudentPage::CStudentPage(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}
CStudentPage::CStudentPage()
{
	AddPage(&student);
}

CStudentPage::~CStudentPage()
{
}


BEGIN_MESSAGE_MAP(CStudentPage, CPropertySheet)
END_MESSAGE_MAP()


// CStudentPage message handlers
