#include <iostream>

class Area
{
	int h,b;

public : 
	void in();
	void calA();

};
void main()
{
	Area area;
	area.in();
	area.calA();
}

void Area::in()
{
	printf("���� ���� : ");
	scanf("%d",&b);
	printf("���� ���� : ");
	scanf("%d",&h);
}

void Area::calA()
{
	printf ("�ﰢ���� ���̴� %.1lf �Դϴ�\n",b*h/2.);
}	

/****************************************************************
#include <iostream>

class Area
{

public : 
	int h,b;
	void calA(int b,int h);

}; 
void main()
{
	Area area;
	printf("���� ���� : ");
	scanf("%d",&area.b);
	printf("���� ���� : ");
	scanf("%d",&area.h);
	area.calA(area.b,area.h);
}


void Area::calA(int b,int h)
{
	printf ("�ﰢ���� ���̴� %.1lf �Դϴ�\n",b*h/2.);
}	
*///////////////////////////////////////////////////////////