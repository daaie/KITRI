#pragma once
#include "afxcmn.h"
#include "syllabusPage.h"

// CProfessor dialog

class CProfessor : public CPropertyPage
{
	DECLARE_DYNAMIC(CProfessor)

public:
	CProfessor();
	virtual ~CProfessor();
	CProfessor(CString id);
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Professor };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl myList;
	CString room;
	CString day;
	CString time;
	CString maxNum;
	CString SubNum;
	CString SubName;
	CString profName;
	syllabusPage *syl;
	int mark = 0;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLvnItemActivateList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton4();
};
