#include <iostream>
using namespace std;
class A{
	int x;						//�����̺� ��� ������
public:
	int y;
	A(){
		cout<<"A()"<<endl;		//�����ڴ� ��� ������
	}
	A(int a):x(a){
		cout<<"A()2"<<endl;
	}
	virtual void test1()
	{
		cout<<"A:test()"<<endl;
	}
};

class B: public A{
public :
	B(int a, int b):A(a){
		cout<<"B()"<<endl;
			y=b;
	}							//�ϳ��� �θ� ������ 

	void test1(){
		cout<<"B:test1()"<<endl;
	}
	void test2(){
		cout<<"B:test2()"<<endl;
	}


};

