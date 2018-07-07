#include <iostream>
/*
using namespace std;       //함수에도 namespace쓸거면 함수보다 위에있어야지!
void simon(int n);
void main()
{

	int count;

	simon(3);
	cout<<"정수를 고르시오";

	cin>>count;
	simon(count);
	cout<<"끝"<<endl;
}
void simon(int n)
{
	cout<<"simon 왈, 발가락을 "<<n<<"번 두드려라"<<endl;
}
*/
//--------------------------------------------------------------------
int stonetolb(int stone)
{
	return 14*stone;
}
void main()
{
	using namespace std;
	int stone;

	cout<<"체중을 스톤으로 입력";
	cin>>stone;

	int pounds=stonetolb(stone);
	cout<< stone<<"스톤은 ";
	cout<< pounds<<"파운드 입니다"<<endl;

}
