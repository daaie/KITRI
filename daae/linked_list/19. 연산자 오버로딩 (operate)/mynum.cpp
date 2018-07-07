#include <iostream>
#include "mynum.h"
using namespace std;

mynum mynum::operator +(const mynum &n) const
{
return mynum(num+n.num);  //클래스의 생성자 호출
}

void mynum::getnum()
{
	cout<<num;
}

ostream& mynum::operator<<(ostream &os)
{
	os<<num;

	return os;
}

std::ostream& operator<<(ostream &os, const mynum &n)
{
	os<<n.num;
	
	return os;
}
