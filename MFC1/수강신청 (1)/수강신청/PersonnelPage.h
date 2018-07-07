#pragma once
#include "Personnel.h"

// CPersonnelPage

class CPersonnelPage : public CPropertySheet
{
	DECLARE_DYNAMIC(CPersonnelPage)

public:
	CPersonnelPage(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPersonnelPage(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CPersonnelPage();
	CPersonnelPage();
protected:
	DECLARE_MESSAGE_MAP()

public:
	CPersonnel personnel;
};


