
// 성적리스트Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "성적리스트.h"
#include "성적리스트Dlg.h"
#include "afxdialogex.h"
#include "iostream"

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


// C성적리스트Dlg dialog



C성적리스트Dlg::C성적리스트Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, group(_T(""))
	, num(_T(""))
	, name(_T(""))
	, korean(_T(""))
	, english(_T(""))
	, math(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C성적리스트Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, myTree);
	DDX_Control(pDX, IDC_LIST1, myList);
	DDX_Text(pDX, IDC_EDIT1, group);
	DDX_Text(pDX, IDC_EDIT2, num);
	DDX_Text(pDX, IDC_EDIT3, name);
	DDX_Text(pDX, IDC_EDIT4, korean);
	DDX_Text(pDX, IDC_EDIT5, english);
	DDX_Text(pDX, IDC_EDIT6, math);
}

BEGIN_MESSAGE_MAP(C성적리스트Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C성적리스트Dlg::OnBnClickedButton1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &C성적리스트Dlg::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// C성적리스트Dlg message handlers




BOOL C성적리스트Dlg::OnInitDialog()
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
	char *colname[7] = { " 반","번호","이름","국어","영어","수학","총점" };
	int width[7] = {40,50,70,70,70,70,75 };
	LVCOLUMN col;
	col.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	col.fmt = LVCFMT_CENTER;


	for (int i = 0; i < 7; i++)
	{
		col.cx = width[i];
		col.iSubItem = i;
		col.pszText = colname[i];
		myList.InsertColumn(i, &col);

	}

	book = new HTREEITEM[1];

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void C성적리스트Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C성적리스트Dlg::OnPaint()
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
HCURSOR C성적리스트Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int groupCnt = 0;
void C성적리스트Dlg::OnBnClickedButton1()
{
	UpdateData(true);

	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;

	char str[20];
	CString str2;
	C성적리스트Dlg* numTemp;

	student = new C성적리스트Dlg;

	(*student).group = group;
	(*student).num = num;
	(*student).name = name;
	(*student).korean = korean;
	(*student).english = english;
	(*student).math = math;
	(*student).tot = (atoi(korean)+atoi(english)+atoi(math));
	group += "반";

	for (int i = 0; i < groupCnt; i++)
	{
		str2 = myTree.GetItemText(book[i]);

		if (group==str2)
		{
			HTREEITEM child = myTree.GetChildItem(book[i]);
			while (child != NULL)
			{
				numTemp = (C성적리스트Dlg*)myTree.GetItemData(child);
				if (numTemp->num == num)
				{
					MessageBox("번호가 같아 바보야");
					delete student;
					return;
				}
				child = myTree.GetNextItem(child, TVGN_NEXT);
			}
			books = new HTREEITEM;
			sprintf(str, "%s", name);
			tInsert.item.pszText = (LPSTR)str;
			(*books) = myTree.InsertItem(&tInsert);
			myTree.SetItemData((*books),(DWORD_PTR)student);
			return;
		}
	}
	

	tInsert.hParent = 0;
	sprintf(str, "%s", group);
	tInsert.item.pszText = (LPSTR)str;
	book[groupCnt] = myTree.InsertItem(&tInsert);


	books = new HTREEITEM;
	tInsert.hParent = book[groupCnt++];
	sprintf(str, "%s", name);
	tInsert.item.pszText = (LPSTR)str;
	(*books) = myTree.InsertItem(&tInsert);
	myTree.SetItemData((*books), (DWORD_PTR)student);


	int length = sizeof(book) / sizeof(HTREEITEM);
	HTREEITEM *imsi = new HTREEITEM[length];
	imsi = book;
	book = new HTREEITEM[length + 1];
	book = imsi;
	delete imsi;
	// TODO: Add your control notification handler code here
}

void C성적리스트Dlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	myList.DeleteAllItems();
	UpdateData(false);
	C성적리스트Dlg* temp;

	int check = myTree.GetItemData(pNMTreeView->itemNew.hItem);
	if (check == 0)
	{
		HTREEITEM child = myTree.GetChildItem(pNMTreeView->itemNew.hItem);
		while (child != NULL)
		{
			temp = (C성적리스트Dlg*)myTree.GetItemData(child);
			printList(temp);
			child = myTree.GetNextItem(child, TVGN_NEXT);
		}
		return;
	}

	temp = (C성적리스트Dlg*)myTree.GetItemData(pNMTreeView->itemNew.hItem);
	printList(temp);


	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

void C성적리스트Dlg::printList(C성적리스트Dlg* temp)
{
	char str[10];
	int idx = 0; 
	LVITEM item;
	item.mask = LVIF_TEXT;
	item.iItem = idx;			//항목 지정.. 줄번호..

	item.iSubItem = 0;			//컬럼번호
	sprintf(str, "%s", (*temp).group);
	item.pszText = (LPSTR)str;
	myList.InsertItem(&item);

	item.iSubItem = 1;
	sprintf(str, "%s", (*temp).num);
	item.pszText = (LPSTR)str;
	myList.SetItem(&item);

	item.iSubItem = 2;
	sprintf(str, "%s", (*temp).name);
	item.pszText = (LPSTR)str;
	myList.SetItem(&item);

	item.iSubItem = 3;
	sprintf(str, "%s", (*temp).korean);
	item.pszText = (LPSTR)str;
	myList.SetItem(&item);

	item.iSubItem = 4;
	sprintf(str, "%s", (*temp).english);
	item.pszText = (LPSTR)str;
	myList.SetItem(&item);

	item.iSubItem = 5;
	sprintf(str, "%s", (*temp).math);
	item.pszText = (LPSTR)str;
	myList.SetItem(&item);

	item.iSubItem = 6;
	sprintf(str, "%d", (*temp).tot);
	item.pszText = (LPSTR)str;
	myList.SetItem(&item);

	//idx++;
	UpdateData(false);

}