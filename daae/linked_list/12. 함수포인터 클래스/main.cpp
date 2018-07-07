#include <iostream>
using namespace std;

class fun
{
public:
	void f1(char *str)
	{
		cout<<"f1 : "<<str;
	}

	void pointer()
	{
		void (fun::*p)(char *) = &fun::f1;		
	}
};

void main()
{
	fun f;
	f.pointer();
}