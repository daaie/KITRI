#include <iostream>
using namespace std;
void main()
{
	int a=10;
	int b=20;

	int &c=a;            //무조건 참조연산자로 레퍼런스 변수는 선언할 때만 
						 //따로 대입은안됨 int &c; &c=a;일케는 안댐
						//구래서 함ㅁ수 매개변수 받을 때 많이 씀

	cout<<"a : "<<a<<endl;
	cout<<"b : "<<b<<endl;

	c=50;
	cout<<"c : "<<c<<endl;
	cout<<"a : "<<a<<endl;
	cout<<"b : "<<b<<endl;

}
