#include <iostream>
using namespace std;
class A{
	int x;						//프라이빗 상속 못받음
public:
	int y;
	A(){
		cout<<"A()"<<endl;		//생성자는 상속 못받음
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
	}							//하나는 부모 생성자 

	void test1(){
		cout<<"B:test1()"<<endl;
	}
	void test2(){
		cout<<"B:test2()"<<endl;
	}


};

