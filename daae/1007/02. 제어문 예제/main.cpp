#include <iostream>
using namespace std;
void main()
{
	int mul=1,hap=0,i;
	cout<<"1~10������ ������"<<endl;
	for (i=1;i<=10;i+=2)
	{
		mul*=i;
		hap+=(i+1);
	}
	cout<<"Ȧ���� �� = "<<mul<<endl;
	cout<<"¦���� �� = "<<hap<<endl;
}
