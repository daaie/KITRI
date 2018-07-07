
// newDlg.cpp : implementation file
//

#include "stdafx.h"
#include "new.h"
#include "newDlg.h"
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


// CnewDlg dialog



CnewDlg::CnewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NEW_DIALOG, pParent)
	, myEdit(_T(""))
	, tel(_T(""))
	, address(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CnewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, myEdit);
	DDX_Control(pDX, IDC_LIST1, myList);
	DDX_Text(pDX, IDC_EDIT2, tel);
	DDX_Text(pDX, IDC_EDIT3, address);
}

BEGIN_MESSAGE_MAP(CnewDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CnewDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CnewDlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &CnewDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON3, &CnewDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CnewDlg message handlers

BOOL CnewDlg::OnInitDialog()
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

void CnewDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CnewDlg::OnPaint()
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
HCURSOR CnewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CnewDlg::OnBnClickedButton1()
{
	UpdateData(true);
	int idx=myList.AddString(myEdit);
	//myList.InsertString(3, "aaa");	//리스트 중간(3번째)에 끼워넣는거
	Member *member = new Member(myEdit, tel, address);
	myList.SetItemDataPtr(idx,member); //주소로 저장..?
	myEdit = "";
	tel = "";
	address = "";
	myEdit = "";
	UpdateData(false);
}

void CnewDlg::OnBnClickedButton2()
{
	int idx;
	idx = myList.GetCurSel();
	Member *ptr = (Member *)myList.GetItemDataPtr(idx);
	//myEdit.Format("%d", idx);
	//MessageBox(myEdit);
	myList.DeleteString(idx);
	delete ptr;			//해제해야함!!
	myEdit = "";
	tel = "";
	address = "";
	UpdateData(false);
	// TODO: Add your control notification handler code here
}


void CnewDlg::OnLbnSelchangeList1()
{
	int idx = myList.GetCurSel();
	Member *ptr = (Member *)myList.GetItemDataPtr(idx);
	myEdit = ptr->name;
	tel = ptr->tel;
	address = ptr->address;
	UpdateData(false);
	// TODO: Add your control notification handler code here
}


void CnewDlg::OnBnClickedButton3()
{

	int idx = myList.GetCurSel();
	Member *ptr = (Member *)myList.GetItemDataPtr(idx);
	UpdateData(true);
	ptr->name = myEdit;
	ptr->tel = tel;
	ptr->address = address;
	myList.DeleteString(idx);
	myList.InsertString(idx,myEdit);
	myList.SetItemDataPtr(idx, ptr);

	myEdit = "";
	tel = "";
	address = "";

	UpdateData(false);


	// TODO: Add your control notification handler code here
}
