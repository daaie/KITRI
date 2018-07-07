#include <iostream>
using namespace std;

void main()
{
	int num1,num2;
	cout<<"두개의 정수를 입력"<<endl;
	cin>>num1>>num2;

	try
	{
		if (num2==0) throw num2;
		cout<<"나눗셈의 몫 : " <<num1/num2<<endl;
		cout<<"나눗셈의 나머지 : "<<num1%num2<<endl;
	}
	catch (int expn)
	{
		cout<<"제수는"<<expn<<"이 될 수 없습니다"<<endl;
		cout<<"다시실행하세요"<<endl;
	}
	cout<<"end of main"<<endl;
}

