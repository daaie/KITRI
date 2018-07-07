#include <iostream>
#include <string.h>
#include "person.h"
using namespace std;

Person::Person()
{
	name=new char[10];
	strcpy(name,"아무개");
	age=0;
}

Person::Person(char *n, int a)
{
	name=new char[strlen(n)+1];	//이름 길이만큼 할당받음..
	strcpy(name,n);
	age=a;
}

Person :: Person(const Person &p)
{
	name=new char[strlen(p.name)+1]; //스트링 길이만 딱 + \0(NULL)
	strcpy(name,p.name);
	age=p.age;
}

Person::~Person()
{
	delete[] name;	//new 가 배열형태면 딜리트 뒤에 []써줘야함 꼭
}

void Person::setName(char *n)
{
	delete[] name;			//기존의 이름은 해제
	name=new char [strlen(n)+1];
	strcpy(name,n);
}

Person& Person:: operator = (const Person &p)
{
	//delete[] name;
	name=new char[strlen(p.name)+1]; //스트링 길이만 딱 + \0(NULL)
	strcpy(name,p.name);
	age=p.age;
	return *this;		//현재 객체를 나타내는 포인터 변수 = this
}

std::ostream& operator <<(ostream &os, const Person &p)
{
	os<<"이름은 : "<<p.name;
	os<<", 나이는 : "<<p.age;
	
	return os;
}
