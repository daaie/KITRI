#include <iostream>
using namespace std;

int fibo(int a)
{
	if(a==1||a==2) {
		return 1;
	}else {
		return fibo(a-2)+fibo(a-1);      //�Լ��� �ڱ⸦ ȣ���ϴ� �Լ�...
										 //���ߴ� ������ �� ���������!!
										 //���丮�� ó�� �ݺ��ϴ°� �ϱ� ����!
										 //�� ���ڸ� ��� ȣ����.. �� ���ڰ� �ʿ��� ��� �迭�� �Ǵ�
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