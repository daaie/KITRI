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

	cout<<"a값 "<<a<<endl;
	cout<<"b값 "<<b<<endl;
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
//	cout<<"a값 "<<a<<endl;
//	cout<<"b값 "<<b<<endl;
//}
//--------------------------------------------
void swap(int &x, int &y)         //변수를 선언할 때 &는 참조 아닐떈 주소..
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

	cout<<"a값 "<<a<<endl;
	cout<<"b값 "<<b<<endl;
}