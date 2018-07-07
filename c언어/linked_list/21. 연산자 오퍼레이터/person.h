#include <iostream>
using namespace std;

class Person
{
	char *name;
	int age;

public :
	Person();				//�⺻ ������ name:�ƹ���, age=0;
	Person(char *n, int a); //�Ű������� ������ 
	Person(const Person &p);//���������
	~Person();
	void setName(char *n);
	Person& operator =(const Person &p);
	friend ostream& operator << (ostream &os, Person &p); //�Է� ������
};