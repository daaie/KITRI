
// mfc1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "mfc1.h"
#include "mfc1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// Cmfc1Dlg 대화 상자



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


// Cmfc1Dlg 메시지 처리기

BOOL Cmfc1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cmfc1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cmfc1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void Cmfc1Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void Cmfc1Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void Cmfc1Dlg::OnBnClickedButton13()
{
	CString num;
	GetDlgItem(IDC_BUTTON13)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void Cmfc1Dlg::OnBnClickedButton9()
{
	CString num;
	GetDlgItem(IDC_BUTTON9)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmfc1Dlg::OnBnClickedButton10()
{
	CString num;
	GetDlgItem(IDC_BUTTON10)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmfc1Dlg::OnBnClickedButton11()
{
	CString num;
	GetDlgItem(IDC_BUTTON11)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmfc1Dlg::OnBnClickedButton5()
{
	CString num;
	GetDlgItem(IDC_BUTTON5)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmfc1Dlg::OnBnClickedButton6()
{
	CString num;
	GetDlgItem(IDC_BUTTON6)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmfc1Dlg::OnBnClickedButton7()
{
	CString num;
	GetDlgItem(IDC_BUTTON7)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmfc1Dlg::OnBnClickedButton1()
{
	CString num;
	GetDlgItem(IDC_BUTTON1)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmfc1Dlg::OnBnClickedButton2()
{
	CString num;
	GetDlgItem(IDC_BUTTON2)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Cmfc1Dlg::OnBnClickedButton3()
{
	CString num;
	GetDlgItem(IDC_BUTTON3)->GetWindowText(num);
	myEdit += num;
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void Cmfc1Dlg::OnBnClickedButton14()
{
	myEdit = "";
	allEdit = "";
	UpdateData(false);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}