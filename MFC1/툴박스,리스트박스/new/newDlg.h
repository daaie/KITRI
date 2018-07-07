
// newDlg.h : header file
//

#pragma once
#include "afxwin.h"
class Member
{
public:
	Member(CString n, CString t, CString a)
	{
		name = n;
		tel = t;
		address = a;
	}
	CString name;
	CString tel;
	CString address;
};

// CnewDlg dialog
class CnewDlg : public CDialogEx
{
// Construction
public:
	CnewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEW_DIALOG };
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
	CString myEdit;
	CListBox myList;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString tel;
	CString address;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton3();
};

