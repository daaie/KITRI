//������ ���̾�α�(������â���� �߻��� �̺�Ʈ����) �ٲ���
// MFC1Dlg.h : header file
//

#pragma once


// CMFC1Dlg dialog
class CMFC1Dlg : public CDialogEx
{
// Construction
public:
	CMFC1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC1_DIALOG };
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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();	//�̺�Ʈ�� �߻��ϸ� ���⼭ ���� 1 �߻�
//	bool str;
	CString str2;		//��Ʈ�� ����
	afx_msg void OnEnChangeEdit1();
	CString myEdit;
};
