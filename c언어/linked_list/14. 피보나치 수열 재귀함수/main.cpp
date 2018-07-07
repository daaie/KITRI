#include <iostream>
using namespace std;

int fibo(int a)
{
	if(a==1||a==2) {
		return 1;
	}else {
		return fibo(a-2)+fibo(a-1);      //함수가 자기를 호출하는 함수...
										 //멈추는 지점을 잘 정해줘야함!!
										 //팩토리얼 처럼 반복하는거 하기 좋음!
										 //앞 숫자를 계속 호출함.. 앞 숫자가 필요한 경우 배열이 옳다
	}
}
void main()
{
	int i;
	for (i=1;i<=100;i++)
	{
		cout<<fibo(i)<<endl;
	}
}