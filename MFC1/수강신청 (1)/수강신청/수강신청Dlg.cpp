
// ������ûDlg.cpp : implementation file
//

#include "stdafx.h"
#include "������û.h"
#include "������ûDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

														// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C������ûDlg dialog



C������ûDlg::C������ûDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, mId(_T(""))
	, mName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C������ûDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, loginCheck);
	DDX_Text(pDX, IDC_EDIT2, mId);
	DDX_Text(pDX, IDC_EDIT1, mName);
}

BEGIN_MESSAGE_MAP(C������ûDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C������ûDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C������ûDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C������ûDlg message handlers

BOOL C������ûDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here
	subject = new CSubject;
	subjectinfo = new CSubjectInfo;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void C������ûDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void C������ûDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR C������ûDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C������ûDlg::OnBnClickedButton1()
{
	UpdateData(true);

	CString temp;
	char infotemp[20] = {0};
	CString info1;
	CString info2;
	int idx = loginCheck.GetCurSel();
	loginCheck.GetLBText(idx, temp);

	if (temp == "Personnel")
	{
		CFile file;
		file.Open("������ȸ������.txt", CFile::modeRead);
		file.Read(infotemp, 10);
		info1 = infotemp;
		file.Read(infotemp, 10);
		info2 = infotemp;
		info1=info1.Trim();
		info2=info2.Trim();

		if (mId == info1&&mName == info2)
		{
			CPersonnelPage Per;
			Per.DoModal();
		}
		else
		{
			MessageBox("�й��� �̸��� Ȯ���Ͽ� �ּ���");
			return;
		}

	}
	else if (temp == "Professor")
	{
		if (subject->head == NULL)
		{
			MessageBox("������û �Ⱓ�� �ƴմϴ�");
			return;
		}

		CFile file;
		file.Open("����ȸ������.txt", CFile::modeRead);
		file.Read(infotemp, 10);
		info1 = infotemp;
		file.Read(infotemp, 10);
		info2 = infotemp;
		info1 = info1.Trim();
		info2 = info2.Trim();

		if (mId == info1&&mName == info2)
		{
			CProfessorPage prof(mName);
			prof.DoModal();
		}
		else
		{
			MessageBox("�й��� �̸��� Ȯ���Ͽ� �ּ���");
			return;
		}
	}
	else if (temp == "Student")
	{
		if (subject->head == NULL)
		{
			MessageBox("������û �Ⱓ�� �ƴմϴ�");
			return;
		}
		CFile file;
		file.Open("�л�ȸ������.txt", CFile::modeRead);
		file.Read(infotemp, 10);
		info1 = infotemp;
		file.Read(infotemp, 10);
		info2 = infotemp;
		info1 = info1.Trim();
		info2 = info2.Trim();

		if (mId == info1&&mName == info2)
		{
			CStudentPage stu;
			stu.DoModal();
		}
		else
		{
			MessageBox("�й��� �̸��� Ȯ���Ͽ� �ּ���");
			return;
		}
	}

	// TODO: Add your control notification handler code here
}


void C������ûDlg::OnBnClickedButton2()
{
	log.DoModal();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
