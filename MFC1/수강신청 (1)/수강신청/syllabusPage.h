#pragma once
#include "syllabus.h"


// syllabusPage

class syllabusPage : public CPropertySheet
{
	DECLARE_DYNAMIC(syllabusPage)

public:
	syllabusPage(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	syllabusPage(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~syllabusPage();
	syllabusPage(CString subjectName);
protected:
	DECLARE_MESSAGE_MAP()
public:
	syllabus *syl;
};


