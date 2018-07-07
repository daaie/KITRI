// Personnel.cpp : implementation file
//

#include "stdafx.h"
#include "������û.h"
#include "Personnel.h"
#include "afxdialogex.h"


// CPersonnel dialog

IMPLEMENT_DYNAMIC(CPersonnel, CPropertyPage)

CPersonnel::CPersonnel()
	: CPropertyPage(Personnel)
	, SubCode(_T(""))
	, SubName(_T(""))
	, Open(_T(""))
{

}

CPersonnel::~CPersonnel()
{
}

void CPersonnel::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SubCode);
	DDX_Text(pDX, IDC_EDIT2, SubName);
	DDX_Text(pDX, IDC_EDIT3, Open);
	DDX_Control(pDX, IDC_LIST1, myList);
}


BEGIN_MESSAGE_MAP(CPersonnel, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &CPersonnel::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CPersonnel::OnBnClickedButton3)
END_MESSAGE_MAP()

BOOL CPersonnel::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  Add extra initialization here
	char *colname[3] = { "  �����ڵ�","�����","��������" };
	int width[3] = { 90,120,80 };
	LVCOLUMN col;
	col.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	col.fmt = LVCFMT_CENTER;

	for (int i = 0; i < 3; i++)
	{
		col.cx = width[i];
		col.iSubItem = i;
		col.pszText = colname[i];
		myList.InsertColumn(i, &col);

	}
	OnBnClickedButton3();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


int idx = 0;
void CPersonnel::OnBnClickedButton1()
{
	UpdateData(true);

	Open = "���� �ȵ�";

	subject->bmp = new struct lecture;
	subject->cmp = new struct lecture;

	subject->bmp->SubjectName = SubName;
	subject->bmp->SubjectCode = SubCode;
	subject->bmp->Open = Open;

	subject->cmp = subject->head;

	while (subject->cmp != NULL)
	{
		if (subject->cmp->SubjectCode == SubCode) {
			MessageBox("�����ڵ尡 ��Ĩ�ϴ�");
			return;
		}
		else
			subject->cmp = subject->cmp->next;
	}
	delete subject->cmp;


	if (subject->head == NULL)
	{
		subject->head = subject->bmp;
	}
	else
	{
		subject->tail->next = subject->bmp;
	}
	subject->tail = subject->bmp;
	subject->tail->next = NULL;


	char str[20];
	LVITEM item;
	item.mask = LVIF_TEXT;
	item.iItem = idx;			//�׸� ����.. �ٹ�ȣ..

	item.iSubItem = 0;			//�÷���ȣ
	sprintf(str, "%s", SubCode);
	item.pszText = (LPSTR)str;
	myList.InsertItem(&item);

	item.iSubItem = 1;			//�÷���ȣ
	sprintf(str, "%s", SubName);
	item.pszText = (LPSTR)str;
	myList.SetItem(&item);

	item.iSubItem = 2;			//�÷���ȣ
	sprintf(str, "%s", Open);
	item.pszText = (LPSTR)str;
	myList.SetItem(&item);

	SubName = "";
	SubCode = "";
	Open = "";
	UpdateData(false);
	idx++;

	// TODO: Add your control notification handler code here
}


void CPersonnel::OnBnClickedButton3()
{
	myList.DeleteAllItems();
	UpdateData(false);

	char str[20];
	LVITEM item;
	item.mask = LVIF_TEXT;

	subject->bmp = subject->head;
	int idx = 0;

	while (subject->bmp != NULL)
	{
		item.iItem = idx;			//�׸� ����.. �ٹ�ȣ..

		item.iSubItem = 0;			//�÷���ȣ
		sprintf(str, "%s", subject->bmp->SubjectCode);
		item.pszText = (LPSTR)str;
		myList.InsertItem(&item);

		item.iSubItem = 1;			//�÷���ȣ
		sprintf(str, "%s", subject->bmp->SubjectName);
		item.pszText = (LPSTR)str;
		myList.SetItem(&item);

		item.iSubItem = 2;			//�÷���ȣ
		sprintf(str, "%s", subject->bmp->Open);
		item.pszText = (LPSTR)str;
		myList.SetItem(&item);
		myList.SetItemData(idx, (DWORD_PTR)&subject->bmp->Open);

		idx++;
		subject->bmp = subject->bmp->next;
	}
}
