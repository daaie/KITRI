#include <iostream>
using namespace std;
class parent
{
private : 
	int private_age;
protected:
	int protected_age;
public:
	int public_age;

//protected :
public:
	parent(int a,int b,int c)
	{
		private_age=a;
		protected_age=b;
		public_age=c;
	}
	void parent_out(int i, int j, int k)
	{
		cout<<"parent out "<<endl;
		cout<<"i= "<<i<<" j= "<<j<<" k= "<<k<<endl;
		cout<<"private_age"<<private_age<<endl;
		cout<<"protected_age"<<protected_age<<endl;
	}
};

class child : public parent
//class child : protected parent  //외부 접근 불가
{
public :
	child(int a, int b, int c) :parent(a,b,c)
	{
		cout<<endl;
	}
	void child_out(int i,int j,int k)
	{
		parent_out(i,j,k);
		cout<<"child_out "<<endl;
	}
};

void main()
{
	child child(6,7,8);
	cout<<"=================================================================="<<endl;
	cout<<"<유도클래스(자식)의 함수를 이용하여 기초클래스(부모)함수를 실행>"<<endl;
	child.child_out(3,4,5);

	/*------유도클래스에서 기초클래스의 함수나 변수를 접근하기 위해서는 public으로 상속받아야한다----*/
	cout<<"=================================================================="<<endl;
	cout<<"<유도클래스(자식)의 객체를 통해서 기초클래스의 함수를 호출?>"<<endl;
	cout<<"기초클래스의 함수 : ";
	child.parent_out(1,2,3);  // 부모의 변수를 자식이 받아줘야함...덜덜

	cout<<"=================================================================="<<endl;
	cout<<"<유도클래스(자식=슈퍼 애)의 객체를 통한 기초클래스의 변수 접근>"<<endl;
	cout<<"기초클래스의 변수 public_age : "<<child.public_age<<endl;


}
