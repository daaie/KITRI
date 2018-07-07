#pragma once
#include "Professor.h"


// CProfessorPage

class CProfessorPage : public CPropertySheet
{
	DECLARE_DYNAMIC(CProfessorPage)

public:
	CProfessorPage(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CProfessorPage(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CProfessorPage();
	CProfessorPage(CString id);
protected:
	DECLARE_MESSAGE_MAP();
public:
	CProfessor *professor;
};


