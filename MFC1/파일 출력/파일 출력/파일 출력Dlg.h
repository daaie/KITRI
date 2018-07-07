
// 파일 출력Dlg.h : header file
//

#pragma once


// C파일출력Dlg dialog
class C파일출력Dlg : public CDialogEx
{
// Construction
public:
	C파일출력Dlg(CWnd* pParent = NULL);	// standard constructor

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
	CString myEdit1;
	CString myEdit2;
	CString myEdit3;
	CString myEdit4;
	CString myEdit5;
	afx_msg void OnBnClickedButton1();
};
