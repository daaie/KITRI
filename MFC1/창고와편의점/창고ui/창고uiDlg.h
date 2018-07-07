
// 창고uiDlg.h : header file
//

#pragma once
#include "afxwin.h"


// C창고uiDlg dialog
class C창고uiDlg : public CDialogEx
{
// Construction
public:
	C창고uiDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UI_DIALOG };
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
	CString name;
	CString price;
	CString now_vol;
	CListBox myList;
	CString Get;	
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	int cnt;
};

class Product
{

public :
	Product(CString n)
	{
		name = n;
		price = "";
		now_vol = "";
		cnt++;
	}
	CString name;
	CString price;
	CString now_vol;
	static int cnt;
};
