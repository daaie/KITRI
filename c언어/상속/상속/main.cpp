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

	A *p3=&b;		//��ĳ������ ĳ���� ������ �ʿ� ����.

	p3->test1();	//���� ����(������ ���� ����) -> ������ Ÿ���� ����.
					//�ּҿ� ���̺��� �ڽ��̶� �θ� ����.
					//������ Ÿ�� ����..�Լ� �����

	((B*)p3)->test2(); //�ٿ� ĳ������ ĳ���� ������ �ʿ�. ���� ��ü�� �ڽ� ��ü�� 


	return 0;
}