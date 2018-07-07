//생성자 클래스 안의 함수...클래스의 이름과 똑같다...
//class unit ->unit(); 생성자
//for 초기화 생성자 안에서 초기화..
//~unit() 소멸자
//객체를 생성하자마자 실행함... 종료할땐 소멸자 실행함..
//변수의 초기화를 생성자 안에서 많이함..
//안쓰면 default
#include <iostream>
using namespace std;
class Unit
{
public : Unit();
		 ~Unit();
		 void out ();
			

};
void main()
{
	Unit unit;
	//unit.out();
}

void Unit::out()  //★★★★★★★★★★★★★★★★  (♡_♡)ㅎㅎㅎ☆
{
	cout<<"출력문"<<endl;
}

Unit::Unit()
{
	out();
	cout<<"start"<<endl;
}

Unit::~Unit()
{

	cout<<"end"<<endl;
}