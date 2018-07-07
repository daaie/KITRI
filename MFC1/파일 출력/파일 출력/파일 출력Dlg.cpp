
// 파일 출력Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "파일 출력.h"
#include "파일 출력Dlg.h"
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


// C파일출력Dlg dialog



C파일출력Dlg::C파일출력Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, myEdit1(_T(""))
	, myEdit2(_T(""))
	, myEdit3(_T(""))
	, myEdit4(_T(""))
	, myEdit5(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C파일출력Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, myEdit1);
	DDX_Text(pDX, IDC_EDIT2, myEdit2);
	DDX_Text(pDX, IDC_EDIT3, myEdit3);
	DDX_Text(pDX, IDC_EDIT4, myEdit4);
	DDX_Text(pDX, IDC_EDIT5, myEdit5);
}

BEGIN_MESSAGE_MAP(C파일출력Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C파일출력Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C파일출력Dlg message handlers

BOOL C파일출력Dlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void C파일출력Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C파일출력Dlg::OnPaint()
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
HCURSOR C파일출력Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C파일출력Dlg::OnBnClickedButton1()
{
	BOOL flag = false;
	CFileDialog dlgOpen(TRUE, "txt", NULL, OFN_FILEMUSTEXIST, "메모장(*.txt)|*.txt|모든파일(*.*)|*.*||", NULL);
	//탐색기 객체 (오픈,확장자,파일이름,존재하는ㄴ파일만 읽음,)
	if (dlgOpen.DoModal() == IDOK)//do a모달// 모달은 부모나 형제를 사용할 수 없음..모달리스는 부모나 형제 팝업과 같이 사용

	{
		myEdit1 = dlgOpen.GetPathName();
		myEdit2 = dlgOpen.GetFileName();
		myEdit3 = dlgOpen.GetFileTitle();
		myEdit4 = dlgOpen.GetFileExt();
		flag = dlgOpen.GetReadOnlyPref();//true or false
		if (flag)
		{
			myEdit5 = "읽기전용";
		}
		else
		{
			myEdit5 = "읽기전용아님";
		}
		UpdateData(false);
	}
	else
	{
		MessageBox("잘못선택");
	}
	// TODO: Add your control notification handler code here
}
