
// 1028Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1028.h"
#include "1028Dlg.h"
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


// CMy1028Dlg dialog



CMy1028Dlg::CMy1028Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY1028_DIALOG, pParent)
	, myEdit(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1028Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, myTree);
	DDX_Text(pDX, IDC_EDIT1, myEdit);
	DDX_Control(pDX, IDC_SPIN2, gg);
}

BEGIN_MESSAGE_MAP(CMy1028Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy1028Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy1028Dlg message handlers

BOOL CMy1028Dlg::OnInitDialog()
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
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//mySpin.SetRange(0, 100);
	gg.SetRange(0, 100);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1028Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1028Dlg::OnPaint()
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
HCURSOR CMy1028Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy1028Dlg::OnBnClickedButton1()
{
	TVINSERTSTRUCT tInsert;
	HTREEITEM food;								//항목 객체
	HTREEITEM foodSort;							//항목 객체	
	tInsert.hParent = 0;				//트리의 부모(루트)
	tInsert.hInsertAfter = TVI_SORT;	//TVI_first / TVI_Last 넣을수있당
	tInsert.item.mask = TVIF_TEXT;		//

	tInsert.item.pszText = "음식";		//최고 항목
	food = myTree.InsertItem(&tInsert);

	tInsert.hParent = food;
	tInsert.item.pszText = "느끼한 음식";
	foodSort = myTree.InsertItem(&tInsert);

	tInsert.hParent = foodSort;
	tInsert.item.pszText = "돈까스";
	myTree.InsertItem(&tInsert);


	tInsert.hParent = foodSort;
	tInsert.item.pszText = "오므라이스";
	myTree.InsertItem(&tInsert);

	tInsert.hParent = foodSort;
	tInsert.item.pszText = "피자";
	myTree.InsertItem(&tInsert);



	tInsert.hParent = food;
	tInsert.item.pszText = "매운음식";
	foodSort = myTree.InsertItem(&tInsert);		//느끼한 음식과 같은 레벨

	tInsert.hParent = foodSort;
	tInsert.item.pszText = "떡볶이";
	myTree.InsertItem(&tInsert);

	tInsert.hParent = foodSort;
	tInsert.item.pszText = "불닭";
	myTree.InsertItem(&tInsert);

	tInsert.hParent = foodSort;
	tInsert.item.pszText = "고추장";
	myTree.InsertItem(&tInsert);
		// TODO: Add your control notification handler code here
}

