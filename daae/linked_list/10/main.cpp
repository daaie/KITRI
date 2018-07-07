#include <iostream>
using namespace std;
int main()
{
	int a[2][3]={{1,2,3},{4,5,6}};
	int *p=a[0];
	int (*p2)[3]=a;
	int i,j;

	for (i=0;i<6;i++)
	{
		cout<<p[i]<<endl;
	}
	cout<<endl;

	for (i=0;i<2;i++)
	{
		for (j=0;j<3;j++)
		{
			cout<<p2[i][j];
		}
	}
	cout<<endl;
	cout<<p2[1][-1]<<endl;
		return 0;
}