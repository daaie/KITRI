#pragma once	//얘가 선언을 확인해서 선언 한번만 해줌 중복선언 에러를 막아줌
#include "Page.h"


// CMySheet

class CMySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CMySheet)

public:
	CMySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CMySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CMySheet();
	virtual ~CMySheet();

protected:
	DECLARE_MESSAGE_MAP()
public:

	CPage1 myPage1;
	CPage2 myPage2;
};


