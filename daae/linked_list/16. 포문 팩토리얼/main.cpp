#include <iostream>
using namespace std;
void main()
{
	int num,fac;
	cout<<"¸î ÆÑ??";
	cin>>num;
	
	fac=num;

	for (int i=num-1;i>=1;i--)
	{
		fac=fac*i;
	}
	cout<<fac<<endl;
}