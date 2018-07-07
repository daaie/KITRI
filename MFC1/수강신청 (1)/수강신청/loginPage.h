#pragma once
#include "login.h"


// loginPage

class loginPage : public CPropertySheet
{
	DECLARE_DYNAMIC(loginPage)

public:
	loginPage(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	loginPage(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~loginPage();
	loginPage();
protected:
	DECLARE_MESSAGE_MAP()
public:
	login login;
};


