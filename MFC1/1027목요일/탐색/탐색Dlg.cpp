
// Å½»öDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Å½»ö.h"
#include "Å½»öDlg.h"
#include "afxdialogex.h"
#include "io.h"
#include "conio.h"
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


// CÅ½»öDlg dialog



CÅ½»öDlg::CÅ½»öDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, search(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CÅ½»öDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, search);
	DDX_Control(pDX, IDC_LIST1, myList);
}

BEGIN_MESSAGE_MAP(CÅ½»öDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CÅ½»öDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CÅ½»öDlg message handlers

BOOL CÅ½»öDlg::OnInitDialog()
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

void CÅ½»öDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CÅ½»öDlg::OnPaint()
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
HCURSOR CÅ½»öDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int idx = 0;
void CÅ½»öDlg::OnBnClickedButton1()
{
	myList.DeleteAllItems();
	UpdateData(true);

	//LVITEM item;
	//item.mask = LVIF_TEXT;
	//item.iItem = idx;

	CString files[100];
	int cnt=0;

	CString path = search + "\*.*";
	
	_finddata_t fd;
	long handle;
	int result = 1;
	handle = _findfirst(path, &fd); //.\\*.* ´Â Æú´õ³» ¸ðµç ÆÄÀÏ Ã£´Â°Å	

	if (handle == -1)
	{
		MessageBox("no files");
		return;
	}


	while (result != -1)
	{
		files[cnt++] = fd.name;
		//item.iSubItem = 0;
		//item.pszText = (LPSTR)fd.name;
		//myList.InsertItem(&item);
		////MessageBox(fd.name);
		result = _findnext(handle, &fd);
	}

	idx++;
	_findclose(handle);
	CString str = "";
	static CImageList imageList; //tÇÔ¼ö°¡ Á¾·áµÅµµ ÀÖ¾î¾ß ÇÏ´Ï±î ½ºÅÂÆ½
	imageList.Create(48, 48, ILC_COLOR32, 2, 0);
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	for (int i = 0; i < cnt; i++)
	{
		int x = files[i].Find('.', 0);

		if (x <= 0)
		{
			myList.InsertItem(i, files[i], 0);
		}
		else
		{
			myList.InsertItem(i, files[i], 1);
		}
	}

	myList.SetImageList(&imageList, LVSIL_NORMAL);
	// TODO: Add your control notification handler code here
}
