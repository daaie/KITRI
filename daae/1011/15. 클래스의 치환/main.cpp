#include <iostream>
using namespace std;
class unit{
	int x,y;
public :
	unit()
	{
		x=0;
		y=0;
	}
	void set (int i, int j) {x=i; y=j;}
	void show () {cout<<x<<","<<y<<endl;}
};
void main()
{
	unit a;
	unit b=a;
	//unit &b=a;
	//b=a;

	a.set(12,4);
	a.show();
	b.show();

	a.set(4,12);
	a.show();
	b.show();
}
	