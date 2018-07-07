// syllabus.cpp : implementation file
//

#include "stdafx.h"
#include "수강신청.h"
#include "syllabus.h"
#include "afxdialogex.h"
#include "fstream"
#include "iostream"

using namespace std;
// syllabus dialog

IMPLEMENT_DYNAMIC(syllabus, CPropertyPage)

syllabus::syllabus()
	: CPropertyPage(IDD_DIALOG2)
,text(_T(""))
{

}
syllabus::syllabus(CString subName)
	: CPropertyPage(IDD_DIALOG2)
	, text(_T(""))
	, fileName(subName)
{

}
syllabus::~syllabus()
{
}

void syllabus::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, text);
}


BEGIN_MESSAGE_MAP(syllabus, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &syllabus::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &syllabus::OnBnClickedButton2)
END_MESSAGE_MAP()


// syllabus message handlers


void syllabus::OnBnClickedButton1()
{
	UpdateData(true);
	ofstream ofs(fileName+"강의계획서.txt");
	ofs << text << endl;
	ofs.close();
	UpdateData(false);
}


void syllabus::OnBnClickedButton2()
{
	char *pData;
	int length;
	text = "";

	ifstream ifs(fileName+"강의계획서.txt");

	while (!ifs.eof()) {
	//length = ifs.tellg();
	pData = new char[100];
	ifs.getline(pData, 100);
	text += "\n";
	text += pData;
	delete pData;
	}

	UpdateData(false);

}
