#include <iostream>
using namespace std;

class Point 
{
//friend Circle ; ģ������� �ϳ��� �ϳ�����..
	int x;
	int y;

public :
	Point (int a, int b) : x(a),y(b){}
	void printxy()
	{
		cout<<"x= "<<x<<" ,y= " <<y<<endl;
	}
};


class Shape
{
public : 
	virtual void draw()=0;
};


class Circle : public Shape
{
	int r;
	Point *point;

public :
	Circle (int a, int b, int c)
	{
		point=new Point(a,b);
		r=c;
	}

	~Circle()
	{
		delete point;
	}

	void draw()		//Ŭ�����ȿ��� ���� �Լ��� ����->�ζ��� �Լ��� ��...�ӵ��� ������ �ڵ��Ŀ��
	{
		cout<<"�߽��� : ";
		point->printxy();
		cout<<"������ r = "<<r<<endl;		
	}

};

class Triangle : public Shape
{
	Point *p;
public :
	Triangle(Point *x)
	{
		p=x;
	}
	void draw()
	{
		cout<<"�ﰢ��"<<endl;
		for (int i=0;i<3;i++)
		{
			cout<<"p"<<i<<" : ";
			p[i].printxy();
			cout<<endl;
		}
	}
};

class Rectangle : public Shape
{
	Point *p1;
	Point *p2;

public :
	Rectangle(int x1, int y1, int x2, int y2)
	{
		p1= new Point(x1,y1);
		p2= new Point(x2,y2);
	}
	~Rectangle()
	{
		delete p1;
		delete p2;
	}
	void draw()
	{
		cout<<"�簡��"<<endl;
		p1->printxy();
		p2->printxy();
		cout<<endl;
	}

};