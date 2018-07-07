
// ÇÏÁ¨ÀåDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ÇÏÁ¨Àå.h"
#include "ÇÏÁ¨ÀåDlg.h"
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
public:
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


// CÇÏÁ¨ÀåDlg dialog



CÇÏÁ¨ÀåDlg::CÇÏÁ¨ÀåDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CÇÏÁ¨ÀåDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CÇÏÁ¨ÀåDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CÇÏÁ¨ÀåDlg::circle)
	ON_COMMAND(ID_32772, &CÇÏÁ¨ÀåDlg::rec)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32774, &CÇÏÁ¨ÀåDlg::line)
	ON_COMMAND(ID_32776, &CÇÏÁ¨ÀåDlg::On32776)
	ON_COMMAND(ID_32777, &CÇÏÁ¨ÀåDlg::line2)
	ON_COMMAND(ID_32778, &CÇÏÁ¨ÀåDlg::line3)
	ON_COMMAND(ID_32779, &CÇÏÁ¨ÀåDlg::line4)
	ON_COMMAND(ID_32780, &CÇÏÁ¨ÀåDlg::On32780)
	ON_COMMAND(ID_32775, &CÇÏÁ¨ÀåDlg::On32775)
END_MESSAGE_MAP()


// CÇÏÁ¨ÀåDlg message handlers

BOOL CÇÏÁ¨ÀåDlg::OnInitDialog()
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
	width = 1;
//	color = RGB(255,255,255);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CÇÏÁ¨ÀåDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CÇÏÁ¨ÀåDlg::OnPaint()
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

	CClientDC dc(this);
	CBrush myBrush(color);
	CBrush *oldBrush = dc.SelectObject(&myBrush);
	dc.Rectangle(0, 0, 10, 10);
	dc.SelectObject(oldBrush);
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CÇÏÁ¨ÀåDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CÇÏÁ¨ÀåDlg::circle()
{
	state = 1;
	// TODO: Add your command handler code here
}


void CÇÏÁ¨ÀåDlg::rec()
{
	state = 2;
	// TODO: Add your command handler code here
}


void CÇÏÁ¨ÀåDlg::line()
{
	state = 3;
	// TODO: Add your command handler code here
}

void CÇÏÁ¨ÀåDlg::On32775()
{
	state = 4;
	// TODO: Add your command handler code here
}

void CÇÏÁ¨ÀåDlg::On32776()
{
	width = 1;
	// TODO: Add your command handler code here
}


void CÇÏÁ¨ÀåDlg::line2()
{
	width = 2;
	// TODO: Add your command handler code here
}


void CÇÏÁ¨ÀåDlg::line3()
{
	width = 6;
	// TODO: Add your command handler code here
}


void CÇÏÁ¨ÀåDlg::line4()
{
	width = 8;
	// TODO: Add your command handler code here
}

void CÇÏÁ¨ÀåDlg::On32780()
{
	CColorDialog dlgcolor;
	if (dlgcolor.DoModal() == IDOK)
	{
		color = dlgcolor.GetColor();
		UpdateData(false);
		Invalidate(true);
	}
	// TODO: Add your command handler code here
}


void CÇÏÁ¨ÀåDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	this->point = point;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CÇÏÁ¨ÀåDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	dc.MoveTo(this->point);
	CPen dash;
	CPen myPen(PS_SOLID, width, color);;
	CPen *oldPen = dc.SelectObject(&myPen);
	CBrush myBrush(color);
	CBrush *oldBrush = dc.SelectObject(&myBrush);

	switch (state)
	{
	case 1:
		dc.Ellipse(this->point.x, this->point.y, point.x, point.y);
		break;
	case 2:
		dc.Rectangle(this->point.x, this->point.y, point.x, point.y);
		break;
	case 3:
		dc.LineTo(point);
		break;
	default : break;
	}

	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);

	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnLButtonUp(nFlags, point);
}

