#include <iostream>
using namespace std;
//상속을 안했음 가상함수는 필요없다..
//!!!!!!!!!부모 클래스의 함수를 자식 클래스가 임의로 변경하여 사용할 수 있도록 하는 함수!!!!!!!!!!!!!!
//int *pa=new int[2]  ==> int *pa= new 8  동적 메모리 할당.
//class Unit { int a, int b;} 라면
//Unit *unit=new Unit ==> Unit *unit=new 8 (int가 2개니까)
//자식이 부모보다 크다..Child *child = new child 되는데 new parent는 안됨...


class Animal
{
public:
	virtual void move()
	{
		cout<<"animal move\n";
	}
};

class Bird : public Animal
{
public :
	void move2()
	{
		cout<<"call move of bird class bird move\n";
	}
};

void main()
{
	Animal *bird =new Bird(); //bird 자식은 부모보다 크니까 동적할당이 된다!!
	bird->move();
}
//virtaul 을 빼면 그냥 animal 나옴 
//자식 클래스에 똑같은 함수가 있고 자식 클래스 크기로 선언하면 오버라이딩...
//함수이름이 다르면 그냥 animal 나옴
//자식 클래스 일때만!! 상속이 아니면 사이즈를 잘모름...
	
