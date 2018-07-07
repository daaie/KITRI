// syllabusPage.cpp : implementation file
//

#include "stdafx.h"
#include "수강신청.h"
#include "syllabusPage.h"


// syllabusPage

IMPLEMENT_DYNAMIC(syllabusPage, CPropertySheet)

syllabusPage::syllabusPage(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

syllabusPage::syllabusPage(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}
syllabusPage::syllabusPage(CString subjectName)
{
	syl = new syllabus(subjectName);
	AddPage(syl);
}
syllabusPage::~syllabusPage()
{
}


BEGIN_MESSAGE_MAP(syllabusPage, CPropertySheet)
END_MESSAGE_MAP()


// syllabusPage message handlers
