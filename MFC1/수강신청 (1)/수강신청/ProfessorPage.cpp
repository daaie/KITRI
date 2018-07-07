// ProfessorPage.cpp : implementation file
//

#include "stdafx.h"
#include "수강신청.h"
#include "ProfessorPage.h"

// CProfessorPage

IMPLEMENT_DYNAMIC(CProfessorPage, CPropertySheet)

CProfessorPage::CProfessorPage(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CProfessorPage::CProfessorPage(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	: CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}
CProfessorPage::CProfessorPage(CString id)
{
	professor = new CProfessor(id);
	AddPage(professor);
}
CProfessorPage::~CProfessorPage()
{
}


BEGIN_MESSAGE_MAP(CProfessorPage, CPropertySheet)
END_MESSAGE_MAP()


// CProfessorPage message handlers
