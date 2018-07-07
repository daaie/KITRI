 // Professor.cpp : implementation file
//

#include "stdafx.h"
#include "������û.h"
#include "Professor.h"
#include "afxdialogex.h"
#include "syllabusPage.h"

// CProfessor dialog

IMPLEMENT_DYNAMIC(CProfessor, CPropertyPage)

CProfessor::CProfessor()
	: CPropertyPage(Professor)
	, room(_T(""))
	, day(_T(""))
	, time(_T(""))
	, maxNum(_T(""))
	, SubNum(_T(""))
	, SubName(_T(""))
{

}
CProfessor::CProfessor(CString id) : CPropertyPage(Professor)
, room(_T(""))
, day(_T(""))
, time(_T(""))
, maxNum(_T(""))
, SubNum(_T(""))
, SubName(_T(""))
, profName(id)
{

}

CProfessor::~CProfessor()
{
}

void CProfessor::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, myList);
	DDX_Text(pDX, IDC_EDIT1, room);
	DDX_Text(pDX, IDC_EDIT3, day);
	DDX_Text(pDX, IDC_EDIT2, time);
	DDX_Text(pDX, IDC_EDIT4, maxNum);
	DDX_Text(pDX, IDC_EDIT5, SubNum);
	DDX_Text(pDX, IDC_EDIT6, SubName);
}


BEGIN_MESSAGE_MAP(CProfessor, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON3, &CProfessor::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CProfessor::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CProfessor::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LIST1, &CProfessor::OnLvnItemActivateList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CProfessor::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON4, &CProfessor::OnBnClickedButton4)
END_MESSAGE_MAP()


// CProfessor message handlers


BOOL CProfessor::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	char *colname[7] = { "  �����ڵ�","�����","��������","���ǽ�","����","�ð�","�ִ��ο�" };
	int width[7] = { 100,150,80,80,60,60,80 };
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
	OnBnClickedButton3();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CProfessor::OnBnClickedButton3()
{
	myList.DeleteAllItems();
	UpdateData(false);

	char str[20];
	LVITEM item;
	item.mask = LVIF_TEXT;

	subjectinfo->bmp = new struct lectureInfo;

	subject->bmp = subject->head;

	int idx = 0;

	while (subject->bmp != NULL)
	{
		item.iItem = idx;			//�׸� ����.. �ٹ�ȣ..

		subjectinfo->bmp = subjectinfo->head;

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
		myList.SetItemData(idx, (DWORD_PTR)subject->bmp);

		while (subjectinfo->bmp != NULL)
		{
			if (subjectinfo->bmp != NULL && subjectinfo->bmp->SubjectCode == subject->bmp->SubjectCode)
			{
				item.iSubItem = 3;			//�÷���ȣ
				sprintf(str, "%s", subjectinfo->bmp->room);
				item.pszText = (LPSTR)str;
				myList.SetItem(&item);

				item.iSubItem = 4;			//�÷���ȣ
				sprintf(str, "%s", subjectinfo->bmp->day);
				item.pszText = (LPSTR)str;
				myList.SetItem(&item);

				item.iSubItem = 5;			//�÷���ȣ
				sprintf(str, "%s", subjectinfo->bmp->time);
				item.pszText = (LPSTR)str;
				myList.SetItem(&item);

				item.iSubItem = 6;			//�÷���ȣ
				sprintf(str, "%s", subjectinfo->bmp->maxNum);
				item.pszText = (LPSTR)str;
				myList.SetItem(&item);
			}
			subjectinfo->bmp = subjectinfo->bmp->next;
		}
		idx++;
		subject->bmp = subject->bmp->next;

	}

	idx = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CProfessor::OnBnClickedButton2()
{
	UpdateData(true);
	mark = myList.GetSelectionMark();

	CString temp3 = myList.GetItemText(mark, 0);

	struct lecture *imsi = (struct lecture *)myList.GetItemData(mark);

	subjectinfo->bmp = new struct lectureInfo;

	subjectinfo->cmp = new struct lectureInfo;
	subjectinfo->cmp = subjectinfo->head;
	
	while (subjectinfo->cmp != NULL)
	{
			if (subjectinfo->cmp->room == room &&
				subjectinfo->cmp->day == day &&
				subjectinfo->cmp->time == time) {

				MessageBox("���°� ��Ĩ�ϴ�");
				return;
			}

			else
				subjectinfo->cmp = subjectinfo->cmp->next;

	}
	delete subjectinfo->cmp;


	subjectinfo->bmp->room = room;
	subjectinfo->bmp->day = day;
	subjectinfo->bmp->time = time;
	subjectinfo->bmp->maxNum = maxNum;
	subjectinfo->bmp->SubjectCode = temp3;
	
	imsi->conn = subjectinfo->bmp;

	if (subjectinfo->head == NULL)
	{
		subjectinfo->head = subjectinfo->bmp;
	}
	else 
	{
		subjectinfo->tail->next = subjectinfo->bmp;
	}
	subjectinfo->tail = subjectinfo->bmp;
	subjectinfo->tail->next = NULL;

	OnBnClickedButton3();
	
	room = "";
	day = "";

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CProfessor::OnBnClickedButton1()
{
	mark = myList.GetSelectionMark();
	CString temp3 = myList.GetItemText(mark, 3);
	CString temp4 = myList.GetItemText(mark, 4);
	CString temp5 = myList.GetItemText(mark, 5);
	CString temp6 = myList.GetItemText(mark, 6);
	if (temp3 == "" || temp4 == "" || temp5 == "" || temp6 == "")
	{
		MessageBox("���� ������ ��� �Է��� �ּ���");
		return;
	}
	else
	{
		int idx = myList.GetSelectionMark();
		struct lecture *imsi = (struct lecture *)myList.GetItemData(idx);
		imsi->Open = "���� ��";
		imsi->profName = profName;
		OnBnClickedButton3();
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CProfessor::OnLvnItemActivateList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	UpdateData(true);
	mark = myList.GetSelectionMark();
	
	CString temp2 = myList.GetItemText(mark, 1);
	CString temp3 = myList.GetItemText(mark, 0);
	
	SubName = temp2;
	SubNum = temp3;
	UpdateData(false);
	
	*pResult = 0;
}

void CProfessor::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	UpdateData(true);
	mark = myList.GetSelectionMark();

	CString temp2 = myList.GetItemText(mark, 1);
	CString temp3 = myList.GetItemText(mark, 0);

	SubName = temp2;
	SubNum = temp3;
	UpdateData(false);

	*pResult = 0;
}


void CProfessor::OnBnClickedButton4()
{
	mark = myList.GetSelectionMark();
	CString temp3 = myList.GetItemText(mark, 1);
	syl = new syllabusPage(temp3);
	(*syl).DoModal();
	// TODO: Add your control notification handler code here
}
