
// ��������ƮDlg.h : header file
//

#pragma once
#include "afxcmn.h"


// C��������ƮDlg dialog
class C��������ƮDlg : public CDialogEx
{
// Construction
public:
	C��������ƮDlg(CWnd* pParent = NULL);	// standard constructor

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
	C��������ƮDlg *student;

	int tot;
	TVINSERTSTRUCT tInsert;
	void printList(C��������ƮDlg* temp);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);


};
