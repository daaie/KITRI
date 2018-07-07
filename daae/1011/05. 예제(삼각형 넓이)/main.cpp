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
	printf("가로 길이 : ");
	scanf("%d",&b);
	printf("세로 길이 : ");
	scanf("%d",&h);
}

void Area::calA()
{
	printf ("삼각형의 넓이는 %.1lf 입니다\n",b*h/2.);
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
	printf("가로 길이 : ");
	scanf("%d",&area.b);
	printf("세로 길이 : ");
	scanf("%d",&area.h);
	area.calA(area.b,area.h);
}


void Area::calA(int b,int h)
{
	printf ("삼각형의 넓이는 %.1lf 입니다\n",b*h/2.);
}	
*///////////////////////////////////////////////////////////