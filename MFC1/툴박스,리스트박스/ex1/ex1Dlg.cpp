
// ex1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ex1.h"
#include "ex1Dlg.h"
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


// Cex1Dlg dialog



Cex1Dlg::Cex1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EX1_DIALOG, pParent)
	, myEdit(_T(""))
	, check1(FALSE)
	, sel(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cex1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, check1);
	DDX_CBString(pDX, IDC_COMBO1, sel);
	DDX_Control(pDX, IDC_PROGRESS1, progress);
}

BEGIN_MESSAGE_MAP(Cex1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &Cex1Dlg::OnBnClickedCheck1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cex1Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &Cex1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cex1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cex1Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cex1Dlg message handlers

BOOL Cex1Dlg::OnInitDialog()		//다이얼로그 초기화
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

/*************************************************************************************/
	//프로그레스 초기화
/*************************************************************************************/

	progress.SetRange(0, 10);//범위 지정
	//한번에 증가하는 양

/*************************************************************************************/

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cex1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cex1Dlg::OnPaint()
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
HCURSOR Cex1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cex1Dlg::OnBnClickedCheck1()
{
	UpdateData(true);
	if (check1)
	{
		myEdit = "체크됐당";
	}
	else
	{
		myEdit = "체크안됐당";
	}

	UpdateData(false);
	// TODO: Add your control notification handler code here
}



void Cex1Dlg::OnCbnSelchangeCombo1()
{
	UpdateData(true);
	MessageBox(sel);
	// TODO: Add your control notification handler code here
}


void Cex1Dlg::OnBnClickedButton1()
{
	UpdateData(true);
	MessageBox(sel);
	// TODO: Add your control notification handler code here
}


void Cex1Dlg::OnBnClickedButton2()
{
	progress.SetStep(1);
	progress.StepIt(); //스텝올리는 함수

	// TODO: Add your control notification handler code here
}


void Cex1Dlg::OnBnClickedButton3()
{
	progress.SetStep(-1);
	progress.StepIt(); //스텝올리는 함수
	// TODO: Add your control notification handler code here
}
