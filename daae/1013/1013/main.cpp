#include <iostream>
//Ŭ������ �Լ��� ģ���� �ɼ�����
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
	//friend bool issame(unit *a);  //unit �̸��� ���������...�ȶȰ��Ƶ��ʰ����ä���
};

bool issame(unit *a)           //bool issame(unit &a)
{
	if(a->x==a->y)				//if(a.x==a.y) ����
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