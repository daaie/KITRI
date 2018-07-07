#include <iostream>
class NUM
{
	//암것도 안쓰면 private
private :
	int num;
	//num=5 private는 초기화 할수 없음...

public :

	void out();
	void in();

};

void main()
{
	NUM num;
//	num.num=5;
//	num.in();
	num.out();
}

void NUM::out() //★★★★★★★★★NUM:: 안해주면 바깥함순줄 앎...
{
	num=5; // 할수 있음..
	printf (" num : %d\n",num);
}

void NUM::in()
{
	scanf("%d",&num);
}
