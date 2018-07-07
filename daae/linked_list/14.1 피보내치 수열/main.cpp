#include <iostream>
using namespace std;

void fibo (double *a,int i)
{
	if(i==0||i==1)
	{
		a[i]=1;
	}
	else 
	{
		a[i]=a[i-1]+a[i-2];
	}
}

void main()
{
	int i;

	float x=3.14;
	float y=3.25; //2의 -2승임.. 2로 계산이 되니까 float 으로 계산잘됨
	cout<<x<<endl;
	

	double a[100];
	for (i=0;i<100;i++)
	{
		fibo(a,i);
	}
	for (i=0;i<100;i++)
		printf("%d = %.lf\n",i+1,a[i]);

}