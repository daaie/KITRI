#include <iostream>
using namespace std;
struct student
{
//	static const int num=0;
	int num;
	int age;
	int kor;
	int mat;
	int sic;
};

void main()
{
	struct student s[25]={0};

	s[24].num=25;
	s[24].age=15;
	s[24].kor=90;
	s[24].mat=85;
	s[24].sic=95;

//	cout<<"s[2].num= "<<s[2].num<<endl;

	for (int i=0;i<25;i++)
	{
		if(s[i].num==25)
		{
			cout<<"��ȣ�� "<<s[i].num<<" �� �л��� ���� : "<<endl;
			cout<<"���� : "<<s[i].age<<endl;
			cout<<"���� : "<<s[i].kor<<endl;
			cout<<"���� : "<<s[i].mat<<endl;
			cout<<"���� : "<<s[i].sic<<endl;
			cout<<endl;
		}
	}
}
