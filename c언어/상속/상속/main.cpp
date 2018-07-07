#include <iostream>
#include "person.h"
using namespace std;

int main()
{
	A a;
	a.test1();
	B b(10,20);
	b.test1();
	b.test2();

	A *p1;
	B *p2;
	p1=&a;
	p2=&b;
	p1->test1();
	p2->test1();
	p2->test2();

	A *p3=&b;		//업캐스팅은 캐스팅 연산자 필요 없음.

	p3->test1();	//정적 결합(컴파일 과정 결합) -> 데이터 타입을 따라감.
					//주소와 테이블이 자식이라도 부모 따라감.
					//포인터 타입 접근..함순 버츄얼

	((B*)p3)->test2(); //다운 캐스팅은 캐스팅 연산자 필요. 상위 객체서 자식 객체로 


	return 0;
}