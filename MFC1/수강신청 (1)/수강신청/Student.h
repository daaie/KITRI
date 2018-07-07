#pragma once
#include "afxcmn.h"
#include "syllabusPage.h"

// CStudent dialog

class CStudent : public CPropertyPage
{
	DECLARE_DYNAMIC(CStudent)

public:
	CStudent();
	virtual ~CStudent();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Student };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl myList;
	CListCtrl myLecture;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	syllabusPage *syl;
};
