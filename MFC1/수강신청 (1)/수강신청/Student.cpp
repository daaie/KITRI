// Student.cpp : implementation file
//

#include "stdafx.h"
#include "수강신청.h"
#include "Student.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CStudent, CPropertyPage)

CStudent::CStudent()
	: CPropertyPage(Student)
{

}

CStudent::~CStudent()
{
}

void CStudent::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, myList);
	DDX_Control(pDX, IDC_LIST2, myLecture);
}

BEGIN_MESSAGE_MAP(CStudent, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &CStudent::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CStudent::OnBnClickedButton5)
END_MESSAGE_MAP()

BOOL CStudent::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	char *colname[8] = { "  과목코드","과목명","교수명","강의실","요일","시간","현재인원","최대인원" };
	int width[8] = { 100,150,80,80,60,60,80,80 };
	LVCOLUMN col;
	col.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	col.fmt = LVCFMT_CENTER;


	for (int i = 0; i < 8; i++)
	{
		col.cx = width[i];
		col.iSubItem = i;
		col.pszText = colname[i];
		myList.InsertColumn(i, &col);

	}

	char *lecturecolname[8] = { "  과목코드","과목명","교수명","강의실","요일","시간","현재인원","최대인원" };
	int lecturewidth[8] = { 80,80,80,80,60,60,60,60 };
	LVCOLUMN lecturecol;
	lecturecol.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	lecturecol.fmt = LVCFMT_CENTER;


	for (int i = 0; i < 8; i++)
	{
		lecturecol.cx = lecturewidth[i];
		lecturecol.iSubItem = i;
		lecturecol.pszText = lecturecolname[i];
		myLecture.InsertColumn(i, &lecturecol);

	}

	char str[20];
	LVITEM item;
	item.mask = LVIF_TEXT;

	subject->bmp = subject->head;

	int idx = 0;

	while (subject->bmp != NULL)
	{
		item.iItem = idx;			//항목 지정.. 줄번호..

		if (subject->bmp->Open == "개설 됨")
		{
			item.iSubItem = 0;			//컬럼번호
			sprintf(str, "%s", subject->bmp->SubjectCode);
			item.pszText = (LPSTR)str;
			myList.InsertItem(&item);
			myList.SetItemData(idx, (DWORD_PTR)subject->bmp);

			item.iSubItem = 1;			//컬럼번호
			sprintf(str, "%s", subject->bmp->SubjectName);
			item.pszText = (LPSTR)str;
			myList.SetItem(&item);

			item.iSubItem = 2;			//컬럼번호
			sprintf(str, "%s", subject->bmp->profName);
			item.pszText = (LPSTR)str;
			myList.SetItem(&item);

			item.iSubItem = 3;			//컬럼번호
			sprintf(str, "%s", subject->bmp->conn->room);
			item.pszText = (LPSTR)str;
			myList.SetItem(&item);
			
			item.iSubItem = 4;			//컬럼번호
			sprintf(str, "%s", subject->bmp->conn->day);
			item.pszText = (LPSTR)str;
			myList.SetItem(&item);

			item.iSubItem = 5;			//컬럼번호
			sprintf(str, "%s", subject->bmp->conn->time);
			item.pszText = (LPSTR)str;
			myList.SetItem(&item);

			item.iSubItem = 6;			//컬럼번호
			sprintf(str, "%d", subject->bmp->conn->nowNum);
			item.pszText = (LPSTR)str;
			myList.SetItem(&item);

			item.iSubItem = 7;			//컬럼번호
			sprintf(str, "%s", subject->bmp->conn->maxNum);
			item.pszText = (LPSTR)str;
			myList.SetItem(&item);
			idx++;
		}
		
			subject->bmp = subject->bmp->next;
		
	}
	idx = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CStudent::OnBnClickedButton1()
{
	CString temp,temp2;
	char str[20];

	int mark = myList.GetSelectionMark();
	struct lecture* imsi = (struct lecture*)myList.GetItemData(mark);

	temp = myList.GetItemText(mark, 7);
	sprintf(str, "%d", imsi->conn->nowNum);

	if (atoi(str) > atoi(temp))
	{
		MessageBox("수강인원이 가득 찼습니다");
		return;
	}

	temp = myList.GetItemText(mark, 0);
	temp2 = myLecture.GetItemText(mark, 0);

	if (temp == temp2)
	{
		MessageBox("이미 신청한 강좌입니다ㅎㅎ");
		return;
	}
	imsi->conn->nowNum++;
	LVITEM itemlecture;
	itemlecture.mask = LVIF_TEXT;

	itemlecture.iItem = 0;

	temp = myList.GetItemText(mark, 0);
	itemlecture.iSubItem = 0;
	sprintf(str, "%s", temp);
	itemlecture.pszText = (LPSTR)str;
	myLecture.InsertItem(&itemlecture);

	for (int i = 1; i < 6; i++)
	{
		temp = myList.GetItemText(mark, i);
		itemlecture.iSubItem = i;
		sprintf(str, "%s", temp);
		itemlecture.pszText = (LPSTR)str;
		myLecture.SetItem(&itemlecture);
	}

	itemlecture.iSubItem = 6;
	sprintf(str, "%d", imsi->conn->nowNum);
	itemlecture.pszText = (LPSTR)str;
	myLecture.SetItem(&itemlecture);
	myList.SetItem(&itemlecture);

	temp = myList.GetItemText(mark, 7);
	itemlecture.iSubItem = 7;
	sprintf(str, "%s", temp);
	itemlecture.pszText = (LPSTR)str;
	myLecture.SetItem(&itemlecture);
}


void CStudent::OnBnClickedButton5()
{
	int mark = myList.GetSelectionMark();
	CString temp3 = myList.GetItemText(mark, 1);
	syl = new syllabusPage(temp3);
	(*syl).DoModal();
	// TODO: Add your control notification handler code here
}
