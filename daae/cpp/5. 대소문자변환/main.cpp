#include <iostream>
using namespace std;
void trans(char *str);
void main()
{
	char str[20];
	char* pa;
	cout<<"���ڿ��� �Է� : ";
	cin>>str;
	pa=str;
	cout<<"test a = "<<pa<<endl; //�����Ͱ��� �巹�ѰŴ� cout<<str�̶� ����

	cout<<"test a2 = ";
	for (int i=0;i<strlen(str);i++)
	{
		cout<<*(pa+i);
	}
	cout<<endl;


	
	for (int i=0;i<20;i++)
	{
		trans(&str[i]);
	}
	cout<<"��ȯ �� :"<<str<<endl;
}

void trans(char *str)
{
	if(*str>='a'&&*str<='z')
	{
		*str-=32;
	}
	else if (*str>='A'&&*str<='Z')
	{
		*str+=32;
	}
}