#include <iostream>
using namespace std;

class unit
{
public :
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
	cout<<unit1.hp+unit2.hp<<endl;

	//cout<<unit3.gethp()<<endl;
}


