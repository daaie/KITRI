
// ex1Dlg.h : header file
//

#pragma once
#include "afxcmn.h"


// Cex1Dlg dialog
class Cex1Dlg : public CDialogEx
{
// Construction
public:
	Cex1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX1_DIALOG };
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
	afx_msg void OnBnClickedCheck1();
	BOOL check1;
	CString sel;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	CProgressCtrl progress;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
