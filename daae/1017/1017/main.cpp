#include <iostream>
using namespace std;
//����� ������ �����Լ��� �ʿ����..
//!!!!!!!!!�θ� Ŭ������ �Լ��� �ڽ� Ŭ������ ���Ƿ� �����Ͽ� ����� �� �ֵ��� �ϴ� �Լ�!!!!!!!!!!!!!!
//int *pa=new int[2]  ==> int *pa= new 8  ���� �޸� �Ҵ�.
//class Unit { int a, int b;} ���
//Unit *unit=new Unit ==> Unit *unit=new 8 (int�� 2���ϱ�)
//�ڽ��� �θ𺸴� ũ��..Child *child = new child �Ǵµ� new parent�� �ȵ�...


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
	Animal *bird =new Bird(); //bird �ڽ��� �θ𺸴� ũ�ϱ� �����Ҵ��� �ȴ�!!
	bird->move();
}
//virtaul �� ���� �׳� animal ���� 
//�ڽ� Ŭ������ �Ȱ��� �Լ��� �ְ� �ڽ� Ŭ���� ũ��� �����ϸ� �������̵�...
//�Լ��̸��� �ٸ��� �׳� animal ����
//�ڽ� Ŭ���� �϶���!! ����� �ƴϸ� ����� �߸�...
	
