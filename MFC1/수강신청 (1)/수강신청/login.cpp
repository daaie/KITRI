// login.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "수강신청.h"
#include "login.h"
#include "afxdialogex.h"
#include "afx.h"
#include "afxwin.h"
#include "afxdb.h"

// login 대화 상자입니다.

IMPLEMENT_DYNAMIC(login, CPropertyPage)

login::login()
	: CPropertyPage(IDD_DIALOG1)
	, Id(_T(""))
	, Name(_T(""))
{

}

login::~login()
{
}

void login::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Id);
	DDX_Text(pDX, IDC_EDIT2, Name);
	DDX_Control(pDX, IDC_RADIO1, Btper);
	DDX_Control(pDX, IDC_RADIO2, BtProf);
	DDX_Control(pDX, IDC_RADIO3, BtStu);
}


BEGIN_MESSAGE_MAP(login, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &login::OnBnClickedButton1)
END_MESSAGE_MAP()


BOOL login::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	file1.Open("교직원회원정보.txt", CFile::modeCreate | CFile::modeReadWrite);
	file1.Close();
	file2.Open("교수회원정보.txt", CFile::modeCreate | CFile::modeReadWrite);
	file2.Close();
	file3.Open("학생회원정보.txt", CFile::modeCreate | CFile::modeReadWrite);
	file3.Close();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
// login 메시지 처리기입니다.


void login::OnBnClickedButton1()
{
	UpdateData(true);
	int data_size;
	CString idinfo;
	char info[1000];
	CFileException ex;
	if (BtStu.GetCheck()==BST_CHECKED)
	{
		file3.Open("학생회원정보.txt", CFile::modeReadWrite,&ex);
		idinfo.Format("%10s%10s\n", Id, Name);
 		data_size = (int)strlen(idinfo);
		file3.Write(idinfo, data_size);
		file3.Close();
	}
	else if(BtProf.GetCheck() == BST_CHECKED)
	{
		file2.Open("교수회원정보.txt", CFile::modeReadWrite);
		idinfo.Format("%10s%10s\n", Id, Name);
		data_size = (int)strlen(idinfo);
		file2.Write(idinfo, data_size);
		file2.Close();
	}
	else if (Btper.GetCheck() == BST_CHECKED)
	{
		file1.Open("교직원회원정보.txt", CFile::modeReadWrite);
		idinfo.Format("%10s%10s\n", Id, Name);
		data_size = (int)strlen(idinfo);
		file1.Write(idinfo, data_size);
		file1.Close();
	}
	
}
