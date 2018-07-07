#include <iostream>

using namespace std;

class Test
{
public :
	int x;
	static int y;

};
int Test::y=10;
int main()
{
	cout<<Test::y;		//스태틱 맴버는 객체 생성안하고 그냥 써두댐..신기
	return 0;			//전역 변수와 달리 Test에 속해 있음..
}
