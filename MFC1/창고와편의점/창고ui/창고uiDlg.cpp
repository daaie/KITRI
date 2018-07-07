
// 창고uiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "창고ui.h"
#include "창고uiDlg.h"
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


// C창고uiDlg dialog



C창고uiDlg::C창고uiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_UI_DIALOG, pParent)
	, name(_T(""))
	, price(_T(""))
	, now_vol(_T(""))
	, Get(_T(""))
	, cnt(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C창고uiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, price);
	DDX_Text(pDX, IDC_EDIT4, now_vol);
	DDX_Control(pDX, IDC_LIST1, myList);
	DDX_Text(pDX, IDC_EDIT6, Get);
	DDX_Text(pDX, IDC_EDIT3, cnt);
}

BEGIN_MESSAGE_MAP(C창고uiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &C창고uiDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &C창고uiDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C창고uiDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C창고uiDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C창고uiDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &C창고uiDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// C창고uiDlg message handlers
int Product::cnt=0;
BOOL C창고uiDlg::OnInitDialog()
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

void C창고uiDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C창고uiDlg::OnPaint()
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
HCURSOR C창고uiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void C창고uiDlg::OnLbnSelchangeList1()
{
	int idx = myList.GetCurSel();
	Product *imsi = (Product *)myList.GetItemDataPtr(idx);
	name = imsi->name;
	price = imsi->price;
	now_vol = imsi->now_vol;
	cnt = imsi->cnt;
	UpdateData(false);
	// TODO: Add your control notification handler code here
}


void C창고uiDlg::OnBnClickedButton1()
{
	UpdateData(true);
	int idx = myList.AddString(name);
	Product *product = new Product(name);
	myList.SetItemDataPtr(idx, product);
	product->price = price;
	product->now_vol = now_vol;
	price = "";
	name = "";
	now_vol = "";
	UpdateData(false);
	// TODO: Add your control notification handler code here
}


void C창고uiDlg::OnBnClickedButton2()
{
	int idx = myList.GetCurSel();
	Product *imsi = (Product *) myList.GetItemDataPtr(idx);
	myList.DeleteString(idx);
	delete imsi;
	price = "";
	name = "";
	now_vol = "";
	UpdateData(false);
	// TODO: Add your control notification handler code here
}



void C창고uiDlg::OnBnClickedButton3()
{
	UpdateData(true);
	int idx = myList.GetCurSel();
	Product *imsi = (Product *)myList.GetItemDataPtr(idx);
	imsi->name = name;
	imsi->price = price;
	imsi->now_vol = now_vol;
	myList.DeleteString(idx);
	myList.InsertString(idx, name);
	myList.SetItemDataPtr(idx, imsi);
	price = "";
	name = "";
	now_vol = "";
	UpdateData(false);
	// TODO: Add your control notification handler code here
}


void C창고uiDlg::OnBnClickedButton4()
{
	int imsi_get;
	int idx = myList.GetCurSel();
	Product *imsi = (Product *)myList.GetItemDataPtr(idx);

	UpdateData(true);

	imsi_get=atoi(imsi->now_vol);
	imsi_get += atoi(Get);
	imsi->now_vol.Format("%d", imsi_get);

	name = imsi->name;
	price = imsi->price;
	now_vol = imsi->now_vol;
	UpdateData(false);
	// TODO: Add your control notification handler code here
}


void C창고uiDlg::OnBnClickedButton5()
{
	int imsi_get;
	int idx = myList.GetCurSel();
	Product *imsi = (Product *)myList.GetItemDataPtr(idx);

	UpdateData(true);

	imsi_get = atoi(imsi->now_vol);
	if (imsi_get - atoi(Get) >= 0)
	{
		imsi_get -= atoi(Get);
	}
	else
	{
		MessageBox("수량이 모자라당..");
		return;
	}
	
	imsi->now_vol.Format("%d", imsi_get);

	name = imsi->name;
	price = imsi->price;
	now_vol = imsi->now_vol;
	UpdateData(false);
	// TODO: Add your control notification handler code here
}
