// login.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "������û.h"
#include "login.h"
#include "afxdialogex.h"
#include "afx.h"
#include "afxwin.h"
#include "afxdb.h"

// login ��ȭ �����Դϴ�.

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

	file1.Open("������ȸ������.txt", CFile::modeCreate | CFile::modeReadWrite);
	file1.Close();
	file2.Open("����ȸ������.txt", CFile::modeCreate | CFile::modeReadWrite);
	file2.Close();
	file3.Open("�л�ȸ������.txt", CFile::modeCreate | CFile::modeReadWrite);
	file3.Close();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
// login �޽��� ó�����Դϴ�.


void login::OnBnClickedButton1()
{
	UpdateData(true);
	int data_size;
	CString idinfo;
	char info[1000];
	CFileException ex;
	if (BtStu.GetCheck()==BST_CHECKED)
	{
		file3.Open("�л�ȸ������.txt", CFile::modeReadWrite,&ex);
		idinfo.Format("%10s%10s\n", Id, Name);
 		data_size = (int)strlen(idinfo);
		file3.Write(idinfo, data_size);
		file3.Close();
	}
	else if(BtProf.GetCheck() == BST_CHECKED)
	{
		file2.Open("����ȸ������.txt", CFile::modeReadWrite);
		idinfo.Format("%10s%10s\n", Id, Name);
		data_size = (int)strlen(idinfo);
		file2.Write(idinfo, data_size);
		file2.Close();
	}
	else if (Btper.GetCheck() == BST_CHECKED)
	{
		file1.Open("������ȸ������.txt", CFile::modeReadWrite);
		idinfo.Format("%10s%10s\n", Id, Name);
		data_size = (int)strlen(idinfo);
		file1.Write(idinfo, data_size);
		file1.Close();
	}
	
}
