#include <iostream>

using namespace std;


void swap1(int x, int y)
{
	int tmp;
	tmp=x;
	x=y;
	y=tmp;
}

void swap2(int *x, int *y)
{
	int tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;
}
void swap3(int &x, int &y)
{
	int tmp;
	tmp=x;
	x=y;
	y=tmp;
}
void main()
{
	int a=10;
	int b=20;
	swap1(a,b);
	cout<<"a "<<a<<"b "<<b<<endl;
	a=10;
	b=20;
	swap2(&a,&b);
	cout<<"a "<<a<<"b "<<b<<endl;
	a=10;
	b=20;
	swap3(a,b);
	cout<<"a "<<a<<"b "<<b<<endl;







//	int &b=a;		//���۷��� ����..�ּҶ�� ���� �� ����..b�� a�� ���� ��Ī�̴�
	//b=20;			//���Ⱑ�� ���� a�� �ٲ� �� ���� 
//	cout<<a;
}