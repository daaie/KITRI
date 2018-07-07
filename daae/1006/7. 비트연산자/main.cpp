#include <iostream>
using namespace std;
void main()
{
	short int x=1;
	short int y=2;

	short int r1=x&y;
	short int r2=x|y;
	unsigned short int r3=~x;
	short int r4=x^y;

//	cout.setf(ios::hex,ios::basefield); //16진수..basefield는 지속형 이후 전부 16진수..
	cout<<x<<"&"<<y<<"="<<r1<<endl;
	cout<<x<<"|"<<y<<"="<<r2<<endl;
//	cout<<hex<<"~"<<x<<"="<<dec<<r3<<endl; //dec=10진수..
	cout<<"~"<<x<<"="<<r3<<endl;
	cout<<x<<"^"<<y<<"="<<r4<<endl;
}