
// 己利府胶飘Dlg.h : header file
//

#pragma once
#include "afxcmn.h"


// C己利府胶飘Dlg dialog
class C己利府胶飘Dlg : public CDialogEx
{
// Construction
public:
	C己利府胶飘Dlg(CWnd* pParent = NULL);	// standard constructor

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
	CTreeCtrl myTree;
	CListCtrl myList;
	CString group;
	CString num;
	CString name;
	CString korean;
	CString english;
	CString math;
	HTREEITEM *book;
	HTREEITEM *books;
	C己利府胶飘Dlg *student;

	int tot;
	TVINSERTSTRUCT tInsert;
	void printList(C己利府胶飘Dlg* temp);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);


};
