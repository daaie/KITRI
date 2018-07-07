
// 메모장Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "메모장.h"
#include "메모장Dlg.h"
#include "afxdialogex.h"
#include "fstream"
#include "iostream"
#include "io.h"
#include "conio.h"
using namespace std;
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


// C메모장Dlg dialog



C메모장Dlg::C메모장Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, search(_T(""))
	, text(_T(""))
	, save(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C메모장Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, search);
	DDX_Text(pDX, IDC_EDIT2, text);
	DDX_Text(pDX, IDC_EDIT3, save);
	DDX_Control(pDX, IDC_LIST1, myList);
}

BEGIN_MESSAGE_MAP(C메모장Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &C메모장Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &C메모장Dlg::OnBnClickedButton1)

	ON_BN_CLICKED(IDC_BUTTON2, &C메모장Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C메모장Dlg message handlers

BOOL C메모장Dlg::OnInitDialog()
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
	imageList.Create(48, 48, ILC_COLOR32, 2, 0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void C메모장Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C메모장Dlg::OnPaint()
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
HCURSOR C메모장Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void C메모장Dlg::OnBnClickedButton3()
{
	UpdateData(true);

	//CFile file;
	//CFileException ex;
	//file.Open(save+".dat", CFile::modeCreate | CFile::modeReadWrite, &ex);
	//file.Write(text, text.GetLength());
	//file.Close();

	save += ".txt";
	ofstream ofs(save);
	ofs << text << endl;
	ofs.close();
	text = "";
	save = "";
	UpdateData(false);
	// TODO: Add your control notification handler code here
}


void C메모장Dlg::OnBnClickedButton1()
{
	myList.DeleteAllItems();

	search = "";
	UpdateData(false);

	char now_path[100];
	UpdateData(true);

	CString path = search + "\*.*";
	
	_finddata_t fd;
	long handle;
	int result = 1;
	handle = _findfirst(path, &fd);
	
	GetCurrentDirectory(_MAX_PATH, now_path);
	search = now_path;
	UpdateData(false);

	if (handle == -1)
	{
		MessageBox("no files");
		return;
	}

	while (result != -1)
	{
		files[cnt++] = fd.name;
		result = _findnext(handle, &fd);
	}
	_findclose(handle);

	
	
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


void C메모장Dlg::OnBnClickedButton2()
{
	CString str;
	char *pData;
	int length;
	int idx = myList.GetSelectionMark();

	str = myList.GetItemText(idx, 0);

//	CFile file;
//	CFileException ex;
//	file.Open(str, CFile::modeRead, &ex);

	ifstream ifs(str);
//	ifs.seekg(0, ios::end);
	length = ifs.tellg();
//	ifs.seekg(0, ios::beg);
	pData = new char[length];

	ifs >> pData;
	text = pData;
	UpdateData(false);

//	file.Read(pData, text.GetLength());
//	file.Close();

}
