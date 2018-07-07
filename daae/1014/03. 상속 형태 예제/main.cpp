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
//class child : protected parent  //�ܺ� ���� �Ұ�
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
	cout<<"<����Ŭ����(�ڽ�)�� �Լ��� �̿��Ͽ� ����Ŭ����(�θ�)�Լ��� ����>"<<endl;
	child.child_out(3,4,5);

	/*------����Ŭ�������� ����Ŭ������ �Լ��� ������ �����ϱ� ���ؼ��� public���� ��ӹ޾ƾ��Ѵ�----*/
	cout<<"=================================================================="<<endl;
	cout<<"<����Ŭ����(�ڽ�)�� ��ü�� ���ؼ� ����Ŭ������ �Լ��� ȣ��?>"<<endl;
	cout<<"����Ŭ������ �Լ� : ";
	child.parent_out(1,2,3);  // �θ��� ������ �ڽ��� �޾������...����

	cout<<"=================================================================="<<endl;
	cout<<"<����Ŭ����(�ڽ�=���� ��)�� ��ü�� ���� ����Ŭ������ ���� ����>"<<endl;
	cout<<"����Ŭ������ ���� public_age : "<<child.public_age<<endl;


}
