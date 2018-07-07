#include <iostream>
using namespace std;

class unit
{
	int hp;
public : 
	unit()
	{
		hp=0;
	}
	unit(int i)
	{
		hp=i;
	}
	int gethp()
	{
		return hp;
	}
	unit operator+(const unit &a)          //a의 오퍼레이터가 b를 받는것.. unit a+unit b...
	{										
		unit unitTemp(hp+a.hp);
		return unitTemp;
	}
};

void main()
{
	unit unit1(10);
	unit unit2(30);

	//unit unit3=unit1+unit2;       //1의 오퍼레이터가 2를 받는것..
	unit unit3=unit1+(unit2);

	cout<<unit3.gethp()<<endl;
}


