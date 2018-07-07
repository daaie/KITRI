#include <iostream>
using namespace std;
void trans(char *str);
void main()
{
	char str[20];
	char* pa;
	cout<<"문자열을 입력 : ";
	cin>>str;
	pa=str;
	cout<<"test a = "<<pa<<endl; //포인터값을 잌레한거는 cout<<str이랑 같다

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
	cout<<"변환 후 :"<<str<<endl;
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