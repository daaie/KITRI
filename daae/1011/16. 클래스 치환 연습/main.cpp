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


///�޸𸮸� �ѹ��� ����־ ���� �����ϰԵ�...string�϶� ����� ����

//b=a�ع�����  �갡 ����...
//unit (unit& agunit)
//{
//	str=agunit.str;  // b�� a�� �ּ� ī��
//}