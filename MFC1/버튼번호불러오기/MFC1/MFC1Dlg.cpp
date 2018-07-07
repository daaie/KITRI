
// MFC1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC1.h"
#include "MFC1Dlg.h"
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


// CMFC1Dlg dialog



CMFC1Dlg::CMFC1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC1_DIALOG, pParent)
//	, str(false)
	, str2(_T("����"))
	, myEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BUTTON1, str2);		
	//�����͸� �ְ�޴°� �ڵ���...view�� �Է��� �޾ƿ��°� ����..
	DDX_Text(pDX, IDC_EDIT1, myEdit);
}

BEGIN_MESSAGE_MAP(CMFC1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC1Dlg::OnBnClickedButton3)	//Ŭ������ �̺�Ʈ�� �߻��ϸ� ���⼭�� ���� 2 �����Ҷ� ���������
	ON_EN_CHANGE(IDC_EDIT1, &CMFC1Dlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CMFC1Dlg message handlers

BOOL CMFC1Dlg::OnInitDialog()
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

void CMFC1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC1Dlg::OnPaint()
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
HCURSOR CMFC1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC1Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString s;
	GetDlgItem(IDC_BUTTON1)->GetWindowText(s);			//getdlgitem ��ư�� ���̵� ���� ��ü�� ��ȯ.(��ư ������Ƽ ���� ����)
	GetDlgItem(IDC_BUTTON1)->SetWindowText(str2);		//getwindowtext ��ư �����⿡ �ִ� �� ����
	str2 = s;											//setwindowtext	 ��ư �����⿡ �ִ� �� ����
	MessageBox(_T("btn1 clicked"));						//���â!! _T��ũ�η� ���μ� ����ƽ ���ڿ��� �ٲ���
}


void CMFC1Dlg::OnBnClickedButton2()
{
	myEdit = "�ȳ��ϼ���";
	UpdateData(false);		//false���ϸ� ������ true�� �ϸ� �ҷ���
	// TODO: Add your control notification handler code here
	MessageBox(_T("btn2 clicked"));
}


void CMFC1Dlg::OnBnClickedButton3()
{
	UpdateData(true);
	// TODO: Add your control notification handler code here
	MessageBox(myEdit);
}


void CMFC1Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
