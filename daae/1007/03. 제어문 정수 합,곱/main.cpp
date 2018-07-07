#include <iostream>
using namespace std;
int i;
void addf(int min,int max);
void mulf(int min,int max);
void fun1(int min,int max);
void fun2(int min,int max);
void main()
{
	int min,max,check;
	cout<<"최소 값을 입력하세요 : ";
	cin>>min;
	cout<<"최대 값을 입력하세요 : ";
	cin>>max;
	while(1)
	{
		cout<<"========================================="<<endl;
		cout<<"1. 최소~최대 까지의 합"<<endl;
		cout<<"2. 최소~최대 까지의 곱"<<endl;
		cout<<"3. 최소~최대 사이의 짝수"<<endl;
		cout<<"4. 최소~최대 사이의 홀수"<<endl;
		cout<<"========================================="<<endl;
		cout<<"메뉴를 선택하세요 : ";
		cin>>check;

		switch (check)
		{
			case 1 : addf(min,max);
					 break;	
			case 2 : mulf(min,max);	
					 break;	
			case 3 : fun1(min,max);	 
					 break;			
			case 4 : fun2(min,max);	
					 break;				
		}
	}
}


void addf(int min,int max)  //함수이름..변수이름..달라야해...
{
	int add=0;
	for (i=min;i<=max;i++)
	{
			add+=i;
	}

	cout<<min<<"~"<<max<<"까지의 합 : "<<add<<endl;
}

void mulf(int min,int max)
{
	int mul=1;
	for (i=min;i<=max;i++)
	{
			mul*=i;
	}
	cout<<min<<"~"<<max<<"까지의 곱 : "<<mul<<endl;
}

void fun1(int min,int max)
{
	cout<<min<<"~"<<max<<"사이의 짝수 : ";
	for(i=min;i<=max;i++)
	{
		if(i%2==0) cout<<i<<" ";
	}
	cout<<endl;
}

void fun2(int min,int max)
{
	cout<<min<<"~"<<max<<"사이의 홀수 : ";
	for(i=min;i<=max;i++)
	{
		if(i%2!=0) cout<<i<<" ";
	}
	cout<<endl;
}