#include <iostream>
#include <iomanip>
using namespace std;
void gugu(int n);
void main()
{
	int n;
	cout<<"���� �Է��ϼ���";
	cin>>n;

	gugu(n);
}
void gugu(int n)
{
	for(int i=1;i<=9;i++)
	{
		cout<<n<<"x"<<i<<"=";
		cout.width(2);
		cout<<n*i<<endl;
	}
}


/*
void gugu(int n)
{
	for (int i=1;i<=9;i++)
	{
		cout<<n<<"x"<<i<<"="<<setw(2)<<n*i<<endl;
	}
}
//setprecision(2)...2�ڸ��� ����?
*/