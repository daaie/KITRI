// MySheet.cpp : implementation file
//

#include "stdafx.h"
#include "1031.h"
#include "MySheet.h"
#include "Page.h"

// CMySheet

IMPLEMENT_DYNAMIC(CMySheet, CPropertySheet)

CMySheet::CMySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CMySheet::CMySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CMySheet::CMySheet()
{
	AddPage(&myPage1);
	AddPage(&myPage2);
}

CMySheet::~CMySheet()
{


}

BEGIN_MESSAGE_MAP(CMySheet, CPropertySheet)
END_MESSAGE_MAP()


// CMySheet message handlers
