#include <iostream>
using namespace std;
class Area
{	
	int h,b;

public : 
	//Area(int h, int b)
	//{
	//	this->h=h;   //this->h 는 멤버변수 private h
	//	this->b=b;	 //우변 h는 생성자의 지역변수	
	//}
/******************************************************
	//Area(int h1, int b1)
	//{
	//	h=h1;
	//	b=b1;
	//}
*///***************************************************
	Area(int h,int b) : h(h),b(b)
	{
	}
//*******************************************************
	void calA();

};
void main()
{
	int b,h;
	printf("가로 길이 : ");
	scanf("%d",&b);
	printf("세로 길이 : ");
	scanf("%d",&h);
	Area* area=new Area(h,b); 	//Area area(h);
	(*area).calA(); //area->calA();
}


void Area::calA()
{
	printf ("삼각형의 넓이는 %.1lf 입니다\n",b*h/2.);
}	
