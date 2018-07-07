
// 1101Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1101.h"
#include "1101Dlg.h"
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


// CMy1101Dlg dialog



CMy1101Dlg::CMy1101Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY1101_DIALOG, pParent)
	, myEdit1(_T(""))
	, myEdit2(_T(""))
	, myEdit3(_T(""))
	, myEdit4(_T(""))
	, myEdit5(_T(""))
	, myEdit6(_T(""))
	, myEdit7(_T(""))
	, myEdit8(_T(""))
	, myEdit9(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1101Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, myEdit1);
	DDX_Text(pDX, IDC_EDIT2, myEdit2);
	DDX_Text(pDX, IDC_EDIT3, myEdit3);
	DDX_Text(pDX, IDC_EDIT4, myEdit4);
	DDX_Text(pDX, IDC_EDIT5, myEdit5);
	DDX_Text(pDX, IDC_EDIT6, myEdit6);
	DDX_Text(pDX, IDC_EDIT7, myEdit7);
	DDX_Text(pDX, IDC_EDIT8, myEdit8);
	DDX_Text(pDX, IDC_EDIT9, myEdit9);
}

BEGIN_MESSAGE_MAP(CMy1101Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy1101Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy1101Dlg message handlers

BOOL CMy1101Dlg::OnInitDialog()
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

void CMy1101Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1101Dlg::OnPaint()
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
HCURSOR CMy1101Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy1101Dlg::OnBnClickedButton1()
{
	Invalidate(true);
	CClientDC dc(this);
	CFontDialog fontdlg;
	COLORREF color;
	CFont myFont, *oldFont;
	if (fontdlg.DoModal() == IDOK)
	{
		myEdit1 = fontdlg.GetFaceName();
		myEdit2 = fontdlg.GetStyleName();
		myEdit3.Format("%d", fontdlg.GetSize() / 10);
		color = fontdlg.GetColor();
		myEdit4.Format("red : %d, Green : %d , Blue : %d", GetRValue(color), GetGValue(color), GetBValue(color));
		myEdit5.Format("%d", fontdlg.GetWeight());
		if (fontdlg.IsStrikeOut())
		{
			myEdit6 = "예";
		}
		else myEdit6 = "아니요";
		if (fontdlg.IsBold())
		{
			myEdit7 = "예";
		}
		else myEdit7 = "아니요";
		if (fontdlg.IsItalic())
		{
			myEdit8 = "예";
		}
		else myEdit8 = "아니요";
		if (fontdlg.IsUnderline())
		{
			myEdit9 = "예";
		}
		else myEdit9 = "아니요";

		myFont.CreateFont(fontdlg.GetSize() / 10, 0, 0, 0, fontdlg.GetWeight(), fontdlg.IsItalic(),
			fontdlg.IsItalic(), fontdlg.IsStrikeOut(), ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			VARIABLE_PITCH | FF_SWISS,fontdlg.GetFaceName());
		oldFont = dc.SelectObject(&myFont);
		dc.SetTextColor(color);
		dc.TextOut(10, 30, "안녕ㅎㅎㅎ");
		dc.SelectObject(oldFont);
		UpdateData(false);


	}
		
		
	// TODO: Add your control notification handler code here
}
