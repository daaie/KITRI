#include <iostream>
using namespace std;
class Area
{	
	int h,b;

public : 
	//Area(int h, int b)
	//{
	//	this->h=h;   //this->h �� ������� private h
	//	this->b=b;	 //�캯 h�� �������� ��������	
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
	printf("���� ���� : ");
	scanf("%d",&b);
	printf("���� ���� : ");
	scanf("%d",&h);
	Area* area=new Area(h,b); 	//Area area(h);
	(*area).calA(); //area->calA();
}


void Area::calA()
{
	printf ("�ﰢ���� ���̴� %.1lf �Դϴ�\n",b*h/2.);
}	
