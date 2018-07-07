#pragma once
#include "Student.h"


// CStudentPage

class CStudentPage : public CPropertySheet
{
	DECLARE_DYNAMIC(CStudentPage)

public:
	CStudentPage(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CStudentPage(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CStudentPage();
	CStudentPage();
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStudent student;
};


