#include <iostream>
using namespace std;

class Person
{
	char *name;
	int age;

public :
	Person();				//기본 생성자 name:아무개, age=0;
	Person(char *n, int a); //매개변수로 받은거 
	Person(const Person &p);//복사생성자
	~Person();
	void setName(char *n);
	Person& operator =(const Person &p);
	friend ostream& operator << (ostream &os, Person &p); //입력 연산자
};