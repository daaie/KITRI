
// 1027�����Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1027�����.h"
#include "1027�����Dlg.h"
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


// CMy1027�����Dlg dialog



CMy1027�����Dlg::CMy1027�����Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY1027_DIALOG, pParent)
	, name(_T(""))
	, email(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1027�����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, myList);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, email);
}

BEGIN_MESSAGE_MAP(CMy1027�����Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON1, &CMy1027�����Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy1027�����Dlg message handlers

BOOL CMy1027�����Dlg::OnInitDialog()			//���� ���̾�α� �ʱ�ȭ
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

// TODO: Add extra initialization here------------------------------------------------//


	char *colName[2] = { "name","email" };		//�÷��� Ÿ��Ʋ
	int width[2] = {65, 180};					//�÷��� ũ��		
	LVCOLUMN col;
	col.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH; //����,�׸�,�ؽ�Ʈ,ũ��
	col.fmt = LVCFMT_LEFT;										 //������ ���� ����
	for (int i = 0; i < 2; i++)
	{
		col.pszText = colName[i];
		col.iSubItem = i;		//�÷��ε���
		col.cx = width[i];
		myList.InsertColumn(i, &col);
	}
//--------------------------------------------------------------------------------------//



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1027�����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1027�����Dlg::OnPaint()
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
HCURSOR CMy1027�����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy1027�����Dlg::OnBnClickedButton1()
{
// TODO: Add your control notification handler code here----------------------------//
//----------------------------------------------------------------------------------//
	// int idx = 0;
	//char str[50];	
	//UpdateData(true);
	//LVITEM item;
	//item.mask = LVIF_TEXT;	    //�����ҰŴ� �ؽ�Ʈ �ۿ�������
	//item.iItem = idx;			//�׸� ����.. �ٹ�ȣ..

	//item.iSubItem = 0;			//�÷���ȣ
	//sprintf(str, "%s", name);	//��������Ʈ���� ���� ����!! ��Ʈ������ ĳ����
	//item.pszText = (LPSTR)str;
	//myList.InsertItem(&item);	//0��° ��ĭ ���� �ѹ��� �ؾ���.

	//item.iSubItem = 1;
	//sprintf(str, "%s", email);
	//item.pszText = (LPSTR)str;
	//myList.SetItem(&item);	//����� �� ����.

	//name = "";
	//email = "";
	//idx++;
	//UpdateData(false);
}
