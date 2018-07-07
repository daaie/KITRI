
// 06Dlg.h : header file
//

#pragma once


// CMy06Dlg dialog
class CMy06Dlg : public CDialogEx
{
// Construction
public:
	CMy06Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY06_DIALOG };
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
	CString tel;
	CString address;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
