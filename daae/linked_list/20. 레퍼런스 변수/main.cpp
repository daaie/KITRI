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







//	int &b=a;		//레퍼런스 변수..주소라기 보다 그 값임..b는 a에 대한 별칭이다
	//b=20;			//여기가서 직접 a를 바꿀 수 있음 
//	cout<<a;
}