#include <iostream>
#include <string.h>
#include "person.h"

using namespace std;

Person :: Person()
{
	name=new char[10];
	strcpy(name, "0");
	age=0;
}

void Person::setinfo(char *n, int a)
{
	name = new char[strlen(n)+1];
	strcpy(name,n);
	age=a;
}

void Person::getinfo()
{
	cout<<age<<"  ";
	cout<<name<<endl;

}

bool Person::operator < (Person &p)
{
	if(age<p.age)
	return 1;
	else 
	return 0;
}

Person& Person :: operator = (Person &p)
{
	name = new char[strlen(p.name)+1];
	strcpy(name,p.name);
	age=p.age;
	return *this;
}