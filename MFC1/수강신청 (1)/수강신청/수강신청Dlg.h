
// 수강신청Dlg.h : header file
//

#pragma once
#include "PersonnelPage.h"
#include "ProfessorPage.h"
#include "StudentPage.h"
#include "afxwin.h"
#include "loginPage.h"

// C수강신청Dlg dialog
class C수강신청Dlg : public CDialogEx
{
	// Construction
public:
	C수강신청Dlg(CWnd* pParent = NULL);	// standard constructor

									// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


														// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CComboBox loginCheck;

	loginPage log;
	afx_msg void OnBnClickedButton2();
	CString mId;
	CString mName;
};

