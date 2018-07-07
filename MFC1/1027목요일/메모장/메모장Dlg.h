
// 메모장Dlg.h : header file
//

#pragma once
#include "afxcmn.h"


// C메모장Dlg dialog
class C메모장Dlg : public CDialogEx
{
// Construction
public:
	C메모장Dlg(CWnd* pParent = NULL);	// standard constructor

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
	CString text;
	CString save;
	CString search;
	afx_msg void OnBnClickedButton3();
	CListCtrl myList;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CImageList imageList;
	CString files[100];
	int cnt = 0;
};
