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
	cout<<"�ּ� ���� �Է��ϼ��� : ";
	cin>>min;
	cout<<"�ִ� ���� �Է��ϼ��� : ";
	cin>>max;
	while(1)
	{
		cout<<"========================================="<<endl;
		cout<<"1. �ּ�~�ִ� ������ ��"<<endl;
		cout<<"2. �ּ�~�ִ� ������ ��"<<endl;
		cout<<"3. �ּ�~�ִ� ������ ¦��"<<endl;
		cout<<"4. �ּ�~�ִ� ������ Ȧ��"<<endl;
		cout<<"========================================="<<endl;
		cout<<"�޴��� �����ϼ��� : ";
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


void addf(int min,int max)  //�Լ��̸�..�����̸�..�޶����...
{
	int add=0;
	for (i=min;i<=max;i++)
	{
			add+=i;
	}

	cout<<min<<"~"<<max<<"������ �� : "<<add<<endl;
}

void mulf(int min,int max)
{
	int mul=1;
	for (i=min;i<=max;i++)
	{
			mul*=i;
	}
	cout<<min<<"~"<<max<<"������ �� : "<<mul<<endl;
}

void fun1(int min,int max)
{
	cout<<min<<"~"<<max<<"������ ¦�� : ";
	for(i=min;i<=max;i++)
	{
		if(i%2==0) cout<<i<<" ";
	}
	cout<<endl;
}

void fun2(int min,int max)
{
	cout<<min<<"~"<<max<<"������ Ȧ�� : ";
	for(i=min;i<=max;i++)
	{
		if(i%2!=0) cout<<i<<" ";
	}
	cout<<endl;
}