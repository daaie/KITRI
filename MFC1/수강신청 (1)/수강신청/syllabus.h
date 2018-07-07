#pragma once


// syllabus dialog

class syllabus : public CPropertyPage
{
	DECLARE_DYNAMIC(syllabus)

public:
	syllabus();
	virtual ~syllabus();
	syllabus(CString subName);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString text;
	int cnt = 0;
	CString fileName;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
