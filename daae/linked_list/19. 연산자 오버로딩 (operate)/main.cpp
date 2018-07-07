#include <iostream>
#include "mynum.h"
using namespace std;


void main()
{
	mynum n1(10);
	mynum n2(20);
	mynum n3=n1+n2;	//n1.operator+(n2) //복사생산자
	n3.getnum();
	n3.operator <<(cout);
	n3<<cout<<endl;
	cout<<n3<<" "<<n2<<" "<<n1<<endl;
}

//cout<<" "; cout을 반환...