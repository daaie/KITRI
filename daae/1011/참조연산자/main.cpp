#include <iostream>
using namespace std;
/*//----------------------------------------------------------------------------------
void swap(int x, int y)
{
	int temp=x;
	x=y;
	y=temp;
}

void main()
{
	int a=10;
	int b=20;

	swap(a,b);

	cout<<"a�� "<<a<<endl;
	cout<<"b�� "<<b<<endl;
}
*/
//-----------------------------------------------------------------------------------
//void swap(int *x, int *y)
//{
//	int temp=*x;
//	*x=*y;
//	*y=temp;
//}
//
//void main()
//{
//	int a=10;
//	int b=20;
//
//	swap(&a,&b);
//
//	cout<<"a�� "<<a<<endl;
//	cout<<"b�� "<<b<<endl;
//}
//--------------------------------------------
void swap(int &x, int &y)         //������ ������ �� &�� ���� �ƴҋ� �ּ�..
{
	int temp=x;
	x=y;
	y=temp;
}

void main()
{
	int a=10;
	int b=20;

	swap(a,b);

	cout<<"a�� "<<a<<endl;
	cout<<"b�� "<<b<<endl;
}