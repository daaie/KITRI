#include <iostream>
using namespace std;

class bear
{
	int a;
	public :
	int asdf()
	{
		a=1;
		a++;
		return a;
	}
};
class snake
{
public:
	void attack(bear b)
	{
		int a=b.asdf();
		cout<<"塊ぬ焦けいぬぬぬし "<<"a="<<a<<endl;
	}
};



void main()
{
	bear b;
	snake s;
	s.attack(b);
}

