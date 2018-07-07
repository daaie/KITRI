#include <iostream>
using namespace std;

void main()
{
	double *pivot;
	int num;
	cout<<"어디까지 출력하까?? ";
	cin>>num;

	pivot=(double *)malloc(sizeof(double)*num);
	pivot[0]=1;
	pivot[1]=1;


	for (int i=2;i<num;i++)
	{
		pivot[i]=pivot[i-1]+pivot[i-2];
	}

	for (int i=0;i<num;i++) printf("%d = %.lf\n",i+1,pivot[i]);



}