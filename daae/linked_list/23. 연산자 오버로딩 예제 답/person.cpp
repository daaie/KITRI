#include <iostream>
#include <string.h>
#include "person.h"
using namespace std;

Person::Person()
{
	name=new char[10];
	strcpy(name,"�ƹ���");
	age=0;
}

Person::Person(char *n, int a)
{
	name=new char[strlen(n)+1];	//�̸� ���̸�ŭ �Ҵ����..
	strcpy(name,n);
	age=a;
}

Person :: Person(const Person &p)
{
	name=new char[strlen(p.name)+1]; //��Ʈ�� ���̸� �� + \0(NULL)
	strcpy(name,p.name);
	age=p.age;
}

Person::~Person()
{
	delete[] name;	//new �� �迭���¸� ����Ʈ �ڿ� []������� ��
}

void Person::setName(char *n)
{
	delete[] name;			//������ �̸��� ����
	name=new char [strlen(n)+1];
	strcpy(name,n);
}

Person& Person:: operator = (const Person &p)
{
	//delete[] name;
	name=new char[strlen(p.name)+1]; //��Ʈ�� ���̸� �� + \0(NULL)
	strcpy(name,p.name);
	age=p.age;
	return *this;		//���� ��ü�� ��Ÿ���� ������ ���� = this
}

std::ostream& operator <<(ostream &os, const Person &p)
{
	os<<"�̸��� : "<<p.name;
	os<<", ���̴� : "<<p.age;
	
	return os;
}
