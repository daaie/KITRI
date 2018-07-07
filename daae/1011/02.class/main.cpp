//클래스 = 붕어빵 틀...ㅇ?..
//class car { 변수 함수 } => class는 틀
//car run99...car run98..=> run 99...는 객체 /객체==인스턴스..?
//class 내부 변수 : 멤버 변수...함수 : 멤버 함수
//public : protected : private :
//class car {변수,함수 선언} => void 멤버 함수들 밖에 따로 정의..
//---------------------------   ----------------------------------------------
//	class car는 헤더임			하나의 바이너리..car.cpp로 정의하는게 일반적..

#include <iostream>

class FISH
{
public :
	void swim()
	{
		printf ("you invoke swim()\n");
	}
};

void main()
{
	FISH fish;
	fish.swim();
}
