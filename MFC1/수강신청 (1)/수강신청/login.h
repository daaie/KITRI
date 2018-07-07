#pragma once
#include "afxwin.h"


// login 대화 상자입니다.

class login : public CPropertyPage
{
	DECLARE_DYNAMIC(login)

public:
	login();
	virtual ~login();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString Id;
	CString Name;
	CButton Btper;
	CButton BtProf;
	CButton BtStu;
	CFile file1,file2,file3;

	virtual BOOL OnInitDialog();
};
