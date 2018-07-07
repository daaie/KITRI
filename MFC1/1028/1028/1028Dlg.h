
// 1028Dlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CMy1028Dlg dialog
class CMy1028Dlg : public CDialogEx
{
// Construction
public:
	CMy1028Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY1028_DIALOG };
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
	CTreeCtrl myTree;
	int myEdit;
	CSpinButtonCtrl gg;
};
