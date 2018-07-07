
// 1027格夸老Dlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CMy1027格夸老Dlg dialog
class CMy1027格夸老Dlg : public CDialogEx
{
// Construction
public:
	CMy1027格夸老Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY1027_DIALOG };
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
	CListCtrl myList;
	CString name;
	CString email;
	afx_msg void OnBnClickedButton1();
};
