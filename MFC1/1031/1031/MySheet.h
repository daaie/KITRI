#pragma once	//�갡 ������ Ȯ���ؼ� ���� �ѹ��� ���� �ߺ����� ������ ������
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


