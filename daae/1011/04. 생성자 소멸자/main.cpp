//������ Ŭ���� ���� �Լ�...Ŭ������ �̸��� �Ȱ���...
//class unit ->unit(); ������
//for �ʱ�ȭ ������ �ȿ��� �ʱ�ȭ..
//~unit() �Ҹ���
//��ü�� �������ڸ��� ������... �����Ҷ� �Ҹ��� ������..
//������ �ʱ�ȭ�� ������ �ȿ��� ������..
//�Ⱦ��� default
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

void Unit::out()  //�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�  (��_��)��������
{
	cout<<"��¹�"<<endl;
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