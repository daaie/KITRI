#include <iostream>
#include "relation.h"
using namespace std;

void main()
{
	int menu;
	cout<<"¸Þ´º?"<<endl;
	cin>>menu;
	Shape *s;
	Point p[]={Point(1,2),Point(3,4),Point(5,6)};

	switch(menu)
	{
	case 1 : s=new Triangle(p);
		break;
	case 2 : s=new Circle(1,2,3);
		break;
	case 3 : s=new Rectangle (1,2,3,4);
		break;
	default : break;
	}

	s->draw();
}