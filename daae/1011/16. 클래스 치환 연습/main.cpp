#include <iostream>
#include <string.h>
using namespace std;
class unit{
	char* str;
public :
	unit()
	{
		str=NULL;
	}
	unit(char *agStr)
	{
		int strLength=strlen(agStr);
		str=new char[strLength+1];
		strcpy(str,agStr);
	}
	unit(unit& agUnit)
	{
		str=new char[strlen(agUnit.str)+1];
		strcpy(str,agUnit.str);
	}

	void set(char *agStr)
	{
		strcpy(str,agStr);
	}
	void show()
	{
		cout<<str<<endl;
	}
};
void main(int argc, char* argv[])
{
	unit a("test");
	unit b=a;


	a.set("test2");

	a.show();
	b.show();
}


///메모리를 한번만 잡고있어서 같이 공유하게됨...string일때 생기는 문제

//b=a해버리면  얘가 생김...
//unit (unit& agunit)
//{
//	str=agunit.str;  // b가 a의 주소 카피
//}