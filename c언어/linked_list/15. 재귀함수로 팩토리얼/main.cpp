#include <iostream>

using namespace std;


int fac(int a)
{
	if (a==1) return 1;
	else return a*fac(a-1);
}

void main()
{
	int num;
	cout<<"�� ���丮��???";
	cin>>num;
	cout<<fac(num)<<endl;
}