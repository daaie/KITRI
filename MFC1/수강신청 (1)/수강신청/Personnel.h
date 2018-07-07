#pragma once
#include "afxcmn.h"

// CPersonnel dialog

class CPersonnel : public CPropertyPage
{
	DECLARE_DYNAMIC(CPersonnel)

public:
	CPersonnel();
	virtual ~CPersonnel();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Personnel };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString SubCode;
	CString SubName;
	CString Open;
	afx_msg void OnBnClickedButton1();
	CListCtrl myList;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
};

