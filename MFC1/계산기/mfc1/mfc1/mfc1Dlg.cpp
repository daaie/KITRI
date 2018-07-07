
// mfc1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "mfc1.h"
#include "mfc1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// Cmfc1Dlg ��ȭ ����



Cmfc1Dlg::Cmfc1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC1_DIALOG, pParent)
	, myEdit(_T(""))
	, allEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, myEdit);
	DDX_Text(pDX, IDC_EDIT2, allEdit);
}

BEGIN_MESSAGE_MAP(Cmfc1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON13, &Cmfc1Dlg::OnBnClickedButton13)
	ON_EN_CHANGE(IDC_EDIT1, &Cmfc1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON9, &Cmfc1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Cmfc1Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &Cmfc1Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON5, &Cmfc1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cmfc1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cmfc1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmfc1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmfc1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cmfc1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON14, &Cmfc1Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON4, &Cmfc1Dlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT2, &Cmfc1Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON8, &Cmfc1Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON12, &Cmfc1Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON16, &Cmfc1Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON15, &Cmfc1Dlg::OnBnClickedButton15)
END_MESSAGE_MAP()


// Cmfc1Dlg �޽��� ó����

BOOL Cmfc1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Cmfc1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Cmfc1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Cmfc1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void Cmfc1Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void Cmfc1Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void Cmfc1Dlg::OnBnClickedButton13()
{
	CString num;
	GetDlgItem(IDC_BUTTON13)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void Cmfc1Dlg::OnBnClickedButton9()
{
	CString num;
	GetDlgItem(IDC_BUTTON9)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton10()
{
	CString num;
	GetDlgItem(IDC_BUTTON10)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton11()
{
	CString num;
	GetDlgItem(IDC_BUTTON11)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton5()
{
	CString num;
	GetDlgItem(IDC_BUTTON5)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton6()
{
	CString num;
	GetDlgItem(IDC_BUTTON6)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton7()
{
	CString num;
	GetDlgItem(IDC_BUTTON7)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton1()
{
	CString num;
	GetDlgItem(IDC_BUTTON1)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton2()
{
	CString num;
	GetDlgItem(IDC_BUTTON2)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton3()
{
	CString num;
	GetDlgItem(IDC_BUTTON3)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void Cmfc1Dlg::OnBnClickedButton14()
{
	myEdit = "";
	allEdit = "";
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
int cnt=0;
void Cmfc1Dlg::OnBnClickedButton4()
{
	int edit;
	UpdateData(true);
	edit = atoi(myEdit);
	allEdit += myEdit + "+";
	myEdit = "";
	UpdateData(false);
	cnt++;
// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void Cmfc1Dlg::OnBnClickedButton8()
{
	int edit;
	UpdateData(true);
	edit = atoi(myEdit);
	allEdit += myEdit + "-";
	myEdit = "";
	UpdateData(false);
	cnt++;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton12()
{
	int edit;
	UpdateData(true);
	edit = atoi(myEdit);
	allEdit += myEdit + "x";
	myEdit = "";
	UpdateData(false);
	cnt++;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cmfc1Dlg::OnBnClickedButton16()
{
	int edit;
	UpdateData(true);
	edit = atoi(myEdit);
	allEdit += myEdit + "/";
	myEdit = "";
	UpdateData(false);
	cnt++;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void Cmfc1Dlg::OnBnClickedButton15()
{
	CString equation;
	int edit;
	cnt++;
	UpdateData(true);
	edit = atoi(myEdit);
	allEdit += myEdit;
	myEdit = "";
	UpdateData(false);

	UpdateData(true);
	equation=allEdit;

	CString *temp1 = new CString[cnt];
	char *temp2 = new char[cnt];

	int j = 0;

	for (int i = 0; i < (signed int)strlen(equation); i++)
	{
		if(equation.GetAt(i)>='0'&&equation.GetAt(i)<='9')
		{
			temp1[j] += equation.GetAt(i);
		}
		else 
		{
			temp2[j] = equation.GetAt(i);
			j++;
		}
	}


	int imsiResult;


	for (int i=0;i<cnt;i++){

		if(temp2[i]=='x')
		{
			imsiResult = atoi(temp1[i]) * atoi(temp1[i + 1]);
			temp1[i].Format ("%d",imsiResult);
			temp1[i + 1].Format ("%d",imsiResult);
		}
	}

	for (int i = 0; i<cnt; i++) {

		if (temp2[i] == '/')
		{
			imsiResult = atoi(temp1[i]) / atoi(temp1[i + 1]);
			temp1[i].Format("%d", imsiResult);
			temp1[i + 1].Format("%d", imsiResult);
		}
	}


	for (int i = 0; i<cnt; i++) {

		if (temp2[i] == '+')
		{
			imsiResult = atoi(temp1[i]) + atoi(temp1[i + 1]);
			temp1[i].Format("%d", imsiResult);
			temp1[i + 1].Format("%d", imsiResult);
		}
	}
	for (int i = 0; i<cnt; i++) {

		if (temp2[i] == '-')
		{
			imsiResult = atoi(temp1[i]) - atoi(temp1[i + 1]);
			temp1[i].Format("%d", imsiResult);
			temp1[i + 1].Format("%d", imsiResult);
		}
	}
	myEdit.Format("%d", imsiResult);
	UpdateData(false);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}