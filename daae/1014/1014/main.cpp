//기초 클래스(부모) - 유도 클래스(자식)  부모를 선택할 수 있다.
// 만약 a클래스의 void whoryou() const 라면 b클래스의 const가 붙은 함수에서만 사용할 수 있다.  
//부모클래스 내용이 자식클래스내용에 들어가는 거랑 비슷..


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
