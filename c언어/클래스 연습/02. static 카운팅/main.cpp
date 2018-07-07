#include <iostream>
using namespace std;

class Test
{
public :
	static int count;
	int x;

	Test()
	{
		x=0;
//		count++;	
	}
};

int Test::count=0;		//선언!!★★★★★ 해야함.. 스태틱이니까 초기호ㅏ 안해주면 0

void main()
{
	//for (int i=0;i<10;i++)
	//{
	//	Test t;
	//	cout<<Test::count<<endl;
	//}
	Test t1,t2,t3;
	t1.count++;
	t1.x++;
	cout<<t1.x<<"  "<<t1.count<<endl;
	t2.count++;
	t2.x++;
	cout<<t2.x<<"  "<<t2.count<<endl;
	t3.count++;
	t3.x++;
	cout<<t3.x<<"  "<<t3.count<<endl;
}

