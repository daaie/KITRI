
// 02Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "02.h"
#include "02Dlg.h"
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


// CMy02Dlg dialog



CMy02Dlg::CMy02Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY02_DIALOG, pParent)
	, myEdit(_T(""))
	, timer(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy02Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, myEdit);
	DDX_Text(pDX, IDC_EDIT2, timer);
}

BEGIN_MESSAGE_MAP(CMy02Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy02Dlg::OnBnClickedButton1)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON2, &CMy02Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy02Dlg::OnBnClickedButton3)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMy02Dlg message handlers

BOOL CMy02Dlg::OnInitDialog()
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

void CMy02Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy02Dlg::OnPaint() //윈도 dc 화면 초기화
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
		dc.DrawIcon(x, y, m_hIcon);
	}

	else
	{
		CDialogEx::OnPaint();
	}
	CClientDC dc(this);	//화면에 그래픽 출력할 때 다이얼로그 전체에 대한 객체 선언해 놓고  
	dc.SetTextColor(RGB(255, 0, 0));
	dc.TextOut(10, 30, "빨간 텍스트");
	dc.SetBkColor(RGB(0, 0, 255));
	dc.TextOut(10, 50, "파란 텍스트"); //텍스트위치 x,y,텍스트
	dc.SetBkMode(TRANSPARENT);
	dc.TextOutA(10, 70, "배경이 투명한 텍스트");
	// Draw the icon

}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy02Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy02Dlg::OnBnClickedButton1()
{

		// TODO: Add your control notification handler code here
}


void CMy02Dlg::OnLButtonDown(UINT nFlags, CPoint point) //이벤트에 대한 add handler , 코드추가
{
	myEdit.Format("x:%d , y:%d 마우스 왼쪽 버튼 클릭",point.x, point.y);
	UpdateData(false);
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMy02Dlg::OnBnClickedButton2()
{
	SetTimer(1, 100, NULL); //id, 0.1초, 함수명 (NULL일 경우 OnTimer()임)

	// TODO: Add your control notification handler code here
}


void CMy02Dlg::OnBnClickedButton3()
{
	KillTimer(1); //타이머 아이디를 1번으로 주었으니까 1번 kill
	// TODO: Add your control notification handler code here
}


void CMy02Dlg::OnTimer(UINT_PTR nIDEvent)
{
	static int i = 0;
	i++;
	if (i > 10)
	{
		i = 0;
	}
	timer.Format("%d", i);
	UpdateData(false);

	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnTimer(nIDEvent);
}
