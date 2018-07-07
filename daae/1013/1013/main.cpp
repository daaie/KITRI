#include <iostream>
//클래스나 함수가 친구가 될수잇음
using namespace std;
class unit
{
	int x,y;
	friend bool issame(unit *b);
public : 
	unit(int i, int j)
	{
		x=i;
		y=j;
	}
	//friend bool issame(unit *a);  //unit 이름은 상관없나봄...안똑같아도됨걍지ㅓㅈㅇ
};

bool issame(unit *a)           //bool issame(unit &a)
{
	if(a->x==a->y)				//if(a.x==a.y) 같댱
	{return 1;}
	else
	{return 0;}

}

void main()
{
	unit a(1,2);
	unit b(3,3);

	cout<<"a(1,2)"<<issame(&a)<<endl;  //issame(a)
	cout<<"b(3,3)"<<issame(&b)<<endl;	//issame(b)

}