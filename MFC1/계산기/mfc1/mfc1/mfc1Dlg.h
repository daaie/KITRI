
// mfc1Dlg.h : 헤더 파일
//

#pragma once


// Cmfc1Dlg 대화 상자
class Cmfc1Dlg : public CDialogEx
{
// 생성입니다.
public:
	Cmfc1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	void Parsing(CString str);
	CString myEdit;
	CString allEdit;
	afx_msg void OnBnClickedButton13();	//0
	afx_msg void OnBnClickedButton9();	//1
	afx_msg void OnBnClickedButton10();	//2
	afx_msg void OnBnClickedButton11();	//3
	afx_msg void OnBnClickedButton5();	//4
	afx_msg void OnBnClickedButton6();	//5
	afx_msg void OnBnClickedButton7();	//6
	afx_msg void OnBnClickedButton1();	//7
	afx_msg void OnBnClickedButton2();	//8	
	afx_msg void OnBnClickedButton3();	//9
	afx_msg void OnBnClickedButton14(); //c
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit2();

	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton15();
};
