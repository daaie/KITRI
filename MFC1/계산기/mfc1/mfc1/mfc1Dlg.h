
// mfc1Dlg.h : ��� ����
//

#pragma once


// Cmfc1Dlg ��ȭ ����
class Cmfc1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Cmfc1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
