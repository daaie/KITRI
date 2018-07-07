
// ÇÏÁ¨ÀåDlg.h : header file
//

#pragma once


// CÇÏÁ¨ÀåDlg dialog
class CÇÏÁ¨ÀåDlg : public CDialogEx
{
// Construction
public:
	CÇÏÁ¨ÀåDlg(CWnd* pParent = NULL);	// standard constructor

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
	CPoint point;
	int state;
	int width;
	afx_msg void circle();
	afx_msg void rec();
	afx_msg void line();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void On32776();
	afx_msg void line2();
	afx_msg void line3();
	afx_msg void line4();
	afx_msg void On32780();
	COLORREF color;
	afx_msg void On32775();
};
