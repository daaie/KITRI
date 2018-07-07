#include <iostream>
using namespace std;
class boy
{
	int height;

public :
	friend class girl;
	int age;
	boy(int len)
	{
		height=len;
		age=25;
	}
};

class girl
{
	char str1[10];
public :
	girl(char *str2)
	{
		strcpy(str1,str2);
	}
	void show(boy &b)
	{
		cout<<"his height "<<b.height<<endl;
		b.height=180;
		cout<<"real height "<<b.height<<endl;
		cout<<"age "<<b.age<<endl;
	}
};

void main()
{
	boy b(170);
	girl g("hello");
	g.show(b);
}

