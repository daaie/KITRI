
// Å½»öDlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CÅ½»öDlg dialog
class CÅ½»öDlg : public CDialogEx
{
// Construction
public:
	CÅ½»öDlg(CWnd* pParent = NULL);	// standard constructor

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
	CString search;
	CListCtrl myList;
	afx_msg void OnBnClickedButton1();
};
