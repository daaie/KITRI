#pragma once
#include "afxwin.h"


// login ��ȭ �����Դϴ�.

class login : public CPropertyPage
{
	DECLARE_DYNAMIC(login)

public:
	login();
	virtual ~login();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
