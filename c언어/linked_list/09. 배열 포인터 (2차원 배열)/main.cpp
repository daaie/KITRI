#include <iostream>
using namespace std;
void main()
{
	int size=0;
	int *p[3];
	
	cout<<"size :";
	cint>>size;

	for (i=0;i<3;i++)
	{
		for (j=0;j<size;j++)
		{
			p[i]=(int*)malloc(sizeof(int)*size);
			p[i][j]=(i+1)+3*j;
			cout<<p[i][j];
		}
	}
}
		

