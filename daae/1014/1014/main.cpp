//���� Ŭ����(�θ�) - ���� Ŭ����(�ڽ�)  �θ� ������ �� �ִ�.
// ���� aŬ������ void whoryou() const ��� bŬ������ const�� ���� �Լ������� ����� �� �ִ�.  
//�θ�Ŭ���� ������ �ڽ�Ŭ�������뿡 ���� �Ŷ� ���..


//class police : public gun1, public gun2 



#include <iostream>
using namespace std;
class npc
{
	int defense;

public :
	void setDefense(int n);
	int getDefense();
};

class grunt : public npc
{
	int armor;

public :
	void setArmor(int n);
	int getarmoredDefense();
};

void npc::setDefense(int n)
{
	defense=n;
}

int npc::getDefense()
{
	return defense;
}

void grunt::setArmor(int n)
{
	armor=n;
}

int grunt::getarmoredDefense()
{
	return armor+getDefense();
}

void main()
{
	grunt unit;
	unit.setDefense(10);
	unit.setArmor(20);

	cout<<"armored defense : "<<unit.getarmoredDefense()<<endl;
	
}
